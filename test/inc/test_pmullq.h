#define CODE                                                                                                           \
    "vpmullq xmm1, xmm2, xmm3;\n"                                                                                      \
    "vpmullq xmm1, xmm2, [rax + 8];\n"                                                                                 \
    "vpmullq ymm1, ymm2, ymm3;\n"                                                                                      \
    "vpmullq ymm1, ymm2, [rsp - 0x40];\n"                                                                              \
    "vpmullq zmm1, zmm2, zmm3;\n"                                                                                      \
    "vpmullq zmm1, zmm2, [rax];\n"                                                                                     \
    ""
