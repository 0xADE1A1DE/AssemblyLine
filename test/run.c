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

/*executes 2 assembly programs represented as a string*/
#include <assemblyline.h>
#include <errno.h>
#include <signal.h> //  sigaction
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

// if a test return 77, autotools considers it as a skipped test.
#define SKIP 77

// Bit position of flag from cpuid, according to intel manual
#define ADX 19
#define BMI2 8

/**
 * @returns 1 if the bit is set
 */
static int check_ise_bit(int bit_no) {
  // EAX value for getting the ISE's from cpu id is 07h
  int r = 0;
  int checkBit = 1 << bit_no;

  asm volatile("mov $7, %%eax \n\t"
               "mov $0, %%ecx \n\t"
               "cpuid\n\t"
               "and %%ebx, %[bit]\n\t"
               "mov %%ebx, %[ret]\n\t"
               : [ret] "=&m"(r)
               : [bit] "m"(checkBit)
               : "rax", "rbx", "rcx", "rdx");
  return r;
};

// the cpuid trick does not work (reliably) on the GH-CI. So we will need to use
// the SIGILL handler. Which needs a pointer to a function.
void exit_skip() { exit(SKIP); }

// expected results
const uint64_t expected_out[] = {0x165651D83282, 0x18883C3EA80B, 0x1EDBDFE96957,
                                 0x238587B25BAC3, 0x182355AC294};
const size_t arg_len = sizeof(expected_out) / sizeof(expected_out[0]);

