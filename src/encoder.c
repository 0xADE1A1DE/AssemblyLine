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
 * @param instrc only support 8-bit registers
 */
static void auto_set_byte(struct instr *instrc) {
  // instrctions with M operand encoding that only supports 8 bit registers
  if (INSTR_TABLE[instrc->key].encode_operand == M) {
    switch (INSTR_TABLE[instrc->key].name) {
    case setc:
    case seto:
    case prefetcht0:
    case prefetcht1:
    case prefetcht2:
    case prefetchnta:
    case clflush:
      instrc->keyword.is_byte = true;
      instrc->op_offset = 0;
    default:
      return;
    }
  }
}

void encode_offset(struct instr *instrc) {
  // check if register is no prefix
  if ((instrc->opd[0].reg & MODE_MASK) == noext8 ||
      (instrc->opd[1].reg & MODE_MASK) == noext8)
    return;
  // set opcode offset
  if (INSTR_TABLE[instrc->key].type != CONTROL_FLOW && !instrc->keyword.is_byte)

    instrc->op_offset = get_opcode_offset(instrc->opd[0].reg);
}

/**
 * determines whether a zero byte is required for @param instrc depending on
 * the @param m register position
 */
static void set_zero_byte(struct instr *instrc, int m) {
  unsigned int reg_opd = instrc->opd[m].reg & MODE_MASK;
  if (reg_opd > ext16 && reg_opd < mmx64 &&
      (instrc->opd[m].reg & VALUE_MASK) == bpl) {
    instrc->mod_disp = MOD8;
    instrc->zero_byte = true;
  }
}

/**
 * determines register and prefix opcode of @param instrc with 3 operands:
 * @param r, @param m, and @param v used for RMV or RVM encoding
 */
static void encode_three_opds(struct instr *instrc, int r, int m, int v) {
  // used for RXB and R
  instrc->hex.rex = get_rex_prefix(instrc, &instrc->opd[m], &instrc->opd[r]);
  // get vvvv parameter
  instrc->hex.vvvv = instrc->opd[v].reg & 0xf;
  if (instrc->mem_disp && !instrc->mem_offset)
    set_zero_byte(instrc, m);
  instrc->hex.reg = get_reg(instrc, instrc->opd[m].reg, instrc->opd[r].reg);
  if (instrc->mem_disp && (instrc->opd[m].reg & VALUE_MASK) == spl)
    instrc->is_sib = true;
}

/**
 * determines register and prefix opcode of @param instrc with 2 operands:
 * @param r and @param m used for MR or RM encoding
 */
static void encode_two_opds(struct instr *instrc, int r, int m) {
  // check if a second register exist in memory reference ex: [rax+rcx]
  instrc->hex.rex = get_rex_prefix(instrc, &instrc->opd[m], &instrc->opd[r]);
  if (instrc->opd[m].reg_mem == reg_none) {
    if (instrc->mem_disp && !instrc->mem_offset)
      set_zero_byte(instrc, m);
    instrc->hex.reg = get_reg(instrc, instrc->opd[m].reg, instrc->opd[r].reg);
    if (instrc->mem_disp && (instrc->opd[m].reg & VALUE_MASK) == spl)
      instrc->is_sib = true;
  } else {
    instrc->hex.reg = rex_r + (((instrc->opd[r].reg & VALUE_MASK)) << 3);
    instrc->hex.sib =
        get_sib(instrc, instrc->opd[m].reg, instrc->opd[m].reg_mem);
    unsigned int bitMRm = instrc->opd[m].reg & MODE_MASK;
    if (bitMRm > ext16 && bitMRm < mmx64 &&
        (instrc->opd[m].reg & VALUE_MASK) == bpl) {
      if (!instrc->mem_offset)
        instrc->zero_byte = true;
      instrc->hex.reg += rex_;
    }
    // instrc->mem_disp = false;
  }
}

/**
 * determines register and prefix opcode of @param instrc with a single operand
 * @param m or special predefined encoding I with 2 operands:
 * @param m and @param i
 */
