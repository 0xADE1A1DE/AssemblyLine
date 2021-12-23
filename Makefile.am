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

EXTRA_DIST =
ACLOCAL_AMFLAGS = -I m4 --install
AM_CFLAGS = -Wall -std=gnu99
AM_CPPFLAGS = -I./src
CLEANFILES = config.h~ \
			 configure~ \
			 assemblyline-*.tar.gz

distclean-local:
	rm -rf autom4te.cache/

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
							 src/tokenizer.c \
							 src/tokenizer.h

include_HEADERS = src/assemblyline.h


oudated = \
		 libassemblyline.so.1.0.4 \
		 libassemblyline.so.1.0.3 \
		 libassemblyline.so.1.0.2 \
		 libassemblyline.so.1.0.1 \
		 libassemblyline.so.1.0.0 

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
libassemblyline_la_LDFLAGS = -version-info 1:5:0

##############################################################################################
##############################################################################################
###############################      BINS       ##############################################
##############################################################################################
##############################################################################################

bin_PROGRAMS = tools/asmline
LDADD = libassemblyline.la

##############################################################################################
##############################################################################################
###############################      MANS       ##############################################
##############################################################################################
##############################################################################################

methods = \
		 asm_create_instance.3 \
		 asm_destroy_instance.3 \
		 assemble_str.3 \
		 assemble_file.3 \
		 assemble_string_counting_chunks.3 \
		 asm_set_chunk_size.3 \
		 asm_set_debug.3 \
		 asm_get_offset.3 \
		 asm_set_offset.3 \
		 asm_get_buffer.3 \
		 asm_get_code.3 \
		 strict_mov_imm_handling.3 \
		 nasm_mov_imm_handling.3 \
		 smart_mov_imm_handling.3

#todo move that to man-dir
dist_man1_MANS = tools/asmline.1
dist_man3_MANS = src/libassemblyline.3 


install-exec-hook:
	cd $(libdir) && \
	rm -f -- $(oudated) && \
	cd $(mandir)/man3 && \
	rm -f -- $(methods) && \
	$(LN_S) libassemblyline.3 asm_create_instance.3 && \
	$(LN_S) libassemblyline.3 asm_destroy_instance.3 && \
	$(LN_S) libassemblyline.3 assemble_str.3 && \
	$(LN_S) libassemblyline.3 assemble_file.3 && \
	$(LN_S) libassemblyline.3 assemble_string_counting_chunks.3 && \
	$(LN_S) libassemblyline.3 asm_set_chunk_size.3 && \
	$(LN_S) libassemblyline.3 asm_set_debug.3 && \
	$(LN_S) libassemblyline.3 asm_get_offset.3 && \
	$(LN_S) libassemblyline.3 asm_set_offset.3 && \
	$(LN_S) libassemblyline.3 asm_get_buffer.3 && \
	$(LN_S) libassemblyline.3 asm_get_code.3 && \
	$(LN_S) libassemblyline.3 strict_mov_imm_handling.3 && \
	$(LN_S) libassemblyline.3 nasm_mov_imm_handling.3 && \
	$(LN_S) libassemblyline.3 smart_mov_imm_handling.3

uninstall-local:
	cd $(mandir)/man3 && \
	rm -f -- $(methods) 

##############################################################################################
##############################################################################################
###############################      TEST       ##############################################
##############################################################################################
##############################################################################################

# runner for 'asm'-tests
ASM_LOG_COMPILER = ./test/al_nasm_compare.sh
# build this program (takes asm file, uses assemblyline
# to assemble and outputs linewise hex of machinecode)


# add .c -tests here
TEST_C= \
		test/check_chunk_counting \
		test/invalid \
		test/jump \
		test/memory_reallocation \
		test/optimization_disabled \
		test/run \
		test/vector_operations

TEST_EXTENSIONS = .asm

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
		  test/high_low_xmm.asm \
		  test/imul.asm \
		  test/lea.asm \
		  test/mov.asm \
		  test/mov_reg_imm.asm \
		  test/mov_reg_imm32.asm \
		  test/movd.asm \
		  test/movntdqa.asm \
		  test/movntq.asm \
		  test/movq.asm \
		  test/movzx.asm \
		  test/mulx.asm \
		  test/negative_mem_disp.asm \
		  test/new_instruction.asm \
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
		  test/pxor.asm \
		  test/rdtsc.asm \
		  test/rdtscp.asm \
		  test/ror.asm \
		  test/rorx.asm \
		  test/sarx.asm \
		  test/sbb.asm \
		  test/setc.asm \
		  test/seto.asm \
		  test/shl.asm \
		  test/shld.asm \
		  test/shlx.asm \
		  test/shr.asm \
		  test/shrd.asm \
		  test/shrx.asm \
		  test/sub.asm \
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
		  test/xor.asm \
		  test/zero_byte_rbp.asm

# if needed, add utility programs, which should be build for the test, to check_PROGRAMS
check_PROGRAMS = $(bin_PROGRAMS) $(TEST_C)

TESTS = $(TEST_ASM) $(TEST_C)

