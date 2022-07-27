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

/*contains register string to asm_reg enum mapping*/
#ifndef REGISTERS_H
#define REGISTERS_H

#include "common.h"
#include "enums.h"

/*stores all string representation of registers along
  with their corresponding generic type*/
struct reg_table {
  // generic register type
  asm_reg gen_reg;
  // list of registers in string format that map to a single generic register
  // type
  char reg_conversion[NUM_OF_REGISTERS][REGISTER_LEN];
};

extern const struct reg_table REG_TABLE[];
#endif