static void encode_special_opd(struct instr *instrc, int m, int i) {

  struct operand no_register = {NULL, {'\0'}, reg_none, {'\0'}, reg_none, 0};
  switch (INSTR_TABLE[instrc->key].encode_operand) {
  case M:
    instrc->hex.rex = get_rex_prefix(instrc, &instrc->opd[m], &no_register);
    if (instrc->mem_disp && !instrc->mem_offset)
      set_zero_byte(instrc, m);
    instrc->hex.reg = get_reg(instrc, instrc->opd[m].reg,
                              INSTR_TABLE[instrc->key].single_reg_r);
    if (instrc->mem_disp && (instrc->opd[m].reg & VALUE_MASK) == spl)
      instrc->is_sib = true;
    break;

  case O:
    if ((MODE_MASK & instrc->opd[m].reg) == ext64)
      instrc->hex.rex = rex_ + rex_b;
    instrc->rd_offset = (instrc->opd[m].reg & VALUE_MASK);
    instrc->hex.reg = get_reg(instrc, instrc->opd[m].reg,
                              INSTR_TABLE[instrc->key].single_reg_r);
    break;

  case I:
    instrc->hex.rex = get_rex_prefix(instrc, &instrc->opd[m], &instrc->opd[i]);
    break;

  default:
    // do nothing
    break;
  }
}

void encode_operands(struct instr *instrc) {
  // xchg instruction with RM operand encoding using rax or al register
  if (INSTR_TABLE[instrc->key].name == xchg &&
      INSTR_TABLE[instrc->key].encode_operand == RM) {
    if ((reg64 & instrc->opd[0].reg) && (REG_MASK & instrc->opd[0].reg) == al) {
      instrc->key++;
      instrc->rd_offset = instrc->opd[1].reg & VALUE_MASK;
    } else if ((reg64 & instrc->opd[1].reg) &&
               (REG_MASK & instrc->opd[1].reg) == al) {
      instrc->key++;
      instrc->rd_offset = instrc->opd[0].reg & VALUE_MASK;
    }
  }
  // set 'byte' keyword
  if (instrc->mem_disp)
    auto_set_byte(instrc);

  // get register value and prefix for each operand encoding type
  switch (INSTR_TABLE[instrc->key].encode_operand) {
  case MR:
    encode_two_opds(instrc, SECOND_OPERAND, FIRST_OPERAND);
    break;

  case RM:
    encode_two_opds(instrc, FIRST_OPERAND, SECOND_OPERAND);
    break;

  case RVM:
    encode_three_opds(instrc, FIRST_OPERAND, THIRD_OPERAND, SECOND_OPERAND);
    break;

  case RMV:
    encode_three_opds(instrc, FIRST_OPERAND, SECOND_OPERAND, THIRD_OPERAND);
    break;

  default:
    encode_special_opd(instrc, FIRST_OPERAND, SECOND_OPERAND);
    break;
  }
}

static void nasm_register_size_optimize(struct instr *instrc) {

  switch (instrc->opd[0].reg & MODE_MASK) {
  case reg64:
    instrc->opd[0].reg = (instrc->opd[0].reg & MODE_CLEAR) | reg32;
    break;

  case ext64:
    instrc->opd[0].reg = (instrc->opd[0].reg & MODE_CLEAR) | ext32;
    break;

  default:
    break;
  }
}

