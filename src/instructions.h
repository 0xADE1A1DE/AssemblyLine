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

/*defines all conss for x86 assembly instruction to opcode mapping*/
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "common.h"
#include "enums.h"
#include <inttypes.h>

// operand format string to enum mapping 
const static struct {
  operand_format val;
  const char str[OPERAND_FORMAT_LEN];
  
} OPD_FORMAT_TABLE[] = {{n,   {'\0'}},  {n,   "i"},   {m,         "m"},
                        {r,   "r"},     {mr,  "mr"},  {rm,        "rm"},
                        {rr,  "rr"},    {ri,  "ri"},  {mi,        "mi"},
                        {rrr, "rrr"},   {rri, "rri"}, {rmi,       "rmi"},
                        {rrm, "rrm"},   {rmr, "rmr"}, {opd_error, "error"}};

// defines opcode layout of each supported instruction
const static struct {

  /* null terminated string representation of an instruction ex: "mov"
   * subsequent instructions of the same name with a different operand
   * encoding will be place contiguously with the first instance of the
   * instuction and will have the '\0' string
   */
  char instr_name[MAX_INSTR_LEN];

  // asm_instr enumerator for uniquely identifying a single instruction
  int name;

  /* contains the valid operand formats for an instruction that maps
   * to the same operand enccoding (at most 2 for a single operand encoding)
   * ex: rr (instr reg,reg) && rm (instr reg, [mem]) -> RM
   */
  int opd_format[VALID_OPERAND_FORMATS];

  /* operand encoding format as an enumerator (determines how instruction
   * operands will be encoded) in assemblyline the 'I' character op/en will be
   * ignored unless it is standalone ex: MI -> M , RMI -> RM , I -> I
   */
  operand_encoding encode_operand;

  /* enumerator for defining the semantic type of an instruction
   * if the instruction type is not known set this value to 'OTHER'
   * refer to the link below to find the correct type for the instruction
   * https://docs.oracle.com/cd/E36784_01/html/E36859/eoizp.html#scrolltoc
   */
  instr_type type;

  /* 'i' index of opcode[i] when a byte changes in the opcode depending
   * on the register size for the instruction
   * set this value to NA if not applicable to the instruction
   */
  int op_offset_i;

  /* 'i' index of opcode[i] when an offset is present for a REG value denoted as
   * '+ rd' set this value to NA if not applicable to the instruction
   */
  int rd_offset_i;

  // used instructions with a single register operand denoted as '/num'
  int single_reg_r;

  // length of instruction opcode excluding immediate and memory displacement 
  int instr_size;

  // displacement for the W0 prefix (following byte after the vector extension
  // prefix VEX)
  int w0_disp;

  /* opcode layout for an instruction ex: {REX,0x0f,0xa9,REG}
   * REX and REG are placeholders for the prefix and register values
   * more can be found in enums.h op_encoding
   */
  unsigned int opcode[MAX_OPCODE_LEN];

} INSTR_TABLE[] = {
    {{'\0'},      EOI,       {NA, NA},   NA,   ASSEMBLYLINE,   NA,  NA,  NA,  0,  0, {0}},
    {{'\0'},      LABEL,     {NA, NA},   NA,   ASSEMBLYLINE,   NA,  NA,  NA,  0,  0, {0}},
    {{'\0'},      SKIP,      {NA, NA},   NA,   ASSEMBLYLINE,   NA,  NA,  NA,  0,  0, {0}},
    {"mov",       mov,       {rr, mr},   MR,   DATA_TRANSFER,  1,   NA,  NA,  3,  0, {REX, 0x88, REG}},
    {{'\0'},      mov,       {NA, rm},   RM,   DATA_TRANSFER,  1,   NA,  NA,  3,  0, {REX, 0x8a, REG}},
    {{'\0'},      mov,       {mi, ri},   M,    DATA_TRANSFER,  1,   NA,  0,   3,  0, {REX, 0xc6, REG}},
    {{'\0'},      mov,       {NA, NA},   I,    DATA_TRANSFER,  1,   1,   NA,  2,  0, {REX, 0xb0}},
    {"movzx",     movzx,     {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0xb6, REG}},
    {"movntq",    movntq,    {NA, mr},   MR,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0xe7, REG}},
    {"movntdqa",  movntdqa,  {NA, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  7,  0, {EVEX, 0x66, REX, 0x0f, 0x38, 0x2a, REG}},
    {"cmova",     cmova,     {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x47, REG}},
    {"cmovae",    cmovae,    {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x43, REG}},
    {"cmovb",     cmovb,     {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x42, REG}},
    {"cmovbe",    cmovbe,    {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x46, REG}},
    {"cmove",     cmove,     {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x44, REG}},
    {"cmovg",     cmovg,     {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4f, REG}},
    {"cmovge",    cmovge,    {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4d, REG}},
    {"cmovl",     cmovl,     {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4c, REG}},
    {"cmovle",    cmovle,    {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4e, REG}},
    {"cmovna",    cmovna,    {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x46, REG}},
    {"cmovnae",   cmovnae,   {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x42, REG}},
    {"cmovnb",    cmovnb,    {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x43, REG}},
    {"cmovnbe",   cmovnbe,   {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x47, REG}},    
    {"cmovnc",    cmovnc,    {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x43, REG}},    
    {"cmovne",    cmovne,    {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x45, REG}},    
    {"cmovng",    cmovng,    {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4e, REG}},    
    {"cmovnz",    cmovnz,    {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x45, REG}},
    {"cmovp",     cmovp,     {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4a, REG}},
    {"cmovpe",    cmovpe,    {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4a, REG}},
    {"cmovpo",    cmovpo,    {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4b, REG}},
    {"cmovs",     cmovs,     {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x48, REG}},
    {"cmovz",     cmovz,     {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x44, REG}},
    {"cmovc",     cmovc,     {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x42, REG}},
    {"cmovo",     cmovo,     {rr, rm},   RM,   DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x40, REG}},
    {"push",      push,      {NA, r },   O,    DATA_TRANSFER,  NA,  1,   NA,  2,  0, {REX, 0x50}},
    {"pop",       pop,       {NA, r },   O,    DATA_TRANSFER,  NA,  1,   NA,  2,  0, {REX, 0x58}},
    {"xchg",      xchg,      {rr, rm},   RM,   DATA_TRANSFER,  1,   NA,  NA,  3,  0, {REX, 0x86, REG}},
    {"xchg",      xchg,      {NA, NA},   I,    DATA_TRANSFER,  NA,  1,   NA,  2,  0, {REX, 0x90}},
    {"cmp",       cmp,       {rr, mr},   MR,   ARITHMETIC,     1,   NA,  NA,  3,  0, {REX, 0x38, REG}},
    {{'\0'},      cmp,       {NA, rm},   RM,   ARITHMETIC,     1,   NA,  NA,  3,  0, {REX, 0x3a, REG}},
    {{'\0'},      cmp,       {mi, ri},   M,    ARITHMETIC,     1,   NA,  7,   3,  0, {REX, 0x80, REG}},
    {{'\0'},      cmp,       {NA, NA},   I,    ARITHMETIC,     1,   NA,  NA,  2,  0, {REX, 0x3c}},
    {"sub",       sub,       {rr, mr},   MR,   ARITHMETIC,     1,   NA,  NA,  3,  0, {REX, 0x28, REG}},
    {{'\0'},      sub,       {NA, rm},   RM,   ARITHMETIC,     1,   NA,  NA,  3,  0, {REX, 0x2a, REG}},
    {{'\0'},      sub,       {mi, ri},   M,    ARITHMETIC,     1,   NA,  5,   3,  0, {REX, 0x80, REG}},
    {{'\0'},      sub,       {NA, NA},   I,    ARITHMETIC,     1,   NA,  NA,  2,  0, {REX, 0x2c}},
    {"add",       add,       {rr, mr},   MR,   ARITHMETIC,     1,   NA,  NA,  3,  0, {REX, 0x00, REG}},
    {{'\0'},      add,       {NA, rm},   RM,   ARITHMETIC,     1,   NA,  NA,  3,  0, {REX, 0x02, REG}},
    {{'\0'},      add,       {mi, ri},   M,    ARITHMETIC,     1,   NA,  0,   3,  0, {REX, 0x80, REG}},
    {{'\0'},      add,       {NA, NA},   I,    ARITHMETIC,     1,   NA,  NA,  2,  0, {REX, 0x04}},
    {"adc",       adc,       {mi, ri},   M,    ARITHMETIC,     1,   NA,  2,   3,  0, {REX, 0x80, REG}},
    {{'\0'},      adc,       {NA, NA},   I,    ARITHMETIC,     1,   NA,  NA,  2,  0, {REX, 0x14}},
    {"adcx",      adcx,      {rr, rm},   RM,   ARITHMETIC,     NA,  NA,  NA,  6,  0, {0x66, REX, 0x0f, 0x38, 0xf6, REG}},
    {"adox",      adox,      {rr, rm},   RM,   ARITHMETIC,     NA,  NA,  NA,  6,  0, {0xf3, REX, 0x0f, 0x38, 0xf6, REG}},
    {"mulx",      mulx,      {rrr, rrm}, RVM,  ARITHMETIC,     NA,  NA,  NA,  5,  0, {0xc4, VEX, W0, 0xf6, REG}},
    {"bzhi",      bzhi,      {rrr, rmr}, RMV,  ARITHMETIC,     NA,  NA,  NA,  5,  3, {0xc4, VEX, W0, 0xf5, REG}},
    {"shlx",      shlx,      {rrr, rmr}, RMV,  ARITHMETIC,     NA,  NA,  NA,  5,  2, {0xc4, VEX, W0, 0xf7, REG}},
    {"sarx",      sarx,      {rrr, rmr}, RMV,  ARITHMETIC,     NA,  NA,  NA,  5,  1, {0xc4, VEX, W0, 0xf7, REG}},
    {"shrx",      shrx,      {rrr, rmr}, RMV,  ARITHMETIC,     NA,  NA,  NA,  5,  0, {0xc4, VEX, W0, 0xf7, REG}},
    {"imul",      imul,      {rri, rmi}, RM,   ARITHMETIC,     1,   NA,  NA,  3,  0, {REX, 0x68, REG}},
    {"sbb",       sbb,       {rr, mr},   MR,   ARITHMETIC,     1,   NA,  NA,  3,  0, {REX, 0x18, REG}},
    {{'\0'},      sbb,       {NA, rm},   RM,   ARITHMETIC,     1,   NA,  NA,  3,  0, {REX, 0x1a, REG}},
    {{'\0'},      sbb,       {mi, ri},   M,    ARITHMETIC,     1,   NA,  3,   3,  0, {REX, 0x80, REG}},
    {{'\0'},      sbb,       {NA, NA},   I,    ARITHMETIC,     1,   NA,  NA,  2,  0, {REX, 0x1c}},
    {"inc",       inc,       {r,  m},    M,    ARITHMETIC,     1,   NA,  0,   3,  0, {REX, 0xfe, REG}},
    {"dec",       dec,       {r,  m},    M,    ARITHMETIC,     1,   NA,  1,   3,  0, {REX, 0xfe, REG}},
    {"shr",       shr,       {NA, ri},   M,    SHIFT,          1,   NA,  5,   3,  0, {REX, 0xbe, REG}},
    {{'\0'},      shr,       {NA, NA},   M,    SHIFT,          NA,  NA,  5,   3,  0, {REX, 0xc1, REG}},
    {{'\0'},      shr,       {NA, rr},   M,    SHIFT,          NA,  NA,  5,   3,  0, {REX, 0xd3, REG}},
    {"shl",       shl,       {NA, ri},   M,    SHIFT,          NA,  NA,  4,   3,  0, {REX, 0xd1, REG}},
    {{'\0'},      shl,       {NA, NA},   M,    SHIFT,          NA,  NA,  4,   3,  0, {REX, 0xc1, REG}},
    {"rcr",       rcr,       {mi, ri},   M,    SHIFT,          1,   NA,  3,   3,  0, {REX, 0xd0, REG}},
    {{'\0'},      rcr,       {NA, NA},   M,    SHIFT,          1,   NA,  2,   3,  0, {REX, 0xc1, REG}},    
    {"shrd",      shrd,      {NA, rri},  MR,   SHIFT_S,        2,   NA,  NA,  4,  0, {REX, 0x0f, 0xa9, REG}},
    {"sar",       sar,       {mi, ri},   M,    SHIFT,          1,   NA,  7,   3,  0, {REX, 0xd0, REG}},
    {{'\0'},      sar,       {NA, NA},   M,    SHIFT,          1,   NA,  7,   3,  0, {REX, 0xc0, REG}},
    {"and",       and,       {rr, mr},   MR,   LOGICAL,        1,   NA,  NA,  3,  0, {REX, 0x20, REG}},
    {{'\0'},      and,       {NA, rm},   RM,   LOGICAL,        1,   NA,  NA,  3,  0, {REX, 0x22, REG}},
    {"xor",       xor,       {rr, mr},   MR,   LOGICAL,        1,   NA,  NA,  3,  0, {REX, 0x30, REG}},
    {{'\0'},      xor,       {NA, rm},   RM,   LOGICAL,        1,   NA,  NA,  3,  0, {REX, 0x32, REG}},
    {{'\0'},      xor,       {mi, ri},   M,    LOGICAL,        1,   NA,  6,   3,  0, {REX, 0x80, REG}},
    {{'\0'},      xor,       {NA, NA},   I,    LOGICAL,        1,   NA,  NA,  2,  0, {REX, 0x34}},    
    {"or",        or,        {rr, mr},   MR,   LOGICAL,        1,   NA,  NA,  3,  0, {REX, 0x08, REG}},
    {{'\0'},      or,        {NA, rm},   RM,   LOGICAL,        1,   NA,  NA,  3,  0, {REX, 0x0a, REG}},
    {"not",       not,       {r,  m},    M,    LOGICAL,        1,   NA,  2,   3,  0, {REX, 0xf6, REG}},
    {"test",      test,      {rr, mr},   MR,   BIT,            1,   NA,  NA,  3,  0, {REX, 0x84, REG}},
    {"setc",      setc,      {r,  m},    M,    BIT,            NA,  NA,  0,   4,  0, {REX, 0x0f, 0x92, REG}},
    {"seto",      seto,      {r,  m},    M,    BIT,            NA,  NA,  0,   4,  0, {REX, 0x0f, 0x90, REG}},
    {"clc",       clc,       {n,  n},    NA,   OTHER,          NA,  NA,  NA,  1,  0, {0xf8}},
    {"clflush",   clflush,   {r,  m},    M,    OTHER,          NA,  NA,  7,   4,  0, {REX, 0x0f, 0xae, REG}},
    {"lea",       lea,       {NA, rm},   RM,   OTHER,          NA,  NA,  NA,  3,  0, {REX, 0x8d, REG}},
    {"sfence",    sfence,    {n,  n},    NA,   OTHER,          NA,  NA,  NA,  3,  0, {0x0f, 0xae, 0xf8}},
    {"lfence",    lfence,    {n,  n},    NA,   OTHER,          NA,  NA,  NA,  3,  0, {0x0f, 0xae, 0xe8}},
    {"mfence",    mfence,    {n,  n},    NA,   OTHER,          NA,  NA,  NA,  3,  0, {0x0f, 0xae, 0xf0}},
    {"nop",       nop,       {n,  n},    NA,   OTHER,          NA,  NA,  NA,  1,  0, {0x90}},
    {"nop2",      nop,       {n,  n},    NA,   OTHER,          NA,  NA,  NA,  2,  0, {0x66, 0x90}},
    {"nop3",      nop,       {n,  n},    NA,   OTHER,          NA,  NA,  NA,  3,  0, {0x0f, 0x1f, 0x00}},
    {"nop4",      nop,       {n,  n},    NA,   OTHER,          NA,  NA,  NA,  4,  0, {0x0f, 0x1f, 0x40, 0x00}},
    {"nop5",      nop,       {n,  n},    NA,   OTHER,          NA,  NA,  NA,  5,  0, {0x0f, 0x1f, 0x44, 0x00, 0x00}},
    {"nop6",      nop,       {n,  n},    NA,   OTHER,          NA,  NA,  NA,  6,  0, {0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00}},
    {"nop7",      nop,       {n,  n},    NA,   OTHER,          NA,  NA,  NA,  7,  0, {0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00}},
    {"nop8",      nop,       {n,  n},    NA,   OTHER,          NA,  NA,  NA,  8,  0, {0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {"nop9",      nop,       {n,  n},    NA,   OTHER,          NA,  NA,  NA,  9,  0, {0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {"nop10",     nop,       {n,  n},    NA,   OTHER,          NA,  NA,  NA,  10, 0, {0x66, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {"nop11",     nop,       {n,  n},    NA,   OTHER,          NA,  NA,  NA,  11, 0, {0x66, 0x66, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {"rdtsc",     rdtsc,     {n,  n},    NA,   OTHER,          NA,  NA,  NA,  1,  0, {0x0f, 0x31}},
    {"rorx",      rorx,      {rri, rmi}, RM,   OTHER,          NA,  NA,  NA,  5,  0, {0xc4, VEX, 0xfb, 0xf0, REG}},
    {"xbegin",    xbegin,    {n,  n},    NA,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0xc7, 0xf8}},
    {"xend",      xend,      {n,  n},    NA,   CONTROL_FLOW,   NA,  NA,  NA,  3,  0, {0x0f, 0x01, 0xd5}},
    {"xabort",    xabort,    {n,  n},    I,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0xc6, 0xf8}},
    {"jmp",       jmp,       {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0xe9}},
    {{'\0'},      jmp,       {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0xeb}},
    {{'\0'},      jmp,       {r,  m},    O,    CONTROL_FLOW,   NA,  NA,  4,   3,  0, {REX, 0xff, REG}},
    {{'\0'},      jmp,       {NA, NA},   D,    CONTROL_FLOW,   NA,  NA,  NA,  3,  0, {0xff, 0x24, 0x25}},
    {"ja",        ja,        {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x87}},
    {{'\0'},      ja,        {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x77}},
    {"jae",       jae,       {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x83}},
    {{'\0'},      jae,       {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x73}},
    {"jb",        jb,        {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x82}},
    {{'\0'},      jb,        {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x72}},
    {"je",        je,        {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x84}},
    {{'\0'},      je,        {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x74}},
    {"jg",        jg,        {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x8f}},
    {{'\0'},      jg,        {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x7f}},
    {"jge",       jge,       {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x8d}},
    {{'\0'},      jge,       {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x7d}},
    {{'\0'},      jbe,       {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x86}},
    {{'\0'},      jbe,       {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x76}},
    {"jl",        jl,        {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x8c}},
    {{'\0'},      jl,        {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x7c}},
    {"jle",       jle,       {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x8e}},
    {{'\0'},      jle,       {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x7e}},
    {"jne",       jne,       {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x85}},
    {{'\0'},      jne,       {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x75}},
    {"js",        js,        {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x88}},
    {{'\0'},      js,        {NA,  NA},  S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x78}},
    {"jno",       jno,       {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x81}},
    {{'\0'},      jno,       {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x71}},
    {"jnp",       jnp,       {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x8b}},
    {{'\0'},      jnp,       {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x7b}},
    {"jns",       jns,       {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x89}},
    {{'\0'},      jns,       {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x79}},
    {"jo",        jo,        {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x80}},
    {{'\0'},      jo,        {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x70}},
    {"jp",        jp,        {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x8a}},
    {{'\0'},      jp,        {n,  n},    S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x7a}},
    {"jrcxz",     jrcxz,     {n,  n},    S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0xe3}},
    {{'\0'},      jrcxz,     {NA, NA},   S,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0xe3}},
    {"call",      call,      {n,  n},    D,    CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0xe8}},
    {{'\0'},      call,      {r,  m},    O,    CONTROL_FLOW,   NA,  NA,  2,   3,  0, {REX, 0xff, REG}},
    {{'\0'},      call,      {NA, NA},   D,    CONTROL_FLOW,   NA,  NA,  NA,  3,  0, {0xff, 0x14, 0x25}},
    {"ret",       ret,       {n,  n},    NA,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0xc3}},
    {{'\0'},      NA,        {NA, NA},   NA,   ASSEMBLYLINE,   NA,  NA,  NA,  0,  0, {0}}};

#endif