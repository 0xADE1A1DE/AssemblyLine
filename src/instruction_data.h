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

/*defines the internal structure for mapping x86 assembly instruction
 to its corresponding opcode*/
#ifndef INSTRUCTION_DATA_H
#define INSTRUCTION_DATA_H

#include "common.h"
#include "enums.h"
#include "instructions.h"
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

// contains the memory context for assembling an asm program
struct assemblyline {
  // points to a memory buffer location containing the first instruction
  uint8_t *buffer;
  int buffer_len;
  // size of assembly program in bytes (could be manually adjusted)
  int offset;
  size_t chunk_size;
  bool external;
  ASM_MODE assembly_mode;
  bool debug;
  bool finalized;
};

// prefix and and register byte values
struct prefix {
  unsigned int reg;
  unsigned int rex;
  unsigned int vex;
  unsigned int w0;
  unsigned int mem;
};

// stores keywords used in assemblyline
struct keyword {
  bool is_short;
  bool is_long;
  bool is_byte;
};

// internal representation of an assembly instruction
struct instr {
  // connects instr to INSTR_TABLE[]
  asm_instr key;
  // stores components assembly instruction into buffer
  char instruction[INSTRUCTION_CHAR_LEN];
  char *operand[NUM_OF_OPD];
  char op_cpy[NUM_OF_OPD][MAX_REG_LEN];
  char op_mem_cpy[NUM_OF_OPD][MAX_REG_LEN];
  char opd_type[OPD_FORMAT_LEN];
  // operand registers represented as asm_reg enum
  asm_reg opd[NUM_OF_OPD];
  asm_reg opd_mem[NUM_OF_OPD];
  // keywords for assemblyline
  bool is_short;
  bool is_long;
  bool is_byte;
  // constants and memory displacement
  bool imm;
  bool reduced_imm;
  unsigned long cons;
  bool zero_byte;
  bool mem_disp;
  bool sib;
  uint32_t mem_offset;
  // displacement for modRM64_m variable based on
  // value of op_en and size of mem_disp
  int mod_disp;
  // uses operand_encoding to get value
  // operand and prefix values
  struct prefix hex;
  // offset for opcode determined by register size
  int op_offset;
  int rd_offset;
};

#endif
