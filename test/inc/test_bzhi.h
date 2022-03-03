#define CODE                                                                                                           \
    "bzhi r9, rax, rax;\n"                                                                                             \
    "bzhi r9, rcx, rcx;\n"                                                                                             \
    "bzhi r9, rdx, rdi;\n"                                                                                             \
    "bzhi r9, rsp, r8;\n"                                                                                              \
    "bzhi r9, r12, r10;\n"                                                                                             \
    "bzhi r9, rax, rsi;\n"                                                                                             \
    "bzhi rsp, rax, rsi;\n"                                                                                            \
    "bzhi r9, [rsp + 0x28], r9;\n"                                                                                     \
    "bzhi r11, [rsp + 0x8], r11;\n"                                                                                    \
    "bzhi r11, r13, r11;\n"                                                                                            \
    ""
