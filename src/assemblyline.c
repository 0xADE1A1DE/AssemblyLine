/**
 * Copyright 2022 University of Adelaide
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(__linux)
#define _GNU_SOURCE 1
#include <fcntl.h> //open
#include <sys/mman.h>
#include <sys/stat.h>
#endif


/**
 * called when an instance of @param al is created and maps the index of
 * INSTR_TABLE[] where the first occurrence of each letter of the alphabet to
 * instr_index_table for more efficient instruction lookup
 */
static void
asm_build_index_tables(assemblyline_t al)
{
    // INSTR_TABLE index starts at the SKIP entry
    size_t i           = 2;
    char previous_char = 'a' - 1;
    while ( INSTR_TABLE[++i].name != NA )
    {
        if ( INSTR_TABLE[i].instr_name[0] != '\0' )
        {
            if ( previous_char != INSTR_TABLE[i].instr_name[0] )
                instr_table_index[INSTR_TABLE[i].instr_name[0] - 'a'] = i;
            previous_char = INSTR_TABLE[i].instr_name[0];
        }
    }
    // create an index table from OPD_FORMAT_TABLE
    i             = 0;
    previous_char = '\0';
    while ( OPD_FORMAT_TABLE[++i].val != opd_error )
    {
        if ( previous_char != OPD_FORMAT_TABLE[i].str[0] )
        {
            opd_format_table_index[OPD_FORMAT_TABLE[i].str[0] - 'a'] = i;
            previous_char                                            = OPD_FORMAT_TABLE[i].str[0];
        }
    }
    al->table_built = true;
}

