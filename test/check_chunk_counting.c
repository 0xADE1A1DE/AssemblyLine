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

/**
 * Test the functionality of assemblyline for counting the number
 * of instructions that break a specified chunk size set for the
 * memory block
 */
#include <assemblyline.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct test_struct {
  int expected_breaks;
  int break_size;
  const char *asm_string;
};

int main() {
  // as those values are the expected number of chunk breaks we can
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  int expected_breaks[] = {8, 8, 16, 16};

  struct test_struct tests[] = {
      {
          .expected_breaks = 0,
          .break_size = expected_breaks[0],
          .asm_string = "mov rax, [rsi]\n" // 3 bytes
                        "inc rax\n"        // 3 bytes
                        "clc\n"            // 1 byte
                        "clc\n"            // 1 byte
                                           // chunk ends here. (@8)
                        "mov [rdi], rax\n" // 3 bytes,
                        "ret",             // 1 bytes
      },
      {
          .expected_breaks = 1,
          .break_size = expected_breaks[1],
          .asm_string = "mov rax, [rsi]\n" // 3 bytes
                        "inc rax\n"        // 3 bytes
                        "mov [rdi], rax\n" // 3 bytes, chunk break here (@8)
                        "ret"              // 1 bytes
      },
      {
          .expected_breaks = 0,
          .break_size = expected_breaks[2],
          .asm_string = "mov rax, [rsi]\n" // 3 bytes
                        "inc rax\n"        // 3 bytes (6)
                        "mov [rdi], rax\n" // 3 bytes,(10)
                        "ret"              // 1 byte (11)
      },
      {
          .expected_breaks = 3,
          .break_size = expected_breaks[3],
          .asm_string = "mov rax, [rsi]\n"     // 3 bytes
                        "inc rax\n"            // 3 bytes (6)
                        "clc\n"                // 1 byte (7)
                        "mov [rdi], rax\n"     // 3 bytes,(10)
                        "inc rax\n"            // 3 bytes(13)
                        "clc\n"                // 1 byte(14)
                        "inc rax\n"            // 3 bytes(17) first break (@16)
                        "mulx r8, r9, [rsi]\n" // 5 bytes(22)
                        "clc\n"                // 1 byte(23)
                        "clc\n"                // 1 byte(24)
                        "mulx r8, r9, [rsi]\n" // 5 bytes(29)
                        "mulx r8, r9, [rsi]\n" // 5 bytes(34) second break (@32)
                        "mulx r8, r9, [rsi]\n" // 5 bytes(39)
                        "mulx r9, r10, [rsi]\n" // 5 bytes(44)
                        "mulx r9, r8, [rsi]\n"  // 5 bytes(49) third break (@48)
                        "ret"                   // 1bytes
      }};

  int result = 0;
  int num_testcases = sizeof(tests) / sizeof(struct test_struct);
  printf("testing %u cases.\n", num_testcases);

  for (int i = 0; i < num_testcases; i++) {
    struct test_struct t = tests[i];

    int counted = -1;
    int nop_chunksize = 0;
    uint8_t *buffer = NULL;

    assemblyline_t al = asm_create_instance(buffer, nop_chunksize);
    asm_set_debug(al, true);

    // HEY YOU, YEAH YOU! DONT YOU DARE REMOVE THE COPY HERE!
    size_t len = strlen(t.asm_string) + 1;
    char *string_modifylable = malloc(len);
    strncpy(string_modifylable, t.asm_string, len);
    // LOOK. in the test array above, the asm_string is const.
    // the asm_assemble_string_counting_chunks requires a changeable string.
    // It'll segfault, if the passed pointer points to the datasegment.

    if (asm_assemble_string_counting_chunks(al, string_modifylable,
                                            t.break_size, &counted)) {
      printf("failed to assemble.\n");
      result |= 1;
    }
    if (counted != t.expected_breaks) {
      printf("did count %d instead of %d; this fails the test.\n", counted,
             t.expected_breaks);
      result |= 1;
    } else {
      printf("did count %d which is what I'd expect. nice.\n", counted);
    }

    // cleanup
    asm_destroy_instance(al);
    free(string_modifylable);
  }
  return result;
}
