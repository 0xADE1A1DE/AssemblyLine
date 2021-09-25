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

/*defines all preprocessors used in assemblyline*/
#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>

// max length of filtered assembly string
#define FILTERED_STR_LEN 100
// default length of internal buffer
#define MEM_BUFFER 6000
// actual writable buffer size = MEM_BUFFER - BUFFER_TOLERANCE
#define BUFFER_TOLERANCE 20
// denotes an error during assembly
#define ASM_ERROR -1
// denotes an error during instruction look up
#define INSTR_ERROR -2

#define _GNU_SOURCE 1

// used to determine register size
#define BIT_MASK 0b01100000000
#define BIT_32 0b01100000000
#define BIT_16 0b01000000000

// immediate ranges
#define NEG64BIT 0xffffffffffffffff
#define NEG32BIT 0xffffffff00000000
#define NEG8BIT 0xffffffffffffff00
#define MAX_SIGNED_8BIT 0x7f
#define MAX_UNSIGNED_8BIT 0xff
#define MAX_SIGNED_32BIT 0x7fffffff
#define MAX_UNSIGNED_32BIT 0xffffffff

// set register length to 1 byte
#define SET_BYTE ~(reg16 | reg32 | reg64)
// used for setting prefix
#define R_VEX 0b10000000
#define M_VEX 0b00100000

// used for getting register type, length, and value
#define REG_MASK 0b00000011111
#define MODE_MASK 0b11110000000
#define VALUE_MASK 0b00000000111

// register string length
#define REGISTER_LEN 5
// all generic registers have at most 7 variations
#define NUM_OF_REGISTERS 7

// used in instruction_data.h
#define MAX_REG_LEN 5
#define NUM_OF_OPD 3
#define OPD_FORMAT_LEN 4
#define INSTRUCTION_CHAR_LEN 15

// opcode encoding length
#define MAX_OPCODE_LEN 15
#define MAX_INSTR_LEN 14
#define VALID_OPERAND_FORMATS 2
#define OPERAND_FORMAT_LEN 7

// used only in tokenizer
#define IN_RANGE(var, lower, upper) ((var >= lower) && (var <= upper))

// keyword length
#define BYTE_LEN 4
#define SHORT_LEN 5
#define LONG_LEN 4

// mod values for the ModR/M Byte
#define MOD8 0b1000000
#define MOD16 0b10000000
#define MOD24 0b11000000

// operand position
#define FIRST_OPERAND 0
#define SECOND_OPERAND 1
#define THIRD_OPERAND 2

// fail condition preprocessor
#define FAIL_IF(EXP)                                                           \
  if (EXP) {                                                                   \
    return EXIT_FAILURE;                                                       \
  }

#define FAIL_SYS(EXP, MSG)                                                     \
  if (EXP) {                                                                   \
    fprintf(stderr, "assembyline: " MSG);                                      \
    perror("error: ");                                                         \
    return EXIT_FAILURE;                                                       \
  }

#define FAIL_IF_ERR(EXP)                                                       \
  if (EXP) {                                                                   \
    return ASM_ERROR;                                                          \
  }

#define FAIL_IF_MSG(EXP, MSG)                                                  \
  if (EXP) {                                                                   \
    fprintf(stderr, "assembyline: " MSG);                                      \
    return EXIT_FAILURE;                                                       \
  }

#define FAIL_IF_VAR(EXP, MSG, VAR)                                             \
  if (EXP) {                                                                   \
    fprintf(stderr, "assembyline: " MSG, VAR);                                 \
    return EXIT_FAILURE;                                                       \
  }

#endif