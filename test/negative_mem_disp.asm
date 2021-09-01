SECTION .text
GLOBAL test
test:
mov [ rsp - 0x100 ], rbx
mov [ rsp - 0x108 ], rbp
mov [ rsp - 0x110 ], r12
mov [ rsp - 0x118 ], r13
mov [ rsp - 0x120 ], r14
mov [ rsp - 0x128 ], r15
mov r11, [ rsi - 0x10 ]
mov r9, [ rsi - 0x1 ]
mov rdx, [ rsi - 0x1]
mov rdx, [ rsi - 0x18 ]
mov [ rsp - 0x1], rdi
mulx r11, rdi, [ rsi - 0x1 ]
mov [ rsp - 0x8 ], r12
mov [ rsp - 0x10 ], r15
mulx r12, r15, [ rsi - 0x8 ]
mov [ rsp - 0x18 ], r14
mov [ rsp - 0x20 ], rax
mulx r14, rax, [ rsi - 0x10 ]
mulx rdx, r10, [ rsi - 0x18 ]
mulx rbp, r12, [ rsi - 0x8 ]
mov r15, [ rsp - 0x8 ]
mov [ rsp - 0x28 ], r11
mov [ rsp - 0x30 ], rsi
mov r13, [ rsp - 0x10 ]
mov [ rsp - 0x38 ], rbx
mov r12, [ rsp - 0x30 ]
mulx rdx, rsi, [ r12 - 0x10 ]
mov [ rsp - 0x40 ], rsi
mov rsi, [ r12 - 0x8 ]
mov [ rsp - 0x48 ], rsi
mulx r13, rsi, [ r12 - 0x10 ]
mov [ rsp - 0x50 ], r13
mov r13, [ rsp - 0x40 ]
mov [ rsp - 0x58 ], r9
mulx rbp, r9, [ r12 - 0x1 ]
mov [ rsp - 0x60 ], rbp
mov [ rsp - 0x30 ], r12
mov r10, [ rsp - 0x58 ]
mov [ rsp - 0x68 ], r14
mov r9, [ rsp - 0x30 ]
mov [ rsp - 0x70 ], r14
mov rdx, [ r9 - 0x8 ]
mov [ rsp - 0x78 ], rdi
mov [ rsp - 0x80 ], r8
mov [ rsp - 0x88 ], r8
mov [ rsp - 0x30 ], r9
mov rdx, [ rsp - 0x70 ]
mov [ rsp - 0x90 ], r14
mov r8, [ rsp - 0x18 ]
mov [ rsp - 0x98 ], rdx
adcx r8, [ rsp - 0x48 ]
mov rdx, [ rsp - 0x80 ]
mov r11, [ rsp - 0x90 ]
mov r11, [ rsp - 0x60 ]
mov r9, [ rsp - 0x88 ]
mov byte [ rsp - 0xa0 ], r14b
mov r11, [ rsp - 0x30 ]
mulx rdx, rbx, [ r11 - 0x18 ]
mov byte [ rsp - 0xa8 ], r14b
adcx r8, [ rsp - 0x38 ]
mov [ rsp - 0x30 ], r11
adcx rcx, [ rsp - 0x20 ]
mov rdi, [ rsp - 0x50 ]
mov rbp, [ rsp - 0x78 ]
mov rsi, [ rsp - 0x30 ]
mov r13, [ rsi - 0x18 ]
mov rdx, [ rsp - 0x90 ]
mov [ rsp - 0xb0 ], rbx
mulx r8, rbx, [ rsi - 0x8 ]
mov [ rsp - 0x30 ], rsi
mov r9, [ rsp - 0xb0 ]
mov rcx, [ rsp - 0x28 ]
mov [ rsp - 0xb8 ], rcx
mov [ rsp - 0xc0 ], rbx
mov [ rsp - 0xc8 ], rcx
mov rdx, [ rsp - 0x30 ]
mulx rcx, rsi, [ r11 - 0x1]
mov [ rsp - 0xd0 ], rbp
mov rbx, [ rsp - 0xc8 ]
mov [ rsp - 0xd8 ], rsi
mov rsi, [ rsp - 0xc0 ]
mov rcx, [ rsp - 0xb8 ]
adox r13, [ rsp - 0x68 ]
mulx r14, rbp, [ r11 - 0x18 ]
mov [ rsp - 0xe0 ], r13
mov rbx, [ rsp - 0xe0 ]
mov r9, [ rsp - 0xd8 ]
mulx rdx, rcx, [ r11 - 0x10 ]
mov [ rsp - 0xe8 ], rcx
mov byte [ rsp - 0xf0 ], r15b
mov [ rsp - 0xf8 ], r14
mov rdi, [ rsp - 0xe8 ]
mov r15, [ rsp - 0xf8 ]
mov [ rsp - 0x30 ], r11
mov rax, [ rsp - 0x1]
mov [ rax - 0x1], r11
mov [ rax - 0x8 ], rbp
mov [ rax - 0x18 ], r15
mov [ rax - 0x10 ], rcx
mov rbx, [ rsp - 0x100 ]
mov rbp, [ rsp - 0x108 ]
mov r12, [ rsp - 0x110 ]
mov r13, [ rsp - 0x118 ]
mov r14, [ rsp - 0x120 ]
mov r15, [ rsp - 0x128 ]
