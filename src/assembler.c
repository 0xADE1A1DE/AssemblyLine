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

/*implements functions for writing assembly instruction
 opcodes into a location allocated in memory*/
#include "assembler.h"
#include "assemblyline.h"
#include "common.h"
#include "encoder.h"
#include "instructions.h"
#include "parser.h"
#include "registers.h"
#include <inttypes.h>
#include <stdbool.h>

static const unsigned int SHIFT_5 = 5;
static const unsigned int SHIFT_3 = 3;
static const unsigned int WORD_IDENTIFIER = 0x66;
static const unsigned int ADDRESS_SIZE_OVERWRITE = 0x67;
static const unsigned int DWORD_BYTES = 4;
static const unsigned int QWORD_BYTES = 8;

// no operation instructions of length 1 to 11 bytes for usage
// in automatic nop padding
static const uint8_t *const FIXED_NOP_LENGTH[] = {
    (uint8_t[]){NOP},  (uint8_t[]){NOP2},  (uint8_t[]){NOP3}, (uint8_t[]){NOP4},
    (uint8_t[]){NOP5}, (uint8_t[]){NOP6},  (uint8_t[]){NOP7}, (uint8_t[]){NOP8},
    (uint8_t[]){NOP9}, (uint8_t[]){NOP10}, (uint8_t[]){NOP11}};

/**
 * assembles a constant from @param instruc and writes the opcode to
 * pointer location @param ptr
 */
static unsigned int assemble_const(unsigned long constant,
                                   unsigned char ptr[]) {

  unsigned int ptr_pos = 0;
  while (constant > 0) {
    ptr[ptr_pos++] = constant & MAX_UNSIGNED_8BIT;
    constant >>= BIT_8;
  }
  return ptr_pos;
}

/**
 * this function determines how the caller interprets an immediate between
 * 0x80000000 and 0xffffffff(64 bits when NASM mode is disabled) by including
 * or excluding an additional leading zero byte in the immediate given
 * @param instruc, immediate @param saved_imm, and instruction type @param type
 * ex: NASM mode disabled "mov rax, 0x80000000" -> 48,b8,00,00,00,80,00,00,00,00
 * ex: NASM mode enabled "mov rax, 0x80000000" -> b8,00,00,00,80
 */
static bool check_zero(struct instr *instruc, unsigned long saved_imm,
                       instr_type type) {
  // check for signed 32bit overflow
  if (IN_RANGE(saved_imm, NEG32BIT_CHECK, MAX_UNSIGNED_32BIT) &&
      !instruc->reduced_imm && type != CONTROL_FLOW) {
    // nasm immediate register handling disabled
    if (!(instruc->assembly_opt & NASM))
      return true;
    // nasm immediate register handling disabled
    if (type != DATA_TRANSFER)
      return true;
  }
  return false;
}

/**
 * assembles the immediate operand of a @param instruc and writes the
 * opcode to pointer location @param ptr
 */
static unsigned int assemble_imm(struct instr *instruc, unsigned char ptr[]) {

  unsigned int ptr_pos = 0;
  unsigned long imm_operand = instruc->cons;
  instr_type type = INSTR_TABLE[instruc->key].type;
  // check is there is a constant in the instruction and if not, return
  if (!instruc->imm)
    return ptr_pos;
  if (instruc->keyword.is_byte)
    imm_operand &= MAX_UNSIGNED_8BIT;
  // assemble the constant
  unsigned int bytes = assemble_const(imm_operand, ptr + ptr_pos);
  ptr_pos += bytes;
  // check if the zero byte is present or needed?
  if (imm_operand == 0 || check_zero(instruc, imm_operand, type)) {
    ptr[ptr_pos++] = 0x0;
    bytes++;
  }
  // no need to zero pad if the immediate operand has been reduced
  if (instruc->reduced_imm || instruc->keyword.is_byte)
    return ptr_pos;
  // get the register size for the first operand
  unsigned int opd0_mode = instruc->opd[0].reg & MODE_MASK;
  // zero padding is required rarely.
  bool zero_pad =
      ((type != CONTROL_FLOW &&       // it must not be CONTROL_FLOW
        instruc->op_offset != 3 &&    // and cannot have op_offset 3
        !instruc->keyword.is_byte) && // and cannot be a byte
       opd0_mode > noext8) ||         // and op0 mode must be bigger than noext8
      (INSTR_TABLE[instruc->key].encode_operand > I) ||
      (type == PAD_ALWAYS);
  // return if zero padding is not required
  if (!zero_pad)
    return ptr_pos;
  // now calculate the required amount of zero-bytes to pad
  bool opd0_is_16 = opd0_mode == reg16 || opd0_mode == ext16;
  if (bytes <= DWORD_BYTES && !(bytes == 1 && opd0_is_16))
    bytes = DWORD_BYTES - bytes;
  else if (bytes > DWORD_BYTES && bytes <= QWORD_BYTES)
    bytes = QWORD_BYTES - bytes;
  // pad zero byte
  for (unsigned int k = 0; k < bytes; k++)
    ptr[ptr_pos++] = 0x0;
  return ptr_pos;
}

