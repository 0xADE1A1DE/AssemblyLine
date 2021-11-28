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

/*executes assembly program represented as a string*/
#include <assemblyline.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

int execute_test(void (*exe)(double *, double *, double *)) {

  double A[] = {1.0, 2.0, 3.0, 4.0};
  double B[] = {1.0, 2.0, 3.0, 4.0};
  double C[] = {1.0, 1.0, 1.0, 1.0};
  exe(A, B, C);
  for (int it = 0; it < 4; it++) {
    if (C[it] != A[it] + B[it])
      return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

int main(int argc, char **argv) {

  const char *add_xmm = "vmovupd ymm0, [rdi]\n"
                        "vmovupd ymm1, [rsi]\n"
                        "vaddpd ymm3, ymm0, ymm1\n"
                        "vmovupd [rdx], ymm3\n"
                        "ret\n";
 
  assemblyline_t asm_exe = asm_create_instance(NULL, 0);
  if (assemble_str(asm_exe, add_xmm) == EXIT_FAILURE)
    return EXIT_FAILURE;

  // type cast to function pointer
  void (*test_add)(double * A, double * B, double * C) =
      (void (*)(double *, double *, double *))(asm_get_code(asm_exe));
      
  if (execute_test(test_add)) {
    fprintf(stderr, "test_add.asm did not produce expected results\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}