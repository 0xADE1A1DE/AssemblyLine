#define CODE                                                                                                           \
    "movntdqa xmm11, [eax+0xee];\n"                                                                                    \
    "movntdqa xmm11, [ecx+0xdd];\n"                                                                                    \
    "movntdqa xmm11, [edx+0x8efde];\n"                                                                                 \
    "movntdqa xmm11, [ebx+0x4cd];\n"                                                                                   \
    "movntdqa xmm11, [esp+0xaa];\n"                                                                                    \
    "movntdqa xmm11, [ebp+0xff];\n"                                                                                    \
    "movntdqa xmm11, [esi+0xfddd];\n"                                                                                  \
    "movntdqa xmm11, [edi+0xabcd];\n"                                                                                  \
    "movntdqa xmm11, [r8d+0x9a9a9];\n"                                                                                 \
    "movntdqa xmm11, [r9d+0x456];\n"                                                                                   \
    "movntdqa xmm11, [r10d+0x123];\n"                                                                                  \
    "movntdqa xmm11, [r11d+0x89dd];\n"                                                                                 \
    "movntdqa xmm11, [r12d+0x9a34];\n"                                                                                 \
    "movntdqa xmm11, [r13d+0xffff];\n"                                                                                 \
    "movntdqa xmm11, [r14d+0x4edf];\n"                                                                                 \
    "movntdqa xmm11, [r15d+0xfe];\n"                                                                                   \
    ";\n"                                                                                                              \
    "movntdqa xmm11, [rax+0xee];\n"                                                                                    \
    "movntdqa xmm11, [rcx+0xdd];\n"                                                                                    \
    "movntdqa xmm11, [rdx+0x8efde];\n"                                                                                 \
    "movntdqa xmm11, [rbx+0x4cd];\n"                                                                                   \
    "movntdqa xmm11, [rsp+0xaa];\n"                                                                                    \
    "movntdqa xmm11, [rbp+0xff];\n"                                                                                    \
    "movntdqa xmm11, [rsi+0xfddd];\n"                                                                                  \
    "movntdqa xmm11, [rdi+0xabcd];\n"                                                                                  \
    "movntdqa xmm11, [r8+0x9a9a9];\n"                                                                                  \
    "movntdqa xmm11, [r9+0x456];\n"                                                                                    \
    "movntdqa xmm11, [r10+0x123];\n"                                                                                   \
    "movntdqa xmm11, [r11+0x89dd];\n"                                                                                  \
    "movntdqa xmm11, [r12+0x9a34];\n"                                                                                  \
    "movntdqa xmm11, [r13+0xffff];\n"                                                                                  \
    "movntdqa xmm11, [r14+0x4edf];\n"                                                                                  \
    "movntdqa xmm11, [r15+0xfe];\n"                                                                                    \
    ";\n"                                                                                                              \
    "movntdqa xmm5, [eax+0xee];\n"                                                                                     \
    "movntdqa xmm5, [ecx+0xdd];\n"                                                                                     \
    "movntdqa xmm5, [edx+0x8efde];\n"                                                                                  \
    "movntdqa xmm5, [ebx+0x4cd];\n"                                                                                    \
    "movntdqa xmm5, [esp+0xaa];\n"                                                                                     \
    "movntdqa xmm5, [ebp+0xff];\n"                                                                                     \
    "movntdqa xmm5, [esi+0xfddd];\n"                                                                                   \
    "movntdqa xmm5, [edi+0xabcd];\n"                                                                                   \
    "movntdqa xmm5, [r8d+0x9a9a9];\n"                                                                                  \
    "movntdqa xmm5, [r9d+0x456];\n"                                                                                    \
    "movntdqa xmm5, [r10d+0x123];\n"                                                                                   \
    "movntdqa xmm5, [r11d+0x89dd];\n"                                                                                  \
    "movntdqa xmm5, [r12d+0x9a34];\n"                                                                                  \
    "movntdqa xmm5, [r13d+0xffff];\n"                                                                                  \
    "movntdqa xmm5, [r14d+0x4edf];\n"                                                                                  \
    "movntdqa xmm5, [r15d+0xfe];\n"                                                                                    \
    ";\n"                                                                                                              \
    "movntdqa xmm5, [eax];\n"                                                                                          \
    "movntdqa xmm5, [ecx];\n"                                                                                          \
    "movntdqa xmm5, [edx];\n"                                                                                          \
    "movntdqa xmm5, [ebx];\n"                                                                                          \
    "movntdqa xmm5, [esp];\n"                                                                                          \
    "movntdqa xmm5, [ebp+0x0];\n"                                                                                      \
    "movntdqa xmm5, [esi];\n"                                                                                          \
    "movntdqa xmm5, [edi];\n"                                                                                          \
    "movntdqa xmm5, [r8d];\n"                                                                                          \
    "movntdqa xmm5, [r9d];\n"                                                                                          \
    "movntdqa xmm5, [r10d];\n"                                                                                         \
    "movntdqa xmm5, [r11d];\n"                                                                                         \
    "movntdqa xmm5, [r12d];\n"                                                                                         \
    "movntdqa xmm5, [r13d+0x0];\n"                                                                                     \
    "movntdqa xmm5, [r14d];\n"                                                                                         \
    "movntdqa xmm5, [r15d];\n"                                                                                         \
    ";\n"                                                                                                              \
    "movntdqa xmm5, [rax+0xee];\n"                                                                                     \
    "movntdqa xmm5, [rcx+0xdd];\n"                                                                                     \
    "movntdqa xmm5, [rdx+0x8efde];\n"                                                                                  \
    "movntdqa xmm5, [rbx+0x4cd];\n"                                                                                    \
    "movntdqa xmm5, [rsp+0xaa];\n"                                                                                     \
    "movntdqa xmm5, [rbp+0xff];\n"                                                                                     \
    "movntdqa xmm5, [rsi+0xfddd];\n"                                                                                   \
    "movntdqa xmm5, [rdi+0xabcd];\n"                                                                                   \
    "movntdqa xmm5, [r8+0x9a9a9];\n"                                                                                   \
    "movntdqa xmm5, [r9+0x456];\n"                                                                                     \
    "movntdqa xmm5, [r10+0x123];\n"                                                                                    \
    "movntdqa xmm5, [r11+0x89dd];\n"                                                                                   \
    "movntdqa xmm5, [r12+0x9a34];\n"                                                                                   \
    "movntdqa xmm5, [r13+0xffff];\n"                                                                                   \
    "movntdqa xmm5, [r14+0x4edf];\n"                                                                                   \
    "movntdqa xmm5, [r15+0xfe];\n"                                                                                     \
    ";\n"                                                                                                              \
    ";\n"                                                                                                              \
    "movntdqa xmm5, [rax];\n"                                                                                          \
    "movntdqa xmm5, [rcx];\n"                                                                                          \
    "movntdqa xmm5, [rdx];\n"                                                                                          \
    "movntdqa xmm5, [rbx];\n"                                                                                          \
    "movntdqa xmm5, [rsp];\n"                                                                                          \
    "movntdqa xmm5, [rbp];\n"                                                                                          \
    "movntdqa xmm5, [rsi];\n"                                                                                          \
    "movntdqa xmm5, [rdi];\n"                                                                                          \
    "movntdqa xmm5, [r8d];\n"                                                                                          \
    "movntdqa xmm5, [r9d];\n"                                                                                          \
    "movntdqa xmm5, [r10];\n"                                                                                          \
    "movntdqa xmm5, [r11];\n"                                                                                          \
    "movntdqa xmm5, [r12];\n"                                                                                          \
    "movntdqa xmm5, [r13];\n"                                                                                          \
    "movntdqa xmm5, [r14];\n"                                                                                          \
    "movntdqa xmm5, [r15];\n"                                                                                          \
    ""