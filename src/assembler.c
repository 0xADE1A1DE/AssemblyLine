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

/*implements functions for writing assembly instruction
 opcodes into a location allocated in memory*/
#include "assembler.h"
#include "assemblyline.h"
#include "encoder.h"
#include "instructions.h"
#include "parser.h"
#include "registers.h"
#include <inttypes.h>
#include <stdbool.h>

// no operation instructions of length 1 to 11 bytes
const static uint8_t *FIXED_NOP_LENGTH[] = {
    (uint8_t[]){0x90},
    (uint8_t[]){0x66, 0x90},
    (uint8_t[]){0x0f, 0x1f, 0x00},
    (uint8_t[]){0x0f, 0x1f, 0x40, 0x00},
    (uint8_t[]){0x0f, 0x1f, 0x44, 0x00, 0x00},
    (uint8_t[]){0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00},
    (uint8_t[]){0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00},
    (uint8_t[]){0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00},
    (uint8_t[]){0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00},
    (uint8_t[]){0x66, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00},
    (uint8_t[]){0x66, 0x66, 0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00,
                0x00}};

/**
 * assembles the constant of a @param single_instr and writes the opcode to
 * pointer location @param ptr
 */
static int assemble_const(unsigned long constant, unsigned char ptr[]) {
  int ptr_pos = 0;
  while (constant > 0) {
    ptr[ptr_pos++] = constant & 0xff;
    constant >>= 8;
  }
  return ptr_pos;
}

/**
 * assembles the immediate operand of a @param single_instr and writes the
 * opcode to pointer location @param ptr
 */
static int assemble_imm(struct instr *single_instr, unsigned char ptr[]) {

  int ptr_pos = 0;
  unsigned int bytes = 0;
  bool zero_pad = false;
  instr_type single_instr_type = INSTR_TABLE[single_instr->key].type;
  unsigned long saved_cons = single_instr->cons;
  // check is there is a constant in the instruction
  if (single_instr->imm) {
    int bytes_written = assemble_const(saved_cons, ptr + ptr_pos);
    ptr_pos += bytes_written;
    bytes += bytes_written;

    // check if the zero byte is present?
    if (saved_cons == 0 ||
        (saved_cons > MAX_SIGNED_32BIT && saved_cons <= MAX_UNSIGNED_32BIT &&
         !single_instr->reduced_imm && single_instr_type != CONTROL_FLOW && 
         single_instr_type != DATA_TRANSFER)) {
      ptr[ptr_pos++] = 0x0;
      bytes++;
    }
    // no need to zero pad if the immediate operand has been reduced
    if (single_instr->reduced_imm)
      return ptr_pos;
    // check if zero padding is required
    if (single_instr_type != CONTROL_FLOW && single_instr_type != SHIFT)
      if (single_instr->op_offset != 3 && !single_instr->is_byte)
        zero_pad = ((single_instr->opd[0] & MODE_MASK) > noext8) ? true : false;
    // check if zero padding is required
    if (!single_instr->is_short &&
        INSTR_TABLE[single_instr->key].encode_operand > I)
      zero_pad = true;
    // zero pad constant to 4 bytes or 8 bytes
    if (zero_pad) {
      if(bytes == 1 && (single_instr->opd[0] & MODE_MASK) == reg16)
        bytes = 1;
      else if (bytes == 1 && (single_instr->opd[0] & MODE_MASK) == ext16)
        bytes = 1; 
      else if (bytes < 5)
        bytes = 4 - bytes;
      else if (bytes > 4 && bytes < 9)
        bytes = 8 - bytes;
      for (int k = 0; k < bytes; k++)
        ptr[ptr_pos++] = 0x0;
    }
  }
  return ptr_pos;
}

/**
 * assembles the memory displacement of a @param single_instr and writes the
 * opcode to pointer location @param ptr
 */
