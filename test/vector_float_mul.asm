SECTION .text
GLOBAL test
test:
mov rcx, 0x6 
mov r12, 0x2
movq xmm4, rcx
movq xmm7, r12
cvtdq2pd xmm4, xmm4
cvtdq2pd xmm7, xmm7
mulpd xmm4, xmm7
movq xmm5, xmm4
cvtpd2dq xmm5, xmm5
movq rax, xmm5
ret
