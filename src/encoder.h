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

/*defines functions for encoding x86 assembly instruction prefix, register, and
 immediate opcode*/
#ifndef ENCODER_H
#define ENCODER_H

#include "common.h"
#include "instruction_data.h"

/**
 * determines opcode offset of @param instruc for  different register size
 */
void encode_offset(struct instr *instruc);

/**
 * determines register and prefix opcode of @param instruc
 */
int encode_operands(struct instr *instruc);

/**
 * preprocess the immediate for @param instruc
 */
void encode_imm(struct instr *instruc);

#endif
