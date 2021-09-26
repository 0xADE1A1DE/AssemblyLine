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

/*implements functions for encoding register and prefix opcode
as well process any offsets or immediate operands*/
#include "encoder.h"
#include "instr_parser.h"
#include "instructions.h"
#include "prefix.h"
#include "reg_parser.h"
#include <stdlib.h>

/**
 * sets the register size to 8 bits if the instruction referenced by
 * @param instruc only support 8-bit registers
 */
static void auto_set_byte(struct instr *instruc) {
  // instructions with M operand encoding that only supports 8 bit registers
  if (INSTR_TABLE[instruc->key].encode_operand == M) {
    switch (INSTR_TABLE[instruc->key].name) {
    case setc:
    case seto:
    case prefetcht0:
    case prefetcht1:
    case prefetcht2:
    case prefetchnta:
    case clflush:
      instruc->is_byte = true;
      instruc->op_offset = 0;
    default:
      return;
    }
  }
}

void encode_offset(struct instr *instruc) {
  // check if register is no prefix
  if ((instruc->opd[0] & MODE_MASK) == noext8 ||
      (instruc->opd[1] & MODE_MASK) == noext8)
    return;
  // set opcode offset
  if (INSTR_TABLE[instruc->key].type != CONTROL_FLOW && !instruc->is_byte)
    instruc->op_offset = get_opcode_offset(instruc->opd[0]);
}

/**
 * returns the register opcode given the operand at @param m and @param r
 * position given and instance of @param instruc
 */
static uint8_t get_modRM32_64(struct instr *instruc, int m, int r) {
  return instruc->mod_disp | ((VALUE_MASK & r) << 3) | (VALUE_MASK & m);
}

/**
 * determines whether a zero byte is required for @param instruc depending on
 * the @param m register position
 */
static void set_zero_byte(struct instr *instruc, int m) {
  unsigned int reg_opd = instruc->opd[m] & MODE_MASK;
  if (reg_opd > ext16 && reg_opd < mmx64 &&
      (instruc->opd[m] & VALUE_MASK) == bpl) {
    instruc->mod_disp = MOD8;
    instruc->mem_disp = false;
    instruc->zero_byte = true;
  }
}

/**
 * determines register and prefix opcode of @param instruc with 3 operands:
 * @param r, @param m, and @param v used for RMV or RVM encoding
 */
static void encode_three_opds(struct instr *instruc, int r, int m, int v) {

  instruc->vex_prefix_hex = get_vex_prefix(instruc->opd[r], instruc->opd[m]);
  instruc->w0_hex = get_w0_prefix(instruc->opd[v]);
  instruc->w0_hex -= INSTR_TABLE[instruc->key].w0_disp;
  if (instruc->mem_disp && !instruc->mem_offset)
    set_zero_byte(instruc, m);
  instruc->reg_hex = get_modRM32_64(instruc, instruc->opd[m], instruc->opd[r]);
  if (instruc->mem_disp && (instruc->opd[m] & VALUE_MASK) == spl)
    instruc->sib = true;
}

/**
 * determines register and prefix opcode of @param instruc with 2 operands:
 * @param r and @param m used for MR or RM encoding
 */
