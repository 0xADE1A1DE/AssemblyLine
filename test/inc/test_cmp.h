#define CODE                                                                                                           \
    "cmp rsp, 0x39a8;\n"                                                                                               \
    "cmp r10, r11;\n"                                                                                                  \
    "cmp r10, r12;\n"                                                                                                  \
    "cmp r10, r13;\n"                                                                                                  \
    "cmp r10, r14;\n"                                                                                                  \
    "cmp r10, r15;\n"                                                                                                  \
    "cmp r10, r8;\n"                                                                                                   \
    "cmp r10, r9;\n"                                                                                                   \
    "cmp r10, rax;\n"                                                                                                  \
    "cmp r10, rbp;\n"                                                                                                  \
    "cmp r10, rbx;\n"                                                                                                  \
    "cmp r10, rcx;\n"                                                                                                  \
    "cmp r10, rdi;\n"                                                                                                  \
    "cmp r10, rdx;\n"                                                                                                  \
    "cmp r10, rsi;\n"                                                                                                  \
    "cmp r10, [ rsp + 0x11f0 ];\n"                                                                                     \
    "cmp r10, [ rsp + 0x19f0 ];\n"                                                                                     \
    "cmp r10, [ rsp + 0x1b10 ];\n"                                                                                     \
    "cmp r10, [ rsp + 0x1c10 ];\n"                                                                                     \
    "cmp r10, [ rsp + 0x1c8 ];\n"                                                                                      \
    "cmp r10, [ rsp + 0x1de8 ];\n"                                                                                     \
    "cmp r10, [ rsp + 0x1f90 ];\n"                                                                                     \
    "cmp r10, [ rsp + 0x2708 ];\n"                                                                                     \
    "cmp r10, [ rsp + 0x2970 ];\n"                                                                                     \
    "cmp r10, [ rsp + 0x2e10 ];\n"                                                                                     \
    "cmp r10, [ rsp + 0x30e0 ];\n"                                                                                     \
    "cmp r10, [ rsp + 0x35c0 ];\n"                                                                                     \
    "cmp r10, [ rsp + 0x460 ];\n"                                                                                      \
    "cmp r10, [ rsp + 0x680 ];\n"                                                                                      \
    "cmp r10, [ rsp + 0xb48 ];\n"                                                                                      \
    "cmp r11, r10;\n"                                                                                                  \
    "cmp r11, r12;\n"                                                                                                  \
    "cmp r11, r13;\n"                                                                                                  \
    "cmp r11, r14;\n"                                                                                                  \
    "cmp r11, r15;\n"                                                                                                  \
    "cmp r11, r8;\n"                                                                                                   \
    "cmp r11, r9;\n"                                                                                                   \
    "cmp r11, rax;\n"                                                                                                  \
    "cmp r11, rcx;\n"                                                                                                  \
    "cmp r11, rdi;\n"                                                                                                  \
    "cmp r11, rsi;\n"                                                                                                  \
    "cmp r11, [ rsp + 0x14a0 ];\n"                                                                                     \
    "cmp r11, [ rsp + 0x158 ];\n"                                                                                      \
    "cmp r11, [ rsp + 0x1750 ];\n"                                                                                     \
    "cmp r11, [ rsp + 0x2218 ];\n"                                                                                     \
    "cmp r11, [ rsp + 0x24b0 ];\n"                                                                                     \
    "cmp r11, [ rsp + 0x2688 ];\n"                                                                                     \
    "cmp r11, [ rsp + 0x26c0 ];\n"                                                                                     \
    "cmp r11, [ rsp + 0x2920 ];\n"                                                                                     \
    "cmp r11, [ rsp + 0x2938 ];\n"                                                                                     \
    "cmp r11, [ rsp + 0x29b0 ];\n"                                                                                     \
    "cmp r11, [ rsp + 0x3780 ];\n"                                                                                     \
    "cmp r11, [ rsp + 0x37e8 ];\n"                                                                                     \
    "cmp r11, [ rsp + 0xbd8 ];\n"                                                                                      \
    "cmp r12, r10;\n"                                                                                                  \
    "cmp r12, r11;\n"                                                                                                  \
    "cmp r12, r13;\n"                                                                                                  \
    "cmp r12, r14;\n"                                                                                                  \
    "cmp r12, r15;\n"                                                                                                  \
    "cmp r12, r9;\n"                                                                                                   \
    "cmp r12, rax;\n"                                                                                                  \
    "cmp r12, rbp;\n"                                                                                                  \
    "cmp r12, rbx;\n"                                                                                                  \
    "cmp r12, rcx;\n"                                                                                                  \
    "cmp r12, rdi;\n"                                                                                                  \
    "cmp r12, rdx;\n"                                                                                                  \
    "cmp r12, rsi;\n"                                                                                                  \
    "cmp r12, [ rsp + 0x1048 ];\n"                                                                                     \
    "cmp r12, [ rsp + 0x12a0 ];\n"                                                                                     \
    "cmp r12, [ rsp + 0x1428 ];\n"                                                                                     \
    "cmp r12, [ rsp + 0x16c8 ];\n"                                                                                     \
    "cmp r12, [ rsp + 0x220 ];\n"                                                                                      \
    "cmp r12, [ rsp + 0x23b8 ];\n"                                                                                     \
    "cmp r12, [ rsp + 0x2520 ];\n"                                                                                     \
    "cmp r12, [ rsp + 0x2528 ];\n"                                                                                     \
    "cmp r12, [ rsp + 0x29a8 ];\n"                                                                                     \
    "cmp r12, [ rsp + 0x2be8 ];\n"                                                                                     \
    "cmp r12, [ rsp + 0x910 ];\n"                                                                                      \
    "cmp r13, r11;\n"                                                                                                  \
    "cmp r13, r12;\n"                                                                                                  \
    "cmp r13, r15;\n"                                                                                                  \
    "cmp r13, r8;\n"                                                                                                   \
    "cmp r13, r9;\n"                                                                                                   \
    "cmp r13, rax;\n"                                                                                                  \
    "cmp r13, rbp;\n"                                                                                                  \
    "cmp r13, rcx;\n"                                                                                                  \
    "cmp r13, rdi;\n"                                                                                                  \
    "cmp r13, rdx;\n"                                                                                                  \
    "cmp r13, rsi;\n"                                                                                                  \
    "cmp r13, [ rsp + 0x110 ];\n"                                                                                      \
    "cmp r13, [ rsp + 0x14c0 ];\n"                                                                                     \
    "cmp r13, [ rsp + 0x1d90 ];\n"                                                                                     \
    "cmp r13, [ rsp + 0x1fe8 ];\n"                                                                                     \
    "cmp r13, [ rsp + 0x2228 ];\n"                                                                                     \
    "cmp r13, [ rsp + 0x2780 ];\n"                                                                                     \
    "cmp r13, [ rsp + 0x27d0 ];\n"                                                                                     \
    "cmp r13, [ rsp + 0x2c20 ];\n"                                                                                     \
    "cmp r13, [ rsp + 0x3658 ];\n"                                                                                     \
    "cmp r13, [ rsp + 0x3c8 ];\n"                                                                                      \
    "cmp r13, [ rsp + 0xe08 ];\n"                                                                                      \
    "cmp r14, r10;\n"                                                                                                  \
    "cmp r14, r11;\n"                                                                                                  \
    "cmp r14, r12;\n"                                                                                                  \
    "cmp r14, r13;\n"                                                                                                  \
    "cmp r14, r15;\n"                                                                                                  \
    "cmp r14, r8;\n"                                                                                                   \
    "cmp r14, r9;\n"                                                                                                   \
    "cmp r14, rax;\n"                                                                                                  \
    "cmp r14, rbp;\n"                                                                                                  \
    "cmp r14, rcx;\n"                                                                                                  \
    "cmp r14, rdx;\n"                                                                                                  \
    "cmp r14, rsi;\n"                                                                                                  \
    "cmp r14, [ rsp + 0x13e8 ];\n"                                                                                     \
    "cmp r14, [ rsp + 0x17b0 ];\n"                                                                                     \
    "cmp r14, [ rsp + 0x18c8 ];\n"                                                                                     \
    "cmp r14, [ rsp + 0x1aa0 ];\n"                                                                                     \
    "cmp r14, [ rsp + 0x1e58 ];\n"                                                                                     \
    "cmp r14, [ rsp + 0x2088 ];\n"                                                                                     \
    "cmp r14, [ rsp + 0x20e8 ];\n"                                                                                     \
    "cmp r14, [ rsp + 0x2498 ];\n"                                                                                     \
    "cmp r14, [ rsp + 0x2a10 ];\n"                                                                                     \
    "cmp r14, [ rsp + 0x2da0 ];\n"                                                                                     \
    "cmp r14, [ rsp + 0x32c0 ];\n"                                                                                     \
    "cmp r14, [ rsp + 0x34f8 ];\n"                                                                                     \
    "cmp r14, [ rsp + 0x3600 ];\n"                                                                                     \
    "cmp r14, [ rsp + 0x3a8 ];\n"                                                                                      \
    "cmp r14, [ rsp + 0x600 ];\n"                                                                                      \
    "cmp r14, [ rsp + 0x848 ];\n"                                                                                      \
    "cmp r14, [ rsp + 0xdc8 ];\n"                                                                                      \
    "cmp r15, r10;\n"                                                                                                  \
    "cmp r15, r11;\n"                                                                                                  \
    "cmp r15, r13;\n"                                                                                                  \
    "cmp r15, r8;\n"                                                                                                   \
    "cmp r15, r9;\n"                                                                                                   \
    "cmp r15, rax;\n"                                                                                                  \
    "cmp r15, rbp;\n"                                                                                                  \
    "cmp r15, rbx;\n"                                                                                                  \
    "cmp r15, rcx;\n"                                                                                                  \
    "cmp r15, rdi;\n"                                                                                                  \
    "cmp r15, rdx;\n"                                                                                                  \
    "cmp r15, rsi;\n"                                                                                                  \
    "cmp r15, [ rsp + 0x1910 ];\n"                                                                                     \
    "cmp r15, [ rsp + 0x1968 ];\n"                                                                                     \
    "cmp r15, [ rsp + 0x1b58 ];\n"                                                                                     \
    "cmp r15, [ rsp + 0x1d0 ];\n"                                                                                      \
    "cmp r15, [ rsp + 0x30c8 ];\n"                                                                                     \
    "cmp r15, [ rsp + 0x3110 ];\n"                                                                                     \
    "cmp r15, [ rsp + 0x3140 ];\n"                                                                                     \
    "cmp r15, [ rsp + 0x8f8 ];\n"                                                                                      \
    "cmp r15, [ rsp + 0xb70 ];\n"                                                                                      \
    "cmp r15, [ rsp + 0xbe0 ];\n"                                                                                      \
    "cmp r15, [ rsp + 0xd50 ];\n"                                                                                      \
    "cmp r8, r11;\n"                                                                                                   \
    "cmp r8, r12;\n"                                                                                                   \
    "cmp r8, r13;\n"                                                                                                   \
    "cmp r8, r14;\n"                                                                                                   \
    "cmp r8, r15;\n"                                                                                                   \
    "cmp r8, r9;\n"                                                                                                    \
    "cmp r8, rax;\n"                                                                                                   \
    "cmp r8, rbp;\n"                                                                                                   \
    "cmp r8, rbx;\n"                                                                                                   \
    "cmp r8, rcx;\n"                                                                                                   \
    "cmp r8, rdi;\n"                                                                                                   \
    "cmp r8, rdx;\n"                                                                                                   \
    "cmp r8, [ rsp + 0x1270 ];\n"                                                                                      \
    "cmp r8, [ rsp + 0x14b0 ];\n"                                                                                      \
    "cmp r8, [ rsp + 0x1700 ];\n"                                                                                      \
    "cmp r8, [ rsp + 0x1730 ];\n"                                                                                      \
    "cmp r8, [ rsp + 0x1c08 ];\n"                                                                                      \
    "cmp r8, [ rsp + 0x1fe0 ];\n"                                                                                      \
    "cmp r8, [ rsp + 0x2110 ];\n"                                                                                      \
    "cmp r8, [ rsp + 0x2500 ];\n"                                                                                      \
    "cmp r8, [ rsp + 0x2e48 ];\n"                                                                                      \
    "cmp r8, [ rsp + 0x3380 ];\n"                                                                                      \
    "cmp r8, [ rsp + 0x3488 ];\n"                                                                                      \
    "cmp r8, [ rsp + 0x38e8 ];\n"                                                                                      \
    "cmp r8, [ rsp + 0x440 ];\n"                                                                                       \
    "cmp r8, [ rsp + 0x6b8 ];\n"                                                                                       \
    "cmp r8, [ rsp + 0xb90 ];\n"                                                                                       \
    "cmp r8, [ rsp + 0xe18 ];\n"                                                                                       \
    "cmp r8, [ rsp + 0xea0 ];\n"                                                                                       \
    "cmp r8, [ rsp + 0xf78 ];\n"                                                                                       \
    "cmp r8, [ rsp + 0xfe0 ];\n"                                                                                       \
    "cmp r9, r10;\n"                                                                                                   \
    "cmp r9, r11;\n"                                                                                                   \
    "cmp r9, r12;\n"                                                                                                   \
    "cmp r9, r14;\n"                                                                                                   \
    "cmp r9, r15;\n"                                                                                                   \
    "cmp r9, r8;\n"                                                                                                    \
    "cmp r9, rax;\n"                                                                                                   \
    "cmp r9, rbp;\n"                                                                                                   \
    "cmp r9, rbx;\n"                                                                                                   \
    "cmp r9, rcx;\n"                                                                                                   \
    "cmp r9, rdi;\n"                                                                                                   \
    "cmp r9, rsi;\n"                                                                                                   \
    "cmp r9, [ rsp + 0x1030 ];\n"                                                                                      \
    "cmp r9, [ rsp + 0x1b70 ];\n"                                                                                      \
    "cmp r9, [ rsp + 0x2310 ];\n"                                                                                      \
    "cmp r9, [ rsp + 0x2318 ];\n"                                                                                      \
    "cmp r9, [ rsp + 0x26f8 ];\n"                                                                                      \
    "cmp r9, [ rsp + 0x27c8 ];\n"                                                                                      \
    "cmp r9, [ rsp + 0x27d8 ];\n"                                                                                      \
    "cmp r9, [ rsp + 0x3860 ];\n"                                                                                      \
    "cmp r9, [ rsp + 0x3958 ];\n"                                                                                      \
    "cmp r9, [ rsp + 0xf70 ];\n"                                                                                       \
    "cmp rax, r10;\n"                                                                                                  \
    "cmp rax, r11;\n"                                                                                                  \
    "cmp rax, r12;\n"                                                                                                  \
    "cmp rax, r14;\n"                                                                                                  \
    "cmp rax, r15;\n"                                                                                                  \
    "cmp rax, r8;\n"                                                                                                   \
    "cmp rax, r9;\n"                                                                                                   \
    "cmp rax, rbp;\n"                                                                                                  \
    "cmp rax, rbx;\n"                                                                                                  \
    "cmp rax, rcx;\n"                                                                                                  \
    "cmp rax, rdx;\n"                                                                                                  \
    "cmp rax, rsi;\n"                                                                                                  \
    "cmp rax, [ rsp + 0x1198 ];\n"                                                                                     \
    "cmp rax, [ rsp + 0x11e8 ];\n"                                                                                     \
    "cmp rax, [ rsp + 0x2b10 ];\n"                                                                                     \
    "cmp rax, [ rsp + 0x2b70 ];\n"                                                                                     \
    "cmp rax, [ rsp + 0x2ea0 ];\n"                                                                                     \
    "cmp rax, [ rsp + 0x3118 ];\n"                                                                                     \
    "cmp rax, [ rsp + 0x3288 ];\n"                                                                                     \
    "cmp rax, [ rsp + 0x34b8 ];\n"                                                                                     \
    "cmp rax, [ rsp + 0x35f0 ];\n"                                                                                     \
    "cmp rax, [ rsp + 0x3700 ];\n"                                                                                     \
    "cmp rax, [ rsp + 0x4b0 ];\n"                                                                                      \
    "cmp rax, [ rsp + 0x978 ];\n"                                                                                      \
    "cmp rax, [ rsp + 0xb88 ];\n"                                                                                      \
    "cmp rbp, r10;\n"                                                                                                  \
    "cmp rbp, r12;\n"                                                                                                  \
    "cmp rbp, r13;\n"                                                                                                  \
    "cmp rbp, r15;\n"                                                                                                  \
    "cmp rbp, r8;\n"                                                                                                   \
    "cmp rbp, r9;\n"                                                                                                   \
    "cmp rbp, rax;\n"                                                                                                  \
    "cmp rbp, rsi;\n"                                                                                                  \
    "cmp rbp, [ rsp + 0x1470 ];\n"                                                                                     \
    "cmp rbp, [ rsp + 0x1970 ];\n"                                                                                     \
    "cmp rbp, [ rsp + 0x1f80 ];\n"                                                                                     \
    "cmp rbp, [ rsp + 0x20a0 ];\n"                                                                                     \
    "cmp rbp, [ rsp + 0x2878 ];\n"                                                                                     \
    "cmp rbp, [ rsp + 0x29d0 ];\n"                                                                                     \
    "cmp rbp, [ rsp + 0x2df8 ];\n"                                                                                     \
    "cmp rbp, [ rsp + 0x2ec8 ];\n"                                                                                     \
    "cmp rbp, [ rsp + 0x30d8 ];\n"                                                                                     \
    "cmp rbp, [ rsp + 0x3320 ];\n"                                                                                     \
    "cmp rbp, [ rsp + 0x3360 ];\n"                                                                                     \
    "cmp rbp, [ rsp + 0x3500 ];\n"                                                                                     \
    "cmp rbp, [ rsp + 0x37a0 ];\n"                                                                                     \
    "cmp rbp, [ rsp + 0x5f0 ];\n"                                                                                      \
    "cmp rbp, [ rsp + 0x858 ];\n"                                                                                      \
    "cmp rbp, [ rsp + 0x980 ];\n"                                                                                      \
    "cmp rbx, r10;\n"                                                                                                  \
    "cmp rbx, r11;\n"                                                                                                  \
    "cmp rbx, r12;\n"                                                                                                  \
    "cmp rbx, r14;\n"                                                                                                  \
    "cmp rbx, r15;\n"                                                                                                  \
    "cmp rbx, r8;\n"                                                                                                   \
    "cmp rbx, r9;\n"                                                                                                   \
    "cmp rbx, rbp;\n"                                                                                                  \
    "cmp rbx, rcx;\n"                                                                                                  \
    "cmp rbx, rdi;\n"                                                                                                  \
    "cmp rbx, rdx;\n"                                                                                                  \
    "cmp rbx, rsi;\n"                                                                                                  \
    "cmp rbx, [ rsp + 0x12d0 ];\n"                                                                                     \
    "cmp rbx, [ rsp + 0x1388 ];\n"                                                                                     \
    "cmp rbx, [ rsp + 0x1890 ];\n"                                                                                     \
    "cmp rbx, [ rsp + 0x1980 ];\n"                                                                                     \
    "cmp rbx, [ rsp + 0x2248 ];\n"                                                                                     \
    "cmp rbx, [ rsp + 0x22c8 ];\n"                                                                                     \
    "cmp rbx, [ rsp + 0x2dc0 ];\n"                                                                                     \
    "cmp rbx, [ rsp + 0x3098 ];\n"                                                                                     \
    "cmp rbx, [ rsp + 0x32d8 ];\n"                                                                                     \
    "cmp rbx, [ rsp + 0x3618 ];\n"                                                                                     \
    "cmp rbx, [ rsp + 0x3758 ];\n"                                                                                     \
    "cmp rbx, [ rsp + 0x620 ];\n"                                                                                      \
    "cmp rbx, [ rsp + 0x730 ];\n"                                                                                      \
    "cmp rbx, [ rsp + 0x8b8 ];\n"                                                                                      \
    "cmp rbx, [ rsp + 0xa60 ];\n"                                                                                      \
    "cmp rbx, [ rsp + 0xec0 ];\n"                                                                                      \
    "cmp rcx, r10;\n"                                                                                                  \
    "cmp rcx, r11;\n"                                                                                                  \
    "cmp rcx, r12;\n"                                                                                                  \
    "cmp rcx, r13;\n"                                                                                                  \
    "cmp rcx, r14;\n"                                                                                                  \
    "cmp rcx, r15;\n"                                                                                                  \
    "cmp rcx, r8;\n"                                                                                                   \
    "cmp rcx, r9;\n"                                                                                                   \
    "cmp rcx, rbp;\n"                                                                                                  \
    "cmp rcx, rbx;\n"                                                                                                  \
    "cmp rcx, rdi;\n"                                                                                                  \
    "cmp rcx, rdx;\n"                                                                                                  \
    "cmp rcx, rsi;\n"                                                                                                  \
    "cmp rcx, [ rsp + 0x1000 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0x1238 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0x1248 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0x1790 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0x1b38 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0x1d58 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0x1e88 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0x1f8 ];\n"                                                                                      \
    "cmp rcx, [ rsp + 0x2058 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0x228 ];\n"                                                                                      \
    "cmp rcx, [ rsp + 0x2460 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0x2940 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0x2ce8 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0x3040 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0x3208 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0x35b8 ];\n"                                                                                     \
    "cmp rcx, [ rsp + 0xd98 ];\n"                                                                                      \
    "cmp rdi, r10;\n"                                                                                                  \
    "cmp rdi, r11;\n"                                                                                                  \
    "cmp rdi, r12;\n"                                                                                                  \
    "cmp rdi, r13;\n"                                                                                                  \
    "cmp rdi, r14;\n"                                                                                                  \
    "cmp rdi, r15;\n"                                                                                                  \
    "cmp rdi, r8;\n"                                                                                                   \
    "cmp rdi, r9;\n"                                                                                                   \
    "cmp rdi, rax;\n"                                                                                                  \
    "cmp rdi, rbp;\n"                                                                                                  \
    "cmp rdi, rcx;\n"                                                                                                  \
    "cmp rdi, rdx;\n"                                                                                                  \
    "cmp rdi, rsi;\n"                                                                                                  \
    "cmp rdi, [ rsp + 0x1080 ];\n"                                                                                     \
    "cmp rdi, [ rsp + 0x14d0 ];\n"                                                                                     \
    "cmp rdi, [ rsp + 0x18f8 ];\n"                                                                                     \
    "cmp rdi, [ rsp + 0x2038 ];\n"                                                                                     \
    "cmp rdi, [ rsp + 0x2b80 ];\n"                                                                                     \
    "cmp rdi, [ rsp + 0x3740 ];\n"                                                                                     \
    "cmp rdi, [ rsp + 0x38a0 ];\n"                                                                                     \
    "cmp rdi, [ rsp + 0x580 ];\n"                                                                                      \
    "cmp rdi, [ rsp + 0x640 ];\n"                                                                                      \
    "cmp rdi, [ rsp + 0x728 ];\n"                                                                                      \
    "cmp rdi, [ rsp + 0x850 ];\n"                                                                                      \
    "cmp rdi, [ rsp + 0xf20 ];\n"                                                                                      \
    "cmp rdx, r10;\n"                                                                                                  \
    "cmp rdx, r12;\n"                                                                                                  \
    "cmp rdx, r13;\n"                                                                                                  \
    "cmp rdx, r14;\n"                                                                                                  \
    "cmp rdx, r15;\n"                                                                                                  \
    "cmp rdx, r8;\n"                                                                                                   \
    "cmp rdx, r9;\n"                                                                                                   \
    "cmp rdx, rax;\n"                                                                                                  \
    "cmp rdx, rbp;\n"                                                                                                  \
    "cmp rdx, rbx;\n"                                                                                                  \
    "cmp rdx, rdi;\n"                                                                                                  \
    "cmp rdx, rsi;\n"                                                                                                  \
    "cmp rdx, [ rsp + 0x1078 ];\n"                                                                                     \
    "cmp rdx, [ rsp + 0x1688 ];\n"                                                                                     \
    "cmp rdx, [ rsp + 0x1ce0 ];\n"                                                                                     \
    "cmp rdx, [ rsp + 0x21a8 ];\n"                                                                                     \
    "cmp rdx, [ rsp + 0x2428 ];\n"                                                                                     \
    "cmp rdx, [ rsp + 0x2620 ];\n"                                                                                     \
    "cmp rdx, [ rsp + 0x2b18 ];\n"                                                                                     \
    "cmp rdx, [ rsp + 0x2c80 ];\n"                                                                                     \
    "cmp rdx, [ rsp + 0x2ed0 ];\n"                                                                                     \
    "cmp rdx, [ rsp + 0x3748 ];\n"                                                                                     \
    "cmp rdx, [ rsp + 0xa0 ];\n"                                                                                       \
    "cmp rdx, [ rsp + 0xbd0 ];\n"                                                                                      \
    "cmp rdx, [ rsp + 0xd68 ];\n"                                                                                      \
    "cmp rsi, r10;\n"                                                                                                  \
    "cmp rsi, r11;\n"                                                                                                  \
    "cmp rsi, r12;\n"                                                                                                  \
    "cmp rsi, r13;\n"                                                                                                  \
    "cmp rsi, r14;\n"                                                                                                  \
    "cmp rsi, r15;\n"                                                                                                  \
    "cmp rsi, r8;\n"                                                                                                   \
    "cmp rsi, rax;\n"                                                                                                  \
    "cmp rsi, rbp;\n"                                                                                                  \
    "cmp rsi, rbx;\n"                                                                                                  \
    "cmp rsi, rcx;\n"                                                                                                  \
    "cmp rsi, rdi;\n"                                                                                                  \
    "cmp rsi, rdx;\n"                                                                                                  \
    "cmp rsi, [ rsp + 0x16b8 ];\n"                                                                                     \
    "cmp rsi, [ rsp + 0x178 ];\n"                                                                                      \
    "cmp rsi, [ rsp + 0x1b80 ];\n"                                                                                     \
    "cmp rsi, [ rsp + 0x1d40 ];\n"                                                                                     \
    "cmp rsi, [ rsp + 0x22b0 ];\n"                                                                                     \
    "cmp rsi, [ rsp + 0x2560 ];\n"                                                                                     \
    "cmp rsi, [ rsp + 0x2760 ];\n"                                                                                     \
    "cmp rsi, [ rsp + 0x2bb8 ];\n"                                                                                     \
    "cmp rsi, [ rsp + 0x2c50 ];\n"                                                                                     \
    "cmp rsi, [ rsp + 0xc78 ];\n"                                                                                      \
    "cmp r10, r11;\n"                                                                                                  \
    "cmp r10, rdi;\n"                                                                                                  \
    "cmp r12, r11;\n"                                                                                                  \
    "cmp r13, r10;\n"                                                                                                  \
    "cmp r14, r8;\n"                                                                                                   \
    "cmp r14, rdi;\n"                                                                                                  \
    "cmp r15, r10;\n"                                                                                                  \
    "cmp r15, r11;\n"                                                                                                  \
    "cmp r8, r10;\n"                                                                                                   \
    "cmp r8, r11;\n"                                                                                                   \
    "cmp r8, rdi;\n"                                                                                                   \
    "cmp r9, r10;\n"                                                                                                   \
    "cmp r9, rdi;\n"                                                                                                   \
    "cmp rax, r10;\n"                                                                                                  \
    "cmp rax, rbp;\n"                                                                                                  \
    "cmp rbx, r11;\n"                                                                                                  \
    "cmp rbx, rdi;\n"                                                                                                  \
    "cmp rcx, r11;\n"                                                                                                  \
    "cmp rcx, rdi;\n"                                                                                                  \
    "cmp rdx, r10;\n"                                                                                                  \
    "cmp al, 0x0;\n"                                                                                                   \
    "cmp ax, 0xe1;\n"                                                                                                  \
    "cmp eax, 0xe11;\n"                                                                                                \
    "cmp sil, 0x0;\n"                                                                                                  \
    "cmp si, 0xe1;\n"                                                                                                  \
    "cmp esi, 0xe11;\n"                                                                                                \
    "cmp rax, 0xfffee12;\n"                                                                                            \
    "cmp rax, 0xff6ee12;\n"                                                                                            \
    "cmp rax, 0xf66ee12;\n"                                                                                            \
    "cmp rax, 0x666ee12;\n"                                                                                            \
    "cmp rax, 0x6666ee12;\n"                                                                                           \
    "cmp rax, -0x1;\n"                                                                                                 \
    "cmp rax, -0xfffee12;\n"                                                                                           \
    "cmp rax, -0xff6ee12;\n"                                                                                           \
    "cmp rax, -0xf66ee12;\n"                                                                                           \
    "cmp rax, -0x666ee12;\n"                                                                                           \
    "cmp rax, -0x6666ee12;\n"                                                                                          \
    "cmp rbp, -0xfffee12;\n"                                                                                           \
    "cmp rbp, 0xfffee12;\n"                                                                                            \
    "cmp rbp, 0xff6ee12;\n"                                                                                            \
    "cmp rbp, 0xf66ee12;\n"                                                                                            \
    "cmp rbp, 0x666ee12;\n"                                                                                            \
    "cmp rbp, 0x6666ee12;\n"                                                                                           \
    "cmp rbp, -0xf;\n"                                                                                                 \
    "cmp rbp, -0xe;\n"                                                                                                 \
    "cmp rbp, -0xd;\n"                                                                                                 \
    "cmp rbp, -0x7;\n"                                                                                                 \
    "cmp rbp, -0x4;\n"                                                                                                 \
    "cmp rbp, -0x3;\n"                                                                                                 \
    "cmp rbp, -0x2;\n"                                                                                                 \
    "cmp rbp, -0xff;\n"                                                                                                \
    "cmp rbp, -0xef;\n"                                                                                                \
    "cmp rbp, -0xdf;\n"                                                                                                \
    "cmp rbp, -0xcf;\n"                                                                                                \
    "cmp rbp, -0xbf;\n"                                                                                                \
    "cmp rbp, -0xaf;\n"                                                                                                \
    "cmp rbp, -0x9f;\n"                                                                                                \
    "cmp rbp, -0x8f;\n"                                                                                                \
    "cmp rbp, -0x7f;\n"                                                                                                \
    "cmp rbp, -0x3e;\n"                                                                                                \
    "cmp rbp, -0x6f;\n"                                                                                                \
    "cmp rbp, -0x5f;\n"                                                                                                \
    "cmp rbp, -0x4f;\n"                                                                                                \
    "cmp rbp, -0x1f;\n"                                                                                                \
    "cmp rbp, -0xfa;\n"                                                                                                \
    "cmp rbp, -0xf9;\n"                                                                                                \
    "cmp rbp, -0xf8;\n"                                                                                                \
    "cmp rbp, -0xf7;\n"                                                                                                \
    "cmp rbp, -0xf6;\n"                                                                                                \
    "cmp rbp, -0xf5;\n"                                                                                                \
    "cmp rbp, -0xf4;\n"                                                                                                \
    "cmp rbp, -0xf3;\n"                                                                                                \
    "cmp rbp, -0xf2;\n"                                                                                                \
    "cmp rbp, -0xf1;\n"                                                                                                \
    "cmp rbp, -0xf66;\n"                                                                                               \
    "cmp rbp, -0x666ee;\n"                                                                                             \
    "cmp rbp, -0x6666ee12;\n"                                                                                          \
    "cmp r13, -0xfffee12;\n"                                                                                           \
    "cmp r13, 0xfffee12;\n"                                                                                            \
    "cmp r13, 0xff6ee12;\n"                                                                                            \
    "cmp r13, 0xf66ee12;\n"                                                                                            \
    "cmp r13, 0x666ee12;\n"                                                                                            \
    "cmp r13, 0x6666ee12;\n"                                                                                           \
    "cmp r13, -0x1;\n"                                                                                                 \
    "cmp r13, -0xfffee12;\n"                                                                                           \
    "cmp r13, -0xff6ee12;\n"                                                                                           \
    "cmp r13, -0xf66ee12;\n"                                                                                           \
    "cmp r13, -0x666ee12;\n"                                                                                           \
    "cmp r13, -0x6666ee12;\n"                                                                                          \
    "cmp rax, 0x12;\n"                                                                                                 \
    "cmp rax, 0xe12;\n"                                                                                                \
    "cmp rax, 0x66ee12;\n"                                                                                             \
    "cmp rax, 0x66ee12;\n"                                                                                             \
    "cmp rax, 0x6ee12;\n"                                                                                              \
    "cmp sp, 0x34ef;\n"                                                                                                \
    "cmp r8w, 0x1;\n"                                                                                                  \
    "cmp rax, [ rbx ];\n"                                                                                              \
    "cmp rax, [ rbx + 0x10 ];\n"                                                                                       \
    "cmp rax, 0x0;\n"                                                                                                  \
    "cmp rax, 0x0 ; with a comment;\n"                                                                                 \
    "cmp r12, r14;\n"                                                                                                  \
    "cmp r12, rbx;\n"                                                                                                  \
    "cmp r12, [ rsp + 0x10 ];\n"                                                                                       \
    "cmp rax, 0xfff;\n"                                                                                                \
    "cmp rax, r15;\n"                                                                                                  \
    "cmp rax, rbp;\n"                                                                                                  \
    "cmp rbp, r12;\n"                                                                                                  \
    "cmp rbp, r8;\n"                                                                                                   \
    "cmp rbp, r9;\n"                                                                                                   \
    "cmp rbx, r9;\n"                                                                                                   \
    "cmp rbx, rdi;\n"                                                                                                  \
    "cmp rdi, r10;\n"                                                                                                  \
    "cmp rdx, r14;\n"                                                                                                  \
    "cmp rsp, 0x138;\n"                                                                                                \
    "cmp rsp, 0x48;\n"                                                                                                 \
    "cmp rsp, 0x50;\n"                                                                                                 \
    "cmp rsp, 0x80;\n"                                                                                                 \
    "cmp rax, -0xf;\n"                                                                                                 \
    ""
