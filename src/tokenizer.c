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

/*implements functions for tokenizing a preprocessed assembly instruction
 * string*/
#include "tokenizer.h"
#include "instr_parser.h"
#include "reg_parser.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * sets @param len number of characters to ' ' for @param str
 */
static void clearstring(char *str, int len) {
  for (int i = 0; i < len; i++)
    str[i] = ' ';
}

/**
 * Given an instance of @param instr_buffer and the sign of memory offset @param
 * neg, sets the 'm' displacement value for modRM32_64[m][r] table
 */
static void get_mod_disp(struct instr *instr_buffer, bool neg) {
  // set modRM_64[i][j] 'i' displacement value depending on the range of
  // memory_offset
  uint32_t memory_offset = instr_buffer->mem_offset;
  if (memory_offset == 0)
    instr_buffer->mod_disp = 0;
  else if (!neg) {
    if (IN_RANGE(memory_offset, 1, MAX_SIGNED_8BIT))
      instr_buffer->mod_disp &= MOD8;
    else if (memory_offset > MAX_SIGNED_8BIT)
      instr_buffer->mod_disp &= MOD16;
  } else {
    if (IN_RANGE(memory_offset, 1, MAX_UNSIGNED_8BIT))
      instr_buffer->mod_disp &= MOD8;
    else if (memory_offset > MAX_UNSIGNED_8BIT)
      instr_buffer->mod_disp &= MOD16;
  }
}

/**
 * Given an instance of @param instr_buffer convert a memory displacement string
 * representation @param mem into its equivalent unsigned long representation
 */
static int mem_tok(struct instr *instr_buffer, char *mem, int opd_pos) {

  instr_buffer->mem_disp = true;
  bool neg = false;
  int base = 0;
  // set index for memory operand
  instr_buffer->mem_index = opd_pos;
  // find the index position of the memory displacement string
  int index_add = find_add_mem(mem, &neg, &base);
  int index_const = find_mem_const(mem, &neg, &base);
  FAIL_IF_MSG(get_index_reg(instr_buffer, mem, instr_buffer->opd[opd_pos].sib),
              "invalid memory syntax\n");
  instr_buffer->mem_offset = 0;
  // convert string to unsigned long for memory displacement representation
  if (index_add != NA) {
    instr_buffer->mem_offset = strtoul(mem + index_add, NULL, base);
    // if displacement is negative represent in 2's complement
    if (neg)
      instr_buffer->mem_offset = process_neg_disp(instr_buffer->mem_offset);
  } else if (index_const != NA) {
    instr_buffer->mem_value = true;
    instr_buffer->mem_const = strtoul(mem + index_const, NULL, base);
    // if displacement is negative represent in 2's complement
    if (neg)
      instr_buffer->mem_const = ~instr_buffer->mem_const + 1;
  }
  get_mod_disp(instr_buffer, neg);
  return EXIT_SUCCESS;
}

/**
 * Given an instance of @param instr_buffer convert a immediate string
 * representation @param imme into its equivalent unsigned long representation
 */
static void imm_tok(struct instr *instr_buffer, char *imme) {

  size_t imme_str_len = strlen(imme);
  char *saved_saved = NULL;
  instr_buffer->imm = true;
  int base = RADIX_10;
  imme = strtok_r(imme, " ", &saved_saved);
  if (imme[1] == 'x' || imme[2] == 'x') {
    base = RADIX_16;
    if ((instr_buffer->assembly_opt & SMART_MOV_IMM) &&
        imme_str_len < STR_HEX_64)
      instr_buffer->assembly_opt |= NASM_MOV_IMM;
  }
  // convert string to unsigned long for immediate representation
  instr_buffer->cons = strtoul(imme, NULL, base);
}

/**
 * Given an instance of @param instr_buffer, checks for the presence of a
 * keyword (byte, short, or long) for @param opds at operand postion
 * @param opd_pos.
 */
