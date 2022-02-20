SECTION .text
GLOBAL test
test:
lea rax, [rax]
lea rax, [ 1*rax]
lea rax, [ 2*rax]
lea rax, [ 4*rax]
lea rax, [ 8*rax]
lea rax, [ 1*r10]
lea rax, [ 2*r11]
lea rax, [ 4*rcx]
lea eax, [ 8*eax]