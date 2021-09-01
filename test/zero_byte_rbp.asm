SECTION .text
GLOBAL test
test:
mov [rbp], rbx
mov [rbp], rbp
mov [rbp], r12
mov [rbp], r13
mov [rbp], r14
mov [rbp], r15
imul r11, [rbp], 0x13
imul r15, [rbp], 0x13
mulx r9, r10, [rbp]
imul r14, [rbp], 0x2
mov rdx, [rbp]
mov rdx, [rbp]
mulx r8, rbp, [rbp]
mulx rcx, r13, [rbp]
mov rdx, [rbp]
mov [rbp], rcx
adcx r15, [rbp]
mulx rdx, rbp, [rbp]
mov rdx, [rbp]
mulx r10, r9, [rbp]
mulx rdx, rbx, [rbp]
imul r12, [rbp], 0x2
imul r15, [rbp], 0x2
mov rdx, [rbp]
mov rdx, [rbp]
mov [rbp], rcx
mov [rbp], rax
lea rdx, [rbp]
mov r8, [rbp]
mov rdx, [rbp]
imul r14, [rbp], 0x2
mulx r15, r11, [rbp]
mulx rdx, r10, [rbp]
mov rdx, [rbp]
mulx r13, r12, [rbp]
mulx rdx, r14, [rbp]
add r12, [rbp]
mov r15, [rbp]
mov [rbp], r8
lea r10, [rbp]
mov [rbp], r12
mov [rbp], rcx
lea r13, [rbp]
mov [rbp], r10
mov [rbp], r13
mov rbx, [rbp]
mov rbp, [rbp]
mov r12, [rbp]
mov r13, [rbp]
mov r14, [rbp]
mov r15, [rbp]
