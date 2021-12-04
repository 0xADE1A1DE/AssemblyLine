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

/*implements functions for filtering a string containing assembly instructions
and converting that filtered string into its respective struct instr
representation*/
#define _GNU_SOURCE 1
#include "parser.h"
#include "assembler.h"
#include "encoder.h"
#include "instr_parser.h"
#include "instructions.h"
#include "reg_parser.h"
#include "tokenizer.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

/**
 * checks the validity of each register within @param check_instr
 */
static int check_registers(struct instr *check_instr) {

  FAIL_IF((check_instr->opd[0] & reg_error) == reg_error);
  FAIL_IF((check_instr->opd_mem[0] & reg_error) == reg_error);
  FAIL_IF((check_instr->opd[1] & reg_error) == reg_error);
  FAIL_IF((check_instr->opd_mem[1] & reg_error) == reg_error);
  FAIL_IF((check_instr->opd[2] & reg_error) == reg_error);
  return EXIT_SUCCESS;
}

/**
 * tokenize and parse @param filtered_asm_str to fill in @param instr_data
 */
static int line_to_instr(struct instr *instr_data, char *filtered_asm_str) {
  // default mod displacement value
  instr_data->mod_disp = MOD24;
  // tokenize filtered instruction for mapping to instr internal structure
  FAIL_IF_MSG(instr_tok(instr_data, filtered_asm_str), "syntax error\n");
  // convert operand format from string to enum representation
  operand_format opd_format = get_opd_format(instr_data->opds.opd_type);
  FAIL_IF_VAR(opd_format == opd_error, "illegal operand format: %s\n",
              instr_data->opds.opd_type)
  // jcc [MEM] no register
  if (opd_format == m && instr_data->opds.opd_cpy[0][0] == '\0') {
    instr_data->mod_disp &= MOD16;
    instr_data->keyword.is_short = true;
  }
  // convert instruction string to enum representation
  instr_data->key = str_to_instr_key(instr_data->instruction, opd_format);
  FAIL_IF_VAR(instr_data->key == INSTR_ERROR,
              "unsupported or illegal instruction: %s\n",
              instr_data->instruction);
  if (instr_data->imm && INSTR_TABLE[instr_data->key].type == CONTROL_FLOW) {
    if (IN_RANGE(instr_data->cons, 0xffffff80, 0xffffffff))
      instr_data->keyword.is_short = true;
    else if (IN_RANGE(instr_data->cons, 0, 0x7f) &&
             !instr_data->keyword.is_long)
      instr_data->keyword.is_short = true;
    else
      FAIL_IF_MSG(instr_data->cons > 0x7f && instr_data->keyword.is_short,
                  "cannot set a long jump to short\n");
  }
  // find the encoding for a short jump instruction if applicable
  instr_data->key += instr_data->keyword.is_short;
  // convert register string to enum representation
  instr_data->opd[0] = str_to_reg(instr_data->opds.opd_cpy[0]);
  instr_data->opd_mem[0] = str_to_reg(instr_data->opds.opd_mem_cpy[0]);
  instr_data->opd[1] = str_to_reg(instr_data->opds.opd_cpy[1]);
  instr_data->opd_mem[1] = str_to_reg(instr_data->opds.opd_mem_cpy[1]);
  instr_data->opd[2] = str_to_reg(instr_data->opds.opd_cpy[2]);
  // values will be determined during encoding
  instr_data->hex.reg = NO_PREFIX;
  instr_data->hex.rex = NO_PREFIX;
  instr_data->hex.is_C5H = true;
  instr_data->hex.vex_R[0] = C5H;
  instr_data->hex.vex_R[1] = 0xfd;
  instr_data->hex.vex_RXB[0] = C4H;
  instr_data->hex.vex_RXB[1] = rex_ + rex_b;
  instr_data->hex.vex_RXB[2] = 0xfd;
  instr_data->hex.mem = NO_PREFIX;
  // checks if the registers are valid
  FAIL_IF_VAR(check_registers(instr_data),
              "Invalid register for instruction: %s\n",
              instr_data->instruction);
  // force jump immediate to 32 bits
  if (INSTR_TABLE[instr_data->key].type == CONTROL_FLOW &&
      IN_RANGE(instr_data->cons, NEG32BIT + 1, NEG64BIT))
    instr_data->cons &= 0xffffffff;
  // encode for the reg_hex value and op_offset for instruction
  if (instr_data->opd[0] != reg_none) {
    // gets all offsets
    encode_offset(instr_data);
    // cleans up immediate
    encode_imm(instr_data);
    // finds the operand and prefix hex values
    encode_operands(instr_data);
  }
  return EXIT_SUCCESS;
}

