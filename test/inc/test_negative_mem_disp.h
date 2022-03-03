#define CODE                                                                                                           \
    "mov [ rsp - 0x100 ], rbx;\n"                                                                                      \
    "mov [ rsp - 0x108 ], rbp;\n"                                                                                      \
    "mov [ rsp - 0x110 ], r12;\n"                                                                                      \
    "mov [ rsp - 0x118 ], r13;\n"                                                                                      \
    "mov [ rsp - 0x120 ], r14;\n"                                                                                      \
    "mov [ rsp - 0x128 ], r15;\n"                                                                                      \
    "mov r11, [ rsi - 0x10 ];\n"                                                                                       \
    "mov r9, [ rsi - 0x1 ];\n"                                                                                         \
    "mov rdx, [ rsi - 0x1];\n"                                                                                         \
    "mov rdx, [ rsi - 0x18 ];\n"                                                                                       \
    "mov [ rsp - 0x1], rdi;\n"                                                                                         \
    "mulx r11, rdi, [ rsi - 0x1 ];\n"                                                                                  \
    "mov [ rsp - 0x8 ], r12;\n"                                                                                        \
    "mov [ rsp - 0x10 ], r15;\n"                                                                                       \
    "mulx r12, r15, [ rsi - 0x8 ];\n"                                                                                  \
    "mov [ rsp - 0x18 ], r14;\n"                                                                                       \
    "mov [ rsp - 0x20 ], rax;\n"                                                                                       \
    "mulx r14, rax, [ rsi - 0x10 ];\n"                                                                                 \
    "mulx rdx, r10, [ rsi - 0x18 ];\n"                                                                                 \
    "mulx rbp, r12, [ rsi - 0x8 ];\n"                                                                                  \
    "mov r15, [ rsp - 0x8 ];\n"                                                                                        \
    "mov [ rsp - 0x28 ], r11;\n"                                                                                       \
    "mov [ rsp - 0x30 ], rsi;\n"                                                                                       \
    "mov r13, [ rsp - 0x10 ];\n"                                                                                       \
    "mov [ rsp - 0x38 ], rbx;\n"                                                                                       \
    "mov r12, [ rsp - 0x30 ];\n"                                                                                       \
    "mulx rdx, rsi, [ r12 - 0x10 ];\n"                                                                                 \
    "mov [ rsp - 0x40 ], rsi;\n"                                                                                       \
    "mov rsi, [ r12 - 0x8 ];\n"                                                                                        \
    "mov [ rsp - 0x48 ], rsi;\n"                                                                                       \
    "mulx r13, rsi, [ r12 - 0x10 ];\n"                                                                                 \
    "mov [ rsp - 0x50 ], r13;\n"                                                                                       \
    "mov r13, [ rsp - 0x40 ];\n"                                                                                       \
    "mov [ rsp - 0x58 ], r9;\n"                                                                                        \
    "mulx rbp, r9, [ r12 - 0x1 ];\n"                                                                                   \
    "mov [ rsp - 0x60 ], rbp;\n"                                                                                       \
    "mov [ rsp - 0x30 ], r12;\n"                                                                                       \
    "mov r10, [ rsp - 0x58 ];\n"                                                                                       \
    "mov [ rsp - 0x68 ], r14;\n"                                                                                       \
    "mov r9, [ rsp - 0x30 ];\n"                                                                                        \
    "mov [ rsp - 0x70 ], r14;\n"                                                                                       \
    "mov rdx, [ r9 - 0x8 ];\n"                                                                                         \
    "mov [ rsp - 0x78 ], rdi;\n"                                                                                       \
    "mov [ rsp - 0x80 ], r8;\n"                                                                                        \
    "mov [ rsp - 0x88 ], r8;\n"                                                                                        \
    "mov [ rsp - 0x30 ], r9;\n"                                                                                        \
    "mov rdx, [ rsp - 0x70 ];\n"                                                                                       \
    "mov [ rsp - 0x90 ], r14;\n"                                                                                       \
    "mov r8, [ rsp - 0x18 ];\n"                                                                                        \
    "mov [ rsp - 0x98 ], rdx;\n"                                                                                       \
    "adcx r8, [ rsp - 0x48 ];\n"                                                                                       \
    "mov rdx, [ rsp - 0x80 ];\n"                                                                                       \
    "mov r11, [ rsp - 0x90 ];\n"                                                                                       \
    "mov r11, [ rsp - 0x60 ];\n"                                                                                       \
    "mov r9, [ rsp - 0x88 ];\n"                                                                                        \
    "mov byte [ rsp - 0xa0 ], r14b;\n"                                                                                 \
    "mov r11, [ rsp - 0x30 ];\n"                                                                                       \
    "mulx rdx, rbx, [ r11 - 0x18 ];\n"                                                                                 \
    "mov byte [ rsp - 0xa8 ], r14b;\n"                                                                                 \
    "adcx r8, [ rsp - 0x38 ];\n"                                                                                       \
    "mov [ rsp - 0x30 ], r11;\n"                                                                                       \
    "adcx rcx, [ rsp - 0x20 ];\n"                                                                                      \
    "mov rdi, [ rsp - 0x50 ];\n"                                                                                       \
    "mov rbp, [ rsp - 0x78 ];\n"                                                                                       \
    "mov rsi, [ rsp - 0x30 ];\n"                                                                                       \
    "mov r13, [ rsi - 0x18 ];\n"                                                                                       \
    "mov rdx, [ rsp - 0x90 ];\n"                                                                                       \
    "mov [ rsp - 0xb0 ], rbx;\n"                                                                                       \
    "mulx r8, rbx, [ rsi - 0x8 ];\n"                                                                                   \
    "mov [ rsp - 0x30 ], rsi;\n"                                                                                       \
    "mov r9, [ rsp - 0xb0 ];\n"                                                                                        \
    "mov rcx, [ rsp - 0x28 ];\n"                                                                                       \
    "mov [ rsp - 0xb8 ], rcx;\n"                                                                                       \
    "mov [ rsp - 0xc0 ], rbx;\n"                                                                                       \
    "mov [ rsp - 0xc8 ], rcx;\n"                                                                                       \
    "mov rdx, [ rsp - 0x30 ];\n"                                                                                       \
    "mulx rcx, rsi, [ r11 - 0x1];\n"                                                                                   \
    "mov [ rsp - 0xd0 ], rbp;\n"                                                                                       \
    "mov rbx, [ rsp - 0xc8 ];\n"                                                                                       \
    "mov [ rsp - 0xd8 ], rsi;\n"                                                                                       \
    "mov rsi, [ rsp - 0xc0 ];\n"                                                                                       \
    "mov rcx, [ rsp - 0xb8 ];\n"                                                                                       \
    "adox r13, [ rsp - 0x68 ];\n"                                                                                      \
    "mulx r14, rbp, [ r11 - 0x18 ];\n"                                                                                 \
    "mov [ rsp - 0xe0 ], r13;\n"                                                                                       \
    "mov rbx, [ rsp - 0xe0 ];\n"                                                                                       \
    "mov r9, [ rsp - 0xd8 ];\n"                                                                                        \
    "mulx rdx, rcx, [ r11 - 0x10 ];\n"                                                                                 \
    "mov [ rsp - 0xe8 ], rcx;\n"                                                                                       \
    "mov byte [ rsp - 0xf0 ], r15b;\n"                                                                                 \
    "mov [ rsp - 0xf8 ], r14;\n"                                                                                       \
    "mov rdi, [ rsp - 0xe8 ];\n"                                                                                       \
    "mov r15, [ rsp - 0xf8 ];\n"                                                                                       \
    "mov [ rsp - 0x30 ], r11;\n"                                                                                       \
    "mov rax, [ rsp - 0x1];\n"                                                                                         \
    "mov [ rax - 0x1], r11;\n"                                                                                         \
    "mov [ rax - 0x8 ], rbp;\n"                                                                                        \
    "mov [ rax - 0x18 ], r15;\n"                                                                                       \
    "mov [ rax - 0x10 ], rcx;\n"                                                                                       \
    "mov rbx, [ rsp - 0x100 ];\n"                                                                                      \
    "mov rbp, [ rsp - 0x108 ];\n"                                                                                      \
    "mov r12, [ rsp - 0x110 ];\n"                                                                                      \
    "mov r13, [ rsp - 0x118 ];\n"                                                                                      \
    "mov r14, [ rsp - 0x120 ];\n"                                                                                      \
    "mov r15, [ rsp - 0x128 ];\n"                                                                                      \
    ""
