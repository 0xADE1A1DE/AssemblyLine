#define CODE                                                                                                           \
    "add rsp, 0x39a8 ;\n"                                                                                              \
    "and r10, r11;\n"                                                                                                  \
    "and r10, r12;\n"                                                                                                  \
    "and r10, r13;\n"                                                                                                  \
    "and r10, r14;\n"                                                                                                  \
    "and r10, r15;\n"                                                                                                  \
    "and r10, r8;\n"                                                                                                   \
    "and r10, r9;\n"                                                                                                   \
    "and r10, rax;\n"                                                                                                  \
    "and r10, rbp;\n"                                                                                                  \
    "and r10, rbx;\n"                                                                                                  \
    "and r10, rcx;\n"                                                                                                  \
    "and r10, rdi;\n"                                                                                                  \
    "and r10, rdx;\n"                                                                                                  \
    "and r10, rsi;\n"                                                                                                  \
    "and r10, [ rsp + 0x11f0 ];\n"                                                                                     \
    "and r10, [ rsp + 0x19f0 ];\n"                                                                                     \
    "and r10, [ rsp + 0x1b10 ];\n"                                                                                     \
    "and r10, [ rsp + 0x1c10 ];\n"                                                                                     \
    "and r10, [ rsp + 0x1c8 ];\n"                                                                                      \
    "and r10, [ rsp + 0x1de8 ];\n"                                                                                     \
    "and r10, [ rsp + 0x1f90 ];\n"                                                                                     \
    "and r10, [ rsp + 0x2708 ];\n"                                                                                     \
    "and r10, [ rsp + 0x2970 ];\n"                                                                                     \
    "and r10, [ rsp + 0x2e10 ];\n"                                                                                     \
    "and r10, [ rsp + 0x30e0 ];\n"                                                                                     \
    "and r10, [ rsp + 0x35c0 ];\n"                                                                                     \
    "and r10, [ rsp + 0x460 ];\n"                                                                                      \
    "and r10, [ rsp + 0x680 ];\n"                                                                                      \
    "and r10, [ rsp + 0xb48 ];\n"                                                                                      \
    "and r11, r10;\n"                                                                                                  \
    "and r11, r12;\n"                                                                                                  \
    "and r11, r13;\n"                                                                                                  \
    "and r11, r14;\n"                                                                                                  \
    "and r11, r15;\n"                                                                                                  \
    "and r11, r8;\n"                                                                                                   \
    "and r11, r9;\n"                                                                                                   \
    "and r11, rax;\n"                                                                                                  \
    "and r11, rcx;\n"                                                                                                  \
    "and r11, rdi;\n"                                                                                                  \
    "and r11, rsi;\n"                                                                                                  \
    "and r11, [ rsp + 0x14a0 ];\n"                                                                                     \
    "and r11, [ rsp + 0x158 ];\n"                                                                                      \
    "and r11, [ rsp + 0x1750 ];\n"                                                                                     \
    "and r11, [ rsp + 0x2218 ];\n"                                                                                     \
    "and r11, [ rsp + 0x24b0 ];\n"                                                                                     \
    "and r11, [ rsp + 0x2688 ];\n"                                                                                     \
    "and r11, [ rsp + 0x26c0 ];\n"                                                                                     \
    "and r11, [ rsp + 0x2920 ];\n"                                                                                     \
    "and r11, [ rsp + 0x2938 ];\n"                                                                                     \
    "and r11, [ rsp + 0x29b0 ];\n"                                                                                     \
    "and r11, [ rsp + 0x3780 ];\n"                                                                                     \
    "and r11, [ rsp + 0x37e8 ];\n"                                                                                     \
    "and r11, [ rsp + 0xbd8 ];\n"                                                                                      \
    "and r12, r10;\n"                                                                                                  \
    "and r12, r11;\n"                                                                                                  \
    "and r12, r13;\n"                                                                                                  \
    "and r12, r14;\n"                                                                                                  \
    "and r12, r15;\n"                                                                                                  \
    "and r12, r9;\n"                                                                                                   \
    "and r12, rax;\n"                                                                                                  \
    "and r12, rbp;\n"                                                                                                  \
    "and r12, rbx;\n"                                                                                                  \
    "and r12, rcx;\n"                                                                                                  \
    "and r12, rdi;\n"                                                                                                  \
    "and r12, rdx;\n"                                                                                                  \
    "and r12, rsi;\n"                                                                                                  \
    "and r12, [ rsp + 0x1048 ];\n"                                                                                     \
    "and r12, [ rsp + 0x12a0 ];\n"                                                                                     \
    "and r12, [ rsp + 0x1428 ];\n"                                                                                     \
    "and r12, [ rsp + 0x16c8 ];\n"                                                                                     \
    "and r12, [ rsp + 0x220 ];\n"                                                                                      \
    "and r12, [ rsp + 0x23b8 ];\n"                                                                                     \
    "and r12, [ rsp + 0x2520 ];\n"                                                                                     \
    "and r12, [ rsp + 0x2528 ];\n"                                                                                     \
    "and r12, [ rsp + 0x29a8 ];\n"                                                                                     \
    "and r12, [ rsp + 0x2be8 ];\n"                                                                                     \
    "and r12, [ rsp + 0x910 ];\n"                                                                                      \
    "and r13, r11;\n"                                                                                                  \
    "and r13, r12;\n"                                                                                                  \
    "and r13, r15;\n"                                                                                                  \
    "and r13, r8;\n"                                                                                                   \
    "and r13, r9;\n"                                                                                                   \
    "and r13, rax;\n"                                                                                                  \
    "and r13, rbp;\n"                                                                                                  \
    "and r13, rcx;\n"                                                                                                  \
    "and r13, rdi;\n"                                                                                                  \
    "and r13, rdx;\n"                                                                                                  \
    "and r13, rsi;\n"                                                                                                  \
    "and r13, [ rsp + 0x110 ];\n"                                                                                      \
    "and r13, [ rsp + 0x14c0 ];\n"                                                                                     \
    "and r13, [ rsp + 0x1d90 ];\n"                                                                                     \
    "and r13, [ rsp + 0x1fe8 ];\n"                                                                                     \
    "and r13, [ rsp + 0x2228 ];\n"                                                                                     \
    "and r13, [ rsp + 0x2780 ];\n"                                                                                     \
    "and r13, [ rsp + 0x27d0 ];\n"                                                                                     \
    "and r13, [ rsp + 0x2c20 ];\n"                                                                                     \
    "and r13, [ rsp + 0x3658 ];\n"                                                                                     \
    "and r13, [ rsp + 0x3c8 ];\n"                                                                                      \
    "and r13, [ rsp + 0xe08 ];\n"                                                                                      \
    "and r14, r10;\n"                                                                                                  \
    "and r14, r11;\n"                                                                                                  \
    "and r14, r12;\n"                                                                                                  \
    "and r14, r13;\n"                                                                                                  \
    "and r14, r15;\n"                                                                                                  \
    "and r14, r8;\n"                                                                                                   \
    "and r14, r9;\n"                                                                                                   \
    "and r14, rax;\n"                                                                                                  \
    "and r14, rbp;\n"                                                                                                  \
    "and r14, rcx;\n"                                                                                                  \
    "and r14, rdx;\n"                                                                                                  \
    "and r14, rsi;\n"                                                                                                  \
    "and r14, [ rsp + 0x13e8 ];\n"                                                                                     \
    "and r14, [ rsp + 0x17b0 ];\n"                                                                                     \
    "and r14, [ rsp + 0x18c8 ];\n"                                                                                     \
    "and r14, [ rsp + 0x1aa0 ];\n"                                                                                     \
    "and r14, [ rsp + 0x1e58 ];\n"                                                                                     \
    "and r14, [ rsp + 0x2088 ];\n"                                                                                     \
    "and r14, [ rsp + 0x20e8 ];\n"                                                                                     \
    "and r14, [ rsp + 0x2498 ];\n"                                                                                     \
    "and r14, [ rsp + 0x2a10 ];\n"                                                                                     \
    "and r14, [ rsp + 0x2da0 ];\n"                                                                                     \
    "and r14, [ rsp + 0x32c0 ];\n"                                                                                     \
    "and r14, [ rsp + 0x34f8 ];\n"                                                                                     \
    "and r14, [ rsp + 0x3600 ];\n"                                                                                     \
    "and r14, [ rsp + 0x3a8 ];\n"                                                                                      \
    "and r14, [ rsp + 0x600 ];\n"                                                                                      \
    "and r14, [ rsp + 0x848 ];\n"                                                                                      \
    "and r14, [ rsp + 0xdc8 ];\n"                                                                                      \
    "and r15, r10;\n"                                                                                                  \
    "and r15, r11;\n"                                                                                                  \
    "and r15, r13;\n"                                                                                                  \
    "and r15, r8;\n"                                                                                                   \
    "and r15, r9;\n"                                                                                                   \
    "and r15, rax;\n"                                                                                                  \
    "and r15, rbp;\n"                                                                                                  \
    "and r15, rbx;\n"                                                                                                  \
    "and r15, rcx;\n"                                                                                                  \
    "and r15, rdi;\n"                                                                                                  \
    "and r15, rdx;\n"                                                                                                  \
    "and r15, rsi;\n"                                                                                                  \
    "and r15, [ rsp + 0x1910 ];\n"                                                                                     \
    "and r15, [ rsp + 0x1968 ];\n"                                                                                     \
    "and r15, [ rsp + 0x1b58 ];\n"                                                                                     \
    "and r15, [ rsp + 0x1d0 ];\n"                                                                                      \
    "and r15, [ rsp + 0x30c8 ];\n"                                                                                     \
    "and r15, [ rsp + 0x3110 ];\n"                                                                                     \
    "and r15, [ rsp + 0x3140 ];\n"                                                                                     \
    "and r15, [ rsp + 0x8f8 ];\n"                                                                                      \
    "and r15, [ rsp + 0xb70 ];\n"                                                                                      \
    "and r15, [ rsp + 0xbe0 ];\n"                                                                                      \
    "and r15, [ rsp + 0xd50 ];\n"                                                                                      \
    "and r8, r11;\n"                                                                                                   \
    "and r8, r12;\n"                                                                                                   \
    "and r8, r13;\n"                                                                                                   \
    "and r8, r14;\n"                                                                                                   \
    "and r8, r15;\n"                                                                                                   \
    "and r8, r9;\n"                                                                                                    \
    "and r8, rax;\n"                                                                                                   \
    "and r8, rbp;\n"                                                                                                   \
    "and r8, rbx;\n"                                                                                                   \
    "and r8, rcx;\n"                                                                                                   \
    "and r8, rdi;\n"                                                                                                   \
    "and r8, rdx;\n"                                                                                                   \
    "and r8, [ rsp + 0x1270 ];\n"                                                                                      \
    "and r8, [ rsp + 0x14b0 ];\n"                                                                                      \
    "and r8, [ rsp + 0x1700 ];\n"                                                                                      \
    "and r8, [ rsp + 0x1730 ];\n"                                                                                      \
    "and r8, [ rsp + 0x1c08 ];\n"                                                                                      \
    "and r8, [ rsp + 0x1fe0 ];\n"                                                                                      \
    "and r8, [ rsp + 0x2110 ];\n"                                                                                      \
    "and r8, [ rsp + 0x2500 ];\n"                                                                                      \
    "and r8, [ rsp + 0x2e48 ];\n"                                                                                      \
    "and r8, [ rsp + 0x3380 ];\n"                                                                                      \
    "and r8, [ rsp + 0x3488 ];\n"                                                                                      \
    "and r8, [ rsp + 0x38e8 ];\n"                                                                                      \
    "and r8, [ rsp + 0x440 ];\n"                                                                                       \
    "and r8, [ rsp + 0x6b8 ];\n"                                                                                       \
    "and r8, [ rsp + 0xb90 ];\n"                                                                                       \
    "and r8, [ rsp + 0xe18 ];\n"                                                                                       \
    "and r8, [ rsp + 0xea0 ];\n"                                                                                       \
    "and r8, [ rsp + 0xf78 ];\n"                                                                                       \
    "and r8, [ rsp + 0xfe0 ];\n"                                                                                       \
    "and r9, r10;\n"                                                                                                   \
    "and r9, r11;\n"                                                                                                   \
    "and r9, r12;\n"                                                                                                   \
    "and r9, r14;\n"                                                                                                   \
    "and r9, r15;\n"                                                                                                   \
    "and r9, r8;\n"                                                                                                    \
    "and r9, rax;\n"                                                                                                   \
    "and r9, rbp;\n"                                                                                                   \
    "and r9, rbx;\n"                                                                                                   \
    "and r9, rcx;\n"                                                                                                   \
    "and r9, rdi;\n"                                                                                                   \
    "and r9, rsi;\n"                                                                                                   \
    "and r9, [ rsp + 0x1030 ];\n"                                                                                      \
    "and r9, [ rsp + 0x1b70 ];\n"                                                                                      \
    "and r9, [ rsp + 0x2310 ];\n"                                                                                      \
    "and r9, [ rsp + 0x2318 ];\n"                                                                                      \
    "and r9, [ rsp + 0x26f8 ];\n"                                                                                      \
    "and r9, [ rsp + 0x27c8 ];\n"                                                                                      \
    "and r9, [ rsp + 0x27d8 ];\n"                                                                                      \
    "and r9, [ rsp + 0x3860 ];\n"                                                                                      \
    "and r9, [ rsp + 0x3958 ];\n"                                                                                      \
    "and r9, [ rsp + 0xf70 ];\n"                                                                                       \
    "and rax, r10;\n"                                                                                                  \
    "and rax, r11;\n"                                                                                                  \
    "and rax, r12;\n"                                                                                                  \
    "and rax, r14;\n"                                                                                                  \
    "and rax, r15;\n"                                                                                                  \
    "and rax, r8;\n"                                                                                                   \
    "and rax, r9;\n"                                                                                                   \
    "and rax, rbp;\n"                                                                                                  \
    "and rax, rbx;\n"                                                                                                  \
    "and rax, rcx;\n"                                                                                                  \
    "and rax, rdx;\n"                                                                                                  \
    "and rax, rsi;\n"                                                                                                  \
    "and rax, [ rsp + 0x1198 ];\n"                                                                                     \
    "and rax, [ rsp + 0x11e8 ];\n"                                                                                     \
    "and rax, [ rsp + 0x2b10 ];\n"                                                                                     \
    "and rax, [ rsp + 0x2b70 ];\n"                                                                                     \
    "and rax, [ rsp + 0x2ea0 ];\n"                                                                                     \
    "and rax, [ rsp + 0x3118 ];\n"                                                                                     \
    "and rax, [ rsp + 0x3288 ];\n"                                                                                     \
    "and rax, [ rsp + 0x34b8 ];\n"                                                                                     \
    "and rax, [ rsp + 0x35f0 ];\n"                                                                                     \
    "and rax, [ rsp + 0x3700 ];\n"                                                                                     \
    "and rax, [ rsp + 0x4b0 ];\n"                                                                                      \
    "and rax, [ rsp + 0x978 ];\n"                                                                                      \
    "and rax, [ rsp + 0xb88 ];\n"                                                                                      \
    "and rbp, r10;\n"                                                                                                  \
    "and rbp, r12;\n"                                                                                                  \
    "and rbp, r13;\n"                                                                                                  \
    "and rbp, r15;\n"                                                                                                  \
    "and rbp, r8;\n"                                                                                                   \
    "and rbp, r9;\n"                                                                                                   \
    "and rbp, rax;\n"                                                                                                  \
    "and rbp, rsi;\n"                                                                                                  \
    "and rbp, [ rsp + 0x1470 ];\n"                                                                                     \
    "and rbp, [ rsp + 0x1970 ];\n"                                                                                     \
    "and rbp, [ rsp + 0x1f80 ];\n"                                                                                     \
    "and rbp, [ rsp + 0x20a0 ];\n"                                                                                     \
    "and rbp, [ rsp + 0x2878 ];\n"                                                                                     \
    "and rbp, [ rsp + 0x29d0 ];\n"                                                                                     \
    "and rbp, [ rsp + 0x2df8 ];\n"                                                                                     \
    "and rbp, [ rsp + 0x2ec8 ];\n"                                                                                     \
    "and rbp, [ rsp + 0x30d8 ];\n"                                                                                     \
    "and rbp, [ rsp + 0x3320 ];\n"                                                                                     \
    "and rbp, [ rsp + 0x3360 ];\n"                                                                                     \
    "and rbp, [ rsp + 0x3500 ];\n"                                                                                     \
    "and rbp, [ rsp + 0x37a0 ];\n"                                                                                     \
    "and rbp, [ rsp + 0x5f0 ];\n"                                                                                      \
    "and rbp, [ rsp + 0x858 ];\n"                                                                                      \
    "and rbp, [ rsp + 0x980 ];\n"                                                                                      \
    "and rbx, r10;\n"                                                                                                  \
    "and rbx, r11;\n"                                                                                                  \
    "and rbx, r12;\n"                                                                                                  \
    "and rbx, r14;\n"                                                                                                  \
    "and rbx, r15;\n"                                                                                                  \
    "and rbx, r8;\n"                                                                                                   \
    "and rbx, r9;\n"                                                                                                   \
    "and rbx, rbp;\n"                                                                                                  \
    "and rbx, rcx;\n"                                                                                                  \
    "and rbx, rdi;\n"                                                                                                  \
    "and rbx, rdx;\n"                                                                                                  \
    "and rbx, rsi;\n"                                                                                                  \
    "and rbx, [ rsp + 0x12d0 ];\n"                                                                                     \
    "and rbx, [ rsp + 0x1388 ];\n"                                                                                     \
    "and rbx, [ rsp + 0x1890 ];\n"                                                                                     \
    "and rbx, [ rsp + 0x1980 ];\n"                                                                                     \
    "and rbx, [ rsp + 0x2248 ];\n"                                                                                     \
    "and rbx, [ rsp + 0x22c8 ];\n"                                                                                     \
    "and rbx, [ rsp + 0x2dc0 ];\n"                                                                                     \
    "and rbx, [ rsp + 0x3098 ];\n"                                                                                     \
    "and rbx, [ rsp + 0x32d8 ];\n"                                                                                     \
    "and rbx, [ rsp + 0x3618 ];\n"                                                                                     \
    "and rbx, [ rsp + 0x3758 ];\n"                                                                                     \
    "and rbx, [ rsp + 0x620 ];\n"                                                                                      \
    "and rbx, [ rsp + 0x730 ];\n"                                                                                      \
    "and rbx, [ rsp + 0x8b8 ];\n"                                                                                      \
    "and rbx, [ rsp + 0xa60 ];\n"                                                                                      \
    "and rbx, [ rsp + 0xec0 ];\n"                                                                                      \
    "and rcx, r10;\n"                                                                                                  \
    "and rcx, r11;\n"                                                                                                  \
    "and rcx, r12;\n"                                                                                                  \
    "and rcx, r13;\n"                                                                                                  \
    "and rcx, r14;\n"                                                                                                  \
    "and rcx, r15;\n"                                                                                                  \
    "and rcx, r8;\n"                                                                                                   \
    "and rcx, r9;\n"                                                                                                   \
    "and rcx, rbp;\n"                                                                                                  \
    "and rcx, rbx;\n"                                                                                                  \
    "and rcx, rdi;\n"                                                                                                  \
    "and rcx, rdx;\n"                                                                                                  \
    "and rcx, rsi;\n"                                                                                                  \
    "and rcx, [ rsp + 0x1000 ];\n"                                                                                     \
    "and rcx, [ rsp + 0x1238 ];\n"                                                                                     \
    "and rcx, [ rsp + 0x1248 ];\n"                                                                                     \
    "and rcx, [ rsp + 0x1790 ];\n"                                                                                     \
    "and rcx, [ rsp + 0x1b38 ];\n"                                                                                     \
    "and rcx, [ rsp + 0x1d58 ];\n"                                                                                     \
    "and rcx, [ rsp + 0x1e88 ];\n"                                                                                     \
    "and rcx, [ rsp + 0x1f8 ];\n"                                                                                      \
    "and rcx, [ rsp + 0x2058 ];\n"                                                                                     \
    "and rcx, [ rsp + 0x228 ];\n"                                                                                      \
    "and rcx, [ rsp + 0x2460 ];\n"                                                                                     \
    "and rcx, [ rsp + 0x2940 ];\n"                                                                                     \
    "and rcx, [ rsp + 0x2ce8 ];\n"                                                                                     \
    "and rcx, [ rsp + 0x3040 ];\n"                                                                                     \
    "and rcx, [ rsp + 0x3208 ];\n"                                                                                     \
    "and rcx, [ rsp + 0x35b8 ];\n"                                                                                     \
    "and rcx, [ rsp + 0xd98 ];\n"                                                                                      \
    "and rdi, r10;\n"                                                                                                  \
    "and rdi, r11;\n"                                                                                                  \
    "and rdi, r12;\n"                                                                                                  \
    "and rdi, r13;\n"                                                                                                  \
    "and rdi, r14;\n"                                                                                                  \
    "and rdi, r15;\n"                                                                                                  \
    "and rdi, r8;\n"                                                                                                   \
    "and rdi, r9;\n"                                                                                                   \
    "and rdi, rax;\n"                                                                                                  \
    "and rdi, rbp;\n"                                                                                                  \
    "and rdi, rcx;\n"                                                                                                  \
    "and rdi, rdx;\n"                                                                                                  \
    "and rdi, rsi;\n"                                                                                                  \
    "and rdi, [ rsp + 0x1080 ];\n"                                                                                     \
    "and rdi, [ rsp + 0x14d0 ];\n"                                                                                     \
    "and rdi, [ rsp + 0x18f8 ];\n"                                                                                     \
    "and rdi, [ rsp + 0x2038 ];\n"                                                                                     \
    "and rdi, [ rsp + 0x2b80 ];\n"                                                                                     \
    "and rdi, [ rsp + 0x3740 ];\n"                                                                                     \
    "and rdi, [ rsp + 0x38a0 ];\n"                                                                                     \
    "and rdi, [ rsp + 0x580 ];\n"                                                                                      \
    "and rdi, [ rsp + 0x640 ];\n"                                                                                      \
    "and rdi, [ rsp + 0x728 ];\n"                                                                                      \
    "and rdi, [ rsp + 0x850 ];\n"                                                                                      \
    "and rdi, [ rsp + 0xf20 ];\n"                                                                                      \
    "and rdx, r10;\n"                                                                                                  \
    "and rdx, r12;\n"                                                                                                  \
    "and rdx, r13;\n"                                                                                                  \
    "and rdx, r14;\n"                                                                                                  \
    "and rdx, r15;\n"                                                                                                  \
    "and rdx, r8;\n"                                                                                                   \
    "and rdx, r9;\n"                                                                                                   \
    "and rdx, rax;\n"                                                                                                  \
    "and rdx, rbp;\n"                                                                                                  \
    "and rdx, rbx;\n"                                                                                                  \
    "and rdx, rdi;\n"                                                                                                  \
    "and rdx, rsi;\n"                                                                                                  \
    "and rdx, [ rsp + 0x1078 ];\n"                                                                                     \
    "and rdx, [ rsp + 0x1688 ];\n"                                                                                     \
    "and rdx, [ rsp + 0x1ce0 ];\n"                                                                                     \
    "and rdx, [ rsp + 0x21a8 ];\n"                                                                                     \
    "and rdx, [ rsp + 0x2428 ];\n"                                                                                     \
    "and rdx, [ rsp + 0x2620 ];\n"                                                                                     \
    "and rdx, [ rsp + 0x2b18 ];\n"                                                                                     \
    "and rdx, [ rsp + 0x2c80 ];\n"                                                                                     \
    "and rdx, [ rsp + 0x2ed0 ];\n"                                                                                     \
    "and rdx, [ rsp + 0x3748 ];\n"                                                                                     \
    "and rdx, [ rsp + 0xa0 ];\n"                                                                                       \
    "and rdx, [ rsp + 0xbd0 ];\n"                                                                                      \
    "and rdx, [ rsp + 0xd68 ];\n"                                                                                      \
    "and rsi, r10;\n"                                                                                                  \
    "and rsi, r11;\n"                                                                                                  \
    "and rsi, r12;\n"                                                                                                  \
    "and rsi, r13;\n"                                                                                                  \
    "and rsi, r14;\n"                                                                                                  \
    "and rsi, r15;\n"                                                                                                  \
    "and rsi, r8;\n"                                                                                                   \
    "and rsi, rax;\n"                                                                                                  \
    "and rsi, rbp;\n"                                                                                                  \
    "and rsi, rbx;\n"                                                                                                  \
    "and rsi, rcx;\n"                                                                                                  \
    "and rsi, rdi;\n"                                                                                                  \
    "and rsi, rdx;\n"                                                                                                  \
    "and rsi, [ rsp + 0x16b8 ];\n"                                                                                     \
    "and rsi, [ rsp + 0x178 ];\n"                                                                                      \
    "and rsi, [ rsp + 0x1b80 ];\n"                                                                                     \
    "and rsi, [ rsp + 0x1d40 ];\n"                                                                                     \
    "and rsi, [ rsp + 0x22b0 ];\n"                                                                                     \
    "and rsi, [ rsp + 0x2560 ];\n"                                                                                     \
    "and rsi, [ rsp + 0x2760 ];\n"                                                                                     \
    "and rsi, [ rsp + 0x2bb8 ];\n"                                                                                     \
    "and rsi, [ rsp + 0x2c50 ];\n"                                                                                     \
    "and rsi, [ rsp + 0xc78 ];\n"                                                                                      \
    "and r10, r11;\n"                                                                                                  \
    "and r10, rdi;\n"                                                                                                  \
    "and r12, r11;\n"                                                                                                  \
    "and r13, r10;\n"                                                                                                  \
    "and r14, r8;\n"                                                                                                   \
    "and r14, rdi;\n"                                                                                                  \
    "and r15, r10;\n"                                                                                                  \
    "and r15, r11;\n"                                                                                                  \
    "and r8, r10;\n"                                                                                                   \
    "and r8, r11;\n"                                                                                                   \
    "and r8, rdi;\n"                                                                                                   \
    "and r9, r10;\n"                                                                                                   \
    "and r9, rdi;\n"                                                                                                   \
    "and rax, r10;\n"                                                                                                  \
    "and rax, rbp;\n"                                                                                                  \
    "and rbx, r11;\n"                                                                                                  \
    "and rbx, rdi;\n"                                                                                                  \
    "and rcx, r11;\n"                                                                                                  \
    "and rcx, rdi;\n"                                                                                                  \
    "and rdx, r10;\n"                                                                                                  \
    "and al, 0x0;\n"                                                                                                   \
    "and ax, 0xe1;\n"                                                                                                  \
    "and eax, 0xe11;\n"                                                                                                \
    "and sil, 0x0;\n"                                                                                                  \
    "and si, 0xe1;\n"                                                                                                  \
    "and esi, 0xe11;\n"                                                                                                \
    "and rax, 0xfffee12;\n"                                                                                            \
    "and rax, 0xff6ee12;\n"                                                                                            \
    "and rax, 0xf66ee12;\n"                                                                                            \
    "and rax, 0x666ee12;\n"                                                                                            \
    "and rax, 0x6666ee12;\n"                                                                                           \
    "and rax, -0x1;\n"                                                                                                 \
    "and rax, -0xfffee12;\n"                                                                                           \
    "and rax, -0xff6ee12;\n"                                                                                           \
    "and rax, -0xf66ee12;\n"                                                                                           \
    "and rax, -0x666ee12;\n"                                                                                           \
    "and rax, -0x6666ee12;\n"                                                                                          \
    "and rbp, -0xfffee12;\n"                                                                                           \
    "and rbp, 0xfffee12;\n"                                                                                            \
    "and rbp, 0xff6ee12;\n"                                                                                            \
    "and rbp, 0xf66ee12;\n"                                                                                            \
    "and rbp, 0x666ee12;\n"                                                                                            \
    "and rbp, 0x6666ee12;\n"                                                                                           \
    "and rbp, -0xf;\n"                                                                                                 \
    "and rbp, -0xe;\n"                                                                                                 \
    "and rbp, -0xd;\n"                                                                                                 \
    "and rbp, -0x7;\n"                                                                                                 \
    "and rbp, -0x4;\n"                                                                                                 \
    "and rbp, -0x3;\n"                                                                                                 \
    "and rbp, -0x2;\n"                                                                                                 \
    "and rbp, -0xff;\n"                                                                                                \
    "and rbp, -0xef;\n"                                                                                                \
    "and rbp, -0xdf;\n"                                                                                                \
    "and rbp, -0xcf;\n"                                                                                                \
    "and rbp, -0xbf;\n"                                                                                                \
    "and rbp, -0xaf;\n"                                                                                                \
    "and rbp, -0x9f;\n"                                                                                                \
    "and rbp, -0x8f;\n"                                                                                                \
    "and rbp, -0x7f;\n"                                                                                                \
    "and rbp, -0x3e;\n"                                                                                                \
    "and rbp, -0x6f;\n"                                                                                                \
    "and rbp, -0x5f;\n"                                                                                                \
    "and rbp, -0x4f;\n"                                                                                                \
    "and rbp, -0x1f;\n"                                                                                                \
    "and rbp, -0xfa;\n"                                                                                                \
    "and rbp, -0xf9;\n"                                                                                                \
    "and rbp, -0xf8;\n"                                                                                                \
    "and rbp, -0xf7;\n"                                                                                                \
    "and rbp, -0xf6;\n"                                                                                                \
    "and rbp, -0xf5;\n"                                                                                                \
    "and rbp, -0xf4;\n"                                                                                                \
    "and rbp, -0xf3;\n"                                                                                                \
    "and rbp, -0xf2;\n"                                                                                                \
    "and rbp, -0xf1;\n"                                                                                                \
    "and rbp, -0xf66;\n"                                                                                               \
    "and rbp, -0x666ee;\n"                                                                                             \
    "and rbp, -0x6666ee12;\n"                                                                                          \
    "and r13, -0xfffee12;\n"                                                                                           \
    "and r13, 0xfffee12;\n"                                                                                            \
    "and r13, 0xff6ee12;\n"                                                                                            \
    "and r13, 0xf66ee12;\n"                                                                                            \
    "and r13, 0x666ee12;\n"                                                                                            \
    "and r13, 0x6666ee12;\n"                                                                                           \
    "and r13, -0x1;\n"                                                                                                 \
    "and r13, -0xfffee12;\n"                                                                                           \
    "and r13, -0xff6ee12;\n"                                                                                           \
    "and r13, -0xf66ee12;\n"                                                                                           \
    "and r13, -0x666ee12;\n"                                                                                           \
    "and r13, -0x6666ee12;\n"                                                                                          \
    "and rax, 0x12;\n"                                                                                                 \
    "and rax, 0xe12;\n"                                                                                                \
    "and rax, 0x66ee12;\n"                                                                                             \
    "and rax, 0x66ee12;\n"                                                                                             \
    "and rax, 0x6ee12;\n"                                                                                              \
    "and sp, 0x34ef;\n"                                                                                                \
    "and r8w, 0x1;\n"                                                                                                  \
    "and rax, [ rbx ];\n"                                                                                              \
    "and rax, [ rbx + 0x10 ];\n"                                                                                       \
    "and rax, 0x0 ;\n"                                                                                                 \
    "and rax, 0x0 ; with a comment;\n"                                                                                 \
    "and r12, r14;\n"                                                                                                  \
    "and r12, rbx;\n"                                                                                                  \
    "and r12, [ rsp + 0x10 ];\n"                                                                                       \
    "and rax, 0xfff;\n"                                                                                                \
    "and rax, r15;\n"                                                                                                  \
    "and rax, rbp;\n"                                                                                                  \
    "and rbp, r12;\n"                                                                                                  \
    "and rbp, r8;\n"                                                                                                   \
    "and rbp, r9;\n"                                                                                                   \
    "and rbx, r9;\n"                                                                                                   \
    "and rbx, rdi;\n"                                                                                                  \
    "and rdi, r10;\n"                                                                                                  \
    "and rdx, r14;\n"                                                                                                  \
    "and rsp, 0x138 ;\n"                                                                                               \
    "and rsp, 0x48 ;\n"                                                                                                \
    "and rsp, 0x50 ;\n"                                                                                                \
    "and rsp, 0x80 ;\n"                                                                                                \
    "and eax, ebx;\n"                                                                                                  \
    "and ebx, [rsi + 0x08];\n"                                                                                         \
    "and ebx, dword [rsi + 0x08];\n"                                                                                   \
    "and ebx, [ rsp ];\n"                                                                                              \
    "and ebx, dword [ rsp ];\n"                                                                                        \
    ""
