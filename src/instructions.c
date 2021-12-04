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

/*declares all supported x86_64 assembly instructions*/
#include "common.h"
#include "enums.h"
#include <inttypes.h>
#include "instructions.h"

const struct instr_table INSTR_TABLE[] = {
    {{'\0'},        EOI,         {NA, NA},   NA,  OTHER,          NA,  NA,  NA,  0,  0, {0}},
    {{'\0'},        LABEL,       {NA, NA},   NA,  OTHER,          NA,  NA,  NA,  0,  0, {0}},
    {{'\0'},        SKIP,        {NA, NA},   NA,  OTHER,          NA,  NA,  NA,  0,  0, {0}},
    {"adc",         adc,         {rr, mr},   MR,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x10, REG}},
    {{'\0'},        adc,         {NA, rm},   RM,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x12, REG}},
    {{'\0'},        adc,         {mi, ri},   M,   OTHER,          1,   NA,  2,   3,  0, {REX, 0x80, REG}},
    {{'\0'},        adc,         {NA, NA},   I,   OTHER,          1,   NA,  NA,  2,  0, {REX, 0x14}},
    {"adcx",        adcx,        {rr, rm},   RM,  OTHER,          NA,  NA,  NA,  6,  0, {0x66, REX, 0x0f, 0x38, 0xf6, REG}},
    {"add",         add,         {rr, mr},   MR,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x00, REG}},
    {{'\0'},        add,         {NA, rm},   RM,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x02, REG}},
    {{'\0'},        add,         {mi, ri},   M,   OTHER,          1,   NA,  0,   3,  0, {REX, 0x80, REG}},
    {{'\0'},        add,         {NA, NA},   I,   OTHER,          1,   NA,  NA,  2,  0, {REX, 0x04}},
    {"adox",        adox,        {rr, rm},   RM,  OTHER,          NA,  NA,  NA,  6,  0, {0xf3, REX, 0x0f, 0x38, 0xf6, REG}},
    {"and",         and,         {rr, mr},   MR,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x20, REG}},
    {{'\0'},        and,         {NA, rm},   RM,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x22, REG}}, 
    {"bextr",       bextr,       {rrr, rmr}, RMV, NEW_VECTOR,     NA,  NA,  NA,  3,  3, {VEX_NEW(NDS,LZ,NONE,X0F38,W0_W1), 0xf7, REG}},
    {"bzhi",        bzhi,        {rrr, rmr}, RMV, NEW_VECTOR,     NA,  NA,  NA,  3,  3, {VEX_NEW(NDS,LZ,NONE,X0F38,W0_W1), 0xf5, REG}},
    {"call",        call,        {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0xe8}},
    {{'\0'},        call,        {r,  m},    O,   CONTROL_FLOW,   NA,  NA,  2,   3,  0, {REX, 0xff, REG}},
    {{'\0'},        call,        {NA, NA},   D,   CONTROL_FLOW,   NA,  NA,  NA,  3,  0, {0xff, 0x14, 0x25}},
    {"clc",         clc,         {n,  n},    NA,  OTHER,          NA,  NA,  NA,  1,  0, {0xf8}},
    {"clflush",     clflush,     {r,  m},    M,   OTHER,          NA,  NA,  7,   4,  0, {REX, 0x0f, 0xae, REG}},
    {"cmova",       cmova,       {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x47, REG}},
    {"cmovae",      cmovae,      {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x43, REG}},
    {"cmovb",       cmovb,       {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x42, REG}},
    {"cmovbe",      cmovbe,      {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x46, REG}},
    {"cmovc",       cmovc,       {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x42, REG}},
    {"cmove",       cmove,       {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x44, REG}},
    {"cmovg",       cmovg,       {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4f, REG}},
    {"cmovge",      cmovge,      {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4d, REG}},
    {"cmovl",       cmovl,       {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4c, REG}},
    {"cmovle",      cmovle,      {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4e, REG}},
    {"cmovna",      cmovna,      {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x46, REG}},
    {"cmovnae",     cmovnae,     {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x42, REG}},
    {"cmovnb",      cmovnb,      {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x43, REG}},
    {"cmovnbe",     cmovnbe,     {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x47, REG}},
    {"cmovnc",      cmovnc,      {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x43, REG}},
    {"cmovne",      cmovne,      {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x45, REG}},
    {"cmovng",      cmovng,      {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4e, REG}},
    {"cmovnz",      cmovnz,      {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x45, REG}},
    {"cmovo",       cmovo,       {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x40, REG}},    
    {"cmovp",       cmovp,       {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4a, REG}},
    {"cmovpe",      cmovpe,      {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4a, REG}},
    {"cmovpo",      cmovpo,      {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x4b, REG}},
    {"cmovs",       cmovs,       {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x48, REG}},
    {"cmovz",       cmovz,       {rr, rm},   RM,  DATA_TRANSFER,  NA,  NA,  NA,  4,  0, {REX, 0x0f, 0x44, REG}},
    {"cmp",         cmp,         {rr, mr},   MR,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x38, REG}},
    {{'\0'},        cmp,         {NA, rm},   RM,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x3a, REG}},
    {{'\0'},        cmp,         {mi, ri},   M,   OTHER,          1,   NA,  7,   3,  0, {REX, 0x80, REG}},
    {{'\0'},        cmp,         {NA, NA},   I,   OTHER,          1,   NA,  NA,  2,  0, {REX, 0x3c}},
    {"cvtdq2pd",    cvtdq2pd,    {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0xf3, REX, 0x0f, 0xe6, REG}},
    {"cvtpd2dq",    cvtpd2dq,    {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0xf2, REX, 0x0f, 0xe6, REG}},
    {"dec",         dec,         {r,  m},    M,   OTHER,          1,   NA,  1,   3,  0, {REX, 0xfe, REG}},
    {"divpd",       divpd,       {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0x5e, REG}},
    {"imul",        imul,        {rri, rmi}, RM,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x68, REG}},
    {"inc",         inc,         {r,  m},    M,   OTHER,          1,   NA,  0,   3,  0, {REX, 0xfe, REG}},
    {"ja",          ja,          {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x87}},
    {{'\0'},        ja,          {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x77}},
    {"jae",         jae,         {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x83}},
    {{'\0'},        jae,         {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x73}},
    {"jb",          jb,          {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x82}},
    {{'\0'},        jb,          {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x72}},
    {"je",          je,          {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x84}},
    {{'\0'},        je,          {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x74}},
    {"jg",          jg,          {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x8f}},
    {{'\0'},        jg,          {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x7f}},
    {"jge",         jge,         {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x8d}},
    {{'\0'},        jge,         {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x7d}},
    {{'\0'},        jbe,         {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x86}},
    {{'\0'},        jbe,         {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x76}},
    {"jl",          jl,          {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x8c}},
    {{'\0'},        jl,          {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x7c}},
    {"jle",         jle,         {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x8e}},
    {{'\0'},        jle,         {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x7e}},
    {"jmp",         jmp,         {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0xe9}},    
    {{'\0'},        jmp,         {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0xeb}},
    {{'\0'},        jmp,         {r,  m},    O,   CONTROL_FLOW,   NA,  NA,  4,   3,  0, {REX, 0xff, REG}},
    {{'\0'},        jmp,         {NA, NA},   D,   CONTROL_FLOW,   NA,  NA,  NA,  3,  0, {0xff, 0x24, 0x25}},    
    {"jne",         jne,         {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x85}},
    {{'\0'},        jne,         {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x75}},
    {"jno",         jno,         {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x81}},
    {{'\0'},        jno,         {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x71}},
    {"jnp",         jnp,         {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x8b}},
    {{'\0'},        jnp,         {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x7b}},
    {"jns",         jns,         {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x89}},
    {{'\0'},        jns,         {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x79}},
    {"jo",          jo,          {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x80}},
    {{'\0'},        jo,          {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x70}},
    {"jp",          jp,          {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x8a}},
    {{'\0'},        jp,          {n,  n},    S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x7a}},
    {"jrcxz",       jrcxz,       {n,  n},    S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0xe3}},
    {{'\0'},        jrcxz,       {NA, NA},   S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0xe3}},
    {"js",          js,          {n,  n},    D,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0x0f, 0x88}},
    {{'\0'},        js,          {NA,  NA},  S,   CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0x78}},
    {"lea",         lea,         {NA, rm},   RM,  OTHER,          NA,  NA,  NA,  3,  0, {REX, 0x8d, REG}},
    {"lfence",      lfence,      {n,  n},    NA,  OTHER,          NA,  NA,  NA,  3,  0, {0x0f, 0xae, 0xe8}},
    {"mfence",      mfence,      {n,  n},    NA,  OTHER,          NA,  NA,  NA,  3,  0, {0x0f, 0xae, 0xf0}},
    {"mov",         mov,         {rr, mr},   MR,  DATA_TRANSFER,  1,   NA,  NA,  3,  0, {REX, 0x88, REG}},
    {{'\0'},        mov,         {NA, rm},   RM,  DATA_TRANSFER,  1,   NA,  NA,  3,  0, {REX, 0x8a, REG}},
    {{'\0'},        mov,         {mi, ri},   I,   DATA_TRANSFER,  1,   1,   NA,  2,  0, {REX, 0xb0}},
    {{'\0'},        mov,         {NA, NA},   M,   DATA_TRANSFER,  1,   NA,  0,   3,  0, {REX, 0xc6, REG}},
    {"movd",        movd,        {vm, vr},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0x6e, REG}},
    {{'\0'},        movd,        {mv, rv},   MR,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0x7e, REG}},
    {"movntdqa",    movntdqa,    {NA, vm},   RM,  VECTOR,         NA,  NA,  NA,  6,  0, {0x66, REX, 0x0f, 0x38, 0x2a, REG}},
    {"movntq",      movntq,      {NA, mr},   MR,  VECTOR,         NA,  NA,  NA,  4,  0, {REX, 0x0f, 0xe7, REG}},
    {"movq",        movq,        {NA, vr},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0x6e, REG}},
    {{'\0'},        movq,        {vm, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0xf3, REX, 0x0f, 0x7e, REG}},
    {{'\0'},        movq,        {NA, rv},   MR,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0x7e, REG}},
    {"movzx",       movzx,       {rr, rm},   RM,  OTHER,          NA,  NA,  NA,  4,  0, {REX, 0x0f, 0xb6, REG}},
    {"mulpd",       mulpd,       {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0x59, REG}},
    {"mulx",        mulx,        {rrr, rrm}, RVM, VECTOR,         NA,  NA,  NA,  5,  0, {0xc4, VEX, W0_, 0xf6, REG}},
    {"nop",         nop,         {n,  n},    NA,  OTHER,          NA,  NA,  NA,  1,  0, {0x90}},
    {"nop2",        nop,         {n,  n},    NA,  OTHER,          NA,  NA,  NA,  2,  0, {0x66, 0x90}},
    {"nop3",        nop,         {n,  n},    NA,  OTHER,          NA,  NA,  NA,  3,  0, {0x0f, 0x1f, 0x00}},
    {"nop4",        nop,         {n,  n},    NA,  OTHER,          NA,  NA,  NA,  4,  0, {0x0f, 0x1f, 0x40, 0x00}},
    {"nop5",        nop,         {n,  n},    NA,  OTHER,          NA,  NA,  NA,  5,  0, {0x0f, 0x1f, 0x44, 0x00, 0x00}},
    {"nop6",        nop,         {n,  n},    NA,  OTHER,          NA,  NA,  NA,  6,  0, {0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00}},
    {"nop7",        nop,         {n,  n},    NA,  OTHER,          NA,  NA,  NA,  7,  0, {0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00}},
    {"nop8",        nop,         {n,  n},    NA,  OTHER,          NA,  NA,  NA,  8,  0, {0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {"nop9",        nop,         {n,  n},    NA,  OTHER,          NA,  NA,  NA,  9,  0, {0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {"nop10",       nop,         {n,  n},    NA,  OTHER,          NA,  NA,  NA,  10, 0, {0x66, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {"nop11",       nop,         {n,  n},    NA,  OTHER,          NA,  NA,  NA,  11, 0, {0x66, 0x66, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {"not",         not,         {r,  m},    M,   OTHER,          1,   NA,  2,   3,  0, {REX, 0xf6, REG}},
    {"or",          or,          {rr, mr},   MR,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x08, REG}},
    {{'\0'},        or,          {NA, rm},   RM,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x0a, REG}},
    {"paddb",       paddb,       {vm, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xfc, REG}},
    {"paddd",       paddd,       {vm, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xfe, REG}},
    {"paddq",       paddq,       {vm, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xd4, REG}},
    {"paddw",       paddw,       {vm, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xfd, REG}},
    {"pand",        pand,        {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xdb, REG}},
    {"pmulhw",      pmulhw,      {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xe5, REG}},
    {"pmulhuw",     pmulhuw,     {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xe4, REG}},
    {"pmulld",      pmulld,      {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  6,  0, {0x66, REX, 0x0f, 0x38, 0x40, REG}},
    {"pmuldq",      pmuldq,      {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  6,  0, {0x66, REX, 0x0f, 0x38, 0x28, REG}},
    {"pmullw",      pmullw,      {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xd5, REG}},
    {"pmuludq",     pmuludq,     {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xf4, REG}},
    {"pop",         pop,         {NA, r },   O,   DATA_TRANSFER,  NA,  1,   NA,  2,  0, {REX, 0x58}},
    {"por",         por,         {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xeb, REG}},
    {"prefetcht0",  prefetcht0,  {r, m},     M,   OTHER,          NA,  NA,  1,   4,  0, {REX,  0x0f, 0x18, REG}},
    {"prefetcht1",  prefetcht1,  {r, m},     M,   OTHER,          NA,  NA,  2,   4,  0, {REX,  0x0f, 0x18, REG}},
    {"prefetcht2",  prefetcht2,  {r, m},     M,   OTHER,          NA,  NA,  3,   4,  0, {REX,  0x0f, 0x18, REG}},
    {"prefetchnta", prefetchnta, {r, m},     M,   OTHER,          NA,  NA,  0,   4,  0, {REX,  0x0f, 0x18, REG}},
    {"psrldq",      psrldq,      {NA, vi},   M,   VECTOR,         NA,  NA,  3,   5,  0, {0x66, REX, 0x0f, 0x73, REG}},
    {"psubb",       psubb,       {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xf8, REG}},
    {"psubd",       psubq,       {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xfa, REG}},
    {"psubq",       psubq,       {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xfb, REG}},
    {"psubw",       psubw,       {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xf9, REG}},
    {"pxor",        pxor,        {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0xef, REG}},
    {"punpcklqdq",  punpcklqdq,  {NA, vv},   RM,  VECTOR,         NA,  NA,  NA,  5,  0, {0x66, REX, 0x0f, 0x6c, REG}},      
    {"push",        push,        {NA, r },   O,   DATA_TRANSFER,  NA,  1,   NA,  2,  0, {REX, 0x50}},
    {"rcr",         rcr,         {mi, ri},   M,   SHIFT,          1,   NA,  3,   3,  0, {REX, 0xd0, REG}},
    {{'\0'},        rcr,         {NA, NA},   M,   SHIFT,          1,   NA,  2,   3,  0, {REX, 0xc1, REG}},
    {"rdtsc",       rdtsc,       {n,  n},    NA,  OTHER,          NA,  NA,  NA,  2,  0, {0x0f, 0x31}},
    {"rdtscp",      rdtscp,      {n,  n},    NA,  OTHER,          NA,  NA,  NA,  3,  0, {0x0f, 0x01, 0xf9}},
    {"ret",         ret,         {n,  n},    NA,  CONTROL_FLOW,   NA,  NA,  NA,  1,  0, {0xc3}},
    {"ror",         ror,         {NA, ri},   M,   SHIFT,          NA,  NA,  1,   3,  0, {REX, 0xd1, REG}},
    {{'\0'},        ror,         {NA, NA},   M,   SHIFT,          NA,  NA,  1,   3,  0, {REX, 0xc1, REG}},
    {"rorx",        rorx,        {rri, rmi}, RM,  OTHER,          NA,  NA,  NA,  5,  0, {0xc4, VEX, 0xfb, 0xf0, REG}},
    {"sar",         sar,         {mi, ri},   M,   SHIFT,          1,   NA,  7,   3,  0, {REX, 0xd0, REG}},
    {{'\0'},        sar,         {NA, NA},   M,   SHIFT,          1,   NA,  7,   3,  0, {REX, 0xc0, REG}},
    {"sarx",        sarx,        {rrr, rmr}, RMV, NEW_VECTOR,     NA,  NA,  NA,  3,  1, {VEX_NEW(NDS,LZ,XF3,X0F38,W0_W1), 0xf7, REG}},
    {"sbb",         sbb,         {rr, mr},   MR,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x18, REG}},
    {{'\0'},        sbb,         {NA, rm},   RM,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x1a, REG}},
    {{'\0'},        sbb,         {mi, ri},   M,   OTHER,          1,   NA,  3,   3,  0, {REX, 0x80, REG}},
    {{'\0'},        sbb,         {NA, NA},   I,   OTHER,          1,   NA,  NA,  2,  0, {REX, 0x1c}},
    {"setc",        setc,        {r,  m},    M,   OTHER,          NA,  NA,  0,   4,  0, {REX, 0x0f, 0x92, REG}},
    {"seto",        seto,        {r,  m},    M,   OTHER,          NA,  NA,  0,   4,  0, {REX, 0x0f, 0x90, REG}},
    {"sfence",      sfence,      {n,  n},    NA,  OTHER,          NA,  NA,  NA,  3,  0, {0x0f, 0xae, 0xf8}},
    {"shl",         shl,         {NA, ri},   M,   SHIFT,          NA,  NA,  4,   3,  0, {REX, 0xd1, REG}},
    {{'\0'},        shl,         {NA, NA},   M,   SHIFT,          NA,  NA,  4,   3,  0, {REX, 0xc1, REG}},
    {"shlx",        shlx,        {rrr, rmr}, RMV, NEW_VECTOR,     NA,  NA,  NA,  3,  2, {VEX_NEW(NDS,LZ,X66,X0F38,W0_W1), 0xf7, REG}},
    {"shr",         shr,         {NA, ri},   M,   SHIFT,          1,   NA,  5,   3,  0, {REX, 0xbe, REG}},
    {{'\0'},        shr,         {NA, NA},   M,   SHIFT,          NA,  NA,  5,   3,  0, {REX, 0xc1, REG}},
    {{'\0'},        shr,         {NA, rr},   M,   SHIFT,          NA,  NA,  5,   3,  0, {REX, 0xd3, REG}},
    {"shrd",        shrd,        {NA, rri},  MR,  OTHER,          2,   NA,  NA,  4,  0, {REX, 0x0f, 0xa9, REG}},
    {"shrx",        shrx,        {rrr, rmr}, RMV, NEW_VECTOR,     NA,  NA,  NA,  3,  0, {VEX_NEW(NDS,LZ,XF2,X0F38,W0_W1), 0xf7, REG}},
    {"sub",         sub,         {rr, mr},   MR,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x28, REG}},
    {{'\0'},        sub,         {NA, rm},   RM,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x2a, REG}},
    {{'\0'},        sub,         {mi, ri},   M,   OTHER,          1,   NA,  5,   3,  0, {REX, 0x80, REG}},
    {{'\0'},        sub,         {NA, NA},   I,   OTHER,          1,   NA,  NA,  2,  0, {REX, 0x2c}},
    {"test",        test,        {rr, mr},   MR,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x84, REG}},

    //{"vaddpd",      vaddpd,      {NA, vvv},  RVM,  VECTOR_AVX,     NA,  NA,  NA,  3,  0, {VEX_NDS_WIG, 0x58, REG}},
    {"vaddpd",      vaddpd,      {NA, vvv},  NA,  VECTOR_AVX,     NA,  NA,  NA,  4,  0, {0xc5, 0xfd, 0x58, 0xd9}},
    {"vmovupd",     vmovupd,     {vm, vv},   RM,  VECTOR_AVX,     NA,  NA,  NA,  3,  0, {VEX_WIG, 0x10, REG}},
    {{'\0'},        vmovupd,     {mv, NA},   MR,  VECTOR_AVX,     NA,  NA,  NA,  3,  0, {VEX_WIG, 0x11, REG}},

    {"xabort",      xabort,      {n,  n},    I,   CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0xc6, 0xf8}},
    {"xbegin",      xbegin,      {n,  n},    NA,  CONTROL_FLOW,   NA,  NA,  NA,  2,  0, {0xc7, 0xf8}},
    {"xchg",        xchg,        {rr, rm},   RM,  DATA_TRANSFER,  1,   NA,  NA,  3,  0, {REX, 0x86, REG}},
    {{'\0'},        xchg,        {NA, NA},   I,   DATA_TRANSFER,  NA,  1,   NA,  2,  0, {REX, 0x90}},
    {"xor",         xor,         {rr, mr},   MR,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x30, REG}},
    {{'\0'},        xor,         {NA, rm},   RM,  OTHER,          1,   NA,  NA,  3,  0, {REX, 0x32, REG}},
    {{'\0'},        xor,         {mi, ri},   M,   OTHER,          1,   NA,  6,   3,  0, {REX, 0x80, REG}},
    {{'\0'},        xor,         {NA, NA},   I,   OTHER,          1,   NA,  NA,  2,  0, {REX, 0x34}},
    {"xend",        xend,        {n,  n},    NA,  CONTROL_FLOW,   NA,  NA,  NA,  3,  0, {0x0f, 0x01, 0xd5}},
    {{'\0'},        NA,          {NA, NA},   NA,  OTHER,          NA,  NA,  NA,  0,  0, {0}}};

int instr_table_index[26] = {NA};