static void check_for_keyword(struct instr *instr_buffer, char *all_opd,
                              int opd_pos) {

  char *pointer = all_opd;
  while (*pointer == ' ')
    pointer++;

  if (strstr(pointer, "byte") == pointer) {
    instr_buffer->keyword.is_byte = true;
    clearstring(pointer, BYTE_LEN);
    return;
  }

  if (strstr(pointer, "word") == pointer) {
    instr_buffer->keyword.is_word = true;
    clearstring(pointer, BYTE_LEN);
    return;
  }

  if (strstr(pointer, "dword") == pointer) {
    instr_buffer->keyword.is_dword = true;
    clearstring(pointer, DWORD_LEN);
    return;
  }

  if (strstr(pointer, "qword") == pointer) {
    clearstring(pointer, DWORD_LEN);
    return;
  }

  if (strstr(pointer, "short") == pointer) {
    instr_buffer->keyword.is_short = true;
    instr_buffer->keyword.is_long = false;
    clearstring(pointer, SHORT_LEN);
    return;
  }

  if (strstr(pointer, "long") == pointer) {
    instr_buffer->keyword.is_long = true;
    instr_buffer->keyword.is_short = false;
    clearstring(pointer, LONG_LEN);
    return;
  }

  if (strstr(pointer, "far") == pointer) {
    instr_buffer->keyword.is_far = true;
    clearstring(pointer, FAR_LEN);
    // check for a possible next keyword in the case for `far qword` etc.
    check_for_keyword(instr_buffer, pointer, opd_pos);
    return;
  }
}

/**
 * Given an instance of @param instr_buffer, checks the operand type of
 * @param opds at operand postion @param opd_pos to get the register if
 * operand is not an immediate.
 */
static int check_operand_type(struct instr *instr_buffer, char *all_opd,
                              int opd_pos, char *saved_opd) {

  switch (instr_buffer->opd[opd_pos].type) {
  // convert immediate to unsigned long
  case 'i':
    imm_tok(instr_buffer, all_opd);
    if (strtok_r(NULL, "", &saved_opd) == NULL)
      return EXIT_SUCCESS;
    FAIL_IF_MSG(true, "cannot have an operand after immediate\n");
    break;
  // get register string from operand
  case 'r':
  case 'v':
  case 'y':
  case 'm':
    // get register for memory and non memory operand
    get_reg_str(all_opd, instr_buffer->opd[opd_pos].str);
    if (instr_buffer->opd[opd_pos].type == 'm')
      return mem_tok(instr_buffer, all_opd, opd_pos);
    return EXIT_SUCCESS;
  // operand type is not found
  default:
    FAIL_IF_VAR(true, "illegal operand : \"%s\"\n", instr_buffer->instruction);
  }
}

/**
 * Given an instance of @param instr_buffer, tokenize operand string @param
 * opds at operand postion @param opd_pos.
 */
static int operand_tok(struct instr *instr_buffer, char *opds, int opd_pos) {

  char *saved_opd = NULL;
  FAIL_IF(opds[0] == ',');
  // get the 1st operand
  char *all_opd = strtok_r(opds, ",", &saved_opd);
  check_for_keyword(instr_buffer, all_opd, opd_pos);
  // get the operand type can be 'i', 'r', or 'm'
  instr_buffer->opd[opd_pos].type = get_operand_type(all_opd);
  FAIL_IF(check_operand_type(instr_buffer, all_opd, opd_pos, saved_opd));
  // get next operand
  char *next_operands = strtok_r(NULL, "", &saved_opd);
  if (next_operands == NULL)
    return EXIT_SUCCESS;
  // recursively call operand_tok to process next operand
  if (opd_pos <= FOURTH_OPERAND)
    return operand_tok(instr_buffer, next_operands, opd_pos + 1);
  return EXIT_FAILURE;
}

int instr_tok(struct instr *instr_buffer, char *comp_instr) {

  char *saved_instr = NULL;
  // get the string component containing the instruction
  char *instruction_str = strtok_r(comp_instr, " \t", &saved_instr);
  strncpy(instr_buffer->instruction, instruction_str, MAX_INSTR_LEN);
  char *next_operands = strtok_r(NULL, "", &saved_instr);
  if (next_operands != NULL)
    return operand_tok(instr_buffer, next_operands, FIRST_OPERAND);
  return EXIT_SUCCESS;
}
