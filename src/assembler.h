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

/*defines functions for assembling intel x86 instructions*/
#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "common.h"
#include "instruction_data.h"
#include <inttypes.h>

/**
 * writes nop instruction with length @param nop_pad_len at pointer location
 * @param buff
 */
unsigned int nop_padding(uint8_t *buf, unsigned int nop_pad_len);

/**
 * assembles the prefix, opcode, memory displacement, and immediate of a
 * @param instruc at pointer location @param ptr
 */
unsigned int assemble_asm(struct instr *instruc, uint8_t *dest);

#endif