int execute_test(void (*exe)(uint64_t *, uint64_t *, ...)) {

  // NOLINTNEXTLINE
  uint64_t in[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xDEADBEEF};
  uint64_t out[] = {0, 0, 0, 0, 0};
  exe(out, in);

  for (size_t it = 0; it < arg_len; it++) {
    if (out[it] != expected_out[it])
      return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

int main() {
  if (!check_ise_bit(BMI2) || !check_ise_bit(ADX))
    exit_skip();
  // Catch sigill and exit with 77
  struct sigaction sa;
  sa.sa_sigaction = &exit_skip;
  sigaction(SIGILL, &sa, NULL);

  const char *cur_B =
      "sub rsp, 0x80 \n"
      "mov [ rsp + 0x48 ], rbx; saving to stack\n"
      "mov [ rsp + 0x50 ], rbp; saving to stack\n"
      "mov [ rsp + 0x58 ], r12; saving to stack\n"
      "mov [ rsp + 0x60 ], r13; saving to stack\n"
      "mov [ rsp + 0x68 ], r14; saving to stack\n"
      "mov [ rsp + 0x70 ], r15; saving to stack\n"
      "imul r11, [ rsi + 0x20 ], 0x13; x1 <- arg1[4] * 0x13\n"
      "mov rdx, [ rsi + 0x0 ]; arg1[0] to rdx\n"
      "mulx r15, rax, [ rsi + 0x0 ]; x38, x37<- arg1[0] * arg1[0]\n"
      "imul r13, [ rsi + 0x18 ], 0x13; x4 <- arg1[3] * 0x13\n"
      "imul rbx, r13, 0x2; x5 <- x4 * 0x2\n"
      "imul rcx, r11, 0x2; x2 <- x1 * 0x2\n"
      "mov rdx, [ rsi + 0x8 ]; arg1[1] to rdx\n"
      "mulx rbp, r8, rcx; x22, x21<- arg1[1] * x2\n"
      "mov rdx, [ rsi + 0x10 ]; arg1[2] to rdx\n"
      "mulx r12, r14, rcx; x16, x15<- arg1[2] * x2\n"
      "mov rdx, [ rsi + 0x10 ]; arg1[2] to rdx\n"
      "mulx rbx, r10, rbx; x18, x17<- arg1[2] * x5\n"
      "test al, al\n"
      "adox r8, r10\n"
      "seto dl; spill OF x40 to reg (rdx)\n"
      "imul r9, [ rsi + 0x10 ], 0x2; x7 <- arg1[2] * 0x2\n"
      "mov r10b, dl; preserving value of x40 into a new reg\n"
      "mov rdx, [ rsi + 0x8 ]; saving arg1[1] in rdx.\n"
      "mov [ rsp + 0x0 ], r9; spilling x7 to mem\n"
      "mov [ rsp + 0x8 ], rdi; spilling out1 to mem\n"
      "mulx r9, rdi, [ rsi + 0x8 ]; x28, x27<- arg1[1] * arg1[1]\n"
      "mov rdx, rcx; x2 to rdx\n"
      "mulx rdx, rcx, [ rsi + 0x18 ]; x12, x11<- arg1[3] * x2\n"
      "mov [ rsp + 0x10 ], r15; spilling x38 to mem\n"
      "mov r15, rdx; preserving value of x12 into a new reg\n"
      "mov rdx, [ rsi + 0x18 ]; saving arg1[3] in rdx.\n"
      "mov byte [ rsp + 0x18 ], r10b; spilling byte x40 to mem\n"
      "mulx r13, r10, r13; x14, x13<- arg1[3] * x4\n"
      "mov rdx, [ rsp + 0x0 ]; x7 to rdx\n"
      "mov [ rsp + 0x20 ], r13; spilling x14 to mem\n"
      "mov [ rsp + 0x28 ], r15; spilling x12 to mem\n"
      "mulx r13, r15, [ rsi + 0x0 ]; x34, x33<- arg1[0] * x7\n"
      "sar byte [ rsp + 0x18 ], 1\n"
      "adcx rbp, rbx\n"
      "imul rbx, [ rsi + 0x8 ], 0x2; x8 <- arg1[1] * 0x2\n"
      "mov [ rsp + 0x30 ], r10; spilling x13 to mem\n"
      "mov r10, rdx; preserving value of x7 into a new reg\n"
      "mov rdx, [ rsi + 0x0 ]; saving arg1[0] in rdx.\n"
      "mov [ rsp + 0x38 ], r15; spilling x33 to mem\n"
      "mulx rbx, r15, rbx; x36, x35<- arg1[0] * x8\n"
      "mov rdx, [ rsp + 0x30 ]; x73, copying x13 here, cause x13 is needed in "
      "a reg for other than x73, namely all: , x73--x74, size: 1\n"
      "add rdx, r14; could be done better, if r0 has been u8 as well\n"
      "mov r14, 0x0 ; moving imm to reg\n"
      "dec r14; OF<-0x0, preserve CF 3\n"
      "adox rax, r8\n"
      "adcx r12, [ rsp + 0x20 ]\n"
      "clc;\n"
      "adcx r15, rdx\n"
      "adox rbp, [ rsp + 0x10 ]\n"
      "mov r8, 0x7ffffffffffff ; moving imm to reg\n"
      "setc dl; spill CF x78 to reg (rdx)\n"
      "mov r14, rax; x48, copying x43 here, cause x43 is needed in a reg for "
      "other than x48, namely all: , x47, x48, size: 2\n"
      "and r14, r8; x48 <- x43& 0x7ffffffffffff\n"
      "shrd rax, rbp, 51; x47 <- x45||x43 >> 51\n"
      "add rax, r15; could be done better, if r0 has been u8 as well\n"
      "mov r15, 0x0 ; moving imm to reg\n"
      "dec r15; OF<-0x0, preserve CF 3\n"
      "adox rdi, rcx\n"
      "adox r9, [ rsp + 0x28 ]\n"
      "movzx rdx, dl\n"
      "lea rbx, [ rbx + r12 ]\n"
      "lea rbx, [ rbx + rdx ]\n"
      "adc rbx, 0x0\n"
      "mov rdx, [ rsi + 0x20 ]; arg1[4] to rdx\n"
      "mulx r11, rcx, r11; x10, x9<- arg1[4] * x1\n"
      "mov r12, rax; x84, copying x81 here, cause x81 is needed in a reg for "
      "other than x84, namely all: , x84, x85, size: 2\n"
      "shrd r12, rbx, 51; x84 <- x83||x81 >> 51\n"
      "imul rbp, [ rsi + 0x18 ], 0x2; x6 <- arg1[3] * 0x2\n"
      "mov rbx, [ rsp + 0x38 ]; x69, copying x33 here, cause x33 is needed in "
      "a reg for other than x69, namely all: , x69--x70, size: 1\n"
      "add rbx, rdi; could be done better, if r0 has been u8 as well\n"
      "adcx r13, r9\n"
      "mov rdx, [ rsi + 0x8 ]; arg1[1] to rdx\n"
      "mulx rdi, r9, rbp; x24, x23<- arg1[1] * x6\n"
      "mov rdx, r10; x7 to rdx\n"
      "mulx rdx, r10, [ rsi + 0x8 ]; x26, x25<- arg1[1] * x7\n"
      "add r12, rbx; could be done better, if r0 has been u8 as well\n"
      "adc r13, 0x0\n"
      "imul rbx, [ rsi + 0x20 ], 0x2; x3 <- arg1[4] * 0x2\n"
      "mov r8, r12; x89, copying x86 here, cause x86 is needed in a reg for "
      "other than x89, namely all: , x89, x90, size: 2\n"
      "shrd r8, r13, 51; x89 <- x88||x86 >> 51\n"
      "mov r13, rdx; preserving value of x26 into a new reg\n"
      "mov rdx, [ rsi + 0x10 ]; saving arg1[2] in rdx.\n"
      "mov [ rsp + 0x40 ], r12; spilling x86 to mem\n"
      "mulx r15, r12, [ rsi + 0x10 ]; x20, x19<- arg1[2] * arg1[2]\n"
      "xor rdx, rdx\n"
      "adox r10, rcx\n"
      "adox r13, r11\n"
      "adcx r9, r12\n"
      "mov r11, rdx; preserving value of 0x0 into a new reg\n"
      "mov rdx, [ rsi + 0x0 ]; saving arg1[0] in rdx.\n"
      "mulx rbp, rcx, rbp; x32, x31<- arg1[0] * x6\n"
      "mov rdx, [ rsi + 0x0 ]; arg1[0] to rdx\n"
      "mulx rbx, rdx, rbx; x30, x29<- arg1[0] * x3\n"
      "adcx rdi, r15\n"
      "test al, al\n"
      "adox rdx, r9\n"
      "adcx rcx, r10\n"
      "adcx rbp, r13\n"
      "clc;\n"
      "adcx r8, rcx\n"
      "adox rbx, rdi\n"
      "adc rbp, 0x0\n"
      "mov r15, r8; x94, copying x91 here, cause x91 is needed in a reg for "
      "other than x94, namely all: , x94, x95, size: 2\n"
      "shrd r15, rbp, 51; x94 <- x93||x91 >> 51\n"
      "test al, al\n"
      "adox r15, rdx\n"
      "adox rbx, r11\n"
      "mov r12, r15; x99, copying x96 here, cause x96 is needed in a reg for "
      "other than x99, namely all: , x100, x99, size: 2\n"
      "shrd r12, rbx, 51; x99 <- x98||x96 >> 51\n"
      "imul r12, r12, 0x13; x101 <- x99 * 0x13\n"
      "mov r10, 0x7ffffffffffff ; moving imm to reg\n"
      "and r15, r10; x100 <- x96& 0x7ffffffffffff\n"
      "mov r13, [ rsp + 0x40 ]; x90, copying x86 here, cause x86 is needed in "
      "a reg for other than x90, namely all: , x90, size: 1\n"
      "and r13, r10; x90 <- x86& 0x7ffffffffffff\n"
      "lea r14, [ r14 + r12 ]\n"
      "and rax, r10; x85 <- x81& 0x7ffffffffffff\n"
      "mov r9, r14; x104, copying x102 here, cause x102 is needed in a reg for "
      "other than x104, namely all: , x103, x104, size: 2\n"
      "and r9, r10; x104 <- x102& 0x7ffffffffffff\n"
      "shr r14, 51; x103 <- x102>> 51\n"
      "lea r14, [ r14 + rax ]\n"
      "mov rdi, [ rsp + 0x8 ]; load m64 out1 to register64\n"
      "mov [ rdi + 0x0 ], r9; out1[0] = x104\n"
      "mov [ rdi + 0x20 ], r15; out1[4] = x100\n"
      "mov rdx, r14; x107, copying x105 here, cause x105 is needed in a reg "
      "for other than x107, namely all: , x106, x107, size: 2\n"
      "and rdx, r10; x107 <- x105& 0x7ffffffffffff\n"
      "shr r14, 51; x106 <- x105>> 51\n"
      "LABEL2:\n"
      "lea r14, [ r14 + r13 ]\n"
      "mov [ rdi + 0x8 ], rdx; out1[1] = x107\n"
      "and r8, r10; x95 <- x91& 0x7ffffffffffff\n"
      "mov [ rdi + 0x18 ], r8; out1[3] = x95\n"
      "mov [ rdi + 0x10 ], r14; out1[2] = x108\n"
      "mov rbx, [ rsp + 0x48 ]; restoring from stack\n"
      "mov rbp, [ rsp + 0x50 ]; restoring from stack\n"
      "mov r12, [ rsp + 0x58 ]; restoring from stack\n"
      "mov r13, [ rsp + 0x60 ]; restoring from stack\n"
      "mov r14, [ rsp + 0x68 ]; restoring from stack\n"
      "mov r15, [ rsp + 0x70 ]; restoring from stack\n"
      "add rsp, 0x80 \n"
      "ret\n";

  const char *function_B = "sub rsp, 0x48 \n"
                           "mov [ rsp + 0x10 ], rbx\n"
                           "mov [ rsp + 0x18 ], rbp\n"
                           "mov [ rsp + 0x20 ], r12\n"
                           "mov [ rsp + 0x28 ], r13\n"
                           "mov [ rsp + 0x30 ], r14\n"
                           "mov [ rsp + 0x38 ], r15\n"
                           "mov rdx, [ rsi + 0x0 ]\n"
                           "mulx r8, rbx, [ rsi + 0x0 ]\n"
                           "imul r10, [ rsi + 0x18 ], 0x13\n"
                           "imul r15, [ rsi + 0x20 ], 0x13\n"
                           "imul rcx, r10, 0x2\n"
                           "imul r13, r15, 0x2\n"
                           "mov rdx, [ rsi + 0x10 ]\n"
                           "mulx rcx, rax, rcx\n"
                           "mov rdx, r13\n"
                           "mulx rbp, r9, [ rsi + 0x8 ]\n"
                           "test al, al\n"
                           "adox r9, rax\n"
                           "seto r11b\n"
                           "imul r12, [ rsi + 0x8 ], 0x2\n"
                           "mov r13, rdx\n"
                           "mov rdx, [ rsi + 0x0 ]\n"
                           "mulx r12, r14, r12\n"
                           "mov rdx, [ rsi + 0x10 ]\n"
                           "mov [ rsp + 0x0 ], rdi\n"
                           "mulx rax, rdi, r13\n"
                           "mov rdx, r10\n"
                           "mulx rdx, r10, [ rsi + 0x18 ]\n"
                           "sar  r11b, 1\n"
                           "adcx rbp, rcx\n"
                           "adox rbx, r9\n"
                           "adox r8, rbp\n"
                           "add rdi, r10\n"
                           "setc cl\n"
                           "mov r9, rbx\n"
                           "shrd r9, r8, 51\n"
                           "xor r11, r11\n"
                           "adox r14, rdi\n"
                           "mov r10, rdx\n"
                           "mov rdx, [ rsi + 0x18 ]\n"
                           "mulx r13, rbp, r13\n"
                           "adcx r9, r14\n"
                           "movzx rcx, cl\n"
                           "lea rax, [ rax + r10 ]\n"
                           "lea rax, [ rax + rcx ]\n"
                           "setc r10b\n"
                           "seto r8b\n"
                           "imul rdi, [ rsi + 0x10 ], 0x2\n"
                           "sar  r8b, 1\n"
                           "adcx r12, rax\n"
                           "mov rdx, [ rsi + 0x0 ]\n"
                           "mulx rcx, r14, rdi\n"
                           "mov rdx, [ rsi + 0x8 ]\n"
                           "mulx r8, rax, [ rsi + 0x8 ]\n"
                           "movzx r11, r10b\n"
                           "lea r11, [ r11 + r12 ]\n"
                           "mov r10, r9\n"
                           "shrd r10, r11, 51\n"
                           "add rax, rbp\n"
                           "mov rbp, -0x1 \n"
                           "inc rbp\n"
                           "adox r14, rax\n"
                           "mov rdx, r15\n"
                           "mulx rdx, r15, [ rsi + 0x20 ]\n"
                           "adcx r8, r13\n"
                           "mov r13, rdx\n"
                           "mov rdx, [ rsi + 0x8 ]\n"
                           "mulx rdi, r12, rdi\n"
                           "seto r11b\n"
                           "imul rax, [ rsi + 0x18 ], 0x2\n"
                           "sar  r11b, 1\n"
                           "adcx rcx, r8\n"
                           "adox r10, r14\n"
                           "adox rcx, rbp\n"
                           "mov r14, r10\n"
                           "shrd r14, rcx, 51\n"
                           "imul r11, [ rsi + 0x20 ], 0x2\n"
                           "mov rdx, [ rsi + 0x0 ]\n"
                           "mulx r8, rcx, rax\n"
                           "xor rdx, rdx\n"
                           "adox r12, r15\n"
                           "xchg rdx, r11\n"
                           "mulx rdx, rbp, [ rsi + 0x0 ]\n"
                           "mov r15, rdx\n"
                           "mov rdx, [ rsi + 0x10 ]\n"
                           "mov [ rsp + 0x8 ], r9\n"
                           "mulx r11, r9, [ rsi + 0x10 ]\n"
                           "adcx rcx, r12\n"
                           "adox rdi, r13\n"
                           "adcx r8, rdi\n"
                           "test al, al\n"
                           "adox r14, rcx\n"
                           "mov r13, 0x0 \n"
                           "adox r8, r13\n"
                           "mov rdx, [ rsi + 0x8 ]\n"
                           "mulx rax, r12, rax\n"
                           "adcx r12, r9\n"
                           "setc r9b\n"
                           "mov rcx, r14\n"
                           "shrd rcx, r8, 51\n"
                           "add rbp, r12\n"
                           "dec r13\n"
                           "adox rcx, rbp\n"
                           "movzx r9, r9b\n"
                           "lea rax, [ rax + r11 ]\n"
                           "lea rax, [ rax + r9 ]\n"
                           "adcx r15, rax\n"
                           "mov r11, 0x0 \n"
                           "adox r15, r11\n"
                           "mov rdi, 0x7ffffffffffff \n"
                           "and rbx, rdi\n"
                           "mov r8, [ rsp + 0x8 ]\n"
                           "and r8, rdi\n"
                           "mov r12, rcx\n"
                           "shrd r12, r15, 51\n"
                           "imul r12, r12, 0x13\n"
                           "lea rbx, [ rbx + r12 ]\n"
                           "mov r9, rbx\n"
                           "shr r9, 51\n"
                           "and rcx, rdi\n"
                           "lea r9, [ r9 + r8 ]\n"
                           "mov rbp, r9\n"
                           "shr rbp, 51\n"
                           "and r10, rdi\n"
                           "and rbx, rdi\n"
                           "mov rax, [ rsp + 0x0 ]\n"
                           "mov [ rax + 0x0 ], rbx\n"
                           "and r9, rdi\n"
                           "mov [ rax + 0x20 ], rcx\n"
                           "lea rbp, [ rbp + r10 ]\n"
                           "mov [ rax + 0x10 ], rbp\n"
                           "mov [ rax + 0x8 ], r9\n"
                           "and r14, rdi\n"
                           "mov [ rax + 0x18 ], r14\n"
                           "mov rbx, [ rsp + 0x10 ]\n"
                           "mov rbp, [ rsp + 0x18 ]\n"
                           "mov r12, [ rsp + 0x20 ]\n"
                           "mov r13, [ rsp + 0x28 ]\n"
                           "mov r14, [ rsp + 0x30 ]\n"
                           "mov r15, [ rsp + 0x38 ]\n"
                           "add rsp, 0x48 \n"
                           "ret\n";

  assemblyline_t al = asm_create_instance(NULL, 0);
  if (asm_assemble_str(al, cur_B) == EXIT_FAILURE)
    return EXIT_FAILURE;

  void (*curB)(uint64_t * out, uint64_t * in0, ...) = asm_get_code(al);

  if (execute_test(curB)) {
    fprintf(stderr, "cur_B.asm did not produce expected results\n");
    return 1;
  }
  asm_set_offset(al, 0);

  if (asm_assemble_str(al, function_B) == EXIT_FAILURE)
    return EXIT_FAILURE;

  void (*funcB)(uint64_t * out, uint64_t * in0, ...) = asm_get_code(al);

  if (execute_test(funcB)) {
    fprintf(stderr, "function_B.asm did not produce expected results\n");
    return 1;
  }
  asm_set_offset(al, 0);
  const int chunk_size = 9;
  asm_set_chunk_size(al, chunk_size);

  if (asm_assemble_str(al, cur_B) == EXIT_FAILURE)
    return EXIT_FAILURE;

  void (*curB_w_chunk)(uint64_t * out, uint64_t * in0, ...) = asm_get_code(al);

  if (execute_test(curB_w_chunk)) {
    fprintf(stderr,
            "cur_B.asm with chunk fitting did not produce expected results\n");
    return 1;
  }
  asm_set_offset(al, 0);

  const int bufsize = 6000;
  uint8_t *buffer =
      mmap(NULL, sizeof(uint8_t) * bufsize, PROT_READ | PROT_WRITE | PROT_EXEC,
           MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
  if (buffer == MAP_FAILED) { // NOLINT
    fprintf(stderr, "failed to allocate internal memory buffer: %s\n",
            strerror(errno));
    return EXIT_FAILURE;
  }

  // use asemblyline with external buffer
  assemblyline_t al_buffer = asm_create_instance(buffer, bufsize);
  if (asm_assemble_str(al_buffer, cur_B) == EXIT_FAILURE)
    return EXIT_FAILURE;

  void (*curB_buffer)(uint64_t * out, uint64_t * in0, ...) =
      asm_get_code(al_buffer);

  if (execute_test(curB_buffer)) {
    fprintf(stderr, "cur_B.asm did not produce expected results\n");
    return 1;
  }

  return 0;
}
