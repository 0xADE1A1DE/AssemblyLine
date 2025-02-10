## Copyright 2022 University of Adelaide

## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at

##    http://www.apache.org/licenses/LICENSE-2.0

## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.

# to tell pkg-config what to place where
pkgconfig_DATA = assemblyline.pc
pkgconfigdir = $(libdir)/pkgconfig

ACLOCAL_AMFLAGS = -I m4 --install
AM_CFLAGS = -Wall -Wextra -std=gnu99
AM_CPPFLAGS = -I./src
CLEANFILES = assemblyline-*.tar.gz \
			 config.h~ \
			 configure~

##############################################################################################
##############################################################################################
###############################      LIB        ##############################################
##############################################################################################
##############################################################################################

lib_LTLIBRARIES = libassemblyline.la
libassemblyline_la_SOURCES = \
							 src/assembler.c \
							 src/assembler.h \
							 src/assemblyline.c \
							 src/common.h \
							 src/encoder.c \
							 src/encoder.h \
							 src/enums.h \
							 src/instr_parser.c \
							 src/instr_parser.h \
							 src/instruction_data.h \
							 src/instructions.c \
							 src/instructions.h \
							 src/parser.c \
							 src/parser.h \
							 src/prefix.c \
							 src/prefix.h \
							 src/reg_parser.c \
							 src/reg_parser.h \
							 src/registers.h \
							 src/registers.c \
							 src/tokenizer.c \
							 src/tokenizer.h

include_HEADERS = src/assemblyline.h


# from  7.3 https://www.gnu.org/software/libtool/manual/html_node/Versioning.html#Versioning
# -version-info accepts ‘current[:revision[:age]]’

# 1. If the library SOURCE CODE has changed at all  since the last update:                    revision++       
# 2. If ANY INTERFACES have been ADDED              since the last public release: current++, revision=0, age++.
# 3. If ANY INTERFACES have been REMOVED or CHANGED since the last public release: current++, revision=0, age=0.

# Hints
# 1. Programs using the previous version may use the new version as drop-in replacement, and programs using the new version can also work with the previous one. In other words, no recompiling nor relinking is needed. In this case, bump revision only, don’t touch current nor age.
# 2. Programs using the previous version may use the new version as drop-in replacement, but programs using the new version may use APIs not present in the previous one. In other words, a program linking against the new version may fail with “unresolved symbols” if linking against the old version at runtime: set revision to 0, bump current and age.
# 3. Programs may need to be changed, recompiled, and relinked in order to use the new version. Bump current, set revision and age to 0.

# in short, if only patch from configure.ac is bumped, bump the middle number below. If more is changed, read the above
libassemblyline_la_LDFLAGS = -version-info 4:0:3
##############################################################################################
##############################################################################################
###############################      BINS       ##############################################
##############################################################################################
##############################################################################################

bin_PROGRAMS = tools/asmline
LDADD = libassemblyline.la

# completion --start--
if ENABLE_BASH_COMPLETION
bashcompletiondir = $(BASH_COMPLETION_DIR)
dist_bashcompletion_DATA = data/completion/asmline
endif
if ENABLE_ZSH_COMPLETION
zshcompletiondir = $(ZSH_COMPLETION_DIR)
dist_zshcompletion_DATA = data/completion/_asmline
endif
# completion --end--

##############################################################################################
##############################################################################################
###############################      MANS       ##############################################
##############################################################################################
##############################################################################################

link_man = \
		   man/asm_create_instance.3 \
		   man/asm_destroy_instance.3 \
		   man/asm_assemble_str.3 \
		   man/asm_assemble_file.3 \
		   man/asm_assemble_string_counting_chunks.3 \
		   man/asm_set_chunk_size.3 \
		   man/asm_set_debug.3 \
		   man/asm_get_offset.3 \
		   man/asm_set_offset.3 \
		   man/asm_get_buffer.3 \
		   man/asm_get_code.3 \
		   man/asm_create_bin_file.3 \
		   man/asm_mov_imm.3 \
		   man/asm_sib_index_base_swap.3 \
		   man/asm_set_all.3

$(link_man): man/libassemblyline.3
	test -e $@ || $(LN_S) libassemblyline.3 $@

dist_man1_MANS = man/asmline.1
dist_man3_MANS = man/libassemblyline.3 $(link_man)

##############################################################################################
##############################################################################################
###############################      TEST       ##############################################
##############################################################################################
##############################################################################################

# runner for 'asm'-tests
TEST_EXTENSIONS = .asm
ASM_LOG_COMPILER = ./test/al_nasm_compare.sh

