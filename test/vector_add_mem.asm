SECTION .text
GLOBAL test
test:

movq xmm4, [rcx]
movq xmm7, [r12]
paddq xmm4, xmm7
movq xmm5, xmm4
movq rax, xmm5
ret
