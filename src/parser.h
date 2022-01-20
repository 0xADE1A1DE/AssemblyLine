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

/*defines functions for parsing x86 assembly instructions as a string*/
#ifndef PARSER_H
#define PARSER_H

#include "assemblyline.h"
#include "common.h"
#include "instruction_data.h"
#include "instructions.h"

/**
 * assemble given a @param str contaning the the
 * string representation of a x64 assembly program and writes the corresponding
 * machine code into the buffer field of @param al. Also counts the number of
 * chunks break in the buffer and stores in @param dest (if applicable)
 */
int assemble_all(assemblyline_t al, const char *str, int *dest);

#endif
