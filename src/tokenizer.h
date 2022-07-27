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

/*defines functions for tokenizing string representation of x86 assembly
 * instructions*/
#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "common.h"
#include "instruction_data.h"

/**
 * Given an instance of @param instr_buffer, tokenize @param comp_instr string
 * and maps instruction componenets to buffer fields within @param instr_buffer
 */
int instr_tok(struct instr *instr_buffer, char *comp_instr);

#endif
