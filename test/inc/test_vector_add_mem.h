#define CODE                                                                                                           \
    ";\n"                                                                                                              \
    "movq xmm4, [rcx];\n"                                                                                              \
    "movq xmm7, [r12];\n"                                                                                              \
    "paddq xmm4, xmm7;\n"                                                                                              \
    "movq xmm5, xmm4;\n"                                                                                               \
    "movq rax, xmm5;\n"                                                                                                \
    "ret;\n"                                                                                                           \
    ""
