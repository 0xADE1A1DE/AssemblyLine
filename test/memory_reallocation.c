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
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_CHUNK_SIZE 0

/**
 * test internal memory reallocation, which happens, when more instructions are
 * being assembled than the internal buffer could store when initially
 * allocated.
 */
int main() {

  // use internal memory allocation
  assemblyline_t al = asm_create_instance(NULL, 0);

  char *long_asm_file_path = {
      "./test/mov.asm"}; // also, this file is very long in itself
  // assemble file multiple times to ensure the internal buffer is exceeded
  for (int i = 0; i <= 1; i++) {
    if (asm_assemble_file(al, long_asm_file_path) == EXIT_FAILURE) {
      fprintf(stderr, "failed to assemble %s\n", long_asm_file_path);
      return EXIT_FAILURE;
    }
  }

  asm_destroy_instance(al);
  return 0;
}
