#define CODE                                                                                                           \
    "sfence;\n"                                                                                                        \
    "lfence;\n"                                                                                                        \
    "mfence;\n"                                                                                                        \
    "clflush [r12];\n"                                                                                                 \
    "xchg rax, rbp ;\n"                                                                                                \
    "add rax, 0xfff;\n"                                                                                                \
    "xend;\n"                                                                                                          \
    ""
