SECTION .text
GLOBAL test
test:
mov rcx, 0x123 
mov r12, 0x321
movq xmm4, rcx
movq xmm7, r12
paddq xmm4, xmm7
movq xmm5, xmm4
movq rax, xmm5
ret
