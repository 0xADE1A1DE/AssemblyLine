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

/*implements functions for determining the prefix opcode for an assembly
 * instruction*/
#include "prefix.h"
#include "common.h"
#include "instructions.h"
#include "registers.h"

unsigned int get_vector_rex_prefix(struct instr *all_instr, asm_reg m,
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
  } else {
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
  }
  return prefix_hex;
}

unsigned int get_rex_prefix(struct instr *all_instr, asm_reg m, asm_reg r) {

  int rex_prefix = 0;
  // preprocess vex paremeters
  all_instr->hex.is_w0 = true;
  if ((m & MODE_MASK) < reg64)
    all_instr->hex.is_w0 = false;
  if ((m & MODE_MASK) == mmx64 || (r & MODE_MASK) == mmx64)
    return get_vector_rex_prefix(all_instr, m, r);
  if (all_instr->keyword.is_byte)
    m = m & SET_BYTE;
  else if (!(m & reg_none) && !(m & MODE_MASK) && m >= spl)
    rex_prefix |= rex_;
  if (!(r & reg_none) && !(r & MODE_MASK) && r >= spl)
    rex_prefix |= rex_;
  // r or m operand is part of the x64 extended set
  if (r & REG_RB)
    rex_prefix |= rex_r;
  if (m & REG_RB)
    rex_prefix |= rex_b;
  // register r or m is 64 bits wide
  if ((m & reg64) || (r & reg64))
    rex_prefix |= rex_w;
  if (rex_prefix & REX_W_RXB)
    return rex_ | rex_prefix;
  return NONE;
}

unsigned int get_mem_prefix(asm_reg s, asm_reg m, asm_reg r) {

  unsigned int prefix_hex = rex_w;
  // registers s, m, or r is part of the 64bit x64 extended set
  if ((s & MODE_MASK) == ext64)
    prefix_hex += rex_r;
  if ((m & MODE_MASK) == ext64)
    prefix_hex += rex_b;
  if ((r & MODE_MASK) == ext64)
    prefix_hex += rex_x;
  return prefix_hex;
}
