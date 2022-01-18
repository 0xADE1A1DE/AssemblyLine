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

/*defines an interface between the calling function and the assembler*/
#ifndef ASSEMBLYLINE_H
#define ASSEMBLYLINE_H

#include "enums.h"
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
typedef struct assemblyline *assemblyline_t;

/**
 * allocates an instance of assemblyline_t and attaches a pointer to a memory
 * buffer @param buffer where machine code will be written to. Buffer length
 * will be specified by @param len.
 * NOTE: @param buffer could also be set to NULL for internal memory memory
 * allocation. In this case @param len would be irrelevant and could be set to
 * any number.
 */
assemblyline_t asm_create_instance(uint8_t *buffer, int len);

/**
 * frees all memory associated with @param instance
 */
int asm_destroy_instance(assemblyline_t instance);

/**
 * assembles the given string @param assembly_str containing valid x64 assembly
 * code with instance @param al It writes the corresponding machine code to the
 * memory location specified by al->buffer.
 * (DEPRECATED: use asm_assemble_str() instead)
 */
int __attribute__((deprecated("use asm_assemble_str instead")))
assemble_str(assemblyline_t al, const char *assembly_str);

/**
 * assembles the given string @param assembly_str containing valid x64 assembly
 * code with instance @param al It writes the corresponding machine code to the
 * memory location specified by al->buffer.
 */
int asm_assemble_str(assemblyline_t al, const char *assembly_str);

/**
 * assembles the given file path @param asm_file containing valid x64 assembly
 * code with instance @param al It writes the corresponding machine code to the
 * memory location specified by al->buffer.
 * (DEPRECATED: use asm_assemble_file() instead)
 */
int __attribute__((deprecated("use asm_assemble_file instead")))
assemble_file(assemblyline_t al, char *asm_file);

/**
 * assembles the given file path @param asm_file containing valid x64 assembly
 * code with instance @param al It writes the corresponding machine code to the
 * memory location specified by al->buffer.
 */
int asm_assemble_file(assemblyline_t al, char *asm_file);

/**
 * assembles the given null-terminated @param string with instance @param al.
 * It counts the number of instructions that break the chunk boundary of size
 * @param chunk_size and saves it to @param dest It does not nop-pad
 * necessarily, depends on the @param al instance (you can nop-pad and count
 * different chunk breaks).
 * NOTE: you cannot pass const char* as @param string, it will segfault, because
 * string will be altered.
 * (DEPRECATED: use asm_assemble_string_counting_chunks() instead)
 */
int __attribute__((
    deprecated("use asm_assemble_string_counting_chunks instead")))
assemble_string_counting_chunks(assemblyline_t al, char *string, int chunk_size,
                                int *dest);

/**
 * assembles the given null-terminated @param string with instance @param al.
 * It counts the number of instructions that break the chunk boundary of size
 * @param chunk_size and saves it to @param dest It does not nop-pad
 * necessarily, depends on the @param al instance (you can nop-pad and count
 * different chunk breaks).
 * NOTE: you cannot pass const char* as @param string, it will segfault, because
 * string will be altered.
 */
int asm_assemble_string_counting_chunks(assemblyline_t al, char *string,
                                        int chunk_size, int *dest);

/**
 * sets a given chunk size boundary @param chunk_size in bytes with instance
 * @param al. When called before assemble_str() or assemble_file() assemblyline
 * will ensure no instruction opcode will cross the specified  @param chunk_size
 * boundary via nop padding.
 * NOTE: @param chunk_size must be greater than 2 in order to
 * be classified as a valid memory chunk boundary
 */
void asm_set_chunk_size(assemblyline_t al, size_t chunk_size);

/**
 * set debug flag @param debug to true or false with instance @param al. When is
 * set @param debug to true machine code represented in hexidecimal will be
 * printed to stdout.
 */
void asm_set_debug(assemblyline_t al, bool debug);

/**
 * returns the offset associated with @param al
 */
int asm_get_offset(assemblyline_t al);

/**
 * sets a memory offset @param offset to specify exact location in memory block
 * for writting machine code with instance @param al.
 * NOTE: @param offset could be set to 0 for the resulting memory block.
 */
void asm_set_offset(assemblyline_t al, int offset);

/**
 * returns the buffer associated with @param al
 * (DEPRECATED: use asm_get_code() instead)
 */
uint8_t __attribute__((deprecated("use asm_get_code instead"))) *
    asm_get_buffer(assemblyline_t al);

/**
 * returns the buffer associated with @param al as type void* for easy
 * typecasting to any function pointer format.
 */
void *asm_get_code(assemblyline_t al);

/**
 * Nasm optimizes a `mov rax, IMM` to `mov eax, imm`, iff imm is <= 0x7fffffff
 * for all destination registers. The following three methods allow the user to
 * specify this behavior.
 */

/**
 * disables nasm-style mov-immediate register-size optimization.
 * ex: even if immediate size for mov is less than or equal to max signed 32 bit
 * assemblyline will pad the immediate to fit 64bit.
 * That is:
 * "mov rax, 0x7fffffff" as "mov rax, 0x000000007fffffff"
 * -> 48 b8 ff ff ff 7f 00 00 00 00
 */
void strict_mov_imm_handling(assemblyline_t al);

/**
 * enables nasm-style mov-immediate register-size optimization.
 * ex: if immediate size for mov is less than or equal to max signed 32 bit
 * assemblyline will emit code to mov to eax rather than rax.
 * That is: "mov rax, 0x7fffffff" as "mov eax, 0x7fffffff"
 * -> b8 ff ff ff 7f
 */
void nasm_mov_imm_handling(assemblyline_t al);

/**
 * With this setting, Assemblyline will check the immediate value for leading
 * 0's and thus allows manual optimizations. This is currently set as default.
 * ex:
 * "mov rax, 0x000000007fffffff" ->  48 b8 ff ff ff 7f 00 00 00 00
 * "mov rax, 0x7fffffff" -> b8 ff ff ff 7f
 */
void smart_mov_imm_handling(assemblyline_t al);

int asm_mov_imm(assemblyline_t al, int option);

#endif
