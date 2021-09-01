SECTION .text
GLOBAL test
test:
shrx r9, rax, rax
shrx r9, rcx, rcx
shrx r9, rdx, rdi
shrx r9, rsp, r8
shrx r9, r12, r10
shrx r9, rax, rsi
shrx r9d, eax, eax
shrx r9d, ecx, ecx
shrx r9d, edx, edi
shrx r9d, esp, r8d
shrx r9d, r12d, r10d
shrx r9d, eax, esi
shrx esp, eax, esi
shrx rsp, rax, rsi
