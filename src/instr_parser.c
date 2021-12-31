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
#include "common.h"
#include "instruction_data.h"
#include "instructions.h"
#include <string.h>

operand_format get_opd_format(char *opd_en) {

  int i = NA;
  if (opd_en[0] != '\0')
    i = opd_format_table_index[opd_en[0] - 'a'] - 1;
  // find the correct operand format enum given the corresponding string
  while (OPD_FORMAT_TABLE[++i].val != opd_error) {
    if (!strcasecmp(opd_en, OPD_FORMAT_TABLE[i].str))
      return OPD_FORMAT_TABLE[i].val;
  }
  // operand format not found
  fprintf(stderr, "unknown operand format: \"%s\"\n", opd_en);
  return opd_error;
}

int str_to_instr_key(char *instruction, operand_format opd_layout) {

  int i = 0;
  // set index of INSTR_TABLE[] to the first letter of instruction
  if (IN_RANGE(instruction[0], 'a', 'z'))
    i = instr_table_index[instruction[0] - 'a'] - 1;
  else
    return INSTR_ERROR;
  // search for instruction entry in INSTR_TABLE[]
  while (INSTR_TABLE[++i].name != NA) {
    if (INSTR_TABLE[i].instr_name[0] != '\0') {
      // compare intruction strings
      if (!strcmp(instruction, INSTR_TABLE[i].instr_name)) {
        asm_instr found_instr = INSTR_TABLE[i].name;
        while (INSTR_TABLE[i].name == found_instr) {
          // compare operand formats
          if (INSTR_TABLE[i].opd_format[0] == opd_layout)
            return i;
          else if (INSTR_TABLE[i].opd_format[1] == opd_layout)
            return i;
          i++;
        }
        // operand format is not found for instruction string
        return INSTR_ERROR;
      }
    }
  }
  // INSTR_TABLE entry is not found for instruction string
  return INSTR_ERROR;
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
