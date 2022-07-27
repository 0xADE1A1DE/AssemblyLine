SECTION .text
GLOBAL test
test:
push rax
push rcx
push rdx
push rbx
push rsi
push rbp
push rdi
push r8
push r9
push r10
push r11
push r12
push r13
push r14
push r15
push qword [rax]
push qword [rax+0x7f]
push qword [rax+0x7fff]
push qword [rax+0x7fffff]
push qword [rcx]
push qword [rdx+0xfff]
push qword [rbx]
push qword [rsi]
push qword [rbp]
push qword [rdi+0x7fffff]
push qword [r8]
push qword [r9]
push qword [r10]
push qword [r11]
push qword [r12]
push qword [r13]
push qword [r14]
push qword [r15]
push 0x7f
push 0xff
push 0xfff
push 0x7fff
push 0xffff
push 0xe0
push 0x7fffffff