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

/*executes 3 assembly programs to test the jump instruction*/
#include <assemblyline.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    const char *short_jmp =
    "mov rcx, 0x123\n"
    "jmp short 0x4\n"
    "add rcx, 1\n"
    "mov rax, rcx\n"
    "ret";

    const char *long_jmp =
    "mov rcx, 0x123\n"
    "jmp long 0x4\n"
    "add rcx, 1\n"
    "mov rax, rcx\n"
    "ret";

    const char *std_jmp =
    "mov rcx, 0x123\n"
    "jmp 0x4\n"
    "add rcx, 1\n"
    "mov rax, rcx\n"
    "ret";

    assemblyline_t asm_exe = asm_create_instance(NULL, 0);
    if (assemble_str(asm_exe, short_jmp) == EXIT_FAILURE) 
        return EXIT_FAILURE; 

    int (*funcA)() = asm_get_code(asm_exe);
    if(funcA() != 0x123)
        return EXIT_FAILURE; 

    asm_set_offset(asm_exe, 0);

    if (assemble_str(asm_exe, long_jmp) == EXIT_FAILURE) 
        return EXIT_FAILURE; 

    int (*funcB)() = asm_get_code(asm_exe);
    if(funcB() != 0x123)
        return EXIT_FAILURE; 

    asm_set_offset(asm_exe, 0);

    if (assemble_str(asm_exe, std_jmp) == EXIT_FAILURE) 
        return EXIT_FAILURE; 

    int (*funcC)() = asm_get_code(asm_exe);
    if(funcC() != 0x123)
        return EXIT_FAILURE; 


    return 0;
}