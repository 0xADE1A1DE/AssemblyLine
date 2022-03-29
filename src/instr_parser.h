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

/*defines functions for parsing x86 assembly instruction as a string*/
#ifndef INSTR_PARSER_H
#define INSTR_PARSER_H

#include "enums.h"

/**
 * takes an operanding format string representation @param opd_en and returns
 * the corresponding enum operand_format
 */
operand_format get_opd_format(char *opd_en);

/**
 * takes a string representation of an instruction name @param instruction and
 * an operand_format enum representation @param opd_index and returns the index
 * key to the matching INSTR_TABLE[] entry.
 */
int str_to_instr_key(char *instruction, operand_format opd_layout);

#endif
