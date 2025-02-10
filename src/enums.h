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

/*defines all enumerators used in assemblyline*/
#ifndef ENUMS_H
#define ENUMS_H

typedef enum { BEGIN, FIRST_CH, SPACE_FOUND } filter_op;

// used to identify special opcodes (must be greater than 255 to avoid conflict
// with instruction opcode)
typedef enum {

  // used in opcode layout to denote a dynamic byte
  REG = 0b00100000000000000000,
  REX = 0b01000000000000000000,
  VEX = 0b10000000000000000000,
  // this denotes the presence of an 8-bit immediate
  ib = 0b0100000000000000000000,
  rd = 0b1000000000000000000000
} opcode_encoding;

// only used for determining what prefix to use based on registers
typedef enum {

  rex_ = 0x40,
  rex_w = 0x48,
  rex_r = 0x04,
  rex_x = 0x02,
  rex_b = 0x01
} prefix_encoding;

typedef enum { CHUNK_COUNT, CHUNK_FITTING, ASSEMBLE } ASM_MODE;

// describes how operands are encoded
typedef enum {

  MR = 500,
  RM,
  RVM,
  RMV,
  M,
  I,
  O,
  D,
  S,
  B
} operand_encoding;

// describes operand layout ex: ri = instruction register, constant
typedef enum {

  opd_error = -1,
  n,
  m,
  r,
  mr,
  rm,
  rr,
  ri,
  mi,
  rrr,
  rri,
  rmi,
  rrm,
  rmr,
  vr,
  rv,
  vv,
  yy,
  vi,
  vm,
  mv,
  ym,
  my,
  vvv,
  yyy,
  mri,
  mrr,
  vvm,
  yym,
  vvvi,
  vvmi,
  yyyi,
  yymi,

} operand_format;

// unique identifier for each instuction
typedef enum {

  EOI,
  LABEL,
  SKIP,
  adc,
  adcx,
  add,
  adox,
  and,
  bextr,
  bzhi,
  call,
  clc,
  clflush,
  cmova,
  cmovae,
  cmovb,
  cmovbe,
  cmovc,
  cmove,
  cmovg,
  cmovge,
  cmovl,
  cmovle,
  cmovna,
  cmovnae,
  cmovnb,
  cmovnbe,
  cmovnc,
  cmovne,
  cmovng,
  cmovnge,
  cmovnl,
  cmovnle,
  cmovno,
  cmovnp,
  cmovns,
  cmovnz,
  cmovo,
  cmovp,
  cmovpe,
  cmovpo,
  cmovs,
  cmovz,
  cmp,
  cpuid,
  cvtdq2pd,
  cvtpd2dq,
  dec,
  divpd,
  imul,
  inc,
  ja,
  jae,
  jb,
  jbe,
  je,
  jg,
  jge,
  jl,
  jle,
  jmp,
  jne,
  jno,
  jnp,
  jns,
  jo,
  jp,
  jrcxz,
  js,
  lea,
  lfence,
  mfence,
  mov,
  movd,
  movntdqa,
  movntq,
  movq,
  movzx,
  mulpd,
  mul,
  mulx,
  neg,
  nop,
  not,
  // clang-format off
  or,
  // clang-format on
  paddb,
  paddd,
  paddq,
  paddw,
  pand,
  pandn,
  pmuldq,
  pmulhrsw,
  pmulhuw,
  pmulhw,
  pmulld,
  pmullw,
  pmuludq,
  pop,
  por,
  prefetchnta,
  prefetcht0,
  prefetcht1,
  prefetcht2,
  psrldq,
  psubb,
  psubd,
  psubq,
  psubw,
  punpcklqdq,
  push,
  pxor,
  rcr,
  rdpmc,
  rdpru,
  rdtsc,
  rdtscp,
  ret,
  ror,
  rorx,
  sal,
  sar,
  sarx,
  sbb,
  seta,
  setae,
  setb,
  setbe,
  setc,
  sete,
  setg,
  setge,
  setl,
  setle,
  setna,
  setnae,
  setnb,
  setnbe,
  setnc,
  setne,
  setng,
  setnge,
  setnl,
  setnle,
  setno,
  setnp,
  setns,
  setnz,
  seto,
  setp,
  setpe,
  setpo,
  sets,
  setz,
  sfence,
  shl,
  shld,
  shlx,
  shr,
  shrd,
  shrx,
  sub,
  test,
  vaddpd,
  vdivpd,
  vmovdqu,
  vmovupd,
  vmulpd,
  vpaddb,
  vpaddd,
  vpaddq,
  vpaddw,
  vpand,
  vpandn,
  vperm2f128,
  vperm2i128,
  vpermd,
  vpmuldq,
  vpmulhrsw,
  vpmulhuw,
  vpmulhw,
  vpmulld,
  vpmullw,
  vpmuludq,
  vpor,
  vpsubb,
  vpsubd,
  vpsubq,
  vpsubw,
  vpxor,
  vsubpd,
  xabort,
  xbegin,
  xchg,
  xend,
  xor
} asm_instr;

