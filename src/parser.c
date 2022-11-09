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

/*implements functions for filtering a string containing assembly instructions
and converting that filtered string into its respective struct instr
representation*/
#define _GNU_SOURCE 1 // NOLINT
#define MAX_OPD 5
#define MAX_LINE_LEN 100
#define OBJDUMP_MAX_LINE_LEN 7
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

  for (int i = 0; i < 3; i++) {
    FAIL_IF((check_instr->opd[i].reg & reg_error) == reg_error);
    FAIL_IF((check_instr->opd[i].index & reg_error) == reg_error);
  }
  return EXIT_SUCCESS;
}

/**
 * convert each operand string register in @param instr_data to enum
 */
static void all_opd_str_to_reg(struct instr *instr_data) {

  for (int i = 0; i < FOURTH_OPERAND; i++)
    instr_data->opd[i].reg = str_to_reg(instr_data->opd[i].str);
  for (int i = 0; i < FOURTH_OPERAND; i++)
    instr_data->opd[i].index = str_to_reg(instr_data->opd[i].sib);
}

/**
 * tokenize and parse @param filtered_asm_str to fill in @param instr_data
 */
static int line_to_instr(struct instr *instr_data, char *filtered_asm_str) {
  // back up instruction for error checking
  char asm_str[MAX_LINE_LEN];
  strncpy(asm_str, filtered_asm_str, MAX_LINE_LEN);
  // default mod displacement value r/m is register
  instr_data->mod_disp = MOD24;
  // clear the least significant bit
  if (instr_data->assembly_opt & SMART_MOV_IMM)
    instr_data->assembly_opt &= ~NASM_MOV_IMM;
  // tokenize filtered instruction for mapping to instr internal structure
  FAIL_IF_MSG(instr_tok(instr_data, filtered_asm_str), "syntax error\n");
  // convert operand format from string to enum representation
  char opd_type[MAX_OPD] = {'\0'};
  for (int i = 0; i < NUM_OF_OPD; i++)
    opd_type[i] = instr_data->opd[i].type;
  operand_format opd_format = get_opd_format(opd_type);
  FAIL_IF_VAR(opd_format == opd_error, "illegal operand format: %s\n", opd_type)
  // convert register string to enum representation
  all_opd_str_to_reg(instr_data);
  int m_index = instr_data->mem_index;
  // [MEM] no register
  if (instr_data->opd[m_index].type == 'm' &&
      instr_data->opd[m_index].str[0] == '\0' &&
      instr_data->opd[m_index].sib[0] == '\0') {
    instr_data->mod_disp &= MOD16;
    instr_data->opd[m_index].reg = spl;
  }
  // convert instruction string to enum representation
  instr_data->key = str_to_instr_key(instr_data->instruction, opd_format);
  FAIL_IF_VAR(instr_data->key == INSTR_ERROR,
              "unsupported or illegal instruction: %s\n", asm_str);
  if (instr_data->imm && TYPE(instr_data->key, CONTROL_FLOW)) {
    if (IN_RANGE(instr_data->cons, NEG80_32BIT, MAX_UNSIGNED_32BIT) ||
        (instr_data->cons <= MAX_SIGNED_8BIT && !instr_data->keyword.is_long))
      instr_data->keyword.is_short = true;
    else if (instr_data->cons > MAX_SIGNED_8BIT &&
             instr_data->keyword.is_short) {
      fprintf(stderr, "cannot set a long jump to short\n");
      return EXIT_FAILURE;
    }
  }
  // find the encoding for a short jump instruction if applicable
  instr_data->key += instr_data->keyword.is_short;
  // values will be determined during encoding
  instr_data->hex.reg = NONE;
  instr_data->hex.rex = NONE;
  instr_data->hex.sib = NO_BYTE;
  // checks if the registers are valid
  FAIL_IF_VAR(check_registers(instr_data),
              "Invalid register for instruction: %s\n",
              instr_data->instruction);
  // force jump immediate to 32 bits
  if (TYPE(instr_data->key, CONTROL_FLOW) &&
      IN_RANGE(instr_data->cons, NEG32BIT + 1, NEG64BIT))
    instr_data->cons &= MAX_UNSIGNED_32BIT;
  // encode for the reg_hex value and op_offset for instruction
  if (instr_data->opd[0].reg != reg_none ||
      instr_data->opd[0].index != reg_none) {
    // gets all offsets
    encode_offset(instr_data);
    // cleans up immediate
    encode_imm(instr_data);
    // finds the operand and prefix hex values
    FAIL_IF(encode_operands(instr_data));
  }
  // special case for push instruction with immediate
  // (used push imm16 or imm32 when immediate is greater than 0x7f)
  if (NAME(instr_data->key, push) && instr_data->cons > MAX_SIGNED_8BIT)
    instr_data->key++;
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
         unfiltered_str[i] != '\0' && j < MAX_LINE_LEN) {
    switch (filter_state) {
    case BEGIN:
      if (unfiltered_str[i] >= 'A' && unfiltered_str[i] <= 'z') {
        filter_str[j++] = (char)tolower(unfiltered_str[i]);
        filter_state = FIRST_CH;
      }
      break;
    case FIRST_CH:
      if (unfiltered_str[i] > '!')
        filter_str[j++] = (char)tolower(unfiltered_str[i]);
      else if (unfiltered_str[i] == ' ') {
        filter_str[j++] = (char)tolower(unfiltered_str[i]);
        filter_state = SPACE_FOUND;
      }
      break;
    case SPACE_FOUND:
      if (unfiltered_str[i] > '!')
        filter_str[j++] = (char)tolower(unfiltered_str[i]);
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
  *read_len = ch_pos;
  // map filter_str to instr_data if not it is not a label or header
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
static void debug_without_chunksize(unsigned int opcode_len, uint8_t *ptr) {

  for (unsigned int i = 0; i < opcode_len; i++) {
    if (i == OBJDUMP_MAX_LINE_LEN)
      printf("\n");
    printf("%02x ", *ptr++);
  }
  printf("\n");
}

/**
 * prints out the machine code stored in @param buf up to @param chunk_size
 * bytes
 */
static void debug_with_chunksize(uint8_t *buf, unsigned int opcode_pos,
                                 const size_t chunk_size) {
  for (unsigned int i = 0; i < opcode_pos; i++) {
    if (i % chunk_size == 0 && chunk_size > 1 && i != 0)
      printf("|\n");
    printf("%02x ", buf[i]);
  }
  printf("\n");
}

/**
 * checks if the buffer length has been exceeded
 */
static int check_len_or_resize(assemblyline_t al, int buf_pos) {

  if (buf_pos + BUFFER_TOLERANCE > al->buffer_len) {
    FAIL_IF_VAR(al->external, "exceeded memory buffer: al->buffer_len = %d\n",
                al->buffer_len)
#ifdef __linux__
    // resize internal memory buffer
    void *resize = mremap(al->buffer, al->buffer_len,
                          al->buffer_len + MEM_BUFFER, MREMAP_MAYMOVE);
    // NOLINTNEXTLINE(performance-no-int-to-ptr)
    FAIL_SYS(resize == MAP_FAILED, "failed to resize buffer\n", EXIT_FAILURE)
    al->buffer_len += MEM_BUFFER;
    al->buffer = (uint8_t *)resize;
#else
    fprintf(stderr, "internal buffer too small. Not running on Linux, "
                    "Thus there is no mremap. Use your own buffer, or "
                    "implement another strategy. ");
    return EXIT_FAILURE;
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
                                    unsigned int *buf_pos, int *chunk_brks) {

  FAIL_IF_MSG(chunk_brks == NULL, "chunk_brks ptr cannot be NULL\n");
  FAIL_IF(check_len_or_resize(al, *buf_pos));
  unsigned int free_space = al->chunk_size - (*buf_pos % al->chunk_size);
  unsigned int written_length = assemble_asm(new_instr, al->buffer + *buf_pos);
  // check if the current instruction machine code crosses the chunk boundary
  if (written_length > free_space)
    (*chunk_brks)++;
  if (al->debug)
    debug_without_chunksize(written_length, al->buffer + *buf_pos);
  *buf_pos += written_length;
  return EXIT_SUCCESS;
}

/**
 * given and instance of @param al write the machine code of @param new_instr
 * into @param buf_pos
 */
static int assemble(assemblyline_t al, struct instr *new_instr,
                    unsigned int *buf_pos) {

  FAIL_IF(check_len_or_resize(al, *buf_pos));
  unsigned int written_length = assemble_asm(new_instr, al->buffer + *buf_pos);
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
                                       struct instr *new_instr,
                                       unsigned int *buf_pos) {

  bool assemble_again = false;
  do {
    assemble_again = false;
    // checks if memory buffer is exceeded
    FAIL_IF(check_len_or_resize(al, *buf_pos));
    // check the number of bytes available in chunk
    size_t free_chunk_space = al->chunk_size - (*buf_pos % al->chunk_size);
    size_t written_length = assemble_asm(new_instr, al->buffer + *buf_pos);
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
 * given and instance of @param al assembles @param str writing the machine
 * code into @param dest. Assembly behaviour will differ depending on
 * assembly_mode
 */
int assemble_all(assemblyline_t al, const char *str, int *dest) {

  if (dest != NULL)
    *dest = 0;
  const char *tokenizer = str;
  unsigned int buf_pos = al->offset;
  // read str and assemble instruction line by line
  while (*tokenizer != '\0') {
    struct instr new_instr = {0};
    new_instr.assembly_opt = al->assembly_opt;
    int chars_read = 0;
    FAIL_IF_ERR(str_to_instr(&new_instr, tokenizer, &chars_read));
    tokenizer += chars_read;
    if (new_instr.key != SKIP) {
      switch (al->assembly_mode) {
      case ASSEMBLE:
        FAIL_IF_ERR(assemble(al, &new_instr, &buf_pos));
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
  if (al->assembly_mode == CHUNK_FITTING && al->debug)
    debug_with_chunksize(al->buffer, buf_pos, al->chunk_size);
  return (int)buf_pos;
}