/**
 * assembles the memory constant of a @param constant and writes the
 * opcode to pointer location @param ptr and always pad to 4 bytes
 */
static unsigned int assemble_mem_const(unsigned long constant,
                                       unsigned char ptr[]) {

  unsigned int ptr_pos = 0;
  // assemble memory displacement byte by byte using little endian format
  unsigned int mbytes = assemble_const(constant, ptr + ptr_pos);
  ptr_pos += mbytes;
  // zero pad memory displacement constant to 4 bytes
  mbytes = DWORD_BYTES - mbytes;
  for (unsigned int m = 0; m < mbytes; m++)
    ptr[ptr_pos++] = 0x0;
  return ptr_pos;
}

/**
 * assembles the memory displacement of a @param instruc and writes the
 * opcode to pointer location @param ptr
 */
static unsigned int assemble_mem_disp(struct instr *instruc,
                                      unsigned char ptr[]) {

  unsigned int ptr_pos = 0;
  // check if zero byte is present
  if (instruc->zero_byte) {
    ptr[ptr_pos++] = 0x0;
    return ptr_pos;
  }
  // check if there is a memory reference
  if (instruc->mem_disp) {
    if (instruc->is_sib_const && !instruc->mem_value)
      ptr[ptr_pos++] = SIB_CONST;
    if (instruc->mod_disp == MOD8) {
      ptr[ptr_pos++] = instruc->mem_offset;
    } else if (instruc->mod_disp == MOD16 || instruc->no_base)
      ptr_pos += assemble_mem_const(instruc->mem_offset, ptr + ptr_pos);
  }
  return ptr_pos;
}

static int assemble_VEX(struct instr *instruc, unsigned char ptr[],
                        unsigned int vex) {

  int i = 0;
  uint8_t vex_first_byte = C4H;
  uint8_t RvvvvLpp = 0;
  // set W bit depending on register size
  if ((vex & W0_W1) == W0_W1 && !instruc->hex.is_w0)
    vex &= ~W1;
  // WIG is true therefore we could switch between C4H and C5H
  else if ((vex & WIG) && !(vex & W1))
    if (!(instruc->hex.rex & rex_b))
      vex_first_byte = C5H;
  // Byte 0 if VEX prefix
  vex >>= 1;
  ptr[i++] = vex_first_byte;
  // set to RXBm-mmmm if vex if 3 bytes ie. C4H
  if (vex_first_byte == C4H)
    ptr[i++] = ((vex >> BIT_8) | (~(instruc->hex.rex & REX_MASK) << SHIFT_5)) &
               MAX_UNSIGNED_8BIT;
  // last byte of the vex prefix
  vex &= ~CLEARvvvv;
  // W is predetermined therefore we do not want to overwrite it
  if (vex_first_byte == C4H) {
    // can be used for both RvvvvLpp and WvvvvLpp
    ptr[i++] = ((~(instruc->hex.vvvv) << SHIFT_3) & MAX_SIGNED_8BIT) |
               (vex & MAX_UNSIGNED_8BIT);
  } else if (vex_first_byte == C5H) {
    RvvvvLpp = (vex & MAX_UNSIGNED_8BIT) |
               ((~(instruc->hex.rex & rex_r) << SHIFT_5) & NEG8BIT_CHECK);
    ptr[i++] = ((~(instruc->hex.vvvv) << SHIFT_3) & MAX_SIGNED_8BIT) |
               (RvvvvLpp & MAX_UNSIGNED_8BIT);
  }
  return i;
}

