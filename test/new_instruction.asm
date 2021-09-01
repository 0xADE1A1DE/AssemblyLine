SECTION .text
GLOBAL test
test:
sfence
lfence
mfence
clflush [r12]
xchg rax, rbp 
add rax, 0xfff
xend
