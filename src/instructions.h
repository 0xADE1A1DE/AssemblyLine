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

/*defines all conss for x86 assembly instruction to opcode mapping*/
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "common.h"
#include "enums.h"
#include <stdatomic.h>

// table for storing register string to enum mapping
struct opd_format_table {
  // enum representation of register
  operand_format val;
  // string representation of register
  const char str[OPERAND_FORMAT_LEN];
};

// defines opcode layout of each supported instruction
struct instr_table {

  /* null-terminated string representation of an instruction ex: "mov"
   * subsequent instructions of the same name with a different operand
   * encoding will be placed contiguously with the first instance of the
   * instuction and will have the '\0' string
   */
  char instr_name[MAX_INSTR_LEN];

  // asm_instr enumerator for uniquely identifying a instruction
  int name;

  /* contains the valid operand formats for an instruction that maps
   * to the same operand enccoding (at most 2 for a single operand encoding)
   * ex: rr (instr reg,reg) && rm (instr reg, [mem]) -> RM
   */
  int opd_format[VALID_OPERAND_FORMATS];

  /* operand encoding format as an enumerator (determines how instruction
   * operands will be encoded) in assemblyline the 'I' character op/en will be
   * ignored unless it is standalone ex: MI -> M , RMI -> RM , I -> I
   */
  operand_encoding encode_operand;

  /* enumerator for defining the semantic type of an instruction
   * where special encoding is required ( currently, only applicable for
   * SHIFT, DATA_TRANSFER, and CONTROLFLOW type instructions)
   * else set this to 'OTHER'
   */
  instr_type type;

  /* 'i' index of opcode[i] when a byte changes in the opcode depending
   * on the register size for the instruction
   * (set this value to NA if not applicable to the instruction)
   */
  unsigned int op_offset_i;

  /* used for instructions with a single register operand denoted as '/digit'
   * in the intel manual section 3.1.1.1
   * (set this value to NA if not applicable to the instruction)
   */
  int single_reg_r;

  // number of bytes in the opcode[MAX_OPCODE_LEN] field
  unsigned int instr_size;

  /* opcode layout for an instruction ex: {REX,0x0f,0xa9,REG}
   * REX and REG are placeholders for the prefix and register values
   * more can be found in enums.h opcode_encoding
   */
  unsigned int opcode[MAX_OPCODE_LEN];
};

extern const struct opd_format_table OPD_FORMAT_TABLE[];
extern const struct instr_table INSTR_TABLE[];
extern _Atomic(int) instr_table_index[LETTERS_IN_ALPHABET];      // NOLINT
extern _Atomic(int) opd_format_table_index[LETTERS_IN_ALPHABET]; // NOLINT
#endif
