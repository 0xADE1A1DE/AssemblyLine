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

#include <assemblyline.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * This file contains invalid string, on which assemblyline must fail to
 * assemble.
 */
const char *const testStrings[] = {
    "mov [rax],[rbx]; cannot mov mem to mem",
    "shrd rax, [rsp], 9; arg2 must be a register.",
    "invalid rax,1",
    "lea rax, [rsp+*4*r14*4]; invalid memory syntax",
    "lea rax, [rsp+*r14 ; invalid memory syntax",
    "lea rax, [rsp+r14*9] ; invalid memory syntax",
    "lea rax, [rsp+42*r14] ; invalid memory syntax",
    "lea rax, [rsp+rsp] ; invalid memory syntax",
    "lea rax, [esp+esp] ; invalid memory syntax",
    "lea rax, [rbp+4*rsp] ; invalid memory syntax",
    "lea rax, [r12+2*rsp] ; invalid memory syntax"};

// test invalid instructions with option
int test_invalid(assemblyline_t al, enum asm_opt option) {

  asm_set_all(al, option);

  for (size_t i = 0; i < sizeof(testStrings) / sizeof(testStrings[0]); i++) {

    char const *str = testStrings[i];

    if (asm_assemble_str(al, str) != EXIT_FAILURE) {
      fprintf(stderr,
              "should have failed to assemble '%s' and return code '%d' \n",
              str, EXIT_FAILURE);
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
  if (argc > 1) {
    fprintf(stderr,
            "\nUSAGE:\n\t%s"
            "\n\nDESCRIPTION:\n\t"
            "tests a predefined list of invalid instructions. If assemblyline "
            "does not return EXIT_FAILURE, this program '%s' exits 1.\n",
            argv[0], argv[0]);
    return 1;
  }

  assemblyline_t al = asm_create_instance(NULL, 0);

  if (test_invalid(al, NASM))
    return EXIT_FAILURE;

  if (test_invalid(al, STRICT))
    return EXIT_FAILURE;

  if (test_invalid(al, SMART))
    return EXIT_FAILURE;

  asm_destroy_instance(al);
  return 0;
}
