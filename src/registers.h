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

/*contains register string to asm_reg enum mapping*/
#ifndef REGISTERS_H
#define REGISTERS_H

#include "common.h"
/*stores all string representation of registers along 
  with their corresponding generic type*/
#include "enums.h"
#include <stdint.h>

const static struct {
  // generic register type
  asm_reg gen_reg;
  // list of registers in string format that map to a single generic register type 
  char reg_conversion[NUM_OF_REGISTERS][REGISTER_LEN];

} REG_TABLE[] = {{al,    {"al",   "\0", "ax",   "eax",  "rax",  "\0"   }},             
                 {cl,    {"cl",   "\0", "cx",   "ecx",  "rcx",  "\0"   }},    
                 {dl,    {"dl",   "\0", "dx",   "edx",  "rdx",  "\0"   }},             
                 {bl,    {"bl",   "\0", "bx",   "ebx",  "rbx",  "\0"   }},    
                 {spl,   {"spl",  "ah", "sp",   "esp",  "rsp",  "\0"   }},           
                 {bpl,   {"bpl",  "ch", "bp",   "ebp",  "rbp",  "\0"   }},  
                 {sil,   {"sil",  "dh", "si",   "esi",  "rsi",  "\0"   }},            
                 {dil,   {"dil",  "bh", "di",   "edi",  "rdi",  "\0"   }},  
                 {r8b,   {"r8b",  "\0", "r8w",  "r8d",  "r8",   "\0"   }},           
                 {r9b,   {"r9b",  "\0", "r9w",  "r9d",  "r9",   "\0"   }},    
                 {r10b,  {"r10b", "\0", "r10w", "r10d", "r10",  "\0"   }},       
                 {r11b,  {"r11b", "\0", "r11w", "r11d", "r11",  "\0"   }}, 
                 {r12b,  {"r12b", "\0", "r12w", "r12d", "r12",  "\0"   }},       
                 {r13b,  {"r13b", "\0", "r13w", "r13d", "r13",  "\0"   }}, 
                 {r14b,  {"r14b", "\0", "r14w", "r14d", "r14",  "\0"   }},       
                 {r15b,  {"r15b", "\0", "r15w", "r15d", "r15",  "\0"   }}, 
                 {mm0,   {"\0",   "\0", "\0",   "\0",   "mm0",  "xmm0" }},           
                 {mm1,   {"\0",   "\0", "\0",   "\0",   "mm1",  "xmm1" }}, 
                 {mm2,   {"\0",   "\0", "\0",   "\0",   "mm2",  "xmm2" }},           
                 {mm3,   {"\0",   "\0", "\0",   "\0",   "mm3",  "xmm3" }},   
                 {mm4,   {"\0",   "\0", "\0",   "\0",   "mm4",  "xmm4" }},           
                 {mm5,   {"\0",   "\0", "\0",   "\0",   "mm5",  "xmm5" }}, 
                 {mm6,   {"\0",   "\0", "\0",   "\0",   "mm6",  "xmm6" }},           
                 {mm7,   {"\0",   "\0", "\0",   "\0",   "mm7",  "xmm7" }},
                 {mm8,   {"\0",   "\0", "\0",   "\0",   "\0",   "xmm8" }},           
                 {mm9,   {"\0",   "\0", "\0",   "\0",   "\0",   "xmm9" }}, 
                 {mm10,  {"\0",   "\0", "\0",   "\0",   "\0",   "xmm10"}},           
                 {mm11,  {"\0",   "\0", "\0",   "\0",   "\0",   "xmm11"}},   
                 {mm12,  {"\0",   "\0", "\0",   "\0",   "\0",   "xmm12"}},           
                 {mm13,  {"\0",   "\0", "\0",   "\0",   "\0",   "xmm13"}}, 
                 {mm14,  {"\0",   "\0", "\0",   "\0",   "\0",   "xmm14"}},           
                 {mm15,  {"\0",   "\0", "\0",   "\0",   "\0",   "xmm15"}},
                 {reg_error, {{'\0'}}}};

#endif