SECTION .TEXT
GLOBAL TEST
TEST:
mov r9, 0x11111111
mov r10, 0x22222222
movq xmm0, r9
movq xmm1, r10
punpcklqdq xmm0, xmm1 
psrldq xmm0, 8
psrldq xmm15, 8
movq rax, xmm0
ret 