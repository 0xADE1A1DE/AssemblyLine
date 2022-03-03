#define CODE                                                                                                           \
    "movzx r11, r10b;\n"                                                                                               \
    "movzx r11, r11b;\n"                                                                                               \
    "movzx r12, r12b;\n"                                                                                               \
    "movzx r14, byte [ rsp + 0xa0 ];\n"                                                                                \
    "movzx r14, r14b;\n"                                                                                               \
    "movzx r8, byte [ rsp + 0xf0 ];\n"                                                                                 \
    "movzx r8, r10b;\n"                                                                                                \
    "movzx r8, r8b;\n"                                                                                                 \
    "movzx r9, r9b;\n"                                                                                                 \
    "movzx r9, r9b;\n"                                                                                                 \
    "movzx rax, al;\n"                                                                                                 \
    "movzx rax, bpl;\n"                                                                                                \
    "movzx rax, dil;\n"                                                                                                \
    "movzx rbp, bl;\n"                                                                                                 \
    "movzx rbp, bpl;\n"                                                                                                \
    "movzx rbx, byte [ rsp + 0xa8 ];\n"                                                                                \
    "movzx rbx, r15b;\n"                                                                                               \
    "movzx rcx, cl;\n"                                                                                                 \
    "movzx rcx, cl;\n"                                                                                                 \
    "movzx rcx, r12b;\n"                                                                                               \
    "movzx rdx, dl;\n"                                                                                                 \
    "movzx rdx, r8b;\n"                                                                                                \
    "movzx rdx, r9b;\n"                                                                                                \
    "movzx eax, al ; r/32 <- r/8;\n"                                                                                   \
    "movzx ebx, byte [ rsp + 0xa8 ] ;r/32 m/8;\n"                                                                      \
    ""
