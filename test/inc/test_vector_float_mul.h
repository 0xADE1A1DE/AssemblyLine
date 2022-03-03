#define CODE                                                                                                           \
    "mov rcx, 0x6 ;\n"                                                                                                 \
    "mov r12, 0x2;\n"                                                                                                  \
    "movq xmm4, rcx;\n"                                                                                                \
    "movq xmm7, r12;\n"                                                                                                \
    "cvtdq2pd xmm4, xmm4;\n"                                                                                           \
    "cvtdq2pd xmm7, xmm7;\n"                                                                                           \
    "mulpd xmm4, xmm7;\n"                                                                                              \
    "movq xmm5, xmm4;\n"                                                                                               \
    "cvtpd2dq xmm5, xmm5;\n"                                                                                           \
    "movq rax, xmm5;\n"                                                                                                \
    "ret;\n"                                                                                                           \
    ""
