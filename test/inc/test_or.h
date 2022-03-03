#define CODE                                                                                                           \
    "or rsp, 0x39a8 ;\n"                                                                                               \
    "or r10, r11;\n"                                                                                                   \
    "or r10, r12;\n"                                                                                                   \
    "or r10, r13;\n"                                                                                                   \
    "or r10, r14;\n"                                                                                                   \
    "or r10, r15;\n"                                                                                                   \
    "or r10, r8;\n"                                                                                                    \
    "or r10, r9;\n"                                                                                                    \
    "or r10, rax;\n"                                                                                                   \
    "or r10, rbp;\n"                                                                                                   \
    "or r10, rbx;\n"                                                                                                   \
    "or r10, rcx;\n"                                                                                                   \
    "or r10, rdi;\n"                                                                                                   \
    "or r10, rdx;\n"                                                                                                   \
    "or r10, rsi;\n"                                                                                                   \
    "or r10, [ rsp + 0x11f0 ];\n"                                                                                      \
    "or r10, [ rsp + 0x19f0 ];\n"                                                                                      \
    "or r10, [ rsp + 0x1b10 ];\n"                                                                                      \
    "or r10, [ rsp + 0x1c10 ];\n"                                                                                      \
    "or r10, [ rsp + 0x1c8 ];\n"                                                                                       \
    "or r10, [ rsp + 0x1de8 ];\n"                                                                                      \
    "or r10, [ rsp + 0x1f90 ];\n"                                                                                      \
    "or r10, [ rsp + 0x2708 ];\n"                                                                                      \
    "or r10, [ rsp + 0x2970 ];\n"                                                                                      \
    "or r10, [ rsp + 0x2e10 ];\n"                                                                                      \
    "or r10, [ rsp + 0x30e0 ];\n"                                                                                      \
    "or r10, [ rsp + 0x35c0 ];\n"                                                                                      \
    "or r10, [ rsp + 0x460 ];\n"                                                                                       \
    "or r10, [ rsp + 0x680 ];\n"                                                                                       \
    "or r10, [ rsp + 0xb48 ];\n"                                                                                       \
    "or r11, r10;\n"                                                                                                   \
    "or r11, r12;\n"                                                                                                   \
    "or r11, r13;\n"                                                                                                   \
    "or r11, r14;\n"                                                                                                   \
    "or r11, r15;\n"                                                                                                   \
    "or r11, r8;\n"                                                                                                    \
    "or r11, r9;\n"                                                                                                    \
    "or r11, rax;\n"                                                                                                   \
    "or r11, rcx;\n"                                                                                                   \
    "or r11, rdi;\n"                                                                                                   \
    "or r11, rsi;\n"                                                                                                   \
    "or r11, [ rsp + 0x14a0 ];\n"                                                                                      \
    "or r11, [ rsp + 0x158 ];\n"                                                                                       \
    "or r11, [ rsp + 0x1750 ];\n"                                                                                      \
    "or r11, [ rsp + 0x2218 ];\n"                                                                                      \
    "or r11, [ rsp + 0x24b0 ];\n"                                                                                      \
    "or r11, [ rsp + 0x2688 ];\n"                                                                                      \
    "or r11, [ rsp + 0x26c0 ];\n"                                                                                      \
    "or r11, [ rsp + 0x2920 ];\n"                                                                                      \
    "or r11, [ rsp + 0x2938 ];\n"                                                                                      \
    "or r11, [ rsp + 0x29b0 ];\n"                                                                                      \
    "or r11, [ rsp + 0x3780 ];\n"                                                                                      \
    "or r11, [ rsp + 0x37e8 ];\n"                                                                                      \
    "or r11, [ rsp + 0xbd8 ];\n"                                                                                       \
    "or r12, r10;\n"                                                                                                   \
    "or r12, r11;\n"                                                                                                   \
    "or r12, r13;\n"                                                                                                   \
    "or r12, r14;\n"                                                                                                   \
    "or r12, r15;\n"                                                                                                   \
    "or r12, r9;\n"                                                                                                    \
    "or r12, rax;\n"                                                                                                   \
    "or r12, rbp;\n"                                                                                                   \
    "or r12, rbx;\n"                                                                                                   \
    "or r12, rcx;\n"                                                                                                   \
    "or r12, rdi;\n"                                                                                                   \
    "or r12, rdx;\n"                                                                                                   \
    "or r12, rsi;\n"                                                                                                   \
    "or r12, [ rsp + 0x1048 ];\n"                                                                                      \
    "or r12, [ rsp + 0x12a0 ];\n"                                                                                      \
    "or r12, [ rsp + 0x1428 ];\n"                                                                                      \
    "or r12, [ rsp + 0x16c8 ];\n"                                                                                      \
    "or r12, [ rsp + 0x220 ];\n"                                                                                       \
    "or r12, [ rsp + 0x23b8 ];\n"                                                                                      \
    "or r12, [ rsp + 0x2520 ];\n"                                                                                      \
    "or r12, [ rsp + 0x2528 ];\n"                                                                                      \
    "or r12, [ rsp + 0x29a8 ];\n"                                                                                      \
    "or r12, [ rsp + 0x2be8 ];\n"                                                                                      \
    "or r12, [ rsp + 0x910 ];\n"                                                                                       \
    "or r13, r11;\n"                                                                                                   \
    "or r13, r12;\n"                                                                                                   \
    "or r13, r15;\n"                                                                                                   \
    "or r13, r8;\n"                                                                                                    \
    "or r13, r9;\n"                                                                                                    \
    "or r13, rax;\n"                                                                                                   \
    "or r13, rbp;\n"                                                                                                   \
    "or r13, rcx;\n"                                                                                                   \
    "or r13, rdi;\n"                                                                                                   \
    "or r13, rdx;\n"                                                                                                   \
    "or r13, rsi;\n"                                                                                                   \
    "or r13, [ rsp + 0x110 ];\n"                                                                                       \
    "or r13, [ rsp + 0x14c0 ];\n"                                                                                      \
    "or r13, [ rsp + 0x1d90 ];\n"                                                                                      \
    "or r13, [ rsp + 0x1fe8 ];\n"                                                                                      \
    "or r13, [ rsp + 0x2228 ];\n"                                                                                      \
    "or r13, [ rsp + 0x2780 ];\n"                                                                                      \
    "or r13, [ rsp + 0x27d0 ];\n"                                                                                      \
    "or r13, [ rsp + 0x2c20 ];\n"                                                                                      \
    "or r13, [ rsp + 0x3658 ];\n"                                                                                      \
    "or r13, [ rsp + 0x3c8 ];\n"                                                                                       \
    "or r13, [ rsp + 0xe08 ];\n"                                                                                       \
    "or r14, r10;\n"                                                                                                   \
    "or r14, r11;\n"                                                                                                   \
    "or r14, r12;\n"                                                                                                   \
    "or r14, r13;\n"                                                                                                   \
    "or r14, r15;\n"                                                                                                   \
    "or r14, r8;\n"                                                                                                    \
    "or r14, r9;\n"                                                                                                    \
    "or r14, rax;\n"                                                                                                   \
    "or r14, rbp;\n"                                                                                                   \
    "or r14, rcx;\n"                                                                                                   \
    "or r14, rdx;\n"                                                                                                   \
    "or r14, rsi;\n"                                                                                                   \
    "or r14, [ rsp + 0x13e8 ];\n"                                                                                      \
    "or r14, [ rsp + 0x17b0 ];\n"                                                                                      \
    "or r14, [ rsp + 0x18c8 ];\n"                                                                                      \
    "or r14, [ rsp + 0x1aa0 ];\n"                                                                                      \
    "or r14, [ rsp + 0x1e58 ];\n"                                                                                      \
    "or r14, [ rsp + 0x2088 ];\n"                                                                                      \
    "or r14, [ rsp + 0x20e8 ];\n"                                                                                      \
    "or r14, [ rsp + 0x2498 ];\n"                                                                                      \
    "or r14, [ rsp + 0x2a10 ];\n"                                                                                      \
    "or r14, [ rsp + 0x2da0 ];\n"                                                                                      \
    "or r14, [ rsp + 0x32c0 ];\n"                                                                                      \
    "or r14, [ rsp + 0x34f8 ];\n"                                                                                      \
    "or r14, [ rsp + 0x3600 ];\n"                                                                                      \
    "or r14, [ rsp + 0x3a8 ];\n"                                                                                       \
    "or r14, [ rsp + 0x600 ];\n"                                                                                       \
    "or r14, [ rsp + 0x848 ];\n"                                                                                       \
    "or r14, [ rsp + 0xdc8 ];\n"                                                                                       \
    "or r15, r10;\n"                                                                                                   \
    "or r15, r11;\n"                                                                                                   \
    "or r15, r13;\n"                                                                                                   \
    "or r15, r8;\n"                                                                                                    \
    "or r15, r9;\n"                                                                                                    \
    "or r15, rax;\n"                                                                                                   \
    "or r15, rbp;\n"                                                                                                   \
    "or r15, rbx;\n"                                                                                                   \
    "or r15, rcx;\n"                                                                                                   \
    "or r15, rdi;\n"                                                                                                   \
    "or r15, rdx;\n"                                                                                                   \
    "or r15, rsi;\n"                                                                                                   \
    "or r15, [ rsp + 0x1910 ];\n"                                                                                      \
    "or r15, [ rsp + 0x1968 ];\n"                                                                                      \
    "or r15, [ rsp + 0x1b58 ];\n"                                                                                      \
    "or r15, [ rsp + 0x1d0 ];\n"                                                                                       \
    "or r15, [ rsp + 0x30c8 ];\n"                                                                                      \
    "or r15, [ rsp + 0x3110 ];\n"                                                                                      \
    "or r15, [ rsp + 0x3140 ];\n"                                                                                      \
    "or r15, [ rsp + 0x8f8 ];\n"                                                                                       \
    "or r15, [ rsp + 0xb70 ];\n"                                                                                       \
    "or r15, [ rsp + 0xbe0 ];\n"                                                                                       \
    "or r15, [ rsp + 0xd50 ];\n"                                                                                       \
    "or r8, r11;\n"                                                                                                    \
    "or r8, r12;\n"                                                                                                    \
    "or r8, r13;\n"                                                                                                    \
    "or r8, r14;\n"                                                                                                    \
    "or r8, r15;\n"                                                                                                    \
    "or r8, r9;\n"                                                                                                     \
    "or r8, rax;\n"                                                                                                    \
    "or r8, rbp;\n"                                                                                                    \
    "or r8, rbx;\n"                                                                                                    \
    "or r8, rcx;\n"                                                                                                    \
    "or r8, rdi;\n"                                                                                                    \
    "or r8, rdx;\n"                                                                                                    \
    "or r8, [ rsp + 0x1270 ];\n"                                                                                       \
    "or r8, [ rsp + 0x14b0 ];\n"                                                                                       \
    "or r8, [ rsp + 0x1700 ];\n"                                                                                       \
    "or r8, [ rsp + 0x1730 ];\n"                                                                                       \
    "or r8, [ rsp + 0x1c08 ];\n"                                                                                       \
    "or r8, [ rsp + 0x1fe0 ];\n"                                                                                       \
    "or r8, [ rsp + 0x2110 ];\n"                                                                                       \
    "or r8, [ rsp + 0x2500 ];\n"                                                                                       \
    "or r8, [ rsp + 0x2e48 ];\n"                                                                                       \
    "or r8, [ rsp + 0x3380 ];\n"                                                                                       \
    "or r8, [ rsp + 0x3488 ];\n"                                                                                       \
    "or r8, [ rsp + 0x38e8 ];\n"                                                                                       \
    "or r8, [ rsp + 0x440 ];\n"                                                                                        \
    "or r8, [ rsp + 0x6b8 ];\n"                                                                                        \
    "or r8, [ rsp + 0xb90 ];\n"                                                                                        \
    "or r8, [ rsp + 0xe18 ];\n"                                                                                        \
    "or r8, [ rsp + 0xea0 ];\n"                                                                                        \
    "or r8, [ rsp + 0xf78 ];\n"                                                                                        \
    "or r8, [ rsp + 0xfe0 ];\n"                                                                                        \
    "or r9, r10;\n"                                                                                                    \
    "or r9, r11;\n"                                                                                                    \
    "or r9, r12;\n"                                                                                                    \
    "or r9, r14;\n"                                                                                                    \
    "or r9, r15;\n"                                                                                                    \
    "or r9, r8;\n"                                                                                                     \
    "or r9, rax;\n"                                                                                                    \
    "or r9, rbp;\n"                                                                                                    \
    "or r9, rbx;\n"                                                                                                    \
    "or r9, rcx;\n"                                                                                                    \
    "or r9, rdi;\n"                                                                                                    \
    "or r9, rsi;\n"                                                                                                    \
    "or r9, [ rsp + 0x1030 ];\n"                                                                                       \
    "or r9, [ rsp + 0x1b70 ];\n"                                                                                       \
    "or r9, [ rsp + 0x2310 ];\n"                                                                                       \
    "or r9, [ rsp + 0x2318 ];\n"                                                                                       \
    "or r9, [ rsp + 0x26f8 ];\n"                                                                                       \
    "or r9, [ rsp + 0x27c8 ];\n"                                                                                       \
    "or r9, [ rsp + 0x27d8 ];\n"                                                                                       \
    "or r9, [ rsp + 0x3860 ];\n"                                                                                       \
    "or r9, [ rsp + 0x3958 ];\n"                                                                                       \
    "or r9, [ rsp + 0xf70 ];\n"                                                                                        \
    "or rax, r10;\n"                                                                                                   \
    "or rax, r11;\n"                                                                                                   \
    "or rax, r12;\n"                                                                                                   \
    "or rax, r14;\n"                                                                                                   \
    "or rax, r15;\n"                                                                                                   \
    "or rax, r8;\n"                                                                                                    \
    "or rax, r9;\n"                                                                                                    \
    "or rax, rbp;\n"                                                                                                   \
    "or rax, rbx;\n"                                                                                                   \
    "or rax, rcx;\n"                                                                                                   \
    "or rax, rdx;\n"                                                                                                   \
    "or rax, rsi;\n"                                                                                                   \
    "or rax, [ rsp + 0x1198 ];\n"                                                                                      \
    "or rax, [ rsp + 0x11e8 ];\n"                                                                                      \
    "or rax, [ rsp + 0x2b10 ];\n"                                                                                      \
    "or rax, [ rsp + 0x2b70 ];\n"                                                                                      \
    "or rax, [ rsp + 0x2ea0 ];\n"                                                                                      \
    "or rax, [ rsp + 0x3118 ];\n"                                                                                      \
    "or rax, [ rsp + 0x3288 ];\n"                                                                                      \
    "or rax, [ rsp + 0x34b8 ];\n"                                                                                      \
    "or rax, [ rsp + 0x35f0 ];\n"                                                                                      \
    "or rax, [ rsp + 0x3700 ];\n"                                                                                      \
    "or rax, [ rsp + 0x4b0 ];\n"                                                                                       \
    "or rax, [ rsp + 0x978 ];\n"                                                                                       \
    "or rax, [ rsp + 0xb88 ];\n"                                                                                       \
    "or rbp, r10;\n"                                                                                                   \
    "or rbp, r12;\n"                                                                                                   \
    "or rbp, r13;\n"                                                                                                   \
    "or rbp, r15;\n"                                                                                                   \
    "or rbp, r8;\n"                                                                                                    \
    "or rbp, r9;\n"                                                                                                    \
    "or rbp, rax;\n"                                                                                                   \
    "or rbp, rsi;\n"                                                                                                   \
    "or rbp, [ rsp + 0x1470 ];\n"                                                                                      \
    "or rbp, [ rsp + 0x1970 ];\n"                                                                                      \
    "or rbp, [ rsp + 0x1f80 ];\n"                                                                                      \
    "or rbp, [ rsp + 0x20a0 ];\n"                                                                                      \
    "or rbp, [ rsp + 0x2878 ];\n"                                                                                      \
    "or rbp, [ rsp + 0x29d0 ];\n"                                                                                      \
    "or rbp, [ rsp + 0x2df8 ];\n"                                                                                      \
    "or rbp, [ rsp + 0x2ec8 ];\n"                                                                                      \
    "or rbp, [ rsp + 0x30d8 ];\n"                                                                                      \
    "or rbp, [ rsp + 0x3320 ];\n"                                                                                      \
    "or rbp, [ rsp + 0x3360 ];\n"                                                                                      \
    "or rbp, [ rsp + 0x3500 ];\n"                                                                                      \
    "or rbp, [ rsp + 0x37a0 ];\n"                                                                                      \
    "or rbp, [ rsp + 0x5f0 ];\n"                                                                                       \
    "or rbp, [ rsp + 0x858 ];\n"                                                                                       \
    "or rbp, [ rsp + 0x980 ];\n"                                                                                       \
    "or rbx, r10;\n"                                                                                                   \
    "or rbx, r11;\n"                                                                                                   \
    "or rbx, r12;\n"                                                                                                   \
    "or rbx, r14;\n"                                                                                                   \
    "or rbx, r15;\n"                                                                                                   \
    "or rbx, r8;\n"                                                                                                    \
    "or rbx, r9;\n"                                                                                                    \
    "or rbx, rbp;\n"                                                                                                   \
    "or rbx, rcx;\n"                                                                                                   \
    "or rbx, rdi;\n"                                                                                                   \
    "or rbx, rdx;\n"                                                                                                   \
    "or rbx, rsi;\n"                                                                                                   \
    "or rbx, [ rsp + 0x12d0 ];\n"                                                                                      \
    "or rbx, [ rsp + 0x1388 ];\n"                                                                                      \
    "or rbx, [ rsp + 0x1890 ];\n"                                                                                      \
    "or rbx, [ rsp + 0x1980 ];\n"                                                                                      \
    "or rbx, [ rsp + 0x2248 ];\n"                                                                                      \
    "or rbx, [ rsp + 0x22c8 ];\n"                                                                                      \
    "or rbx, [ rsp + 0x2dc0 ];\n"                                                                                      \
    "or rbx, [ rsp + 0x3098 ];\n"                                                                                      \
    "or rbx, [ rsp + 0x32d8 ];\n"                                                                                      \
    "or rbx, [ rsp + 0x3618 ];\n"                                                                                      \
    "or rbx, [ rsp + 0x3758 ];\n"                                                                                      \
    "or rbx, [ rsp + 0x620 ];\n"                                                                                       \
    "or rbx, [ rsp + 0x730 ];\n"                                                                                       \
    "or rbx, [ rsp + 0x8b8 ];\n"                                                                                       \
    "or rbx, [ rsp + 0xa60 ];\n"                                                                                       \
    "or rbx, [ rsp + 0xec0 ];\n"                                                                                       \
    "or rcx, r10;\n"                                                                                                   \
    "or rcx, r11;\n"                                                                                                   \
    "or rcx, r12;\n"                                                                                                   \
    "or rcx, r13;\n"                                                                                                   \
    "or rcx, r14;\n"                                                                                                   \
    "or rcx, r15;\n"                                                                                                   \
    "or rcx, r8;\n"                                                                                                    \
    "or rcx, r9;\n"                                                                                                    \
    "or rcx, rbp;\n"                                                                                                   \
    "or rcx, rbx;\n"                                                                                                   \
    "or rcx, rdi;\n"                                                                                                   \
    "or rcx, rdx;\n"                                                                                                   \
    "or rcx, rsi;\n"                                                                                                   \
    "or rcx, [ rsp + 0x1000 ];\n"                                                                                      \
    "or rcx, [ rsp + 0x1238 ];\n"                                                                                      \
    "or rcx, [ rsp + 0x1248 ];\n"                                                                                      \
    "or rcx, [ rsp + 0x1790 ];\n"                                                                                      \
    "or rcx, [ rsp + 0x1b38 ];\n"                                                                                      \
    "or rcx, [ rsp + 0x1d58 ];\n"                                                                                      \
    "or rcx, [ rsp + 0x1e88 ];\n"                                                                                      \
    "or rcx, [ rsp + 0x1f8 ];\n"                                                                                       \
    "or rcx, [ rsp + 0x2058 ];\n"                                                                                      \
    "or rcx, [ rsp + 0x228 ];\n"                                                                                       \
    "or rcx, [ rsp + 0x2460 ];\n"                                                                                      \
    "or rcx, [ rsp + 0x2940 ];\n"                                                                                      \
    "or rcx, [ rsp + 0x2ce8 ];\n"                                                                                      \
    "or rcx, [ rsp + 0x3040 ];\n"                                                                                      \
    "or rcx, [ rsp + 0x3208 ];\n"                                                                                      \
    "or rcx, [ rsp + 0x35b8 ];\n"                                                                                      \
    "or rcx, [ rsp + 0xd98 ];\n"                                                                                       \
    "or rdi, r10;\n"                                                                                                   \
    "or rdi, r11;\n"                                                                                                   \
    "or rdi, r12;\n"                                                                                                   \
    "or rdi, r13;\n"                                                                                                   \
    "or rdi, r14;\n"                                                                                                   \
    "or rdi, r15;\n"                                                                                                   \
    "or rdi, r8;\n"                                                                                                    \
    "or rdi, r9;\n"                                                                                                    \
    "or rdi, rax;\n"                                                                                                   \
    "or rdi, rbp;\n"                                                                                                   \
    "or rdi, rcx;\n"                                                                                                   \
    "or rdi, rdx;\n"                                                                                                   \
    "or rdi, rsi;\n"                                                                                                   \
    "or rdi, [ rsp + 0x1080 ];\n"                                                                                      \
    "or rdi, [ rsp + 0x14d0 ];\n"                                                                                      \
    "or rdi, [ rsp + 0x18f8 ];\n"                                                                                      \
    "or rdi, [ rsp + 0x2038 ];\n"                                                                                      \
    "or rdi, [ rsp + 0x2b80 ];\n"                                                                                      \
    "or rdi, [ rsp + 0x3740 ];\n"                                                                                      \
    "or rdi, [ rsp + 0x38a0 ];\n"                                                                                      \
    "or rdi, [ rsp + 0x580 ];\n"                                                                                       \
    "or rdi, [ rsp + 0x640 ];\n"                                                                                       \
    "or rdi, [ rsp + 0x728 ];\n"                                                                                       \
    "or rdi, [ rsp + 0x850 ];\n"                                                                                       \
    "or rdi, [ rsp + 0xf20 ];\n"                                                                                       \
    "or rdx, r10;\n"                                                                                                   \
    "or rdx, r12;\n"                                                                                                   \
    "or rdx, r13;\n"                                                                                                   \
    "or rdx, r14;\n"                                                                                                   \
    "or rdx, r15;\n"                                                                                                   \
    "or rdx, r8;\n"                                                                                                    \
    "or rdx, r9;\n"                                                                                                    \
    "or rdx, rax;\n"                                                                                                   \
    "or rdx, rbp;\n"                                                                                                   \
    "or rdx, rbx;\n"                                                                                                   \
    "or rdx, rdi;\n"                                                                                                   \
    "or rdx, rsi;\n"                                                                                                   \
    "or rdx, [ rsp + 0x1078 ];\n"                                                                                      \
    "or rdx, [ rsp + 0x1688 ];\n"                                                                                      \
    "or rdx, [ rsp + 0x1ce0 ];\n"                                                                                      \
    "or rdx, [ rsp + 0x21a8 ];\n"                                                                                      \
    "or rdx, [ rsp + 0x2428 ];\n"                                                                                      \
    "or rdx, [ rsp + 0x2620 ];\n"                                                                                      \
    "or rdx, [ rsp + 0x2b18 ];\n"                                                                                      \
    "or rdx, [ rsp + 0x2c80 ];\n"                                                                                      \
    "or rdx, [ rsp + 0x2ed0 ];\n"                                                                                      \
    "or rdx, [ rsp + 0x3748 ];\n"                                                                                      \
    "or rdx, [ rsp + 0xa0 ];\n"                                                                                        \
    "or rdx, [ rsp + 0xbd0 ];\n"                                                                                       \
    "or rdx, [ rsp + 0xd68 ];\n"                                                                                       \
    "or rsi, r10;\n"                                                                                                   \
    "or rsi, r11;\n"                                                                                                   \
    "or rsi, r12;\n"                                                                                                   \
    "or rsi, r13;\n"                                                                                                   \
    "or rsi, r14;\n"                                                                                                   \
    "or rsi, r15;\n"                                                                                                   \
    "or rsi, r8;\n"                                                                                                    \
    "or rsi, rax;\n"                                                                                                   \
    "or rsi, rbp;\n"                                                                                                   \
    "or rsi, rbx;\n"                                                                                                   \
    "or rsi, rcx;\n"                                                                                                   \
    "or rsi, rdi;\n"                                                                                                   \
    "or rsi, rdx;\n"                                                                                                   \
    "or rsi, [ rsp + 0x16b8 ];\n"                                                                                      \
    "or rsi, [ rsp + 0x178 ];\n"                                                                                       \
    "or rsi, [ rsp + 0x1b80 ];\n"                                                                                      \
    "or rsi, [ rsp + 0x1d40 ];\n"                                                                                      \
    "or rsi, [ rsp + 0x22b0 ];\n"                                                                                      \
    "or rsi, [ rsp + 0x2560 ];\n"                                                                                      \
    "or rsi, [ rsp + 0x2760 ];\n"                                                                                      \
    "or rsi, [ rsp + 0x2bb8 ];\n"                                                                                      \
    "or rsi, [ rsp + 0x2c50 ];\n"                                                                                      \
    "or rsi, [ rsp + 0xc78 ];\n"                                                                                       \
    "or r10, r11;\n"                                                                                                   \
    "or r10, rdi;\n"                                                                                                   \
    "or r12, r11;\n"                                                                                                   \
    "or r13, r10;\n"                                                                                                   \
    "or r14, r8;\n"                                                                                                    \
    "or r14, rdi;\n"                                                                                                   \
    "or r15, r10;\n"                                                                                                   \
    "or r15, r11;\n"                                                                                                   \
    "or r8, r10;\n"                                                                                                    \
    "or r8, r11;\n"                                                                                                    \
    "or r8, rdi;\n"                                                                                                    \
    "or r9, r10;\n"                                                                                                    \
    "or r9, rdi;\n"                                                                                                    \
    "or rax, r10;\n"                                                                                                   \
    "or rax, rbp;\n"                                                                                                   \
    "or rbx, r11;\n"                                                                                                   \
    "or rbx, rdi;\n"                                                                                                   \
    "or rcx, r11;\n"                                                                                                   \
    "or rcx, rdi;\n"                                                                                                   \
    "or rdx, r10;\n"                                                                                                   \
    "or al, 0x0;\n"                                                                                                    \
    "or ax, 0xe1;\n"                                                                                                   \
    "or eax, 0xe11;\n"                                                                                                 \
    "or sil, 0x0;\n"                                                                                                   \
    "or si, 0xe1;\n"                                                                                                   \
    "or esi, 0xe11;\n"                                                                                                 \
    "or rax, 0xfffee12;\n"                                                                                             \
    "or rax, 0xff6ee12;\n"                                                                                             \
    "or rax, 0xf66ee12;\n"                                                                                             \
    "or rax, 0x666ee12;\n"                                                                                             \
    "or rax, 0x6666ee12;\n"                                                                                            \
    "or rax, -0x1;\n"                                                                                                  \
    "or rax, -0xfffee12;\n"                                                                                            \
    "or rax, -0xff6ee12;\n"                                                                                            \
    "or rax, -0xf66ee12;\n"                                                                                            \
    "or rax, -0x666ee12;\n"                                                                                            \
    "or rax, -0x6666ee12;\n"                                                                                           \
    "or rbp, -0xfffee12;\n"                                                                                            \
    "or rbp, 0xfffee12;\n"                                                                                             \
    "or rbp, 0xff6ee12;\n"                                                                                             \
    "or rbp, 0xf66ee12;\n"                                                                                             \
    "or rbp, 0x666ee12;\n"                                                                                             \
    "or rbp, 0x6666ee12;\n"                                                                                            \
    "or rbp, -0xf;\n"                                                                                                  \
    "or rbp, -0xe;\n"                                                                                                  \
    "or rbp, -0xd;\n"                                                                                                  \
    "or rbp, -0x7;\n"                                                                                                  \
    "or rbp, -0x4;\n"                                                                                                  \
    "or rbp, -0x3;\n"                                                                                                  \
    "or rbp, -0x2;\n"                                                                                                  \
    "or rbp, -0xff;\n"                                                                                                 \
    "or rbp, -0xef;\n"                                                                                                 \
    "or rbp, -0xdf;\n"                                                                                                 \
    "or rbp, -0xcf;\n"                                                                                                 \
    "or rbp, -0xbf;\n"                                                                                                 \
    "or rbp, -0xaf;\n"                                                                                                 \
    "or rbp, -0x9f;\n"                                                                                                 \
    "or rbp, -0x8f;\n"                                                                                                 \
    "or rbp, -0x7f;\n"                                                                                                 \
    "or rbp, -0x3e;\n"                                                                                                 \
    "or rbp, -0x6f;\n"                                                                                                 \
    "or rbp, -0x5f;\n"                                                                                                 \
    "or rbp, -0x4f;\n"                                                                                                 \
    "or rbp, -0x1f;\n"                                                                                                 \
    "or rbp, -0xfa;\n"                                                                                                 \
    "or rbp, -0xf9;\n"                                                                                                 \
    "or rbp, -0xf8;\n"                                                                                                 \
    "or rbp, -0xf7;\n"                                                                                                 \
    "or rbp, -0xf6;\n"                                                                                                 \
    "or rbp, -0xf5;\n"                                                                                                 \
    "or rbp, -0xf4;\n"                                                                                                 \
    "or rbp, -0xf3;\n"                                                                                                 \
    "or rbp, -0xf2;\n"                                                                                                 \
    "or rbp, -0xf1;\n"                                                                                                 \
    "or rbp, -0xf66;\n"                                                                                                \
    "or rbp, -0x666ee;\n"                                                                                              \
    "or rbp, -0x6666ee12;\n"                                                                                           \
    "or r13, -0xfffee12;\n"                                                                                            \
    "or r13, 0xfffee12;\n"                                                                                             \
    "or r13, 0xff6ee12;\n"                                                                                             \
    "or r13, 0xf66ee12;\n"                                                                                             \
    "or r13, 0x666ee12;\n"                                                                                             \
    "or r13, 0x6666ee12;\n"                                                                                            \
    "or r13, -0x1;\n"                                                                                                  \
    "or r13, -0xfffee12;\n"                                                                                            \
    "or r13, -0xff6ee12;\n"                                                                                            \
    "or r13, -0xf66ee12;\n"                                                                                            \
    "or r13, -0x666ee12;\n"                                                                                            \
    "or r13, -0x6666ee12;\n"                                                                                           \
    "or rax, 0x12;\n"                                                                                                  \
    "or rax, 0xe12;\n"                                                                                                 \
    "or rax, 0x66ee12;\n"                                                                                              \
    "or rax, 0x66ee12;\n"                                                                                              \
    "or rax, 0x6ee12;\n"                                                                                               \
    "or sp, 0x34ef;\n"                                                                                                 \
    "or r8w, 0x1;\n"                                                                                                   \
    "or rax, [ rbx ];\n"                                                                                               \
    "or rax, [ rbx + 0x10 ];\n"                                                                                        \
    "or rax, 0x0 ;\n"                                                                                                  \
    "or rax, 0x0 ; with a comment;\n"                                                                                  \
    "or r12, r14;\n"                                                                                                   \
    "or r12, rbx;\n"                                                                                                   \
    "or r12, [ rsp + 0x10 ];\n"                                                                                        \
    "or rax, 0xfff;\n"                                                                                                 \
    "or rax, r15;\n"                                                                                                   \
    "or rax, rbp;\n"                                                                                                   \
    "or rbp, r12;\n"                                                                                                   \
    "or rbp, r8;\n"                                                                                                    \
    "or rbp, r9;\n"                                                                                                    \
    "or rbx, r9;\n"                                                                                                    \
    "or rbx, rdi;\n"                                                                                                   \
    "or rdi, r10;\n"                                                                                                   \
    "or rdx, r14;\n"                                                                                                   \
    "or rsp, 0x138 ;\n"                                                                                                \
    "or rsp, 0x48 ;\n"                                                                                                 \
    "or rsp, 0x50 ;\n"                                                                                                 \
    "or rsp, 0x80 ;\n"                                                                                                 \
    "or eax, ebx;\n"                                                                                                   \
    "or eax, [rbx];\n"                                                                                                 \
    "or eax, dword [rsp];\n"                                                                                           \
    "or eax, dword [rbx];\n"                                                                                           \
    "or eax, [rsp];\n"                                                                                                 \
    ""