void encode_imm(struct instr *instrc) {
  // ignore imm value if instruction is a branch type
  if ((INSTR_TABLE[instrc->key].type == SHIFT && instrc->cons == 1) ||
      INSTR_TABLE[instrc->key].type == CONTROL_FLOW)
    instrc->imm = false;
  // used for shift instruction with an 8bit imm rather than one
  else if (INSTR_TABLE[instrc->key].type == SHIFT && instrc->cons > 1)
    instrc->key++;
  // change op offset based on reg and imm size
  if (!instrc->imm)
    return;
  // return register rax for imm instrctions sub, sbb, add, adc
  asm_instr sp_instr = EOI;
  if (INSTR_TABLE[instrc->key].encode_operand == M) {
    if ((instrc->opd[0].reg == al && instrc->cons != NEG64BIT) ||
        ((instrc->opd[0].reg & REG_MASK) == al &&
         IN_RANGE(instrc->cons, MAX_SIGNED_8BIT + 1, NEG64BIT - 1)))
      sp_instr = to_special_instr_key(instrc->key);
    // return if instruction has special encoding
    if (sp_instr)
      instrc->key = sp_instr;
  }
  // vector shift instrctions
  if ((instrc->opd[0].reg & MODE_MASK) == mmx64)
    instrc->reduced_imm = true;
  // 16 to 64 bit register and 8 bit immediate combination
  if (instrc->op_offset == 1 &&
      INSTR_TABLE[instrc->key].type != DATA_TRANSFER) {
    //-0x1 and 0x0 are always 8 bits except for mov
    // 8 bit positive
    if (IN_RANGE(instrc->cons, 0, 0xe0))
      instrc->op_offset += 2;
    // 8 bit positive immediate
    if (instrc->cons > MAX_SIGNED_8BIT)
      instrc->op_offset = 1;
    // 8 bit negative immediate
    if (IN_RANGE(instrc->cons, NEG8BIT + 1, NEG64BIT) &&
        (instrc->cons & NEG8BIT_CHECK)) {
      instrc->cons &= MAX_UNSIGNED_8BIT;
      instrc->op_offset += 2;
    } else if (IN_RANGE(instrc->cons, NEG32BIT + 1, NEG64BIT)) {
      instrc->cons &= MAX_UNSIGNED_32BIT;
      instrc->reduced_imm = true;
    }
    // special condition for to mov instrction
  } else if (INSTR_TABLE[instrc->key].type == DATA_TRANSFER) {
    // calculate value for +rd and +rw
    instrc->rd_offset = instrc->opd[0].reg & VALUE_MASK;
    // only condition for mov with M operand encoding implemenation
    // check if immediate operand is a negative 32 bit value
    if (IN_RANGE(instrc->cons, NEG32BIT + 1, NEG64BIT) &&
        (instrc->cons & NEG32BIT_CHECK) && (instrc->opd[0].reg & reg64)) {
      // set mov I operand encoding to M
      instrc->key++;
      // clear most significant 4 bytes
      instrc->cons &= MAX_UNSIGNED_32BIT;
      // do not zero pad immediate
      instrc->reduced_imm = true;
      return;
    } else if (instrc->cons <= MAX_UNSIGNED_32BIT) {
      if (instrc->imm_handling & NASM)
        nasm_register_size_optimize(instrc);
      // ensure instrction does not default to movabs
      else if (instrc->cons < NEG32BIT_CHECK &&
               (instrc->opd[0].reg & MODE_MASK) >= reg64)
        instrc->key++;
    }
    if ((instrc->opd[0].reg & MODE_MASK) > noext8) {
      if (instrc->imm_handling & NASM)
        instrc->op_offset = 8;
      else if (INSTR_TABLE[instrc->key].encode_operand == I)
        instrc->op_offset = 8;
    }
  }
  // mask all bits except for the most significant byte
  if ((instrc->opd[0].reg & MODE_MASK) < reg32) {
    instrc->cons &= MAX_UNSIGNED_16BIT;
    instrc->reduced_imm = true;
    if (((instrc->opd[0].reg & MODE_MASK) == reg16 ||
         (instrc->opd[0].reg & MODE_MASK) == ext16) &&
        instrc->cons <= MAX_UNSIGNED_8BIT)
      instrc->reduced_imm = false;
  }
  if ((instrc->opd[0].reg & MODE_MASK) < reg16) {
    instrc->cons &= MAX_UNSIGNED_8BIT;
    instrc->reduced_imm = true;
  }
}