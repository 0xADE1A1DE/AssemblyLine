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

/*defines all preprocessors used in assemblyline*/
#ifndef COMMON_H
#define COMMON_H

#define LETTERS_IN_ALPHABET 26
// max length of filtered assembly string
#define FILTERED_STR_LEN 100
// default length of internal buffer
#define MEM_BUFFER 6000
// actual writable buffer size = MEM_BUFFER - BUFFER_TOLERANCE
#define BUFFER_TOLERANCE 20
// used when 0 cannot denote none
#define NA (-1)
// denotes an error during assembly
#define ASM_ERROR (-1)
// denotes an error during instruction look up
#define INSTR_ERROR (-2)

// base for string to unsigned long conversions
#define RADIX_16 16
#define RADIX_10 10
#define STR_HEX_64 18
// used to determine register size
#define BIT_MASK 0b01100000000
#define BIT_32 0b01100000000
#define BIT_16 0b01000000000
// number of bits in a byte
#define BIT_8 8
// immediate ranges
#define NEG64BIT 0xffffffffffffffff
#define NEG32BIT 0xffffffff00000000
#define NEG8BIT 0xffffffffffffff00
#define NEG80BIT 0xffffffffffffff80
#define NEG80_32BIT 0xffffff80
#define MASK_4BIT 0xf
#define MAX_BYTE_IDENTIFIER 0xe0
#define MAX_SIGNED_8BIT 0x7f
#define MAX_UNSIGNED_8BIT 0xff
#define MAX_UNSIGNED_16BIT 0xffff
#define MAX_SIGNED_32BIT 0x7fffffff
#define MAX_UNSIGNED_32BIT 0xffffffff
#define NEG32BIT_CHECK 0x80000000
// check if a number is at least 32 bits
#define X32BIT_CHECK 0x10000000
#define NEG8BIT_CHECK 0x80

// set register length to 1 byte
#define SET_BYTE ~(reg16 | reg32 | reg64)
#define SET_WORD ~(reg32 | reg64)
#define SET_DWORD ~(reg64)

#define C5H 0xc5
#define C4H 0xc4
#define NONE 0x0
#define NO_BYTE 0x100
#define NO_REG_MEM 0x25

// RXB bits in front of mmmm corresponds to !(rex_r), !(rex_x), and !(rex_b)
// Obtained from get_rex_prefix()
#define RXB 0x0
// mmmmm constants (VEX must be 3-byte)
#define X0F 0b00001000000000
#define X0F38 0b00010000000000
#define X0F3A 0b00011000000000
// just a place holder for reference
#define W 0x0
#define W0 0b000000000
// most signifcant bit will depend on the size of m operand (default 64 bit)
#define W1 0b100000000
// most signifcant bit will depend on the size of m operand (default 64 bit)
#define W0_W1 0b100000001
// WIG constant to specify we could switch between 3 and 2 byte hex
#define WIG 0b1

// pp constant
#define X66 0b010
#define XF3 0b100
#define XF2 0b110

// vvvv to specify which register to encode
#define NDS 0b01000000
#define NDD 0b00100000
#define DDS 0b00010000
// no register specifier
#define NNN 0b11110000
#define CLEARvvvv 0b1111000

// L constant
#define LZ 0x0
#define B128 0x0
#define B256 0b1000

// VEX settings (Will be shifted right one bit to remove WIG)
// use NONE if not present
#define VEX(vvvv, L, pp, mmmmm, WIG)                                           \
  ((VEX) | (RXB) | (mmmmm) | (W) | (vvvv) | (L) | (pp) | (WIG))

#define R_VEX 0b10000000
#define M_VEX 0b00100000

// used for getting register type, length, and value
#define REX_MASK 0b111
#define REG_MASK 0b00000011111
#define MODE_MASK 0b11110000000
#define MODE_CLEAR 0b00001111111
#define VALUE_MASK 0b00000000111
#define VVVV_MASK 0b00000001111

// process WRXB bit of the rex prefix
#define REG_RB 0b1000
#define REX_W_RXB 0b1001111

// max register string length
#define REGISTER_LEN 6
// all generic registers have at most 7 variations
#define NUM_OF_REGISTERS 7

// used in instruction_data.h
#define MAX_REG_LEN 6
#define NUM_OF_OPD 4
#define OPD_FORMAT_LEN 4
#define INSTRUCTION_CHAR_LEN 15

// opcode encoding length
#define MAX_OPCODE_LEN 15
#define MAX_INSTR_LEN 14
#define VALID_OPERAND_FORMATS 2
#define OPERAND_FORMAT_LEN 7

// used only in tokenizer
#define IN_RANGE(var, lower, upper) (((var) >= (lower)) && ((var) <= (upper)))
#define DO_NOT_PAD(reduce, set, mask)                                          \
  (reduce) &= (mask);                                                          \
  (set) = true;

// keyword length
#define DWORD_LEN 5
#define BYTE_LEN 4
#define LONG_LEN 4
#define SHORT_LEN 5
#define FAR_LEN 3

// mod values for the ModR/M Byte
#define MOD8 0b01000000
#define MOD16 0b10000000
#define MOD24 0b11000000

#define SIB 0b000000000
#define SIB2 0b01000000
#define SIB4 0b10000000
#define SIB8 0b11000000

// scaled indexed addressing
#define SIB_CONST 0x24
#define NO_BASE 0b101

// operand position
#define FIRST_OPERAND 0
#define SECOND_OPERAND 1
#define THIRD_OPERAND 2
#define FOURTH_OPERAND 3

// assembly mode options
#define NASM_MOV_IMM 0b00001
#define NASM_SIB_INDEX_BASE_SWAP 0b00100
#define NASM_SIB_NO_BASE 0b01000
#define SMART_MOV_IMM 0b00010
#define GET_EN 0b11111100000000000000000

// check instruction attributes
#define TYPE(key, instr_type) (INSTR_TABLE[(key)].type == (instr_type))
#define NAME(key, instr_name) (INSTR_TABLE[(key)].name == (instr_name))

// various length nop instructions
#define NOP 0x90
#define NOP2 0x66, 0x90
#define NOP3 0x0f, 0x1f, 0x00
#define NOP4 0x0f, 0x1f, 0x40, 0x00
#define NOP5 0x0f, 0x1f, 0x44, 0x00, 0x00
#define NOP6 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00
#define NOP7 0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00
#define NOP8 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00
#define NOP9 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00
#define NOP10 0x66, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00
#define NOP11 0x66, 0x66, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00

// fail conditions
#define FAIL_IF(EXP)                                                           \
  if (EXP) {                                                                   \
    return EXIT_FAILURE;                                                       \
  }

#define FAIL_SYS(EXP, MSG, RET)                                                \
  if (EXP) {                                                                   \
    fprintf(stderr, "assembyline: " MSG);                                      \
    perror("error ");                                                          \
    return RET;                                                                \
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
