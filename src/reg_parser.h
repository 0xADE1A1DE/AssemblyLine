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

/*defines functions for parsing x86 assembly registers as a string*/
#ifndef REG_PARSER_H
#define REG_PARSER_H

#include "enums.h"
#include "instruction_data.h"
#include "registers.h"
#include <inttypes.h>
#include <stdbool.h>

/**
 * returns an opcode offset based on the value of @param reg_value
 */
int get_opcode_offset(struct instr *instrc);

/**
 * finds the register in @param str and copies the characters to @param reg
 * ex: "[rax+0x8]" or "rax ," -> "rax"
 */
void get_reg_str(char *opd_str, char *reg);

/**
 * converts @param neg_num to is negative 2's complement representation and
 * return the value
 */
uint32_t process_neg_disp(uint32_t neg_num);

/**
 * finds the index register in @param mem and copies characters to @param reg
 * ex: "[rax+rbp]" -> "rbp"
 */
unsigned int get_index_reg(struct instr *instruc, const char *mem, char reg[]);

/**
 * finds the addition sign in @param mem and returns the index of memory
 * displacement as well as determining its base its sign(+ or -)
 */
int find_add_mem(char *mem, bool *neg, int *base);

int find_mem_const(char *mem, bool *neg, int *base);

/**
 * determines operand type of @param operand, returns 'r' for register, 'm' for
 * memory reference, and 'i' immediate.
 */
char get_operand_type(const char *operand);

/**
 * takes a string representation of a register @param reg and return the
 * corresponding enum representation
 */
asm_reg str_to_reg(char *reg);

#endif
