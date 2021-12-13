/**
 * Copyright 2021 University of Adelaide
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*implements an interface between the calling function and the assembler*/
#include "assemblyline.h"
#include "common.h"
#include "parser.h"
#if HAVE_CONFIG_H
#include <config.h> // from autotools
#endif
#include <fcntl.h> //open
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>

/**
 * called when an instance of @param al is created and maps the index of
 * INSTR_TABLE[] where the first occurrence of each letter of the alphabet to
 * instr_index_table for more efficient instruction lookup
 */
static void asm_build_index_table(assemblyline_t al) {
  int i = 3;
  char previous_char = 'a' - 1;
  while (INSTR_TABLE[i].name != NA) {
    if (INSTR_TABLE[i].instr_name[0] != '\0') {
      if (previous_char != INSTR_TABLE[i].instr_name[0])
        instr_table_index[INSTR_TABLE[i].instr_name[0] - 'a'] = i;
      previous_char = INSTR_TABLE[i].instr_name[0];
    }
    i++;
  }
}

assemblyline_t asm_create_instance(uint8_t *buffer, int len) {

  assemblyline_t al = malloc(sizeof(struct assemblyline));
  al->offset = 0;
  al->mov_imm_handling = SMART;
  // allocate buffer internally if not directly given
  if (buffer == NULL) {
    al->external = false;
    al->buffer_len = MEM_BUFFER + BUFFER_TOLERANCE;
    al->buffer = mmap(NULL, sizeof(uint8_t) * al->buffer_len,
                      PROT_READ | PROT_WRITE | PROT_EXEC,
                      MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (al->buffer == MAP_FAILED) {
      fprintf(stderr, "failed to allocate internal memory buffer\n");
      perror("Error: ");
      free(al);
      return NULL;
    }
  } else {
    al->external = true;
    al->buffer_len = len;
    al->buffer = buffer;
  }
  al->assembly_mode = ASSEMBLE;
  al->chunk_size = NONE;
  al->chunk_size++;
  al->debug = false;
  al->finalized = false;
  asm_build_index_table(al);
  return al;
}

int asm_destroy_instance(assemblyline_t instance) {
  // free internal buffer
  if (!instance->external)
    if (munmap((void *)instance->buffer, instance->buffer_len) == -1)
      perror("Error: ");
  free(instance);
  return EXIT_SUCCESS;
}

// checks the minimum buffer length requirement 20 bytes at least
static int check_buffer_len(int buffer_len) {

  FAIL_IF_MSG(buffer_len < BUFFER_TOLERANCE,
              "insufficient buffer size: ensure length of buffer is at least "
              "20 bytes\n");
  return EXIT_SUCCESS;
}

int assemble_str(assemblyline_t al, const char *assembly_str) {

  al->finalized = false;
  // check minimum buffer length requirement
  check_buffer_len(al->buffer_len);
  // assemble string containing x64 assembly code
  al->offset = assemble_all(al, assembly_str, NULL);
  FAIL_IF(al->offset == ASM_ERROR);
  al->finalized = true;
  return EXIT_SUCCESS;
}

int assemble_string_counting_chunks(assemblyline_t al, char *str,
                                    int chunk_size, int *dest) {
  al->assembly_mode = CHUNK_COUNT;
  if (chunk_size < 2)
    al->assembly_mode = ASSEMBLE;
  al->chunk_size = chunk_size;
  check_buffer_len(al->buffer_len);
  // assemble string containing x64 assembly code
  al->offset = assemble_all(al, str, dest);
  FAIL_IF(al->offset == ASM_ERROR);
  al->finalized = true;
  return EXIT_SUCCESS;
}

int assemble_file(assemblyline_t al, char *asm_file) {
  // open file for reading
  int fd = open(asm_file, O_RDONLY, S_IRUSR | S_IRUSR);
  FAIL_SYS(fd == -1, "failed to open file\n");
  struct stat file_stat;
  FAIL_SYS(fstat(fd, &file_stat), "failed to get file stats\n");
  // map file contents to a string
  size_t str_len = file_stat.st_size;
  const char *assembly_str =
      mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  close(fd);
  FAIL_SYS(assembly_str == MAP_FAILED, "failed to allocate memory via mmap\n");
  int exit_status = assemble_str(al, assembly_str);
  // free mmap memory used for reading file
  FAIL_SYS(munmap((void *)assembly_str, str_len) == -1,
           "Error: failed to free memory\n");
  return exit_status;
}

void asm_set_chunk_size(assemblyline_t al, size_t chunk_size) {
  // set chunk size to 1 to prevent floating point exception
  if (chunk_size < 2) {
    al->assembly_mode = ASSEMBLE;
  } else {
    al->chunk_size = chunk_size;
    al->assembly_mode = CHUNK_FITTING;
  }
}

void asm_set_debug(assemblyline_t al, bool debug) { al->debug = debug; }

int asm_get_offset(assemblyline_t al) { return al->offset; }

void asm_set_offset(assemblyline_t al, int offset) { al->offset = offset; }

uint8_t *asm_get_buffer(assemblyline_t al) { return al->buffer; }

void *asm_get_code(assemblyline_t al) { return (void *)al->buffer; }

void strict_mov_imm_handling(assemblyline_t al) {
  al->mov_imm_handling = STRICT;
}

void nasm_mov_imm_handling(assemblyline_t al) { al->mov_imm_handling = NASM; }

void smart_mov_imm_handling(assemblyline_t al) {
  al->mov_imm_handling = SMART;
}
