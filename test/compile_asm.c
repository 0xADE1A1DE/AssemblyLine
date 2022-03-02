#include <assemblyline.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

///
/// The code to evaluate for comparison
///
#define CODE                                                                                                           \
    "vaddpd ymm0, ymm0, ymm0;\n"                                                                                       \
    "vaddpd ymm0, ymm0, ymm1;\n"                                                                                       \
    "vaddpd ymm0, ymm0, ymm2;\n"                                                                                       \
    "vaddpd ymm0, ymm0, ymm3;\n"                                                                                       \
    "vperm2i128 ymm0, ymm0, [rax], 0xff;\n"                                                                            \
    "vperm2i128 ymm0, ymm0, [rbx], 0xff;\n"                                                                            \
    "vperm2i128 ymm0, ymm0, [rcx], 0xff;\n"                                                                            \
    "vperm2i128 ymm0, ymm0, [rdx], 0xff;\n"                                                                            \
    "vperm2i128 ymm0, ymm0, [rdi], 0xff;\n"                                                                            \
    "vperm2i128 ymm0, ymm0, [r8], 0xff;\n"                                                                             \
    "vperm2i128 ymm0, ymm0, [r9], 0xff;\n"                                                                             \
    "vperm2i128 ymm0, ymm0, [r10], 0xff;\n"                                                                            \
    "vperm2i128 ymm0, ymm0, [r11], 0xff;\n"                                                                            \
    "vperm2i128 ymm0, ymm0, [r12], 0xff;\n"                                                                            \
    "vperm2i128 ymm0, ymm0, [r13], 0xff;\n"                                                                            \
    "sub al, 0x0;\n"                                                                                                   \
    "sub ax, 0xe1;\n"                                                                                                  \
    "sub eax, 0xe11;\n"                                                                                                \
    "sub ax, 0xe2;\n"                                                                                                  \
    "sub eax, 0xeff;\n"                                                                                                \
    "sub ax, 0xe0;\n"                                                                                                  \
    "sub sil, 0x0;\n"                                                                                                  \
    "sub si, 0xe1;\n"                                                                                                  \
    "sub esi, 0xe11;\n"                                                                                                \
    "sub rax, 0xfffee12;\n"                                                                                            \
    "sub rax, 0xff6ee12;\n"                                                                                            \
    "sub rax, 0xf66ee12;\n"                                                                                            \
    "sub rax, 0x666ee12;\n"                                                                                            \
    "seto r8b;\n"                                                                                                      \
    "seto r9b;\n"                                                                                                      \
    "seto r10b;\n"                                                                                                     \
    "seto r11b;\n"                                                                                                     \
    "seto r12b;\n"                                                                                                     \
    "seto r13b;\n"                                                                                                     \
    "seto r14b;\n"                                                                                                     \
    "seto r15b;\n"                                                                                                     \
    "or r12, [rsp+0x1e08]; \n"                                                                                         \
    "mov [rbp], r14;\n"                                                                                                \
    "mov [rbp], r15;\n"


__attribute__((noinline, section("mytest"), naked)) void
test(void)
{
    __asm__(CODE);
}


int
main()
{
    // get the section size
    extern unsigned char __start_mytest[];
    extern unsigned char __stop_mytest[];
    size_t test_sz = __stop_mytest - __start_mytest;
    printf("size = %lu\n", test_sz);

    // prepare asmline
    assemblyline_t al = asm_create_instance(NULL, 0);
    if ( asm_assemble_str(al, CODE) == EXIT_FAILURE )
        return EXIT_FAILURE;

    void (*fun)(uint64_t * out, uint64_t * in0, ...) = asm_get_code(al);
    unsigned char* c1                                = (unsigned char*)fun;

    // adjust (because gcc always adds some junk instructions)
    unsigned char* c2 = (unsigned char*)test;
    c2 += 4;
    test_sz -= 6;

    // compare
    size_t nb_errors = 0;
    for ( size_t offset = 0; offset < test_sz; offset++ )
    {
        char valid = (c1[offset] == c2[offset]);
        printf("[%ld] %#.02x == %#.02x ? %s\n", offset, c1[offset], c2[offset], valid ? "TRUE" : "FALSE");
        if ( !valid )
            nb_errors++;
    }

    printf("%lu error(s) found\n", nb_errors);
    return nb_errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
