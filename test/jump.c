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

/*executes 3 assembly programs to test the jump instruction*/
#include <assemblyline.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// expected return value
#define RET_S "0x123"
#define RADIX 16

int main() {

  const char *short_jmp = "mov rcx, " RET_S "\n"
                          "jmp short 0x4\n"
                          "add rcx, 1\n"
                          "mov rax, rcx\n"
                          "ret";

  const char *long_jmp = "mov rcx, " RET_S "\n"
                         "jmp long 0x4\n"
                         "add rcx, 1\n"
                         "mov rax, rcx\n"
                         "ret";

  const char *std_jmp = "mov rcx, " RET_S "\n"
                        "jmp 0x4\n"
                        "add rcx, 1\n"
                        "mov rax, rcx\n"
                        "ret";

  // init AL
  assemblyline_t al = asm_create_instance(NULL, 0);
  long ret = strtol(RET_S, NULL, RADIX);
  long (*func)() = NULL;

  // test short jump
  asm_set_offset(al, 0);
  if (asm_assemble_str(al, short_jmp) == EXIT_FAILURE)
    return EXIT_FAILURE;

  func = asm_get_code(al);
  if (func() != ret)
    return EXIT_FAILURE;

  // test long jump
  asm_set_offset(al, 0);
  if (asm_assemble_str(al, long_jmp) == EXIT_FAILURE)
    return EXIT_FAILURE;

  func = asm_get_code(al);
  if (func() != ret)
    return EXIT_FAILURE;

  // test std jump
  asm_set_offset(al, 0);
  if (asm_assemble_str(al, std_jmp) == EXIT_FAILURE)
    return EXIT_FAILURE;

  func = asm_get_code(al);
  if (func() != ret)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