/**
 * assembles the prefix and opcode of a @param instruc and writes the
 * opcode to pointer location @param ptr
 */
static unsigned int assemble_instr(struct instr *instruc, unsigned char ptr[]) {

  unsigned int ptr_pos = 0;
  unsigned int opcode_pos = 0;
  unsigned int new_vex = 0;
  // 16 bit register prefix
  if ((instruc->opd[0].reg & BIT_MASK) == BIT_16 || instruc->hex.is_66H ||
      instruc->keyword.is_word)
    ptr[ptr_pos++] = WORD_IDENTIFIER;
  // 67h - address size overwrite prefix
  if (instruc->hex.is_67H)
    ptr[ptr_pos++] = ADDRESS_SIZE_OVERWRITE;
  // assemble all prefixes and instruction opcode
  while (opcode_pos < INSTR_TABLE[instruc->key].instr_size) {
    unsigned char opc =
        INSTR_TABLE[instruc->key].opcode[opcode_pos] & MAX_UNSIGNED_8BIT;
    // check if the byte in the opcode is fixed
    if (!(INSTR_TABLE[instruc->key].opcode[opcode_pos] &
          (~MAX_UNSIGNED_8BIT))) {
      if (opcode_pos == INSTR_TABLE[instruc->key].op_offset_i)
        opc += instruc->op_offset;
      ptr[ptr_pos++] = opc;
    } else {
      switch (INSTR_TABLE[instruc->key].opcode[opcode_pos] & GET_EN) {
      case REX:
        if (instruc->hex.rex != NONE)
          ptr[ptr_pos++] = instruc->hex.rex;
        break;

      case REG:
        ptr[ptr_pos++] = instruc->hex.reg;
        break;

      case VEX:
        new_vex = ~GET_EN & INSTR_TABLE[instruc->key].opcode[opcode_pos];
        ptr_pos += assemble_VEX(instruc, ptr + ptr_pos, new_vex);
        break;

      case ib:
        instruc->reduced_imm = true;
        instruc->cons &= MAX_UNSIGNED_8BIT;
        break;

      case rd:
        if (opcode_pos == INSTR_TABLE[instruc->key].op_offset_i)
          opc += instruc->op_offset;
        ptr[ptr_pos++] = opc + instruc->rd_offset;
        break;

      default:
        break;
      }
    }
    opcode_pos++;
  }
  if (instruc->hex.sib != NO_BYTE)
    ptr[ptr_pos++] = instruc->hex.sib;
  return ptr_pos;
}

/**
 * writes a nop instruction of length @param nop_pad_len
 * to pointer location @param buf
 */
unsigned int nop_padding(uint8_t *buf, unsigned int nop_pad_len) {

  uint8_t *ptr = buf;
  // find nop instruction of a specified length
  const uint8_t *nop_to_use = FIXED_NOP_LENGTH[nop_pad_len - 1];
  unsigned int j = 0;
  // assemble nop instruction
  for (unsigned i = 0; i < nop_pad_len; i++) {
    *(ptr + j) = nop_to_use[i];
    j++;
  }
  return nop_pad_len;
}

/**
 * assembles a @param instruc and write the opcode
 * to pointer location @param ptr
 */
unsigned int assemble_asm(struct instr *instruc, uint8_t *dest) {

  // dest index
  unsigned int ptr_pos = 0;
  // opcode length
  unsigned int instr_len = 0;
  unsigned int mem_disp_len = 0;
  unsigned int mem_const_len = 0;
  unsigned int imm_len = 0;
  // assemble instruction
  instr_len = assemble_instr(instruc, dest);
  ptr_pos += instr_len;
  // assemble memory displacemet
  mem_disp_len = assemble_mem_disp(instruc, dest + ptr_pos);
  ptr_pos += mem_disp_len;
  // assemble memory constant
  if (instruc->mem_value) {
    dest[ptr_pos++] = NO_REG_MEM;
    mem_const_len = assemble_mem_const(instruc->mem_const, dest + ptr_pos);
    ptr_pos += mem_const_len;
  }
  // assemble immediate
  imm_len = assemble_imm(instruc, dest + ptr_pos);
  ptr_pos += imm_len;

  return ptr_pos;
}