assemblyline_t
asm_create_instance(uint8_t* buffer, int len)
{

    assemblyline_t al = malloc(sizeof(struct assemblyline));
    al->offset        = 0;
    al->assembly_opt  = DEFAULT;
    // allocate buffer internally if not directly given
    if ( buffer == NULL )
    {
        al->external   = false;
        al->buffer_len = MEM_BUFFER + BUFFER_TOLERANCE;
#if defined(__linux__)
        al->buffer = mmap(
            NULL,
            sizeof(uint8_t) * al->buffer_len,
            PROT_READ | PROT_WRITE | PROT_EXEC,
            MAP_ANONYMOUS | MAP_PRIVATE,
            -1,
            0);
        if ( al->buffer == MAP_FAILED )
        {
#else
        al->buffer = VirtualAlloc(NULL, sizeof(uint8_t) * al->buffer_len, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        if ( al->buffer == NULL )
        {
#endif
            fprintf(stderr, "failed to allocate internal memory buffer\n");
            perror("Error: ");
            free(al);
            return NULL;
        }
    }
    else
    {
        al->external   = true;
        al->buffer_len = len;
        al->buffer     = buffer;
    }
    al->assembly_mode = ASSEMBLE;
    al->chunk_size    = NONE;
    al->chunk_size++;
    al->debug     = false;
    al->finalized = false;
    asm_build_index_tables(al);
    return al;
}

int
asm_destroy_instance(assemblyline_t instance)
{
    // free internal buffer
    if ( !instance->external )
#if defined(__linux__)
        if ( munmap((void*)instance->buffer, instance->buffer_len) == -1 )
#else
        if ( VirtualFree((void*)instance->buffer, instance->buffer_len, MEM_DECOMMIT) == FALSE )
#endif
            perror("Error: ");
    free(instance);
    return EXIT_SUCCESS;
}

// checks the minimum buffer length requirement 20 bytes at least
static int
check_buffer_len(int buffer_len)
{

    FAIL_IF_MSG(
        buffer_len < BUFFER_TOLERANCE,
        "insufficient buffer size: ensure length of buffer is at least "
        "20 bytes\n");
    return EXIT_SUCCESS;
}

int
assemble_str(assemblyline_t al, const char* assembly_str)
{
    return asm_assemble_str(al, assembly_str);
}

int
asm_assemble_str(assemblyline_t al, const char* assembly_str)
{

    al->finalized = false;
    // check minimum buffer length requirement
    check_buffer_len(al->buffer_len);
    // assemble string containing x64 assembly code
    al->offset = assemble_all(al, assembly_str, NULL);
    FAIL_IF(al->offset == ASM_ERROR);
    al->finalized = true;
    return EXIT_SUCCESS;
}

int
assemble_string_counting_chunks(assemblyline_t al, char* str, int chunk_size, int* dest)
{
    return asm_assemble_string_counting_chunks(al, str, chunk_size, dest);
}

int
asm_assemble_string_counting_chunks(assemblyline_t al, char* str, int chunk_size, int* dest)
{
    al->assembly_mode = CHUNK_COUNT;
    if ( chunk_size < 2 )
        al->assembly_mode = ASSEMBLE;
    al->chunk_size = chunk_size;
    check_buffer_len(al->buffer_len);
    // assemble string containing x64 assembly code
    al->offset = assemble_all(al, str, dest);
    FAIL_IF(al->offset == ASM_ERROR);
    al->finalized = true;
    return EXIT_SUCCESS;
}

int
assemble_file(assemblyline_t al, char* asm_file)
{
    return asm_assemble_file(al, asm_file);
}

#ifdef __linux__
static inline int
asm_assemble_file_linux(assemblyline_t al, char* asm_file)
{
    // open file for reading
    int fd = open(asm_file, O_RDONLY, S_IRUSR | S_IRUSR);
    FAIL_SYS(fd == -1, "failed to open file\n");
    struct stat file_stat;
    FAIL_SYS(fstat(fd, &file_stat), "failed to get file stats\n");
    // map file contents to a string
    size_t str_len           = file_stat.st_size;
    const char* assembly_str = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);
    FAIL_SYS(assembly_str == MAP_FAILED, "failed to allocate memory via mmap\n");
    int exit_status = asm_assemble_str(al, assembly_str);
    // free mmap memory used for reading file
    FAIL_SYS(munmap((void*)assembly_str, str_len) == -1, "Error: failed to free memory\n");
    return exit_status;
}
#else
static inline int
asm_assemble_file_windows(assemblyline_t al, char* asm_file)
{
    // open file for reading
    HANDLE hFile = CreateFileA(asm_file, GENERIC_READ, 0, NULL, OPEN_ALWAYS, 0, NULL);
    FAIL_SYS((hFile == INVALID_HANDLE_VALUE), "failed to open file\n");

    // map file contents to a string
    HANDLE hMapFile = CreateFileMappingA(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    FAIL_SYS((hMapFile == NULL), "Error: failed to map memory\n");

    LPCSTR assembly_str = (LPCSTR)MapViewOfFile(hMapFile, FILE_MAP_READ, 0, 0, GetFileSize(hFile, NULL));
    FAIL_SYS((assembly_str == NULL), "Error: failed to map memory\n");

    int exit_status = asm_assemble_str(al, assembly_str);

    // free mmap memory used for reading file
    FAIL_SYS(UnmapViewOfFile(assembly_str) == FALSE, "Error: failed to unmap memory handle\n");
    FAIL_SYS(CloseHandle(hMapFile) == FALSE, "Error: failed to close memory handle\n");
    FAIL_SYS(CloseHandle(hFile) == FALSE, "Error: failed to close file handle\n");

    return exit_status;
}
#endif

int
asm_assemble_file(assemblyline_t al, char* asm_file)
{
#ifdef __linux__
    return asm_assemble_file_linux(al, asm_file);
#else
    return asm_assemble_file_windows(al, asm_file);
#endif
}

void
asm_set_chunk_size(assemblyline_t al, size_t chunk_size)
{
    // set chunk size to 1 to prevent floating point exception
    if ( chunk_size < 2 )
    {
        al->assembly_mode = ASSEMBLE;
    }
    else
    {
        al->chunk_size    = chunk_size;
        al->assembly_mode = CHUNK_FITTING;
    }
}

void
asm_set_debug(assemblyline_t al, bool debug)
{
    al->debug = debug;
}

int
asm_get_offset(assemblyline_t al)
{
    return al->offset;
}

void
asm_set_offset(assemblyline_t al, int offset)
{
    al->offset = offset;
}

DEPRECATED("use asm_get_code instead")
uint8_t*
asm_get_buffer(assemblyline_t al)
{
    return al->buffer;
}

void*
asm_get_code(assemblyline_t al)
{
    return (void*)al->buffer;
}

int
asm_create_bin_file(assemblyline_t al, const char* file_name)
{
    void* buffer    = asm_get_code(al);
    int len         = asm_get_offset(al);
    FILE* write_ptr = fopen(file_name, "wb");

    FAIL_IF_MSG(write_ptr == NULL, "failed to create binary file")

    fwrite(buffer, sizeof(uint8_t), len, write_ptr);

    fclose(write_ptr);

    return EXIT_SUCCESS;
}

void
asm_mov_imm(assemblyline_t al, enum asm_opt option)
{

    switch ( option )
    {
    case ASM_OPT_NASM:
        al->assembly_opt |= NASM_MOV_IMM;
        al->assembly_opt &= ~SMART_MOV_IMM;
        break;
    case ASM_OPT_STRICT:
        al->assembly_opt &= ~(NASM_MOV_IMM | SMART_MOV_IMM);
        break;
    case ASM_OPT_SMART:
        al->assembly_opt |= SMART_MOV_IMM;
        al->assembly_opt &= ~NASM_MOV_IMM;
        break;
    default:
        return;
    }
}

void
asm_sib(assemblyline_t al, enum asm_opt option)
{

    switch ( option )
    {
    case ASM_OPT_NASM:
        asm_sib_index_base_swap(al, ASM_OPT_NASM);
        asm_sib_no_base(al, ASM_OPT_NASM);
        break;
    case ASM_OPT_STRICT:
        asm_sib_index_base_swap(al, ASM_OPT_STRICT);
        asm_sib_no_base(al, ASM_OPT_STRICT);
        break;
    default:
        return;
    }
}

void
asm_sib_index_base_swap(assemblyline_t al, enum asm_opt option)
{

    switch ( option )
    {
    case ASM_OPT_NASM:
        al->assembly_opt |= NASM_SIB_INDEX_BASE_SWAP;
        break;
    case ASM_OPT_STRICT:
        al->assembly_opt &= ~NASM_SIB_INDEX_BASE_SWAP;
        break;
    default:
        return;
    }
}

void
asm_sib_no_base(assemblyline_t al, enum asm_opt option)
{

    switch ( option )
    {
    case ASM_OPT_NASM:
        al->assembly_opt |= NASM_SIB_NO_BASE;
        break;
    case ASM_OPT_STRICT:
        al->assembly_opt &= ~NASM_SIB_NO_BASE;
        break;
    default:
        return;
    }
}

void
asm_set_all(assemblyline_t al, enum asm_opt option)
{

    switch ( option )
    {
    case ASM_OPT_NASM:
        asm_mov_imm(al, ASM_OPT_NASM);
        asm_sib_index_base_swap(al, ASM_OPT_NASM);
        asm_sib_no_base(al, ASM_OPT_NASM);
        break;
    case ASM_OPT_STRICT:
        asm_mov_imm(al, ASM_OPT_STRICT);
        asm_sib_index_base_swap(al, ASM_OPT_STRICT);
        asm_sib_no_base(al, ASM_OPT_STRICT);
        break;
    case ASM_OPT_SMART:
        asm_mov_imm(al, ASM_OPT_SMART);
        break;
    default:
        return;
    }
}
