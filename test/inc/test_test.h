#define CODE                                                                                                           \
    "test r10, r11;\n"                                                                                                 \
    "test rax, rax;\n"                                                                                                 \
    "test r10, r12;\n"                                                                                                 \
    "test r10, r13;\n"                                                                                                 \
    "test r10, r14;\n"                                                                                                 \
    "test r10, r15;\n"                                                                                                 \
    "test r10, r8;\n"                                                                                                  \
    "test r10, r9;\n"                                                                                                  \
    "test r10, rax;\n"                                                                                                 \
    "test r10, rbp;\n"                                                                                                 \
    "test r10, rbx;\n"                                                                                                 \
    "test r10, rcx;\n"                                                                                                 \
    "test r10, rdi;\n"                                                                                                 \
    "test r10, rdx;\n"                                                                                                 \
    "test r10, rsi;\n"                                                                                                 \
    "test [ rsp + 0x11f0 ], r10;\n"                                                                                    \
    "test [ rsp + 0x19f0 ], r10;\n"                                                                                    \
    "test [ rsp + 0x1b10 ], r10;\n"                                                                                    \
    "test [ rsp + 0x1c10 ], r10;\n"                                                                                    \
    "test [ rsp + 0x1c8 ] , r10;\n"                                                                                    \
    "test [ rsp + 0x1de8 ], r10;\n"                                                                                    \
    "test [ rsp + 0x1f90 ], r10;\n"                                                                                    \
    "test [ rsp + 0x2708 ], r10;\n"                                                                                    \
    "test [ rsp + 0x2970 ], r10;\n"                                                                                    \
    "test [ rsp + 0x2e10 ], r10;\n"                                                                                    \
    "test [ rsp + 0x30e0 ], r10;\n"                                                                                    \
    "test [ rsp + 0x35c0 ], r10;\n"                                                                                    \
    "test [ rsp + 0x460 ] , r10;\n"                                                                                    \
    "test [ rsp + 0x680 ] , r10;\n"                                                                                    \
    "test [ rsp + 0xb48 ] , r10;\n"                                                                                    \
    ""