/**
 * reads @param unfiltered_str and writes the filtered string into @param
 * filter_str
 */
static int filter_assembly_str_fsa(const char unfiltered_str[],
                                   char filter_str[]) {

  filter_op filter_state = BEGIN;
  int j = 0;
  int i = 0;
  while (unfiltered_str[i] != ';' && unfiltered_str[i] != '%' &&
         unfiltered_str[i] != '\r' && unfiltered_str[i] != '\n' &&
         unfiltered_str[i] != '\0' && j < 100) {
    switch (filter_state) {
    case BEGIN:
      if (unfiltered_str[i] >= 'A' && unfiltered_str[i] <= 'z') {
        filter_str[j++] = tolower(unfiltered_str[i]);
        filter_state = FIRST_CH;
      }
      break;
    case FIRST_CH:
      if (unfiltered_str[i] > '!')
        filter_str[j++] = tolower(unfiltered_str[i]);
      else if (unfiltered_str[i] == ' ') {
        filter_str[j++] = tolower(unfiltered_str[i]);
        filter_state = SPACE_FOUND;
      }
      break;
    case SPACE_FOUND:
      if (unfiltered_str[i] > '!')
        filter_str[j++] = tolower(unfiltered_str[i]);
      break;
    }
    // last printable ascii character
    FAIL_IF_MSG(unfiltered_str[i] > '~', "Printable ascii characters only\n");
    i++;
  }
  return i;
}

/**
 * reads @param unfiltered_str and fills in the @param instr_data fields
 */
static int str_to_instr(struct instr *instr_data, const char unfiltered_str[],
                        int *read_len) {

  char filter_str[FILTERED_STR_LEN] = {'\0'};
  // sanitize user input and copy filtered string to filter_str
  int ch_pos = filter_assembly_str_fsa(unfiltered_str, filter_str);
  // skip comments/macro
  while (unfiltered_str[ch_pos] != '\n' && unfiltered_str[ch_pos] != '\r' &&
         unfiltered_str[ch_pos] != '\0')
    ch_pos++;
  if (unfiltered_str[ch_pos] == '\n' || unfiltered_str[ch_pos] == '\r')
    ch_pos++;
  // for debugging purposes to check the filtered instruction
  // printf("filter = {%s}\n", filter);
  *read_len = ch_pos;
  // map filter_str to instr_data if not it is not a label
  if (filter_str[0] != '\0' && strstr(filter_str, "section") == NULL &&
      strstr(filter_str, "global") == NULL && strchr(filter_str, ':') == NULL)
    return line_to_instr(instr_data, filter_str);
  // set to skip and return EXIT_SUCCESS
  instr_data->key = SKIP;
  return EXIT_SUCCESS;
}

/**
 * prints out the machine code stored in @param buf up to 7 bytes
 */
static void debug_without_chunksize(int opcode_len, uint8_t *ptr) {

  for (int i = 0; i < opcode_len; i++) {
    if (i == 7)
      printf("\n");
    printf("%02x ", *ptr++);
  }
  printf("\n");
}

/**
 * prints out the machine code stored in @param buf up to @param chunk_size
 * bytes
 */
static void debug_with_chunksize(uint8_t *buf, int opcode_pos,
                                 size_t chunk_size) {

  for (int i = 0; i < opcode_pos; i++) {
    if (i % chunk_size == 0 && chunk_size > 1 && i != 0)
      printf("|\n");
    printf("%02x ", buf[i]);
  }
  printf("\n");
}

/**
 * checks if the buffer length has been exceeded
 */
