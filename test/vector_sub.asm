SECTION .text
GLOBAL test
test:
mov rcx, 0xffffffff 
mov r12, 0x21524110
movq xmm4, rcx
movq xmm7, r12
psubq xmm4, xmm7
movq xmm5, xmm4
movq rax, xmm5
ret