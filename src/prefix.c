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

/*implements functions for determining the prefix opcode for an assembly
 * instruction*/
#include "prefix.h"
#include "common.h"
#include "instructions.h"
#include "registers.h"
#include <stdlib.h>

static void overide_opd_size(struct instr *all_instr, unsigned int *rm) {
  if (all_instr->keyword.is_byte)
    *rm = *rm & SET_BYTE;
  else if (all_instr->keyword.is_word)
    *rm = *rm & SET_WORD;
  else if (all_instr->keyword.is_dword)
    *rm = *rm & SET_DWORD;
}

static unsigned int get_vector_rex_prefix(struct instr *all_instr, asm_reg m,
                                          asm_reg r) {

  unsigned int prefix_hex = rex_;
  if (IN_RANGE((m & MODE_MASK), reg64, ext64) && !all_instr->mem_disp)
    prefix_hex = rex_w;
  // check register size
  if ((m & REG_MASK) > mm7 || (r & REG_MASK) > mm7) {
    if ((r & REG_MASK) > mm7)
      prefix_hex += rex_r;
    if ((m & REG_MASK) > mm7 || m & REG_RB)
      prefix_hex += rex_b;
    return prefix_hex;
  }
  // M encoding refers to a memory displacement
  if (all_instr->mem_disp)
    return (m & ext8) ? rex_ + rex_b : NONE;
  if ((m & MODE_MASK) == mmx64)
    return NONE;
  // only a single operand
  if (m == reg_none || r == reg_none)
    return NONE;
  if ((m & MODE_MASK) < reg64 && !(m & REG_RB))
    prefix_hex = NONE;
  // an operand is part of the x64 extended set
  if (m & REG_RB || r & REG_RB)
    prefix_hex += rex_b;
  return prefix_hex;
}

unsigned int get_rex_prefix(struct instr *all_instr, struct operand *m,
                            struct operand *r) {

  int rex_prefix = 0;
  unsigned int rm = m->reg;
  // preprocess vex paremeters
  all_instr->hex.is_w0 = true;
  if ((m->reg & MODE_MASK) < reg64)
    all_instr->hex.is_w0 = false;
  if ((m->reg & MODE_MASK) == mmx64 || (r->reg & MODE_MASK) == mmx64)
    return get_vector_rex_prefix(all_instr, m->reg, r->reg);
  if (all_instr->keyword.is_keyword)
    overide_opd_size(all_instr, &rm);
  else if (!(rm & reg_none) && !(rm & MODE_MASK) && rm >= spl)
    rex_prefix |= rex_;
  if (!(r->reg & reg_none) && !(r->reg & MODE_MASK) && r->reg >= spl)
    rex_prefix |= rex_;
  // r or m operand is part of the x64 extended set
  if (r->reg & REG_RB)
    rex_prefix |= rex_r;
  if (rm & REG_RB)
    rex_prefix |= rex_b;
  if (m->index & REG_RB)
    rex_prefix |= rex_x;
  // register r or m is 64 bits wide
  if ((rm & reg64) || (r->reg & reg64))
    rex_prefix |= rex_w;
  if (rex_prefix & REX_W_RXB)
    return rex_ | rex_prefix;
  return NONE;
}

uint8_t get_reg(struct instr *instrc, struct operand *m, int r) {
  // check for base register (sib with not base)
  if (m->reg == reg_none && m->index != reg_none) {
    // this is the strict implementation
    if (instrc->assembly_opt & NASM_SIB_NO_BASE) {
      switch (instrc->sib_disp) {
      case SIB:
        // disable Scaled Index Addressing
        m->reg = m->index;
        m->index = reg_none;
        break;
      case SIB2:
        m->reg = m->index;
        instrc->sib_disp = SIB;
        break;
      default:

        m->reg = NO_BASE;
        instrc->no_base = true;
        break;
      }
    } else {
      m->reg = NO_BASE;
      instrc->no_base = true;
    }
    if (m->reg == NO_BASE)
      instrc->mod_disp = 0;
  }
  // check for index register
  if (m->index == reg_none) {
    instrc->hex.reg =
        instrc->mod_disp | ((r & VALUE_MASK) << 3) | (m->reg & VALUE_MASK);
    return EXIT_SUCCESS;
  }
  //
  if ((m->index & REG_MASK) == spl) {
    FAIL_IF_MSG((m->reg & REG_MASK) == spl || instrc->sib_disp,
                "error stack pointer register is not scalable\n");
  }
  // SIB addressing mode
  instrc->is_sib = true;
  instrc->hex.sib =
      instrc->sib_disp | ((m->index & VALUE_MASK) << 3) | (m->reg & VALUE_MASK);

  instrc->hex.reg = instrc->mod_disp | ((r & VALUE_MASK) << 3) | rex_r;
  return EXIT_SUCCESS;
}