int check_len_or_resize(assemblyline_t al, int buf_pos) {

  if (buf_pos + BUFFER_TOLERANCE > al->buffer_len) {
    FAIL_IF_VAR(al->external,
                "exceeded memory buffer length: al->buffer_len = %d\n",
                al->buffer_len)
#ifdef __linux__
    // resize internal memory buffer
    void *resize = mremap(al->buffer, al->buffer_len,
                          al->buffer_len + MEM_BUFFER, MREMAP_MAYMOVE);
    FAIL_SYS(resize == (void *)-1, "failed to resize buffer\n")
    al->buffer_len += MEM_BUFFER;
    al->buffer = (uint8_t *)resize;
#else
    fprintf(stderr, "internal buffer too small. Not running on Linux, "
                    "Thus there is no mremap. Use your own buffer, or "
                    "implement another strategy. ");
#endif
  }
  return EXIT_SUCCESS;
}

/**
 * given and instance of @param al write the machine code of @param new_instr
 * into @param buf_pos while counting the number of instructions that break a
 * chunk boundary, storing the number of breaks into @param chunk_brks
 */
static int assemble_counting_chunks(assemblyline_t al, struct instr *new_instr,
                                    int *buf_pos, int *chunk_brks) {

  FAIL_IF(check_len_or_resize(al, *buf_pos));
  int free_space = al->chunk_size - (*buf_pos % al->chunk_size);
  int written_length = assemble_asm(new_instr, al->buffer + *buf_pos);
  // check if the current instruction machine code crosses the chunk boundary
  if (written_length > free_space)
    (*chunk_brks)++;
  *buf_pos += written_length;
  return EXIT_SUCCESS;
}

/**
 * given and instance of @param al write the machine code of @param new_instr
 * into @param buf_pos
 */
static int assemble(assemblyline_t al, struct instr *new_instr, int *buf_pos) {

  FAIL_IF(check_len_or_resize(al, *buf_pos));
  int written_length = assemble_asm(new_instr, al->buffer + *buf_pos);
  if (al->debug)
    debug_without_chunksize(written_length, al->buffer + *buf_pos);
  *buf_pos += written_length;
  return EXIT_SUCCESS;
}

/**
 * given and instance of @param al write the machine code of @param new_instr
 * into @param buf_pos while enforcing chunk boundaries with nop padding
 */
static int assemble_with_chunk_fitting(assemblyline_t al,
                                       struct instr *new_instr, int *buf_pos) {

  bool assemble_again = false;
  do {
    assemble_again = false;
    // checks if memory buffer is exceeded
    FAIL_IF(check_len_or_resize(al, *buf_pos));
    // check the number of bytes available in chunk
    int free_chunk_space = al->chunk_size - (*buf_pos % al->chunk_size);
    int written_length = assemble_asm(new_instr, al->buffer + *buf_pos);
    // write machine code to memory if there is sufficient chunk space
    if (written_length <= free_chunk_space ||
        written_length >= al->chunk_size ||
        written_length == free_chunk_space + al->chunk_size) {
      *buf_pos += written_length;
    } else {
      *buf_pos += nop_padding(al->buffer + *buf_pos, free_chunk_space);
      assemble_again = true;
    }
  } while (assemble_again);
  return EXIT_SUCCESS;
}

/**
 * given and instance of @param al assembles @param str writing the machine code
 * into @param dest. Assembly behaviour will differ depending on assembly_mode
 */
int assemble_all(assemblyline_t al, const char *str, int *dest) {

  if (dest != NULL)
    *dest = 0;
  const char *tokenizer = str;
  int buf_pos = al->offset;
  // read str and assemble instruction line by line
  while (*tokenizer != '\0') {
    struct instr new_instr = {0};
    int chars_read = 0;
    FAIL_IF_ERR(str_to_instr(&new_instr, tokenizer, &chars_read));
    tokenizer += chars_read;
    if (new_instr.key != SKIP) {
      switch (al->assembly_mode) {
      case ASSEMBLE:
        FAIL_IF_ERR(assemble(al, &new_instr, &buf_pos))
        break;
      case CHUNK_COUNT:
        FAIL_IF_ERR(assemble_counting_chunks(al, &new_instr, &buf_pos, dest));
        break;
      case CHUNK_FITTING:
        FAIL_IF_ERR(assemble_with_chunk_fitting(al, &new_instr, &buf_pos));
        break;
      }
    }
  }
  // print machine code with chunk boundary fitting
  if (al->chunk_size > 1 && al->debug)
    debug_with_chunksize(al->buffer, buf_pos, al->chunk_size);
  return buf_pos;
}