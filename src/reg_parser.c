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

/*implements reg_parser.h*/
#include "reg_parser.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_add_mem(char *mem, bool *neg, int *base) {
  // find the index of the memory displacement followed by '+' or '-' character
  for (int i = 1; i < strlen(mem); i++) {
    if (mem[i] == '-' && IN_RANGE(mem[i + 1], '0', '9'))
      *neg = true;
    // memory displacement represented in hex
    if (mem[i] == '0' && (mem[i - 1] == '-' || mem[i - 1] == '+')) {
      if (mem[i + 1] == 'x')
        return i;
      // memory displacement represented in decimal
    } else if (IN_RANGE(mem[i], '1', '9') &&
               (mem[i - 1] == '-' || mem[i - 1] == '+')) {
      if (mem[i - 1] == '-' || mem[i - 1] == '+') {
        if (mem[i + 1] != 'x') {
          *base = 10;
          return i;
        }
      }
    }
  }
  return NA;
}

uint32_t process_neg_disp(uint32_t neg_num) {
  // convert neg_num to negative 2's complement representation
  uint32_t new_disp = ~neg_num + 1;
  if (neg_num < 0x81)
    new_disp &= 0xff;
  return new_disp;
}

int get_opcode_offset(asm_reg reg_value) {

  unsigned int index = reg_value & MODE_MASK;
  if (IN_RANGE(index, reg16, ext64))
    return 1;
  else
    return none;
}

void get_reg_str(char *opd_str, char *reg) {

  int j = 0;
  // copies the register from mem to reg ex: "rax ," -> "rax"
  for (int i = 0; i < strlen(opd_str); i++) {
    if (j > 0 && IN_RANGE(opd_str[i], 'a', 'z'))
      reg[j++] = opd_str[i];
    else if (j > 0 && IN_RANGE(opd_str[i], '0', '9'))
      reg[j++] = opd_str[i];
    else if (j > 0)
      return;
    if (j < 1 && IN_RANGE(opd_str[i], 'a', 'z'))
      reg[j++] = opd_str[i];
    if (j > 4)
      return;
  }
}

void get_second_reg(char *mem, char *reg) {

  int i;
  bool plus = false;
  // copies the register from mem to reg ex: "[rax+0x16]" -> "rax"
  for (i = 0; i < strlen(mem); i++) {
    if (plus && IN_RANGE(mem[i], 'a', 'z')) {
      int j = i;
      int k = 0;
      while (((IN_RANGE(mem[j], 'a', 'x')) || (IN_RANGE(mem[j], '0', '9'))) &&
             k < 5)
        reg[k++] = mem[j++];
      return;
    }
    if (mem[i] == '+')
      plus = true;
    else if (mem[i] != ' ')
      plus = false;
  }
}

char get_operand_type(char *operand) {

  int i = 0;
  // skip empty space
  while (operand[i] == ' ')
    i++;
  // the starting character of each operand note the type
  if (operand[i] == '[')
    return 'm';
  if (operand[i] >= 'a' && operand[i] <= 's')
    return 'r';
  if (operand[i] >= 'x' && operand[i] <= 'z')
    return 'v';
  if (operand[i] >= '0' && operand[i] <= '9')
    return 'i';
  if (operand[i] >= '-')
    return 'i';
  else
    return 'e';
}

asm_reg find_reg(int row, const int col, char *reg_str) {
  // match reg_str to REG_TABLE reg_conversion entry
  while (REG_TABLE[row].reg_conversion[col][0] != '\0') {
    if (!strcmp(reg_str, REG_TABLE[row].reg_conversion[col]))
      return REG_TABLE[row].gen_reg;
    row++;
  }
  fprintf(stderr, "assembyline: %s register not found\n", reg_str);
  return reg_error;
}

asm_reg str_to_reg(char *reg) {
  // the operand does not exit or is an immediate
  if (reg[0] == '\0')
    return reg_none;
  unsigned int end = strlen(reg) - 1;
  // 64 bit register
  if (reg[0] == 'r') {
    if (IN_RANGE(reg[1], 'a', 'z'))
      return reg64 | find_reg(0, 4, reg);
    if (IN_RANGE(reg[1], '0', '9') && reg[end] == 'd')
      return ext32 | find_reg(8, 3, reg);
    if (IN_RANGE(reg[1], '0', '9') && reg[end] == 'w')
      return ext16 | find_reg(8, 2, reg);
    if (IN_RANGE(reg[1], '0', '9') && reg[end] == 'b')
      return ext8 | find_reg(8, 0, reg);
    else
      return ext64 | find_reg(8, 4, reg);
    // vector registers
  } else if (reg[0] == 'm') {
    return mmx64 | find_reg(16, 4, reg);
  } else if (reg[0] == 'x') {
    return mmx64 | find_reg(16, 5, reg);
  } else if (reg[0] == 'y') {
    return mmx64 | find_reg(16, 6, reg);
    // 64 bit register
  } else if (reg[0] == 'e') {
    return reg32 | find_reg(0, 3, reg);
  }
  // 16-8 bit register
  else {
    if (reg[end] == 'l')
      return reg8 | find_reg(0, 0, reg);
    if (reg[end] == 'h')
      return noext8 | find_reg(4, 1, reg);
    return reg16 | find_reg(0, 2, reg);
  }
  return reg_error;
}
