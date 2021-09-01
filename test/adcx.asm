SECTION .text
GLOBAL test
test:
adcx r10, r14
adcx r10, rbp
adcx r11, r14
adcx r11, r9
adcx r12, r11
adcx r12, r9
adcx r12, r9
adcx r12, rax
adcx r12, rbx
adcx r12, [ rsp + 0x20 ]
adcx r13, r9
adcx r13, rbp
adcx r13, rsi
adcx r14, r11
adcx r14, rbp
adcx r14, rcx
adcx r15, r12
adcx r15, r13
adcx r15, r9
adcx r15, rax
adcx r15, rdx
adcx r15, [ rsp + 0x0 ]
adcx r8, r12
adcx r8, r13
adcx r8, r9
adcx r8, rcx
adcx r8, rdi
adcx r8, [ rsp + 0x38 ]
adcx r8, [ rsp + 0x48 ]
adcx r9, r12
adcx r9, r14
adcx rax, r10
adcx rbp, r11
adcx rbp, r13
adcx rbp, r14
adcx rbp, r9
adcx rbp, rbx
adcx rbp, rcx
adcx rbp, rdx
adcx rbx, r11
adcx rbx, r15
adcx rbx, r8
adcx rbx, rcx
adcx rcx, r10
adcx rcx, r12
adcx rcx, r12
adcx rcx, r13
adcx rcx, r14
adcx rcx, r8
adcx rcx, r9
adcx rcx, [ rsp + 0x20 ]
adcx rdi, r15
adcx rdi, r8
adcx rdx, r15
adcx rdx, r9
adcx rsi, rcx
