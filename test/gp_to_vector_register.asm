SECTION .text
GLOBAL test
test:
mov rcx, 0x11111111 
mov r12, 0x22222222
movq xmm4, rcx
movq xmm7, r12
paddq xmm4, xmm7
movq xmm5, xmm4
movq rax, xmm5
ret