// used to categorize instruction based on their functionality
typedef enum {

  // enforce a different mode of processing constant operand
  DATA_TRANSFER = 0b000001,
  /* to ensure shift instruction such as "shr REG, 1" does not
   * assemble the predefined constant 1 operand. Rather use the special
   * instruction  for shr REG, 1
   */
  SHIFT = 0b000010,
  /* for control flow instructions constant operand is handled
   * differently due to not having an associated register
   */
  CONTROL_FLOW = 0b000100,
  // SSE and vector extension instructions
  VECTOR = 0b001000,
  // AVX 256 instruction
  VECTOR_AVX = 0b011000,
  // this is a test used to bypass old implementation
  VECTOR_EXT = 0b101000,
  // used to encode instructions with both an I and M operand encoding
  OPERATION = 0b1000000,
  PAD_ALWAYS = 0b1000010,
  // operand can only be a byte
  BYTE_OPD = 0b1000011,
  // instructions that do not require special encodings
  OTHER
} instr_type;

// register bit size and category (ext denotes extended x64 registers)
typedef enum {

  reg8 = 0b00000000000,
  ext8 = 0b00010000000,
  noext8 = 0b00100000000,
  reg16 = 0b01000000000,
  ext16 = 0b01010000000,
  reg32 = 0b01100000000,
  ext32 = 0b01110000000,
  reg64 = 0b10000000000,
  ext64 = 0b10010000000,
  mmx64 = 0b10100000000
} bit_mode;

// register representation (converted from string)
typedef enum {

  reg_error = 0b1000000,
  reg_none = 0b100000,
  // 8-bit registers
  al = 0b00000,
  cl = 0b00001,
  dl = 0b00010,
  bl = 0b00011,
  spl = 0b00100,
  bpl = 0b00101,
  sil = 0b00110,
  dil = 0b00111,
  // 8-bit extended registers
  r8b = 0b01000,
  r9b = 0b01001,
  r10b = 0b01010,
  r11b = 0b01011,
  r12b = 0b01100,
  r13b = 0b01101,
  r14b = 0b01110,
  r15b = 0b01111,
  // 64-bit vector reigsters
  mm0 = 0b10000,
  mm1 = 0b10001,
  mm2 = 0b10010,
  mm3 = 0b10011,
  mm4 = 0b10100,
  mm5 = 0b10101,
  mm6 = 0b10110,
  mm7 = 0b10111,
  // 64-bit extended vector reigsters
  mm8 = 0b11000,
  mm9 = 0b11001,
  mm10 = 0b11010,
  mm11 = 0b11011,
  mm12 = 0b11100,
  mm13 = 0b11101,
  mm14 = 0b11110,
  mm15 = 0b11111

} asm_reg;

#endif
