#define CODE                                                                                                           \
    "mov rcx, 0x143e572d ;\n"                                                                                          \
    "mov r12, 0xb;\n"                                                                                                  \
    "movq xmm4, rcx;\n"                                                                                                \
    "movq xmm7, r12;\n"                                                                                                \
    "pmuldq xmm4, xmm7;\n"                                                                                             \
    "movq xmm5, xmm4;\n"                                                                                               \
    "movq rax, xmm5;\n"                                                                                                \
    "ret;\n"                                                                                                           \
    ""