# get the tap-driver
TEST_EXTENSIONS += .tap
TAP_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) \
                  $(top_srcdir)/build-aux/tap-driver.sh
TAP_LOG_COMPILER = ./test/tap/compiler.sh

# add TAP tests here
TEST_TAP = \
		test/tap/call.tap \
		test/tap/cmp.tap \
		test/tap/imul.tap \
		test/tap/lea.tap \
		test/tap/misc.tap \
		test/tap/movq.tap \
		test/tap/nasm_incompatible.tap \
		test/tap/vmovupd.tap \
		test/tap/vmovdqu.tap \
		test/tap/xor.tap

# those are the tests, where asmline is expected to fail, for the suite to be ok.
# eaf stands for 'expected asmline to fail'
TEST_EXTENSIONS += .eaf
EAF_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) \
                  $(top_srcdir)/build-aux/tap-driver.sh

EAF_LOG_COMPILER = ./test/tap/compiler.sh --no-nasm
TEST_EAF = \
		test/eaf/imul.eaf \
		test/eaf/misc.eaf


# In case you want a test to fail for the suite to pass, add the test here
XFAIL_TESTS= $(TEST_EAF) \
		test/tap/nasm_incompatible.tap

# add SH-tests here
TEST_SH = test/tools/asmline.sh \
		  test/tools/asmlineP.sh


# add .c -tests here
TEST_C= \
		test/check_chunk_counting \
		test/invalid \
		test/jump \
		test/memory_reallocation \
		test/optimization_disabled \
		test/run \
		test/vector_operations

# add .asm-tests here
TEST_ASM = \
		  test/MOV_REG_IMM.asm \
		  test/adc.asm \
		  test/adcx.asm \
		  test/add.asm \
		  test/adox.asm \
		  test/and.asm \
		  test/bextr.asm \
		  test/bzhi.asm \
		  test/clc.asm \
		  test/clflush.asm \
		  test/cmp.asm \
		  test/cpuid.asm \
		  test/high_low_xmm.asm \
		  test/imul.asm \
		  test/jmp.asm \
		  test/lea.asm \
		  test/lea_no_base.asm \
		  test/mov.asm \
		  test/mov_reg_imm.asm \
		  test/mov_reg_imm32.asm \
		  test/movd.asm \
		  test/movntdqa.asm \
		  test/movntq.asm \
		  test/movq.asm \
		  test/movzx.asm \
		  test/mul.asm \
		  test/mulx.asm \
		  test/neg.asm \
		  test/negative_mem_disp.asm \
		  test/no_ptr.asm \
		  test/no_operand.asm \
		  test/nop.asm \
		  test/not.asm \
		  test/or.asm \
		  test/paddb.asm \
		  test/paddd.asm \
		  test/paddq.asm \
		  test/paddw.asm \
		  test/pand.asm \
		  test/pmuldq.asm \
		  test/pmulhuw.asm \
		  test/pmulhw.asm \
		  test/pmulld.asm \
		  test/pmullq.asm \
		  test/pmullw.asm \
		  test/pmuludq.asm \
		  test/por.asm \
		  test/prefetch.asm \
		  test/psubb.asm \
		  test/psubd.asm \
		  test/psubq.asm \
		  test/psubw.asm \
		  test/ptr.asm \
		  test/push.asm \
		  test/pxor.asm \
		  test/rdpmc.asm \
		  test/rdtsc.asm \
		  test/rdtscp.asm \
		  test/ror.asm \
		  test/rorx.asm \
		  test/sal.asm \
		  test/sar.asm \
		  test/sarx.asm \
		  test/sbb.asm \
		  test/setc.asm \
		  test/setcc.asm \
		  test/seto.asm \
		  test/shl.asm \
		  test/shld.asm \
		  test/shlx.asm \
		  test/shr.asm \
		  test/shrd.asm \
		  test/shrx.asm \
		  test/sub.asm \
		  test/test.asm \
		  test/vaddpd.asm \
		  test/vector_add.asm \
		  test/vector_add_mem.asm \
		  test/vector_float_divide.asm \
		  test/vector_float_mul.asm \
		  test/vector_mul.asm \
		  test/vector_sub.asm \
		  test/vmovupd.asm \
		  test/vperm2i128.asm \
		  test/vsubpd.asm \
		  test/xabort.asm \
		  test/xchg.asm \
		  test/xor.asm \
		  test/zero_byte_rbp.asm

# if needed, add utility programs, which should be build for the test, to check_PROGRAMS
check_PROGRAMS = $(bin_PROGRAMS) $(TEST_C)

TESTS = $(TEST_EAF) $(TEST_TAP) $(TEST_SH) $(TEST_ASM) $(TEST_C)
