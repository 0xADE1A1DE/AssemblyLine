## Copyright 2021 University of Adelaide

## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at

##    http://www.apache.org/licenses/LICENSE-2.0

## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.

LDADD = -lassemblyline
AM_LDFLAGS = -L$(top_srcdir)/src
AM_CPPFLAGS = -I$(top_srcdir)/src/
AM_CFLAGS = -Wall -std=gnu99

# runner for 'asm'-tests
ASM_LOG_COMPILER = ./al_nasm_compare.sh
# build this program (takes asm file, uses assemblyline
# to assemble and outputs linewise hex of machinecode)


# add .c -tests here
TEST_C= check_chunk_counting \
		invalid \
		jump \
		memory_reallocation \
		run 
		

TEST_EXTENSIONS = .asm

# add .asm-tests here
TEST_ASM =\
		  adc.asm \
		  adcx.asm \
		  add.asm \
		  adox.asm \
		  and.asm \
		  bzhi.asm \
		  clc.asm \
		  high_low_xmm.asm \
		  imul.asm \
		  lea.asm \
		  mov.asm \
		  movntdqa.asm \
		  movntq.asm \
		  movq.asm \
		  movzx.asm \
		  mov_reg_imm.asm \
		  MOV_REG_IMM.asm \
		  mulx.asm \
		  negative_mem_disp.asm \
		  new_instruction.asm \
		  nop.asm \
		  not.asm \
		  or.asm \
		  paddb.asm \
		  paddd.asm \
		  paddq.asm \
		  paddw.asm \
		  pand.asm \
		  pmuldq.asm \
		  por.asm \
		  prefetch.asm \
		  psubq.asm \
		  pxor.asm \
		  rdtsc.asm \
		  rdtscp.asm \
		  ror.asm \
		  rorx.asm \
		  sarx.asm \
		  sbb.asm \
		  setc.asm \
		  seto.asm \
		  shl.asm \
		  shlx.asm \
		  shr.asm \
		  shrd.asm \
		  shrx.asm \
		  sub.asm \
		  vector_add.asm \
		  vector_float_divide.asm \
		  vector_float_mul.asm \
		  vector_mul.asm \
		  vector_sub.asm \
		  xor.asm \
		  zero_byte_rbp.asm

# if needed, add utility programs, which should be build for the test, to check_PROGRAMS
check_PROGRAMS = asm_to_stdout $(TEST_C)
TESTS = $(TEST_ASM) $(TEST_C)

# maybe this is helpful to create testcases:
# R='rax rbx rcx rdx rdi r8 r9 r10 r11 r12 r13 r14 r15 rsp rsi rbp';
# for a in `echo $R`; do for b in $(echo $R); do for c in $(echo $R); do echo "shlx $a, $b, $c" >> shlx.asm; done ; done; done
#
# R='al cl dl bl spl bpl sil dil r8b r9b r10b r11b r12b r13b r14b r15b';
# for a in `echo $R`; do echo "setc $a" >> setc.asm; done
