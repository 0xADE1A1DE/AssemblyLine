#define CODE                                                                                                           \
    "adcx r10, r14;\n"                                                                                                 \
    "adcx r10, rbp;\n"                                                                                                 \
    "adcx r11, r14;\n"                                                                                                 \
    "adcx r11, r9;\n"                                                                                                  \
    "adcx r12, r11;\n"                                                                                                 \
    "adcx r12, r9;\n"                                                                                                  \
    "adcx r12, r9;\n"                                                                                                  \
    "adcx r12, rax;\n"                                                                                                 \
    "adcx r12, rbx;\n"                                                                                                 \
    "adcx r12, [ rsp + 0x20 ];\n"                                                                                      \
    "adcx r13, r9;\n"                                                                                                  \
    "adcx r13, rbp;\n"                                                                                                 \
    "adcx r13, rsi;\n"                                                                                                 \
    "adcx r14, r11;\n"                                                                                                 \
    "adcx r14, rbp;\n"                                                                                                 \
    "adcx r14, rcx;\n"                                                                                                 \
    "adcx r15, r12;\n"                                                                                                 \
    "adcx r15, r13;\n"                                                                                                 \
    "adcx r15, r9;\n"                                                                                                  \
    "adcx r15, rax;\n"                                                                                                 \
    "adcx r15, rdx;\n"                                                                                                 \
    "adcx r15, [ rsp + 0x0 ];\n"                                                                                       \
    "adcx r8, r12;\n"                                                                                                  \
    "adcx r8, r13;\n"                                                                                                  \
    "adcx r8, r9;\n"                                                                                                   \
    "adcx r8, rcx;\n"                                                                                                  \
    "adcx r8, rdi;\n"                                                                                                  \
    "adcx r8, [ rsp + 0x38 ];\n"                                                                                       \
    "adcx r8, [ rsp + 0x48 ];\n"                                                                                       \
    "adcx r9, r12;\n"                                                                                                  \
    "adcx r9, r14;\n"                                                                                                  \
    "adcx rax, r10;\n"                                                                                                 \
    "adcx rbp, r11;\n"                                                                                                 \
    "adcx rbp, r13;\n"                                                                                                 \
    "adcx rbp, r14;\n"                                                                                                 \
    "adcx rbp, r9;\n"                                                                                                  \
    "adcx rbp, rbx;\n"                                                                                                 \
    "adcx rbp, rcx;\n"                                                                                                 \
    "adcx rbp, rdx;\n"                                                                                                 \
    "adcx rbx, r11;\n"                                                                                                 \
    "adcx rbx, r15;\n"                                                                                                 \
    "adcx rbx, r8;\n"                                                                                                  \
    "adcx rbx, rcx;\n"                                                                                                 \
    "adcx rcx, r10;\n"                                                                                                 \
    "adcx rcx, r12;\n"                                                                                                 \
    "adcx rcx, r12;\n"                                                                                                 \
    "adcx rcx, r13;\n"                                                                                                 \
    "adcx rcx, r14;\n"                                                                                                 \
    "adcx rcx, r8;\n"                                                                                                  \
    "adcx rcx, r9;\n"                                                                                                  \
    "adcx rcx, [ rsp + 0x20 ];\n"                                                                                      \
    "adcx rdi, r15;\n"                                                                                                 \
    "adcx rdi, r8;\n"                                                                                                  \
    "adcx rdx, r15;\n"                                                                                                 \
    "adcx rdx, r9;\n"                                                                                                  \
    "adcx rsi, rcx;\n"                                                                                                 \
    ""