static void encode_two_opds(struct instr *instruc, int r, int m) {
  // check if a second register exist in memory reference ex: [rax+rcx]
  if (instruc->opd_mem[m] == reg_none) {
    instruc->prefix_hex =
        get_rex_prefix(instruc, instruc->opd[m], instruc->opd[r]);
    if (instruc->mem_disp && !instruc->mem_offset)
      set_zero_byte(instruc, m);
    instruc->reg_hex =
        get_modRM32_64(instruc, instruc->opd[m], instruc->opd[r]);
    instruc->vex_prefix_hex =
        get_vex_prefix(instruc->opd[r], instruc->opd[m]) + 1;
    if (instruc->mem_disp && (instruc->opd[m] & VALUE_MASK) == spl)
      instruc->sib = true;
  } else {
    instruc->prefix_hex =
        get_mem_prefix(instruc->opd[r], instruc->opd[m], instruc->opd_mem[m]);
    instruc->reg_hex = rex_r + (((instruc->opd[r] & VALUE_MASK)) * 0x8);
    instruc->mem_hex =
        get_modRM32_64(instruc, instruc->opd[m], instruc->opd_mem[m]);
    unsigned int bitMRm = instruc->opd[m] & MODE_MASK;
    if (bitMRm > ext16 && bitMRm < mmx64 &&
        (instruc->opd[m] & VALUE_MASK) == bpl) {
      instruc->zero_byte = true;
      instruc->reg_hex += rex;
    }
    instruc->mem_disp = false;
  }
}

/**
 * determines register and prefix opcode of @param instruc with a single operand
 * @param m or special predefined encoding I with 2 operands:
 * @param m and @param i
 */
static void encode_special_opd(struct instr *instruc, int m, int i) {

  switch (INSTR_TABLE[instruc->key].encode_operand) {
  case M:
    instruc->prefix_hex = get_rex_prefix(instruc, instruc->opd[m], reg_none);
    if (instruc->mem_disp && !instruc->mem_offset)
      set_zero_byte(instruc, m);
    instruc->reg_hex = get_modRM32_64(instruc, instruc->opd[m],
                                      INSTR_TABLE[instruc->key].single_reg_r);
    if (instruc->mem_disp && (instruc->opd[m] & VALUE_MASK) == spl)
      instruc->sib = true;
    break;

  case O:
    if ((MODE_MASK & instruc->opd[m]) == ext64)
      instruc->prefix_hex = rex + rex_b;
    instruc->rd_offset = (instruc->opd[m] & VALUE_MASK);
    instruc->reg_hex = get_modRM32_64(instruc, instruc->opd[m],
                                      INSTR_TABLE[instruc->key].single_reg_r);
    break;

  case I:
    instruc->prefix_hex =
        get_rex_prefix(instruc, instruc->opd[m], instruc->opd[i]);
    break;

  default:
    // do nothing
    break;
  }
}

