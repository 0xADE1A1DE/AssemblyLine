SECTION .text
GLOBAL test
test:
add rax, rbx
add al, 0x0
add rax, [ rbx ]
add rax, [ rbx + 0x10 ]
add rax, 0x0 
add rax, 0x0 ; with a comment
add r12, r14
add r12, rbx
add r12, [ rsp + 0x10 ]
add rax, 0xfff
add rax, r15
add rax, rbp
add rbp, r12
add rbp, r8
add rbp, r9
add rbx, r9
add rbx, rdi
add rdi, r10
add rdx, r14
add rsp, 0x138 
add rsp, 0x48 
add rsp, 0x50 
add rsp, 0x80 
