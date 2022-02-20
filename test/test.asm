SECTION .text
GLOBAL test
test:
test r10, r11
test rax, rax
test r10, r12
test r10, r13
test r10, r14
test r10, r15
test r10, r8
test r10, r9
test r10, rax
test r10, rbp
test r10, rbx
test r10, rcx
test r10, rdi
test r10, rdx
test r10, rsi
test [ rsp + 0x11f0 ], r10
test [ rsp + 0x19f0 ], r10
test [ rsp + 0x1b10 ], r10
test [ rsp + 0x1c10 ], r10
test [ rsp + 0x1c8 ] , r10
test [ rsp + 0x1de8 ], r10
test [ rsp + 0x1f90 ], r10
test [ rsp + 0x2708 ], r10
test [ rsp + 0x2970 ], r10
test [ rsp + 0x2e10 ], r10
test [ rsp + 0x30e0 ], r10
test [ rsp + 0x35c0 ], r10
test [ rsp + 0x460 ] , r10
test [ rsp + 0x680 ] , r10
test [ rsp + 0xb48 ] , r10
