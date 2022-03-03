#define CODE                                                                                                           \
    "mov rcx, 0xffffffff ;\n"                                                                                          \
    "mov r12, 0x21524110;\n"                                                                                           \
    "movq xmm4, rcx;\n"                                                                                                \
    "movq xmm7, r12;\n"                                                                                                \
    "psubq xmm4, xmm7;\n"                                                                                              \
    "movq xmm5, xmm4;\n"                                                                                               \
    "movq rax, xmm5;\n"                                                                                                \
    "ret;\n" 
