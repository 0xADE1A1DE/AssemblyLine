#define CODE                                                                                                           \
    "mov r9, 0x11111111;\n"                                                                                            \
    "mov r10, 0x22222222;\n"                                                                                           \
    "movq xmm0, r9;\n"                                                                                                 \
    "movq xmm1, r10;\n"                                                                                                \
    "punpcklqdq xmm0, xmm1 ;\n"                                                                                        \
    "psrldq xmm0, 8;\n"                                                                                                \
    "psrldq xmm15, 8;\n"                                                                                               \
    "movq rax, xmm0;\n"                                                                                                \
    "ret ;\n"
