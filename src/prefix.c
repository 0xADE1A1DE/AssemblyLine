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
#include "instructions.h"
#include "registers.h"

unsigned int get_rex_prefix(struct instr *all_instr, asm_reg m, asm_reg r) {

  unsigned int prefix_hex = NO_PREFIX;
  // check if register r is a vectorized
  if ((m & REG_MASK) > mm7 || (r & REG_MASK) > mm7) {
    prefix_hex = rex;
    if ((r & REG_MASK) > mm7)
      prefix_hex += rex_r;
    if ((m & REG_MASK) > mm7)
      prefix_hex += rex_b;
    return prefix_hex;
  } else if ((r & MODE_MASK) == mmx64 && (r & REG_MASK) <= mm7)
    return (m & ext8) ? rex + rex_b : NO_PREFIX;
  // keyword 'byte' is present
  if (all_instr->is_byte)
    m = m & SET_BYTE;
  else if (!(m & reg_none) && !(m & MODE_MASK) && m >= spl)
    prefix_hex = rex;
  // register r or m is part of the 8 bit x64 extended set
  if (!(r & reg_none) && !(r & MODE_MASK) && r >= spl)
    prefix_hex = rex;
  else if ((r & ext8) || (m & ext8))
    prefix_hex = rex;
  // register r or m is 64 bits wide
  if ((m & reg64) || (r & reg64))
    prefix_hex = rex_w;
  // register is r or m is part of the x64 extended set
  if (r & ext8)
    prefix_hex += rex_r;
  if (m & ext8)
    prefix_hex += rex_b;
  return prefix_hex;
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

unsigned int get_vex_prefix(asm_reg r, asm_reg m) {

  unsigned int vex_prefix_hex = rex + rex_x;
  // registers r or m is part of the standard x86 set
  if (!(r & ext8))
    vex_prefix_hex |= R_VEX;
  if (!(m & ext8))
    vex_prefix_hex |= M_VEX;
  return vex_prefix_hex;
}

unsigned int get_w0_prefix(asm_reg v) {

  switch (v & MODE_MASK) {
  case reg64:
    return 0xfb - ((v & VALUE_MASK) << 3);
  case reg32:
    return 0x7b - ((v & VALUE_MASK) << 3);
  case ext64:
    return 0xbb - ((v & VALUE_MASK) << 3);
  case ext32:
    return 0x3b - ((v & VALUE_MASK) << 3);
  }
  return NO_PREFIX;
}
