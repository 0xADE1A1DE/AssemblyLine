SECTION .text
GLOBAL test
test:
add al, 0x0
add ax, 0xe1
add eax, 0xe11
add sil, 0x0
add si, 0xe1
add esi, 0xe11
add rax, 0xfffee12
add rax, 0xff6ee12
add rax, 0xf66ee12
add rax, 0x666ee12
add rax, 0x6666ee12
add rax, -0x1
add rax, -0xfffee12
add rax, -0xff6ee12
add rax, -0xf66ee12
add rax, -0x666ee12
add rax, -0x6666ee12
add rbp, -0xfffee12
add rbp, 0xfffee12
add rbp, 0xff6ee12
add rbp, 0xf66ee12
add rbp, 0x666ee12
add rbp, 0x6666ee12
add rbp, -0xf
add rbp, -0xe
add rbp, -0xd
add rbp, -0x7
add rbp, -0x4
add rbp, -0x3
add rbp, -0x2
add rbp, -0xff
add rbp, -0xef
add rbp, -0xdf
add rbp, -0xcf
add rbp, -0xbf
add rbp, -0xaf
add rbp, -0x9f
add rbp, -0x8f
add rbp, -0x7f
add rbp, -0x3e
add rbp, -0x6f
add rbp, -0x5f
add rbp, -0x4f
add rbp, -0x1f
add rbp, -0xfa
add rbp, -0xf9
add rbp, -0xf8
add rbp, -0xf7
add rbp, -0xf6
add rbp, -0xf5
add rbp, -0xf4
add rbp, -0xf3
add rbp, -0xf2
add rbp, -0xf1
add rbp, -0xf66
add rbp, -0x666ee
add rbp, -0x6666ee12
add r13, -0xfffee12
add r13, 0xfffee12
add r13, 0xff6ee12
add r13, 0xf66ee12
add r13, 0x666ee12
add r13, 0x6666ee12
add r13, -0x1
add r13, -0xfffee12
add r13, -0xff6ee12
add r13, -0xf66ee12
add r13, -0x666ee12
add r13, -0x6666ee12
add rax, 0x12
add rax, 0xe12
add rax, 0x66ee12
add rax, 0x66ee12
add rax, 0x6ee12
add sp, 0x34ef
add r8w, 0x1
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
add dword [ebp], -0xf
add dword [ebp], -0xe
add dword [ebp], -0xd
add dword [ebp], -0x7
add dword [ebp], -0x4
add dword [ebp], -0x3
add dword [ebp], -0x2
add dword [ebp], -0xff
add dword [ebp], 0xf
add dword [ebp], 0xe
add dword [ebp], 0xd
add dword [ebp], 0x7
add dword [ebp], 0x4
add dword [ebp], 0x3
add dword [ebp], 0x2
add dword [ebp], 0xff
add eax, dword [rsp]
add eax, dword [rsp + 0x40]
add eax, [rsp + 0x40]
add eax, dword [rbp]
add eax, ebx
