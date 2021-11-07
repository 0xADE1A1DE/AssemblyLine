SECTION .text
GLOBAL test
test:
mov rcx, 0x143e572d 
mov r12, 0xb
movq xmm4, rcx
movq xmm7, r12
pmuldq xmm4, xmm7
movq xmm5, xmm4
movq rax, xmm5
ret
