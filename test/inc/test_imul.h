#define CODE                                                                                                           \
    "imul r10, [ rsi + 0x18 ], 0x13;\n"                                                                                \
    "imul r11, [ rsi + 0x20 ], 0x13;\n"                                                                                \
    "imul r11, [ rsi + 0x20 ], 0x2;\n"                                                                                 \
    "imul r12, r12, 0x13;\n"                                                                                           \
    "imul r12, r12, 0x13;\n"                                                                                           \
    "imul r12, r15, 0x2;\n"                                                                                            \
    "imul r12, [ rsi + 0x10 ], 0x2;\n"                                                                                 \
    "imul r12, [ rsi + 0x8 ], 0x2;\n"                                                                                  \
    "imul r13, r15, 0x2;\n"                                                                                            \
    "imul r13, [ rsi + 0x18 ], 0x13;\n"                                                                                \
    "imul r14, [ rsi + 0x20 ], 0x2;\n"                                                                                 \
    "imul r14, [ rsi + 0x8 ], 0x2;\n"                                                                                  \
    "imul r15, [ rsi + 0x18 ], 0x13;\n"                                                                                \
    "imul r15, [ rsi + 0x18 ], 0x2;\n"                                                                                 \
    "imul r15, [ rsi + 0x20 ], 0x13;\n"                                                                                \
    "imul r9, [ rsi + 0x10 ], 0x2;\n"                                                                                  \
    "imul rax, [ rsi + 0x18 ], 0x2;\n"                                                                                 \
    "imul rbp, [ rsi + 0x18 ], 0x2;\n"                                                                                 \
    "imul rbx, r13, 0x2;\n"                                                                                            \
    "imul rbx, [ rsi + 0x20 ], 0x2;\n"                                                                                 \
    "imul rbx, [ rsi + 0x8 ], 0x2;\n"                                                                                  \
    "imul rcx, r10, 0x2;\n"                                                                                            \
    "imul rcx, r11, 0x2;\n"                                                                                            \
    "imul rdi, [ rsi + 0x10 ], 0x2;\n"                                                                                 \
    "imul rdx, r11, 0x2;\n"                                                                                            \
    "imul rbx, rax;\n"                                                                                                 \
    "imul ebx, eax;\n"                                                                                                 \
    "imul bx, ax;\n"                                                                                                   \
    "imul bl;\n"                                                                                                       \
    "imul rax, [rax];\n"                                                                                               \
    "imul rax, [rbx];\n"                                                                                               \
    "imul rax, [rcx];\n"                                                                                               \
    "imul rax, [rdx];\n"                                                                                               \
    "imul rax, [rdi];\n"                                                                                               \
    "imul rax, [r8];\n"                                                                                                \
    "imul rax, [r9];\n"                                                                                                \
    "imul rax, [r10];\n"                                                                                               \
    "imul rax, [r11];\n"                                                                                               \
    "imul rax, [r12];\n"                                                                                               \
    "imul rax, [r13];\n"                                                                                               \
    "imul rax, [r14];\n"                                                                                               \
    "imul rax, [r15];\n"                                                                                               \
    "imul rax, [rsp];\n"                                                                                               \
    "imul rax, [rsi];\n"                                                                                               \
    "imul rax, [rbp];\n"                                                                                               \
    "imul rbx, [rax];\n"                                                                                               \
    "imul rbx, [rbx];\n"                                                                                               \
    "imul rbx, [rcx];\n"                                                                                               \
    "imul rbx, [rdx];\n"                                                                                               \
    "imul rbx, [rdi];\n"                                                                                               \
    "imul rbx, [r8];\n"                                                                                                \
    "imul rbx, [r9];\n"                                                                                                \
    "imul rbx, [r10];\n"                                                                                               \
    "imul rbx, [r11];\n"                                                                                               \
    "imul rbx, [r12];\n"                                                                                               \
    "imul rbx, [r13];\n"                                                                                               \
    "imul rbx, [r14];\n"                                                                                               \
    "imul rbx, [r15];\n"                                                                                               \
    "imul rbx, [rsp];\n"                                                                                               \
    "imul rbx, [rsi];\n"                                                                                               \
    "imul rbx, [rbp];\n"                                                                                               \
    "imul rcx, [rax];\n"                                                                                               \
    "imul rcx, [rbx];\n"                                                                                               \
    "imul rcx, [rcx];\n"                                                                                               \
    "imul rcx, [rdx];\n"                                                                                               \
    "imul rcx, [rdi];\n"                                                                                               \
    "imul rcx, [r8];\n"                                                                                                \
    "imul rcx, [r9];\n"                                                                                                \
    "imul rcx, [r10];\n"                                                                                               \
    "imul rcx, [r11];\n"                                                                                               \
    "imul rcx, [r12];\n"                                                                                               \
    "imul rcx, [r13];\n"                                                                                               \
    "imul rcx, [r14];\n"                                                                                               \
    "imul rcx, [r15];\n"                                                                                               \
    "imul rcx, [rsp];\n"                                                                                               \
    "imul rcx, [rsi];\n"                                                                                               \
    "imul rcx, [rbp];\n"                                                                                               \
    "imul rdx, [rax];\n"                                                                                               \
    "imul rdx, [rbx];\n"                                                                                               \
    "imul rdx, [rcx];\n"                                                                                               \
    "imul rdx, [rdx];\n"                                                                                               \
    "imul rdx, [rdi];\n"                                                                                               \
    "imul rdx, [r8];\n"                                                                                                \
    "imul rdx, [r9];\n"                                                                                                \
    "imul rdx, [r10];\n"                                                                                               \
    "imul rdx, [r11];\n"                                                                                               \
    "imul rdx, [r12];\n"                                                                                               \
    "imul rdx, [r13];\n"                                                                                               \
    "imul rdx, [r14];\n"                                                                                               \
    "imul rdx, [r15];\n"                                                                                               \
    "imul rdx, [rsp];\n"                                                                                               \
    "imul rdx, [rsi];\n"                                                                                               \
    "imul rdx, [rbp];\n"                                                                                               \
    "imul rdi, [rax];\n"                                                                                               \
    "imul rdi, [rbx];\n"                                                                                               \
    "imul rdi, [rcx];\n"                                                                                               \
    "imul rdi, [rdx];\n"                                                                                               \
    "imul rdi, [rdi];\n"                                                                                               \
    "imul rdi, [r8];\n"                                                                                                \
    "imul rdi, [r9];\n"                                                                                                \
    "imul rdi, [r10];\n"                                                                                               \
    "imul rdi, [r11];\n"                                                                                               \
    "imul rdi, [r12];\n"                                                                                               \
    "imul rdi, [r13];\n"                                                                                               \
    "imul rdi, [r14];\n"                                                                                               \
    "imul rdi, [r15];\n"                                                                                               \
    "imul rdi, [rsp];\n"                                                                                               \
    "imul rdi, [rsi];\n"                                                                                               \
    "imul rdi, [rbp];\n"                                                                                               \
    "imul r8, [rax];\n"                                                                                                \
    "imul r8, [rbx];\n"                                                                                                \
    "imul r8, [rcx];\n"                                                                                                \
    "imul r8, [rdx];\n"                                                                                                \
    "imul r8, [rdi];\n"                                                                                                \
    "imul r8, [r8];\n"                                                                                                 \
    "imul r8, [r9];\n"                                                                                                 \
    "imul r8, [r10];\n"                                                                                                \
    "imul r8, [r11];\n"                                                                                                \
    "imul r8, [r12];\n"                                                                                                \
    "imul r8, [r13];\n"                                                                                                \
    "imul r8, [r14];\n"                                                                                                \
    "imul r8, [r15];\n"                                                                                                \
    "imul r8, [rsp];\n"                                                                                                \
    "imul r8, [rsi];\n"                                                                                                \
    "imul r8, [rbp];\n"                                                                                                \
    "imul r9, [rax];\n"                                                                                                \
    "imul r9, [rbx];\n"                                                                                                \
    "imul r9, [rcx];\n"                                                                                                \
    "imul r9, [rdx];\n"                                                                                                \
    "imul r9, [rdi];\n"                                                                                                \
    "imul r9, [r8];\n"                                                                                                 \
    "imul r9, [r9];\n"                                                                                                 \
    "imul r9, [r10];\n"                                                                                                \
    "imul r9, [r11];\n"                                                                                                \
    "imul r9, [r12];\n"                                                                                                \
    "imul r9, [r13];\n"                                                                                                \
    "imul r9, [r14];\n"                                                                                                \
    "imul r9, [r15];\n"                                                                                                \
    "imul r9, [rsp];\n"                                                                                                \
    "imul r9, [rsi];\n"                                                                                                \
    "imul r9, [rbp];\n"                                                                                                \
    "imul r10, [rax];\n"                                                                                               \
    "imul r10, [rbx];\n"                                                                                               \
    "imul r10, [rcx];\n"                                                                                               \
    "imul r10, [rdx];\n"                                                                                               \
    "imul r10, [rdi];\n"                                                                                               \
    "imul r10, [r8];\n"                                                                                                \
    "imul r10, [r9];\n"                                                                                                \
    "imul r10, [r10];\n"                                                                                               \
    "imul r10, [r11];\n"                                                                                               \
    "imul r10, [r12];\n"                                                                                               \
    "imul r10, [r13];\n"                                                                                               \
    "imul r10, [r14];\n"                                                                                               \
    "imul r10, [r15];\n"                                                                                               \
    "imul r10, [rsp];\n"                                                                                               \
    "imul r10, [rsi];\n"                                                                                               \
    "imul r10, [rbp];\n"                                                                                               \
    "imul r11, [rax];\n"                                                                                               \
    "imul r11, [rbx];\n"                                                                                               \
    "imul r11, [rcx];\n"                                                                                               \
    "imul r11, [rdx];\n"                                                                                               \
    "imul r11, [rdi];\n"                                                                                               \
    "imul r11, [r8];\n"                                                                                                \
    "imul r11, [r9];\n"                                                                                                \
    "imul r11, [r10];\n"                                                                                               \
    "imul r11, [r11];\n"                                                                                               \
    "imul r11, [r12];\n"                                                                                               \
    "imul r11, [r13];\n"                                                                                               \
    "imul r11, [r14];\n"                                                                                               \
    "imul r11, [r15];\n"                                                                                               \
    "imul r11, [rsp];\n"                                                                                               \
    "imul r11, [rsi];\n"                                                                                               \
    "imul r11, [rbp];\n"                                                                                               \
    "imul r12, [rax];\n"                                                                                               \
    "imul r12, [rbx];\n"                                                                                               \
    "imul r12, [rcx];\n"                                                                                               \
    "imul r12, [rdx];\n"                                                                                               \
    "imul r12, [rdi];\n"                                                                                               \
    "imul r12, [r8];\n"                                                                                                \
    "imul r12, [r9];\n"                                                                                                \
    "imul r12, [r10];\n"                                                                                               \
    "imul r12, [r11];\n"                                                                                               \
    "imul r12, [r12];\n"                                                                                               \
    "imul r12, [r13];\n"                                                                                               \
    "imul r12, [r14];\n"                                                                                               \
    "imul r12, [r15];\n"                                                                                               \
    "imul r12, [rsp];\n"                                                                                               \
    "imul r12, [rsi];\n"                                                                                               \
    "imul r12, [rbp];\n"                                                                                               \
    "imul r13, [rax];\n"                                                                                               \
    "imul r13, [rbx];\n"                                                                                               \
    "imul r13, [rcx];\n"                                                                                               \
    "imul r13, [rdx];\n"                                                                                               \
    "imul r13, [rdi];\n"                                                                                               \
    "imul r13, [r8];\n"                                                                                                \
    "imul r13, [r9];\n"                                                                                                \
    "imul r13, [r10];\n"                                                                                               \
    "imul r13, [r11];\n"                                                                                               \
    "imul r13, [r12];\n"                                                                                               \
    "imul r13, [r13];\n"                                                                                               \
    "imul r13, [r14];\n"                                                                                               \
    "imul r13, [r15];\n"                                                                                               \
    "imul r13, [rsp];\n"                                                                                               \
    "imul r13, [rsi];\n"                                                                                               \
    "imul r13, [rbp];\n"                                                                                               \
    "imul r14, [rax];\n"                                                                                               \
    "imul r14, [rbx];\n"                                                                                               \
    "imul r14, [rcx];\n"                                                                                               \
    "imul r14, [rdx];\n"                                                                                               \
    "imul r14, [rdi];\n"                                                                                               \
    "imul r14, [r8];\n"                                                                                                \
    "imul r14, [r9];\n"                                                                                                \
    "imul r14, [r10];\n"                                                                                               \
    "imul r14, [r11];\n"                                                                                               \
    "imul r14, [r12];\n"                                                                                               \
    "imul r14, [r13];\n"                                                                                               \
    "imul r14, [r14];\n"                                                                                               \
    "imul r14, [r15];\n"                                                                                               \
    "imul r14, [rsp];\n"                                                                                               \
    "imul r14, [rsi];\n"                                                                                               \
    "imul r14, [rbp];\n"                                                                                               \
    "imul r15, [rax];\n"                                                                                               \
    "imul r15, [rbx];\n"                                                                                               \
    "imul r15, [rcx];\n"                                                                                               \
    "imul r15, [rdx];\n"                                                                                               \
    "imul r15, [rdi];\n"                                                                                               \
    "imul r15, [r8];\n"                                                                                                \
    "imul r15, [r9];\n"                                                                                                \
    "imul r15, [r10];\n"                                                                                               \
    "imul r15, [r11];\n"                                                                                               \
    "imul r15, [r12];\n"                                                                                               \
    "imul r15, [r13];\n"                                                                                               \
    "imul r15, [r14];\n"                                                                                               \
    "imul r15, [r15];\n"                                                                                               \
    "imul r15, [rsp];\n"                                                                                               \
    "imul r15, [rsi];\n"                                                                                               \
    "imul r15, [rbp];\n"                                                                                               \
    "imul rsp, [rax];\n"                                                                                               \
    "imul rsp, [rbx];\n"                                                                                               \
    "imul rsp, [rcx];\n"                                                                                               \
    "imul rsp, [rdx];\n"                                                                                               \
    "imul rsp, [rdi];\n"                                                                                               \
    "imul rsp, [r8];\n"                                                                                                \
    "imul rsp, [r9];\n"                                                                                                \
    "imul rsp, [r10];\n"                                                                                               \
    "imul rsp, [r11];\n"                                                                                               \
    "imul rsp, [r12];\n"                                                                                               \
    "imul rsp, [r13];\n"                                                                                               \
    "imul rsp, [r14];\n"                                                                                               \
    "imul rsp, [r15];\n"                                                                                               \
    "imul rsp, [rsp];\n"                                                                                               \
    "imul rsp, [rsi];\n"                                                                                               \
    "imul rsp, [rbp];\n"                                                                                               \
    "imul rsi, [rax];\n"                                                                                               \
    "imul rsi, [rbx];\n"                                                                                               \
    "imul rsi, [rcx];\n"                                                                                               \
    "imul rsi, [rdx];\n"                                                                                               \
    "imul rsi, [rdi];\n"                                                                                               \
    "imul rsi, [r8];\n"                                                                                                \
    "imul rsi, [r9];\n"                                                                                                \
    "imul rsi, [r10];\n"                                                                                               \
    "imul rsi, [r11];\n"                                                                                               \
    "imul rsi, [r12];\n"                                                                                               \
    "imul rsi, [r13];\n"                                                                                               \
    "imul rsi, [r14];\n"                                                                                               \
    "imul rsi, [r15];\n"                                                                                               \
    "imul rsi, [rsp];\n"                                                                                               \
    "imul rsi, [rsi];\n"                                                                                               \
    "imul rsi, [rbp];\n"                                                                                               \
    "imul rbp, [rax];\n"                                                                                               \
    "imul rbp, [rbx];\n"                                                                                               \
    "imul rbp, [rcx];\n"                                                                                               \
    "imul rbp, [rdx];\n"                                                                                               \
    "imul rbp, [rdi];\n"                                                                                               \
    "imul rbp, [r8];\n"                                                                                                \
    "imul rbp, [r9];\n"                                                                                                \
    "imul rbp, [r10];\n"                                                                                               \
    "imul rbp, [r11];\n"                                                                                               \
    "imul rbp, [r12];\n"                                                                                               \
    "imul rbp, [r13];\n"                                                                                               \
    "imul rbp, [r14];\n"                                                                                               \
    "imul rbp, [r15];\n"                                                                                               \
    "imul rbp, [rsp];\n"                                                                                               \
    "imul rbp, [rsi];\n"                                                                                               \
    "imul rbp, [rbp];\n"                                                                                               \
    "imul eax, [eax];\n"                                                                                               \
    "imul eax, [ebx];\n"                                                                                               \
    "imul eax, [ecx];\n"                                                                                               \
    "imul eax, [edx];\n"                                                                                               \
    "imul eax, [edi];\n"                                                                                               \
    "imul eax, [r8d];\n"                                                                                               \
    "imul eax, [r9d];\n"                                                                                               \
    "imul eax, [r10d];\n"                                                                                              \
    "imul eax, [r11d];\n"                                                                                              \
    "imul eax, [r12d];\n"                                                                                              \
    "imul eax, [r13d];\n"                                                                                              \
    "imul eax, [r14d];\n"                                                                                              \
    "imul eax, [r15d];\n"                                                                                              \
    "imul eax, [esp];\n"                                                                                               \
    "imul eax, [esi];\n"                                                                                               \
    "imul eax, [ebp];\n"                                                                                               \
    "imul ebx, [eax];\n"                                                                                               \
    "imul ebx, [ebx];\n"                                                                                               \
    "imul ebx, [ecx];\n"                                                                                               \
    "imul ebx, [edx];\n"                                                                                               \
    "imul ebx, [edi];\n"                                                                                               \
    "imul ebx, [r8d];\n"                                                                                               \
    "imul ebx, [r9d];\n"                                                                                               \
    "imul ebx, [r10d];\n"                                                                                              \
    "imul ebx, [r11d];\n"                                                                                              \
    "imul ebx, [r12d];\n"                                                                                              \
    "imul ebx, [r13d];\n"                                                                                              \
    "imul ebx, [r14d];\n"                                                                                              \
    "imul ebx, [r15d];\n"                                                                                              \
    "imul ebx, [esp];\n"                                                                                               \
    "imul ebx, [esi];\n"                                                                                               \
    "imul ebx, [ebp];\n"                                                                                               \
    "imul ecx, [eax];\n"                                                                                               \
    "imul ecx, [ebx];\n"                                                                                               \
    "imul ecx, [ecx];\n"                                                                                               \
    "imul ecx, [edx];\n"                                                                                               \
    "imul ecx, [edi];\n"                                                                                               \
    "imul ecx, [r8d];\n"                                                                                               \
    "imul ecx, [r9d];\n"                                                                                               \
    "imul ecx, [r10d];\n"                                                                                              \
    "imul ecx, [r11d];\n"                                                                                              \
    "imul ecx, [r12d];\n"                                                                                              \
    "imul ecx, [r13d];\n"                                                                                              \
    "imul ecx, [r14d];\n"                                                                                              \
    "imul ecx, [r15d];\n"                                                                                              \
    "imul ecx, [esp];\n"                                                                                               \
    "imul ecx, [esi];\n"                                                                                               \
    "imul ecx, [ebp];\n"                                                                                               \
    "imul edx, [eax];\n"                                                                                               \
    "imul edx, [ebx];\n"                                                                                               \
    "imul edx, [ecx];\n"                                                                                               \
    "imul edx, [edx];\n"                                                                                               \
    "imul edx, [edi];\n"                                                                                               \
    "imul edx, [r8d];\n"                                                                                               \
    "imul edx, [r9d];\n"                                                                                               \
    "imul edx, [r10d];\n"                                                                                              \
    "imul edx, [r11d];\n"                                                                                              \
    "imul edx, [r12d];\n"                                                                                              \
    "imul edx, [r13d];\n"                                                                                              \
    "imul edx, [r14d];\n"                                                                                              \
    "imul edx, [r15d];\n"                                                                                              \
    "imul edx, [esp];\n"                                                                                               \
    "imul edx, [esi];\n"                                                                                               \
    "imul edx, [ebp];\n"                                                                                               \
    "imul edi, [eax];\n"                                                                                               \
    "imul edi, [ebx];\n"                                                                                               \
    "imul edi, [ecx];\n"                                                                                               \
    "imul edi, [edx];\n"                                                                                               \
    "imul edi, [edi];\n"                                                                                               \
    "imul edi, [r8d];\n"                                                                                               \
    "imul edi, [r9d];\n"                                                                                               \
    "imul edi, [r10d];\n"                                                                                              \
    "imul edi, [r11d];\n"                                                                                              \
    "imul edi, [r12d];\n"                                                                                              \
    "imul edi, [r13d];\n"                                                                                              \
    "imul edi, [r14d];\n"                                                                                              \
    "imul edi, [r15d];\n"                                                                                              \
    "imul edi, [esp];\n"                                                                                               \
    "imul edi, [esi];\n"                                                                                               \
    "imul edi, [ebp];\n"                                                                                               \
    "imul r8d, [eax];\n"                                                                                               \
    "imul r8d, [ebx];\n"                                                                                               \
    "imul r8d, [ecx];\n"                                                                                               \
    "imul r8d, [edx];\n"                                                                                               \
    "imul r8d, [edi];\n"                                                                                               \
    "imul r8d, [r8d];\n"                                                                                               \
    "imul r8d, [r9d];\n"                                                                                               \
    "imul r8d, [r10d];\n"                                                                                              \
    "imul r8d, [r11d];\n"                                                                                              \
    "imul r8d, [r12d];\n"                                                                                              \
    "imul r8d, [r13d];\n"                                                                                              \
    "imul r8d, [r14d];\n"                                                                                              \
    "imul r8d, [r15d];\n"                                                                                              \
    "imul r8d, [esp];\n"                                                                                               \
    "imul r8d, [esi];\n"                                                                                               \
    "imul r8d, [ebp];\n"                                                                                               \
    "imul r9d, [eax];\n"                                                                                               \
    "imul r9d, [ebx];\n"                                                                                               \
    "imul r9d, [ecx];\n"                                                                                               \
    "imul r9d, [edx];\n"                                                                                               \
    "imul r9d, [edi];\n"                                                                                               \
    "imul r9d, [r8d];\n"                                                                                               \
    "imul r9d, [r9d];\n"                                                                                               \
    "imul r9d, [r10d];\n"                                                                                              \
    "imul r9d, [r11d];\n"                                                                                              \
    "imul r9d, [r12d];\n"                                                                                              \
    "imul r9d, [r13d];\n"                                                                                              \
    "imul r9d, [r14d];\n"                                                                                              \
    "imul r9d, [r15d];\n"                                                                                              \
    "imul r9d, [esp];\n"                                                                                               \
    "imul r9d, [esi];\n"                                                                                               \
    "imul r9d, [ebp];\n"                                                                                               \
    "imul r10d, [eax];\n"                                                                                              \
    "imul r10d, [ebx];\n"                                                                                              \
    "imul r10d, [ecx];\n"                                                                                              \
    "imul r10d, [edx];\n"                                                                                              \
    "imul r10d, [edi];\n"                                                                                              \
    "imul r10d, [r8d];\n"                                                                                              \
    "imul r10d, [r9d];\n"                                                                                              \
    "imul r10d, [r10d];\n"                                                                                             \
    "imul r10d, [r11d];\n"                                                                                             \
    "imul r10d, [r12d];\n"                                                                                             \
    "imul r10d, [r13d];\n"                                                                                             \
    "imul r10d, [r14d];\n"                                                                                             \
    "imul r10d, [r15d];\n"                                                                                             \
    "imul r10d, [esp];\n"                                                                                              \
    "imul r10d, [esi];\n"                                                                                              \
    "imul r10d, [ebp];\n"                                                                                              \
    "imul r11d, [eax];\n"                                                                                              \
    "imul r11d, [ebx];\n"                                                                                              \
    "imul r11d, [ecx];\n"                                                                                              \
    "imul r11d, [edx];\n"                                                                                              \
    "imul r11d, [edi];\n"                                                                                              \
    "imul r11d, [r8d];\n"                                                                                              \
    "imul r11d, [r9d];\n"                                                                                              \
    "imul r11d, [r10d];\n"                                                                                             \
    "imul r11d, [r11d];\n"                                                                                             \
    "imul r11d, [r12d];\n"                                                                                             \
    "imul r11d, [r13d];\n"                                                                                             \
    "imul r11d, [r14d];\n"                                                                                             \
    "imul r11d, [r15d];\n"                                                                                             \
    "imul r11d, [esp];\n"                                                                                              \
    "imul r11d, [esi];\n"                                                                                              \
    "imul r11d, [ebp];\n"                                                                                              \
    "imul r12d, [eax];\n"                                                                                              \
    "imul r12d, [ebx];\n"                                                                                              \
    "imul r12d, [ecx];\n"                                                                                              \
    "imul r12d, [edx];\n"                                                                                              \
    "imul r12d, [edi];\n"                                                                                              \
    "imul r12d, [r8d];\n"                                                                                              \
    "imul r12d, [r9d];\n"                                                                                              \
    "imul r12d, [r10d];\n"                                                                                             \
    "imul r12d, [r11d];\n"                                                                                             \
    "imul r12d, [r12d];\n"                                                                                             \
    "imul r12d, [r13d];\n"                                                                                             \
    "imul r12d, [r14d];\n"                                                                                             \
    "imul r12d, [r15d];\n"                                                                                             \
    "imul r12d, [esp];\n"                                                                                              \
    "imul r12d, [esi];\n"                                                                                              \
    "imul r12d, [ebp];\n"                                                                                              \
    "imul r13d, [eax];\n"                                                                                              \
    "imul r13d, [ebx];\n"                                                                                              \
    "imul r13d, [ecx];\n"                                                                                              \
    "imul r13d, [edx];\n"                                                                                              \
    "imul r13d, [edi];\n"                                                                                              \
    "imul r13d, [r8d];\n"                                                                                              \
    "imul r13d, [r9d];\n"                                                                                              \
    "imul r13d, [r10d];\n"                                                                                             \
    "imul r13d, [r11d];\n"                                                                                             \
    "imul r13d, [r12d];\n"                                                                                             \
    "imul r13d, [r13d];\n"                                                                                             \
    "imul r13d, [r14d];\n"                                                                                             \
    "imul r13d, [r15d];\n"                                                                                             \
    "imul r13d, [esp];\n"                                                                                              \
    "imul r13d, [esi];\n"                                                                                              \
    "imul r13d, [ebp];\n"                                                                                              \
    "imul r14d, [eax];\n"                                                                                              \
    "imul r14d, [ebx];\n"                                                                                              \
    "imul r14d, [ecx];\n"                                                                                              \
    "imul r14d, [edx];\n"                                                                                              \
    "imul r14d, [edi];\n"                                                                                              \
    "imul r14d, [r8d];\n"                                                                                              \
    "imul r14d, [r9d];\n"                                                                                              \
    "imul r14d, [r10d];\n"                                                                                             \
    "imul r14d, [r11d];\n"                                                                                             \
    "imul r14d, [r12d];\n"                                                                                             \
    "imul r14d, [r13d];\n"                                                                                             \
    "imul r14d, [r14d];\n"                                                                                             \
    "imul r14d, [r15d];\n"                                                                                             \
    "imul r14d, [esp];\n"                                                                                              \
    "imul r14d, [esi];\n"                                                                                              \
    "imul r14d, [ebp];\n"                                                                                              \
    "imul r15d, [eax];\n"                                                                                              \
    "imul r15d, [ebx];\n"                                                                                              \
    "imul r15d, [ecx];\n"                                                                                              \
    "imul r15d, [edx];\n"                                                                                              \
    "imul r15d, [edi];\n"                                                                                              \
    "imul r15d, [r8d];\n"                                                                                              \
    "imul r15d, [r9d];\n"                                                                                              \
    "imul r15d, [r10d];\n"                                                                                             \
    "imul r15d, [r11d];\n"                                                                                             \
    "imul r15d, [r12d];\n"                                                                                             \
    "imul r15d, [r13d];\n"                                                                                             \
    "imul r15d, [r14d];\n"                                                                                             \
    "imul r15d, [r15d];\n"                                                                                             \
    "imul r15d, [esp];\n"                                                                                              \
    "imul r15d, [esi];\n"                                                                                              \
    "imul r15d, [ebp];\n"                                                                                              \
    "imul esp, [eax];\n"                                                                                               \
    "imul esp, [ebx];\n"                                                                                               \
    "imul esp, [ecx];\n"                                                                                               \
    "imul esp, [edx];\n"                                                                                               \
    "imul esp, [edi];\n"                                                                                               \
    "imul esp, [r8d];\n"                                                                                               \
    "imul esp, [r9d];\n"                                                                                               \
    "imul esp, [r10d];\n"                                                                                              \
    "imul esp, [r11d];\n"                                                                                              \
    "imul esp, [r12d];\n"                                                                                              \
    "imul esp, [r13d];\n"                                                                                              \
    "imul esp, [r14d];\n"                                                                                              \
    "imul esp, [r15d];\n"                                                                                              \
    "imul esp, [esp];\n"                                                                                               \
    "imul esp, [esi];\n"                                                                                               \
    "imul esp, [ebp];\n"                                                                                               \
    "imul esi, [eax];\n"                                                                                               \
    "imul esi, [ebx];\n"                                                                                               \
    "imul esi, [ecx];\n"                                                                                               \
    "imul esi, [edx];\n"                                                                                               \
    "imul esi, [edi];\n"                                                                                               \
    "imul esi, [r8d];\n"                                                                                               \
    "imul esi, [r9d];\n"                                                                                               \
    "imul esi, [r10d];\n"                                                                                              \
    "imul esi, [r11d];\n"                                                                                              \
    "imul esi, [r12d];\n"                                                                                              \
    "imul esi, [r13d];\n"                                                                                              \
    "imul esi, [r14d];\n"                                                                                              \
    "imul esi, [r15d];\n"                                                                                              \
    "imul esi, [esp];\n"                                                                                               \
    "imul esi, [esi];\n"                                                                                               \
    "imul esi, [ebp];\n"                                                                                               \
    "imul ebp, [eax];\n"                                                                                               \
    "imul ebp, [ebx];\n"                                                                                               \
    "imul ebp, [ecx];\n"                                                                                               \
    "imul ebp, [edx];\n"                                                                                               \
    "imul ebp, [edi];\n"                                                                                               \
    "imul ebp, [r8d];\n"                                                                                               \
    "imul ebp, [r9d];\n"                                                                                               \
    "imul ebp, [r10d];\n"                                                                                              \
    "imul ebp, [r11d];\n"                                                                                              \
    "imul ebp, [r12d];\n"                                                                                              \
    "imul ebp, [r13d];\n"                                                                                              \
    "imul ebp, [r14d];\n"                                                                                              \
    "imul ebp, [r15d];\n"                                                                                              \
    "imul ebp, [esp];\n"                                                                                               \
    "imul ebp, [esi];\n"                                                                                               \
    "imul ebp, [ebp];\n"                                                                                               \
    "imul ax, word [eax];\n"                                                                                           \
    "imul ax, word [ebx];\n"                                                                                           \
    "imul ax, word [ecx];\n"                                                                                           \
    "imul ax, word [edx];\n"                                                                                           \
    "imul ax, word [edi];\n"                                                                                           \
    "imul ax, word [r8d];\n"                                                                                           \
    "imul ax, word [r9d];\n"                                                                                           \
    "imul ax, word [r10d];\n"                                                                                          \
    "imul ax, word [r11d];\n"                                                                                          \
    "imul ax, word [r12d];\n"                                                                                          \
    "imul ax, word [r13d];\n"                                                                                          \
    "imul ax, word [r14d];\n"                                                                                          \
    "imul ax, word [r15d];\n"                                                                                          \
    "imul ax, word [esp];\n"                                                                                           \
    "imul ax, word [esi];\n"                                                                                           \
    "imul ax, word [ebp];\n"                                                                                           \
    "imul bx, word [eax];\n"                                                                                           \
    "imul bx, word [ebx];\n"                                                                                           \
    "imul bx, word [ecx];\n"                                                                                           \
    "imul bx, word [edx];\n"                                                                                           \
    "imul bx, word [edi];\n"                                                                                           \
    "imul bx, word [r8d];\n"                                                                                           \
    "imul bx, word [r9d];\n"                                                                                           \
    "imul bx, word [r10d];\n"                                                                                          \
    "imul bx, word [r11d];\n"                                                                                          \
    "imul bx, word [r12d];\n"                                                                                          \
    "imul bx, word [r13d];\n"                                                                                          \
    "imul bx, word [r14d];\n"                                                                                          \
    "imul bx, word [r15d];\n"                                                                                          \
    "imul bx, word [esp];\n"                                                                                           \
    "imul bx, word [esi];\n"                                                                                           \
    "imul bx, word [ebp];\n"                                                                                           \
    "imul cx, word [eax];\n"                                                                                           \
    "imul cx, word [ebx];\n"                                                                                           \
    "imul cx, word [ecx];\n"                                                                                           \
    "imul cx, word [edx];\n"                                                                                           \
    "imul cx, word [edi];\n"                                                                                           \
    "imul cx, word [r8d];\n"                                                                                           \
    "imul cx, word [r9d];\n"                                                                                           \
    "imul cx, word [r10d];\n"                                                                                          \
    "imul cx, word [r11d];\n"                                                                                          \
    "imul cx, word [r12d];\n"                                                                                          \
    "imul cx, word [r13d];\n"                                                                                          \
    "imul cx, word [r14d];\n"                                                                                          \
    "imul cx, word [r15d];\n"                                                                                          \
    "imul cx, word [esp];\n"                                                                                           \
    "imul cx, word [esi];\n"                                                                                           \
    "imul cx, word [ebp];\n"                                                                                           \
    "imul dx, word [eax];\n"                                                                                           \
    "imul dx, word [ebx];\n"                                                                                           \
    "imul dx, word [ecx];\n"                                                                                           \
    "imul dx, word [edx];\n"                                                                                           \
    "imul dx, word [edi];\n"                                                                                           \
    "imul dx, word [r8d];\n"                                                                                           \
    "imul dx, word [r9d];\n"                                                                                           \
    "imul dx, word [r10d];\n"                                                                                          \
    "imul dx, word [r11d];\n"                                                                                          \
    "imul dx, word [r12d];\n"                                                                                          \
    "imul dx, word [r13d];\n"                                                                                          \
    "imul dx, word [r14d];\n"                                                                                          \
    "imul dx, word [r15d];\n"                                                                                          \
    "imul dx, word [esp];\n"                                                                                           \
    "imul dx, word [esi];\n"                                                                                           \
    "imul dx, word [ebp];\n"                                                                                           \
    "imul di, word [eax];\n"                                                                                           \
    "imul di, word [ebx];\n"                                                                                           \
    "imul di, word [ecx];\n"                                                                                           \
    "imul di, word [edx];\n"                                                                                           \
    "imul di, word [edi];\n"                                                                                           \
    "imul di, word [r8d];\n"                                                                                           \
    "imul di, word [r9d];\n"                                                                                           \
    "imul di, word [r10d];\n"                                                                                          \
    "imul di, word [r11d];\n"                                                                                          \
    "imul di, word [r12d];\n"                                                                                          \
    "imul di, word [r13d];\n"                                                                                          \
    "imul di, word [r14d];\n"                                                                                          \
    "imul di, word [r15d];\n"                                                                                          \
    "imul di, word [esp];\n"                                                                                           \
    "imul di, word [esi];\n"                                                                                           \
    "imul di, word [ebp];\n"                                                                                           \
    "imul r8w, word [eax];\n"                                                                                          \
    "imul r8w, word [ebx];\n"                                                                                          \
    "imul r8w, word [ecx];\n"                                                                                          \
    "imul r8w, word [edx];\n"                                                                                          \
    "imul r8w, word [edi];\n"                                                                                          \
    "imul r8w, word [r8d];\n"                                                                                          \
    "imul r8w, word [r9d];\n"                                                                                          \
    "imul r8w, word [r10d];\n"                                                                                         \
    "imul r8w, word [r11d];\n"                                                                                         \
    "imul r8w, word [r12d];\n"                                                                                         \
    "imul r8w, word [r13d];\n"                                                                                         \
    "imul r8w, word [r14d];\n"                                                                                         \
    "imul r8w, word [r15d];\n"                                                                                         \
    "imul r8w, word [esp];\n"                                                                                          \
    "imul r8w, word [esi];\n"                                                                                          \
    "imul r8w, word [ebp];\n"                                                                                          \
    "imul r9w, word [eax];\n"                                                                                          \
    "imul r9w, word [ebx];\n"                                                                                          \
    "imul r9w, word [ecx];\n"                                                                                          \
    "imul r9w, word [edx];\n"                                                                                          \
    "imul r9w, word [edi];\n"                                                                                          \
    "imul r9w, word [r8d];\n"                                                                                          \
    "imul r9w, word [r9d];\n"                                                                                          \
    "imul r9w, word [r10d];\n"                                                                                         \
    "imul r9w, word [r11d];\n"                                                                                         \
    "imul r9w, word [r12d];\n"                                                                                         \
    "imul r9w, word [r13d];\n"                                                                                         \
    "imul r9w, word [r14d];\n"                                                                                         \
    "imul r9w, word [r15d];\n"                                                                                         \
    "imul r9w, word [esp];\n"                                                                                          \
    "imul r9w, word [esi];\n"                                                                                          \
    "imul r9w, word [ebp];\n"                                                                                          \
    "imul r10w, word [eax];\n"                                                                                         \
    "imul r10w, word [ebx];\n"                                                                                         \
    "imul r10w, word [ecx];\n"                                                                                         \
    "imul r10w, word [edx];\n"                                                                                         \
    "imul r10w, word [edi];\n"                                                                                         \
    "imul r10w, word [r8d];\n"                                                                                         \
    "imul r10w, word [r9d];\n"                                                                                         \
    "imul r10w, word [r10d];\n"                                                                                        \
    "imul r10w, word [r11d];\n"                                                                                        \
    "imul r10w, word [r12d];\n"                                                                                        \
    "imul r10w, word [r13d];\n"                                                                                        \
    "imul r10w, word [r14d];\n"                                                                                        \
    "imul r10w, word [r15d];\n"                                                                                        \
    "imul r10w, word [esp];\n"                                                                                         \
    "imul r10w, word [esi];\n"                                                                                         \
    "imul r10w, word [ebp];\n"                                                                                         \
    "imul r11w, word [eax];\n"                                                                                         \
    "imul r11w, word [ebx];\n"                                                                                         \
    "imul r11w, word [ecx];\n"                                                                                         \
    "imul r11w, word [edx];\n"                                                                                         \
    "imul r11w, word [edi];\n"                                                                                         \
    "imul r11w, word [r8d];\n"                                                                                         \
    "imul r11w, word [r9d];\n"                                                                                         \
    "imul r11w, word [r10d];\n"                                                                                        \
    "imul r11w, word [r11d];\n"                                                                                        \
    "imul r11w, word [r12d];\n"                                                                                        \
    "imul r11w, word [r13d];\n"                                                                                        \
    "imul r11w, word [r14d];\n"                                                                                        \
    "imul r11w, word [r15d];\n"                                                                                        \
    "imul r11w, word [esp];\n"                                                                                         \
    "imul r11w, word [esi];\n"                                                                                         \
    "imul r11w, word [ebp];\n"                                                                                         \
    "imul r12w, word [eax];\n"                                                                                         \
    "imul r12w, word [ebx];\n"                                                                                         \
    "imul r12w, word [ecx];\n"                                                                                         \
    "imul r12w, word [edx];\n"                                                                                         \
    "imul r12w, word [edi];\n"                                                                                         \
    "imul r12w, word [r8d];\n"                                                                                         \
    "imul r12w, word [r9d];\n"                                                                                         \
    "imul r12w, word [r10d];\n"                                                                                        \
    "imul r12w, word [r11d];\n"                                                                                        \
    "imul r12w, word [r12d];\n"                                                                                        \
    "imul r12w, word [r13d];\n"                                                                                        \
    "imul r12w, word [r14d];\n"                                                                                        \
    "imul r12w, word [r15d];\n"                                                                                        \
    "imul r12w, word [esp];\n"                                                                                         \
    "imul r12w, word [esi];\n"                                                                                         \
    "imul r12w, word [ebp];\n"                                                                                         \
    "imul r13w, word [eax];\n"                                                                                         \
    "imul r13w, word [ebx];\n"                                                                                         \
    "imul r13w, word [ecx];\n"                                                                                         \
    "imul r13w, word [edx];\n"                                                                                         \
    "imul r13w, word [edi];\n"                                                                                         \
    "imul r13w, word [r8d];\n"                                                                                         \
    "imul r13w, word [r9d];\n"                                                                                         \
    "imul r13w, word [r10d];\n"                                                                                        \
    "imul r13w, word [r11d];\n"                                                                                        \
    "imul r13w, word [r12d];\n"                                                                                        \
    "imul r13w, word [r13d];\n"                                                                                        \
    "imul r13w, word [r14d];\n"                                                                                        \
    "imul r13w, word [r15d];\n"                                                                                        \
    "imul r13w, word [esp];\n"                                                                                         \
    "imul r13w, word [esi];\n"                                                                                         \
    "imul r13w, word [ebp];\n"                                                                                         \
    "imul r14w, word [eax];\n"                                                                                         \
    "imul r14w, word [ebx];\n"                                                                                         \
    "imul r14w, word [ecx];\n"                                                                                         \
    "imul r14w, word [edx];\n"                                                                                         \
    "imul r14w, word [edi];\n"                                                                                         \
    "imul r14w, word [r8d];\n"                                                                                         \
    "imul r14w, word [r9d];\n"                                                                                         \
    "imul r14w, word [r10d];\n"                                                                                        \
    "imul r14w, word [r11d];\n"                                                                                        \
    "imul r14w, word [r12d];\n"                                                                                        \
    "imul r14w, word [r13d];\n"                                                                                        \
    "imul r14w, word [r14d];\n"                                                                                        \
    "imul r14w, word [r15d];\n"                                                                                        \
    "imul r14w, word [esp];\n"                                                                                         \
    "imul r14w, word [esi];\n"                                                                                         \
    "imul r14w, word [ebp];\n"                                                                                         \
    "imul r15w, word [eax];\n"                                                                                         \
    "imul r15w, word [ebx];\n"                                                                                         \
    "imul r15w, word [ecx];\n"                                                                                         \
    "imul r15w, word [edx];\n"                                                                                         \
    "imul r15w, word [edi];\n"                                                                                         \
    "imul r15w, word [r8d];\n"                                                                                         \
    "imul r15w, word [r9d];\n"                                                                                         \
    "imul r15w, word [r10d];\n"                                                                                        \
    "imul r15w, word [r11d];\n"                                                                                        \
    "imul r15w, word [r12d];\n"                                                                                        \
    "imul r15w, word [r13d];\n"                                                                                        \
    "imul r15w, word [r14d];\n"                                                                                        \
    "imul r15w, word [r15d];\n"                                                                                        \
    "imul r15w, word [esp];\n"                                                                                         \
    "imul r15w, word [esi];\n"                                                                                         \
    "imul r15w, word [ebp];\n"                                                                                         \
    "imul sp, word [eax];\n"                                                                                           \
    "imul sp, word [ebx];\n"                                                                                           \
    "imul sp, word [ecx];\n"                                                                                           \
    "imul sp, word [edx];\n"                                                                                           \
    "imul sp, word [edi];\n"                                                                                           \
    "imul sp, word [r8d];\n"                                                                                           \
    "imul sp, word [r9d];\n"                                                                                           \
    "imul sp, word [r10d];\n"                                                                                          \
    "imul sp, word [r11d];\n"                                                                                          \
    "imul sp, word [r12d];\n"                                                                                          \
    "imul sp, word [r13d];\n"                                                                                          \
    "imul sp, word [r14d];\n"                                                                                          \
    "imul sp, word [r15d];\n"                                                                                          \
    "imul sp, word [esp];\n"                                                                                           \
    "imul sp, word [esi];\n"                                                                                           \
    "imul sp, word [ebp];\n"                                                                                           \
    "imul si, word [eax];\n"                                                                                           \
    "imul si, word [ebx];\n"                                                                                           \
    "imul si, word [ecx];\n"                                                                                           \
    "imul si, word [edx];\n"                                                                                           \
    "imul si, word [edi];\n"                                                                                           \
    "imul si, word [r8d];\n"                                                                                           \
    "imul si, word [r9d];\n"                                                                                           \
    "imul si, word [r10d];\n"                                                                                          \
    "imul si, word [r11d];\n"                                                                                          \
    "imul si, word [r12d];\n"                                                                                          \
    "imul si, word [r13d];\n"                                                                                          \
    "imul si, word [r14d];\n"                                                                                          \
    "imul si, word [r15d];\n"                                                                                          \
    "imul si, word [esp];\n"                                                                                           \
    "imul si, word [esi];\n"                                                                                           \
    "imul si, word [ebp];\n"                                                                                           \
    "imul bp, word [eax];\n"                                                                                           \
    "imul bp, word [ebx];\n"                                                                                           \
    "imul bp, word [ecx];\n"                                                                                           \
    "imul bp, word [edx];\n"                                                                                           \
    "imul bp, word [edi];\n"                                                                                           \
    "imul bp, word [r8d];\n"                                                                                           \
    "imul bp, word [r9d];\n"                                                                                           \
    "imul bp, word [r10d];\n"                                                                                          \
    "imul bp, word [r11d];\n"                                                                                          \
    "imul bp, word [r12d];\n"                                                                                          \
    "imul bp, word [r13d];\n"                                                                                          \
    "imul bp, word [r14d];\n"                                                                                          \
    "imul bp, word [r15d];\n"                                                                                          \
    "imul bp, word [esp];\n"                                                                                           \
    "imul bp, word [esi];\n"                                                                                           \
    "imul bp, word [ebp];\n"                                                                                           \
    "imul rax;\n"                                                                                                      \
    "imul rbx;\n"                                                                                                      \
    "imul rcx;\n"                                                                                                      \
    "imul rdx;\n"                                                                                                      \
    "imul rdi;\n"                                                                                                      \
    "imul r8;\n"                                                                                                       \
    "imul r9;\n"                                                                                                       \
    "imul r10;\n"                                                                                                      \
    "imul r11;\n"                                                                                                      \
    "imul r12;\n"                                                                                                      \
    "imul r13;\n"                                                                                                      \
    "imul r14;\n"                                                                                                      \
    "imul r15;\n"                                                                                                      \
    "imul rsp;\n"                                                                                                      \
    "imul rsi;\n"                                                                                                      \
    "imul rbp;\n"                                                                                                      \
    "imul eax;\n"                                                                                                      \
    "imul ebx;\n"                                                                                                      \
    "imul ecx;\n"                                                                                                      \
    "imul edx;\n"                                                                                                      \
    "imul edi;\n"                                                                                                      \
    "imul r8d;\n"                                                                                                      \
    "imul r9d;\n"                                                                                                      \
    "imul r10d;\n"                                                                                                     \
    "imul r11d;\n"                                                                                                     \
    "imul r12d;\n"                                                                                                     \
    "imul r13d;\n"                                                                                                     \
    "imul r14d;\n"                                                                                                     \
    "imul r15d;\n"                                                                                                     \
    "imul esp;\n"                                                                                                      \
    "imul esi;\n"                                                                                                      \
    "imul ebp;\n"                                                                                                      \
    "imul ax;\n"                                                                                                       \
    "imul bx;\n"                                                                                                       \
    "imul cx;\n"                                                                                                       \
    "imul dx;\n"                                                                                                       \
    "imul di;\n"                                                                                                       \
    "imul r8w;\n"                                                                                                      \
    "imul r9w;\n"                                                                                                      \
    "imul r10w;\n"                                                                                                     \
    "imul r11w;\n"                                                                                                     \
    "imul r12w;\n"                                                                                                     \
    "imul r13w;\n"                                                                                                     \
    "imul r14w;\n"                                                                                                     \
    "imul r15w;\n"                                                                                                     \
    "imul sp;\n"                                                                                                       \
    "imul si;\n"                                                                                                       \
    "imul bp;\n"                                                                                                       \
    "imul al;\n"                                                                                                       \
    "imul bl;\n"                                                                                                       \
    "imul cl;\n"                                                                                                       \
    "imul dl;\n"                                                                                                       \
    "imul dl;\n"                                                                                                       \
    "imul r8b;\n"                                                                                                      \
    "imul r9b;\n"                                                                                                      \
    "imul r10b;\n"                                                                                                     \
    "imul r11b;\n"                                                                                                     \
    "imul r12b;\n"                                                                                                     \
    "imul r13b;\n"                                                                                                     \
    "imul r14b;\n"                                                                                                     \
    "imul r15b;\n"                                                                                                     \
    "imul spl;\n"                                                                                                      \
    "imul sil;\n"                                                                                                      \
    "imul bpl;\n"                                                                                                      \
    ""
