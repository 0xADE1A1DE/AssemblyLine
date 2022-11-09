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

/*defines the internal structure for mapping x86 assembly instruction
 to its corresponding opcode*/
#ifndef INSTRUCTION_DATA_H
#define INSTRUCTION_DATA_H

#include "common.h"
#include "enums.h"
#include "instructions.h"
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

// contains the memory context for assembling an asm program
struct assemblyline {
  // points to a memory buffer location containing the first instruction
  uint8_t *buffer;
  int buffer_len;
  // size of assembly program in bytes (could be manually adjusted) and offset
  // of -1 denotes assembly parsing error
  int offset;
  size_t chunk_size;
  bool external : 1;
  ASM_MODE assembly_mode;
  uint8_t assembly_opt;
  bool debug : 1;
  bool finalized : 1;
};

// prefix and and register byte values
struct prefix {
  unsigned int reg;
  unsigned int rex;
  // [W|R][vvvv][L][pp]
  uint8_t vvvv : 4;
  bool is_w0 : 1;
  bool is_67H : 1;
  bool is_66H : 1;
  // fix later if possible
  unsigned int sib;
};

struct operand {
  // pointer to operand in instruction string
  char *ptr;
  // stores the string representation of register
  char str[MAX_REG_LEN];
  // enum representation of register
  asm_reg reg;
  // stores the 2nd register in a memory reference
  char sib[MAX_REG_LEN];
  // enum representation of 2nd register in
  // a memory reference
  asm_reg index;
  // operand typecould be: r,m, or i
  char type;
};

// stores keywords used in assemblyline
union keywords {
  struct {
    uint8_t is_short : 1;
    uint8_t is_long : 1;
    uint8_t is_far : 1;
    uint8_t is_byte : 1;
    uint8_t is_word : 1;
    uint8_t is_dword : 1;
  };
  uint8_t is_keyword;
};

// internal representation of an assembly instruction
struct instr {
  // connects instr to INSTR_TABLE[]
  int key;
  // stores components of assembly instruction into buffer
  char instruction[INSTRUCTION_CHAR_LEN];
  // stores operands represented as strings
  struct operand opd[NUM_OF_OPD];
  // bitmap for keywords
  union keywords keyword;
  // enable or disable nasm register optimization
  uint8_t assembly_opt;
  // constants and memory displacement
  bool imm : 1;
  bool reduced_imm : 1;
  unsigned long cons;
  bool zero_byte : 1;
  // when operand is a memory reference M
  bool mem_disp : 1;
  bool mem_value : 1;
  bool is_sib_const : 1;
  bool is_sib : 1;
  bool no_base : 1;
  uint8_t mem_index : 3;
  uint32_t mem_offset;
  uint32_t mem_const;
  // displacement for modRM64_m variable based on
  // value of op_en and size of mem_disp
  int mod_disp;
  int sib_disp;
  // uses operand_encoding to get value
  // operand and prefix values
  struct prefix hex;
  // offset for opcode determined by register size
  int op_offset;
  unsigned int rd_offset;
};

#endif
