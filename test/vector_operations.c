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

#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3

int execute_test(void (*exe)(double *, double *, double *), int type) {

  double A[] = {1.0, 2.0, 3.0, 4.0};
  double B[] = {1.0, 2.0, 3.0, 4.0};
  double C[] = {1.0, 1.0, 1.0, 1.0};
  exe(A, B, C);
  switch (type) {
  case ADD:
    for (int it = 0; it < 4; it++)
      if (C[it] != A[it] + B[it])
        return EXIT_FAILURE;
    break;
  case SUB:
    for (int it = 0; it < 4; it++)
      if (C[it] != A[it] - B[it])
        return EXIT_FAILURE;
    break;
  case MUL:
    for (int it = 0; it < 4; it++)
      if (C[it] != A[it] * B[it])
        return EXIT_FAILURE;
    break;
  case DIV:
    for (int it = 0; it < 4; it++)
      if (C[it] != A[it] / B[it])
        return EXIT_FAILURE;
    break;
  default:
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

int main(int argc, char **argv) {

  const char *add_ymm = "vmovupd ymm0, [rdi]\n"
                        "vmovupd ymm1, [rsi]\n"
                        "vaddpd ymm3, ymm0, ymm1\n"
                        "vmovupd [rdx], ymm3\n"
                        "ret\n";

  const char *sub_ymm = "vmovupd ymm0, [rdi]\n"
                        "vmovupd ymm1, [rsi]\n"
                        "vsubpd ymm3, ymm0, ymm1\n"
                        "vmovupd [rdx], ymm3\n"
                        "ret\n";

  const char *mul_ymm = "vmovupd ymm0, [rdi]\n"
                        "vmovupd ymm1, [rsi]\n"
                        "vmulpd ymm3, ymm0, ymm1\n"
                        "vmovupd [rdx], ymm3\n"
                        "ret\n";

  const char *div_ymm = "vmovupd ymm0, [rdi]\n"
                        "vmovupd ymm1, [rsi]\n"
                        "vdivpd ymm3, ymm0, ymm1\n"
                        "vmovupd [rdx], ymm3\n"
                        "ret\n";

  assemblyline_t al = asm_create_instance(NULL, 0);
  if (assemble_str(al, add_ymm) == EXIT_FAILURE)
    return EXIT_FAILURE;

  // type cast to function pointer
  void (*test_op)(double *A, double *B, double *C) = asm_get_code(al);

  if (execute_test(test_op, ADD)) {
    fprintf(stderr, "ADD did not produce expected results\n");
    return EXIT_FAILURE;
  }
  // clear previous test
  asm_set_offset(al, 0);

  if (assemble_str(al, sub_ymm) == EXIT_FAILURE)
    return EXIT_FAILURE;

  test_op = asm_get_code(al);

  if (execute_test(test_op, SUB)) {
    fprintf(stderr, "SUBTRACT did not produce expected results\n");
    return EXIT_FAILURE;
  }

  // clear previous test
  asm_set_offset(al, 0);

  if (assemble_str(al, mul_ymm) == EXIT_FAILURE)
    return EXIT_FAILURE;

  test_op = asm_get_code(al);

  if (execute_test(test_op, MUL)) {
    fprintf(stderr, "MULTIPLY did not produce expected results\n");
    return EXIT_FAILURE;
  }

  // clear previous test
  asm_set_offset(al, 0);

  if (assemble_str(al, div_ymm) == EXIT_FAILURE)
    return EXIT_FAILURE;

  test_op = asm_get_code(al);

  if (execute_test(test_op, DIV)) {
    fprintf(stderr, "DIVIDE did not produce expected results\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}