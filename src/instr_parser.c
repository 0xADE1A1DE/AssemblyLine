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

/*implements functions for parsing instruction name
 and operand format of instruction*/
#include "instr_parser.h"
#include "instruction_data.h"
#include "instructions.h"
#include <stdio.h>
#include <string.h>

operand_format get_opd_format(char *opd_en) {

  int i = NA;
  // find the correct operand format enum given the corresponding string
  while (OPD_FORMAT_TABLE[++i].val != opd_error) {
    if (strcmp(opd_en, OPD_FORMAT_TABLE[i].str) == 0)
      return OPD_FORMAT_TABLE[i].val;
  }
  // operand format not found
  fprintf(stderr, "unknown operand format: \"%s\"\n", opd_en);
  return opd_error;
}

int str_to_instr_key(char *instruction, operand_format opd_index) {

  int i = instr_table_index[instruction[0] - 'a'] - 1;
  while (INSTR_TABLE[++i].name != NA) {
    if (INSTR_TABLE[i].instr_name[0] != '\0') {
      // compare intruction strings
      if (strcmp(instruction, INSTR_TABLE[i].instr_name) == 0) {
        asm_instr found_instr = INSTR_TABLE[i].name;
        while (INSTR_TABLE[i].name == found_instr) {
          // compare operand formats
          if (INSTR_TABLE[i].opd_format[0] == opd_index)
            return i;
          else if (INSTR_TABLE[i].opd_format[1] == opd_index)
            return i;
          i++;
        }
        // operand format not found
        return EOI;
      }
    }
  }
  return EOI;
}

int to_special_instr_key(int key) {
  // converts special instructions to their corresponding key
  switch (INSTR_TABLE[key].name) {
  case sub:
  case sbb:
  case add:
  case adc:
  case xor:
    if (INSTR_TABLE[key].encode_operand == M)
      return key + 1;
  default:
    return EOI;
  }
}
