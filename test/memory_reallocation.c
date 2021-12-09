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

/*test internal memory reallocation*/
#include <assemblyline.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_CHUNK_SIZE 0

int main(int argc, char **argv) {

  // use internal memory allocation
  assemblyline_t al = asm_create_instance(NULL, 0);

  // assemble file twice to ensure the internal buffer is exceeded
  if (assemble_file(al, "mov.asm") == EXIT_FAILURE) {
    fprintf(stderr, "failed to assemble %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  if (assemble_file(al, "mov.asm") == EXIT_FAILURE) {
    fprintf(stderr, "failed to assemble %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  asm_destroy_instance(al);
  return 0;
}