void encode_operands(struct instr *instruc) {
  // xchg instruction with RM operand encoding using rax or al register
  if (INSTR_TABLE[instruc->key].name == xchg &&
      INSTR_TABLE[instruc->key].encode_operand == RM) {
    if ((reg64 & instruc->opd[0]) && (REG_MASK & instruc->opd[0]) == al) {
      instruc->key++;
      instruc->rd_offset = instruc->opd[1] & VALUE_MASK;
    } else if ((reg64 & instruc->opd[1]) &&
               (REG_MASK & instruc->opd[1]) == al) {
      instruc->key++;
      instruc->rd_offset = instruc->opd[0] & VALUE_MASK;
    }
  }
  // set 'byte' keyword
  if (instruc->mem_disp)
    auto_set_byte(instruc);

  // get register value and prefix for each operand encoding type
  switch (INSTR_TABLE[instruc->key].encode_operand) {
  case MR:
    encode_two_opds(instruc, SECOND_OPERAND, FIRST_OPERAND);
    break;

  case RM:
    encode_two_opds(instruc, FIRST_OPERAND, SECOND_OPERAND);
    break;

  case RVM:
    encode_three_opds(instruc, FIRST_OPERAND, THIRD_OPERAND, SECOND_OPERAND);
    break;

  case RMV:
    encode_three_opds(instruc, FIRST_OPERAND, SECOND_OPERAND, THIRD_OPERAND);
    break;

  default:
    encode_special_opd(instruc, FIRST_OPERAND, SECOND_OPERAND);
    break;
  }
}
static void nasm_register_size_optimize(struct instr *instruc){
  switch (instruc->opd[0] & MODE_MASK) {
  case reg64:
    instruc->opd[0] = (instruc->opd[0]& MODE_CLEAR) | reg32;
    break;
  case ext64:
    instruc->opd[0] = (instruc->opd[0]& MODE_CLEAR) | ext32;
    break;
  default:
    break;
  }
}
void encode_imm(struct instr *instruc) {
  // ignore imm value if instruction is a branch type
  if ((INSTR_TABLE[instruc->key].type == SHIFT && instruc->cons == 1) ||
      INSTR_TABLE[instruc->key].type == CONTROL_FLOW)
    instruc->imm = false;
  // used for shift instruction with an 8bit imm rather than one
  else if (INSTR_TABLE[instruc->key].type == SHIFT && instruc->cons > 1)
    instruc->key++;
  // change op offset based on reg and imm size
  if (!instruc->imm)
    return;
  // return register rax for imm instructions sub, sbb, add, adc
  asm_instr sp_instr = EOI;
  if (INSTR_TABLE[instruc->key].encode_operand == M) {
    if ((instruc->opd[0] == al && instruc->cons != NEG64BIT) ||
        (instruc->opd[0] == (reg64 | al) &&
         IN_RANGE(instruc->cons, MAX_SIGNED_8BIT + 1, NEG64BIT - 1)))
      sp_instr = to_special_instr_key(instruc->key);
    // return if instruction has special encoding
    if (sp_instr) {
      instruc->key = sp_instr;
      return;
    }
  }
  // 16 to 64 bit register and 8 bit immediate combination
  if (instruc->op_offset == 1 &&
      INSTR_TABLE[instruc->key].type != DATA_TRANSFER) {
    //-0x1 and 0x0 are always 8 bits except for mov
    // 8 bit positive
    if (instruc->cons < 0xe1 && instruc->cons >= 0)
      instruc->op_offset += 2;
    // 8 bit positive immediate
    if (instruc->cons > MAX_SIGNED_8BIT)
      instruc->op_offset = 1;
    // 8 bit negative immediate
    if (IN_RANGE(instruc->cons, NEG8BIT + 1, NEG64BIT)) {
      instruc->cons &= MAX_UNSIGNED_8BIT;
      instruc->op_offset += 2;
    } else if (IN_RANGE(instruc->cons, NEG32BIT + 1, NEG64BIT))
      instruc->cons &= MAX_UNSIGNED_32BIT;
    // special condition for to mov instruction
  } else if (INSTR_TABLE[instruc->key].type == DATA_TRANSFER) {
    // only condition for mov with M operand encoding implemenation
    if (INSTR_TABLE[instruc->key].type == DATA_TRANSFER &&
        IN_RANGE(instruc->cons, NEG32BIT + 1, NEG64BIT) &&
        (instruc->opd[0] & reg64)) {
      SET_MOV_M(instruc->key);
      // dont zero pad imm
      instruc->cons &= MAX_UNSIGNED_32BIT;
      instruc->reduced_imm = true;
      return;
    }
    if (instruc->cons <= MAX_UNSIGNED_32BIT)
      nasm_register_size_optimize(instruc);
    if ((instruc->opd[0] & MODE_MASK) > noext8)
      instruc->op_offset = 8;

    instruc->rd_offset = instruc->opd[0] & VALUE_MASK;
  }
  // mask all bits except for the most significant byte
  if ((instruc->opd[0] & MODE_MASK) < reg32) {
    instruc->cons &= MAX_UNSIGNED_16BIT;
    instruc->reduced_imm = true;
    if(((instruc->opd[0] & MODE_MASK) == reg16 || 
       (instruc->opd[0] & MODE_MASK) == ext16) &&
       instruc->cons <= MAX_UNSIGNED_8BIT)
      instruc->reduced_imm = false; 
  }
  if ((instruc->opd[0] & MODE_MASK) < reg16) {
    instruc->cons &= MAX_UNSIGNED_8BIT;
    instruc->reduced_imm = true;
  }
}