static int assemble_mem(struct instr *single_instr, unsigned char ptr[]) {

  int ptr_pos = 0;
  int mbytes = 0;
  // check if zero byte is present
  if (single_instr->zero_byte)
    ptr[ptr_pos++] = 0x0;
  // check if there is a memory reference
  if (single_instr->mem_disp) {
    if (single_instr->sib)
      ptr[ptr_pos++] = SIB;
    if (single_instr->mod_disp == MOD8) {
      ptr[ptr_pos++] = single_instr->mem_offset;
    } else if (single_instr->mod_disp == MOD16) {
      // assemble memory displacement byte by byte using little endian format
      int bytes_written =
          assemble_const(single_instr->mem_offset, ptr + ptr_pos);
      ptr_pos += bytes_written;
      mbytes += bytes_written;
      // zero pad memory displacement constant to 4 bytes
      mbytes = 4 - mbytes;
      for (int m = 0; m < mbytes; m++)
        ptr[ptr_pos++] = 0x0;
    }
  }
  return ptr_pos;
}

/**
 * assembles the prefix and opcode of a @param single_instr and writes the
 * opcode to pointer location @param ptr
 */
static int assemble_instr(struct instr *single_instr, unsigned char ptr[]) {

  int ptr_pos = 0;
  int opcode_pos = 0;
  // 16 bit register prefix
  if ((single_instr->opd[0] & BIT_MASK) == BIT_16)
    ptr[ptr_pos++] = 0x66;
  // assemble all prefixes and instruction opcode
  while (opcode_pos < INSTR_TABLE[single_instr->key].instr_size) {
    switch (INSTR_TABLE[single_instr->key].opcode[opcode_pos]) {
    case REX:
      if (single_instr->prefix_hex != NO_PREFIX)
        ptr[ptr_pos++] = single_instr->prefix_hex;
      break;

    case REG:
      if (single_instr->reg_hex != NO_PREFIX)
        ptr[ptr_pos++] = single_instr->reg_hex;
      break;

    case VEX:
      if (single_instr->vex_prefix_hex != NO_PREFIX)
        ptr[ptr_pos++] = single_instr->vex_prefix_hex;
      break;

    case EVEX:
      if ((single_instr->opd[1] & BIT_MASK) == BIT_32)
        ptr[ptr_pos++] = evex;
      break;

    case W0:
      if (single_instr->w0_hex != NO_PREFIX)
        ptr[ptr_pos++] = single_instr->w0_hex;
      break;

    default:
      if (INSTR_TABLE[single_instr->key].opcode[opcode_pos] < REG) {
        unsigned char opc = INSTR_TABLE[single_instr->key].opcode[opcode_pos];
        if (opcode_pos == INSTR_TABLE[single_instr->key].rd_offset_i)
          opc += single_instr->rd_offset;
        if (opcode_pos == INSTR_TABLE[single_instr->key].op_offset_i)
          opc += single_instr->op_offset;
        ptr[ptr_pos++] = opc;
      }
    }
    opcode_pos++;
  }
  if (single_instr->mem_hex != NO_PREFIX)
    ptr[ptr_pos++] = single_instr->mem_hex;
  return ptr_pos;
}

/**
 * writes a nop instruction of length @param nop_pad_len
 * to pointer location @param buf
 */
int nop_padding(uint8_t *buf, int nop_pad_len) {

  uint8_t *ptr = buf;
  // find nop instruction of a specified length
  const uint8_t *nop_to_use = FIXED_NOP_LENGTH[nop_pad_len - 1];
  int j = 0;
  // assemble nop instruction
  for (int i = 0; i < nop_pad_len; i++) {
    *(ptr + j) = nop_to_use[i];
    j++;
  }
  return nop_pad_len;
}

/**
 * assembles a @param single_instr and write the opcode
 * to pointer location @param ptr
 */
int assemble_asm(struct instr *single_instr, uint8_t *dest) {

  // dest index
  int ptr_pos = 0;
  // opcode length
  int instr_len = 0;
  int mem_len = 0;
  int imm_len = 0;

  // assemble instruction
  instr_len = assemble_instr(single_instr, dest);
  ptr_pos += instr_len;
  // assemble memory displacemet
  mem_len = assemble_mem(single_instr, dest + ptr_pos);
  ptr_pos += mem_len;
  // assemble immediate
  imm_len = assemble_imm(single_instr, dest + ptr_pos);
  ptr_pos += imm_len;

  return ptr_pos;
}
