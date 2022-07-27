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

/*defines functions for determining prefix opcode
based on instruction operands*/
#ifndef PREFIX_H
#define PREFIX_H

#include "common.h"
#include "enums.h"
#include "instruction_data.h"

/**
 * takes in 2 operands @param m @param r, as well as a pointer to @param instr
 * and returns the rex prefix value.
 */
unsigned int get_rex_prefix(struct instr *all_instr, struct operand *m,
                            struct operand *r);

/**
 * returns the register opcode given the operand at @param m and @param r
 * position given and instance of @param instrc
 */
uint8_t get_reg(struct instr *instrc, struct operand *m, int r);

/**
 * takes in 3 operands @param s, @param m, and @param r, and returns the rex
 * prefix value. note: used for "reg, [reg+reg]" syntax
 */
unsigned int get_mem_prefix(asm_reg s, asm_reg m, asm_reg r);

#endif
