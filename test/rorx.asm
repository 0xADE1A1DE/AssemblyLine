SECTION .text
GLOBAL test
test:
rorx rax, r12, 0x3f
rorx rbp, rcx, 0x69
rorx r11, r12, 0x4f
rorx r13, rsp, 0x7c
rorx rdx, rsi, 0x7b
rorx r12, rax, 0x3f
rorx rcx, rbp, 0x49
rorx r12, r11, 0x2f
rorx rsp, r13, 0x7c
rorx rsi, rdx, 0x7b
rorx r9, rax, 0x0
rorx r9, rcx, 0x0
rorx r9, rax, 0x01
rorx r9, rcx, 0x10
rorx r9, [rcx], 0x13
rorx r9, [rcx+0x20], 0x3f
rorx rax, rcx, 0x3f
rorx rcx, [rcx+0x20], 0x11
