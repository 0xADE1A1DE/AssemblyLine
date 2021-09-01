SECTION .text
GLOBAL test
test:
sarx r9, rax, rax
sarx r9, rcx, rcx
sarx r9, rdx, rdi
sarx r9, rsp, r8
sarx r9, r12, r10
sarx r9, rax, rsi
sarx rsp, rax, rsi