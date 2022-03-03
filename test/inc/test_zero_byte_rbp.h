#define CODE                                                                                                           \
    "mov [rbp], rbx;\n"                                                                                                \
    "mov [rbp], rbp;\n"                                                                                                \
    "mov [rbp], r12;\n"                                                                                                \
    "mov [rbp], r13;\n"                                                                                                \
    "mov [rbp], r14;\n"                                                                                                \
    "mov [rbp], r15;\n"                                                                                                \
    "imul r11, [rbp], 0x13;\n"                                                                                         \
    "imul r15, [rbp], 0x13;\n"                                                                                         \
    "mulx r9, r10, [rbp];\n"                                                                                           \
    "imul r14, [rbp], 0x2;\n"                                                                                          \
    "mov rdx, [rbp];\n"                                                                                                \
    "mov rdx, [rbp];\n"                                                                                                \
    "mulx r8, rbp, [rbp];\n"                                                                                           \
    "mulx rcx, r13, [rbp];\n"                                                                                          \
    "mov rdx, [rbp];\n"                                                                                                \
    "mov [rbp], rcx;\n"                                                                                                \
    "adcx r15, [rbp];\n"                                                                                               \
    "mulx rdx, rbp, [rbp];\n"                                                                                          \
    "mov rdx, [rbp];\n"                                                                                                \
    "mulx r10, r9, [rbp];\n"                                                                                           \
    "mulx rdx, rbx, [rbp];\n"                                                                                          \
    "imul r12, [rbp], 0x2;\n"                                                                                          \
    "imul r15, [rbp], 0x2;\n"                                                                                          \
    "mov rdx, [rbp];\n"                                                                                                \
    "mov rdx, [rbp];\n"                                                                                                \
    "mov [rbp], rcx;\n"                                                                                                \
    "mov [rbp], rax;\n"                                                                                                \
    "lea rdx, [rbp];\n"                                                                                                \
    "mov r8, [rbp];\n"                                                                                                 \
    "mov rdx, [rbp];\n"                                                                                                \
    "imul r14, [rbp], 0x2;\n"                                                                                          \
    "mulx r15, r11, [rbp];\n"                                                                                          \
    "mulx rdx, r10, [rbp];\n"                                                                                          \
    "mov rdx, [rbp];\n"                                                                                                \
    "mulx r13, r12, [rbp];\n"                                                                                          \
    "mulx rdx, r14, [rbp];\n"                                                                                          \
    "add r12, [rbp];\n"                                                                                                \
    "mov r15, [rbp];\n"                                                                                                \
    "mov [rbp], r8;\n"                                                                                                 \
    "lea r10, [rbp];\n"                                                                                                \
    "mov [rbp], r12;\n"                                                                                                \
    "mov [rbp], rcx;\n"                                                                                                \
    "lea r13, [rbp];\n"                                                                                                \
    "mov [rbp], r10;\n"                                                                                                \
    "mov [rbp], r13;\n"                                                                                                \
    "mov rbx, [rbp];\n"                                                                                                \
    "mov rbp, [rbp];\n"                                                                                                \
    "mov r12, [rbp];\n"                                                                                                \
    "mov r13, [rbp];\n"                                                                                                \
    "mov r14, [rbp];\n"                                                                                                \
    "mov r15, [rbp];\n"                                                                                                \
    ""
