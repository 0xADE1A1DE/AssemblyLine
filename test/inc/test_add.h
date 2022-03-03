#define CODE                                                                                                           \
    "add al, 0x0;\n"                                                                                                   \
    "add ax, 0xe1;\n"                                                                                                  \
    "add eax, 0xe11;\n"                                                                                                \
    "add sil, 0x0;\n"                                                                                                  \
    "add si, 0xe1;\n"                                                                                                  \
    "add esi, 0xe11;\n"                                                                                                \
    "add rax, 0xfffee12;\n"                                                                                            \
    "add rax, 0xff6ee12;\n"                                                                                            \
    "add rax, 0xf66ee12;\n"                                                                                            \
    "add rax, 0x666ee12;\n"                                                                                            \
    "add rax, 0x6666ee12;\n"                                                                                           \
    "add rax, -0x1;\n"                                                                                                 \
    "add rax, -0xfffee12;\n"                                                                                           \
    "add rax, -0xff6ee12;\n"                                                                                           \
    "add rax, -0xf66ee12;\n"                                                                                           \
    "add rax, -0x666ee12;\n"                                                                                           \
    "add rax, -0x6666ee12;\n"                                                                                          \
    "add rbp, -0xfffee12;\n"                                                                                           \
    "add rbp, 0xfffee12;\n"                                                                                            \
    "add rbp, 0xff6ee12;\n"                                                                                            \
    "add rbp, 0xf66ee12;\n"                                                                                            \
    "add rbp, 0x666ee12;\n"                                                                                            \
    "add rbp, 0x6666ee12;\n"                                                                                           \
    "add rbp, -0xf;\n"                                                                                                 \
    "add rbp, -0xe;\n"                                                                                                 \
    "add rbp, -0xd;\n"                                                                                                 \
    "add rbp, -0x7;\n"                                                                                                 \
    "add rbp, -0x4;\n"                                                                                                 \
    "add rbp, -0x3;\n"                                                                                                 \
    "add rbp, -0x2;\n"                                                                                                 \
    "add rbp, -0xff;\n"                                                                                                \
    "add rbp, -0xef;\n"                                                                                                \
    "add rbp, -0xdf;\n"                                                                                                \
    "add rbp, -0xcf;\n"                                                                                                \
    "add rbp, -0xbf;\n"                                                                                                \
    "add rbp, -0xaf;\n"                                                                                                \
    "add rbp, -0x9f;\n"                                                                                                \
    "add rbp, -0x8f;\n"                                                                                                \
    "add rbp, -0x7f;\n"                                                                                                \
    "add rbp, -0x3e;\n"                                                                                                \
    "add rbp, -0x6f;\n"                                                                                                \
    "add rbp, -0x5f;\n"                                                                                                \
    "add rbp, -0x4f;\n"                                                                                                \
    "add rbp, -0x1f;\n"                                                                                                \
    "add rbp, -0xfa;\n"                                                                                                \
    "add rbp, -0xf9;\n"                                                                                                \
    "add rbp, -0xf8;\n"                                                                                                \
    "add rbp, -0xf7;\n"                                                                                                \
    "add rbp, -0xf6;\n"                                                                                                \
    "add rbp, -0xf5;\n"                                                                                                \
    "add rbp, -0xf4;\n"                                                                                                \
    "add rbp, -0xf3;\n"                                                                                                \
    "add rbp, -0xf2;\n"                                                                                                \
    "add rbp, -0xf1;\n"                                                                                                \
    "add rbp, -0xf66;\n"                                                                                               \
    "add rbp, -0x666ee;\n"                                                                                             \
    "add rbp, -0x6666ee12;\n"                                                                                          \
    "add r13, -0xfffee12;\n"                                                                                           \
    "add r13, 0xfffee12;\n"                                                                                            \
    "add r13, 0xff6ee12;\n"                                                                                            \
    "add r13, 0xf66ee12;\n"                                                                                            \
    "add r13, 0x666ee12;\n"                                                                                            \
    "add r13, 0x6666ee12;\n"                                                                                           \
    "add r13, -0x1;\n"                                                                                                 \
    "add r13, -0xfffee12;\n"                                                                                           \
    "add r13, -0xff6ee12;\n"                                                                                           \
    "add r13, -0xf66ee12;\n"                                                                                           \
    "add r13, -0x666ee12;\n"                                                                                           \
    "add r13, -0x6666ee12;\n"                                                                                          \
    "add rax, 0x12;\n"                                                                                                 \
    "add rax, 0xe12;\n"                                                                                                \
    "add rax, 0x66ee12;\n"                                                                                             \
    "add rax, 0x66ee12;\n"                                                                                             \
    "add rax, 0x6ee12;\n"                                                                                              \
    "add sp, 0x34ef;\n"                                                                                                \
    "add r8w, 0x1;\n"                                                                                                  \
    "add rax, [ rbx ];\n"                                                                                              \
    "add rax, [ rbx + 0x10 ];\n"                                                                                       \
    "add rax, 0x0 ;\n"                                                                                                 \
    "add rax, 0x0 ; with a comment;\n"                                                                                 \
    "add r12, r14;\n"                                                                                                  \
    "add r12, rbx;\n"                                                                                                  \
    "add r12, [ rsp + 0x10 ];\n"                                                                                       \
    "add rax, 0xfff;\n"                                                                                                \
    "add rax, r15;\n"                                                                                                  \
    "add rax, rbp;\n"                                                                                                  \
    "add rbp, r12;\n"                                                                                                  \
    "add rbp, r8;\n"                                                                                                   \
    "add rbp, r9;\n"                                                                                                   \
    "add rbx, r9;\n"                                                                                                   \
    "add rbx, rdi;\n"                                                                                                  \
    "add rdi, r10;\n"                                                                                                  \
    "add rdx, r14;\n"                                                                                                  \
    "add rsp, 0x138 ;\n"                                                                                               \
    "add rsp, 0x48 ;\n"                                                                                                \
    "add rsp, 0x50 ;\n"                                                                                                \
    "add rsp, 0x80 ;\n"                                                                                                \
    "add dword [ebp], -0xf;\n"                                                                                         \
    "add dword [ebp], -0xe;\n"                                                                                         \
    "add dword [ebp], -0xd;\n"                                                                                         \
    "add dword [ebp], -0x7;\n"                                                                                         \
    "add dword [ebp], -0x4;\n"                                                                                         \
    "add dword [ebp], -0x3;\n"                                                                                         \
    "add dword [ebp], -0x2;\n"                                                                                         \
    "add dword [ebp], -0xff;\n"                                                                                        \
    "add dword [ebp], 0xf;\n"                                                                                          \
    "add dword [ebp], 0xe;\n"                                                                                          \
    "add dword [ebp], 0xd;\n"                                                                                          \
    "add dword [ebp], 0x7;\n"                                                                                          \
    "add dword [ebp], 0x4;\n"                                                                                          \
    "add dword [ebp], 0x3;\n"                                                                                          \
    "add dword [ebp], 0x2;\n"                                                                                          \
    "add dword [ebp], 0xff;\n"                                                                                         \
    "add eax, dword [rsp];\n"                                                                                          \
    "add eax, dword [rsp + 0x40];\n"                                                                                   \
    "add eax, [rsp + 0x40];\n"                                                                                         \
    "add eax, dword [rbp];\n"                                                                                          \
    "add eax, ebx;\n"                                                                                                  \
    ""
