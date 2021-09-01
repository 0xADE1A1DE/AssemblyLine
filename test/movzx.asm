SECTION .text
GLOBAL test
test:
movzx r11, r10b
movzx r11, r11b
movzx r12, r12b
movzx r14, byte [ rsp + 0xa0 ]
movzx r14, r14b
movzx r8, byte [ rsp + 0xf0 ]
movzx r8, r10b
movzx r8, r8b
movzx r9, r9b
movzx r9, r9b
movzx rax, al
movzx rax, bpl
movzx rax, dil
movzx rbp, bl
movzx rbp, bpl
movzx rbx, byte [ rsp + 0xa8 ]
movzx rbx, r15b
movzx rcx, cl
movzx rcx, cl
movzx rcx, r12b
movzx rdx, dl
movzx rdx, r8b
movzx rdx, r9b