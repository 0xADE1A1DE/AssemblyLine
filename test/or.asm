SECTION .text
GLOBAL test
test:
or rsp, 0x39a8 
or r10, r11
or r10, r12
or r10, r13
or r10, r14
or r10, r15
or r10, r8
or r10, r9
or r10, rax
or r10, rbp
or r10, rbx
or r10, rcx
or r10, rdi
or r10, rdx
or r10, rsi
or r10, [ rsp + 0x11f0 ]
or r10, [ rsp + 0x19f0 ]
or r10, [ rsp + 0x1b10 ]
or r10, [ rsp + 0x1c10 ]
or r10, [ rsp + 0x1c8 ]
or r10, [ rsp + 0x1de8 ]
or r10, [ rsp + 0x1f90 ]
or r10, [ rsp + 0x2708 ]
or r10, [ rsp + 0x2970 ]
or r10, [ rsp + 0x2e10 ]
or r10, [ rsp + 0x30e0 ]
or r10, [ rsp + 0x35c0 ]
or r10, [ rsp + 0x460 ]
or r10, [ rsp + 0x680 ]
or r10, [ rsp + 0xb48 ]
or r11, r10
or r11, r12
or r11, r13
or r11, r14
or r11, r15
or r11, r8
or r11, r9
or r11, rax
or r11, rcx
or r11, rdi
or r11, rsi
or r11, [ rsp + 0x14a0 ]
or r11, [ rsp + 0x158 ]
or r11, [ rsp + 0x1750 ]
or r11, [ rsp + 0x2218 ]
or r11, [ rsp + 0x24b0 ]
or r11, [ rsp + 0x2688 ]
or r11, [ rsp + 0x26c0 ]
or r11, [ rsp + 0x2920 ]
or r11, [ rsp + 0x2938 ]
or r11, [ rsp + 0x29b0 ]
or r11, [ rsp + 0x3780 ]
or r11, [ rsp + 0x37e8 ]
or r11, [ rsp + 0xbd8 ]
or r12, r10
or r12, r11
or r12, r13
or r12, r14
or r12, r15
or r12, r9
or r12, rax
or r12, rbp
or r12, rbx
or r12, rcx
or r12, rdi
or r12, rdx
or r12, rsi
or r12, [ rsp + 0x1048 ]
or r12, [ rsp + 0x12a0 ]
or r12, [ rsp + 0x1428 ]
or r12, [ rsp + 0x16c8 ]
or r12, [ rsp + 0x220 ]
or r12, [ rsp + 0x23b8 ]
or r12, [ rsp + 0x2520 ]
or r12, [ rsp + 0x2528 ]
or r12, [ rsp + 0x29a8 ]
or r12, [ rsp + 0x2be8 ]
or r12, [ rsp + 0x910 ]
or r13, r11
or r13, r12
or r13, r15
or r13, r8
or r13, r9
or r13, rax
or r13, rbp
or r13, rcx
or r13, rdi
or r13, rdx
or r13, rsi
or r13, [ rsp + 0x110 ]
or r13, [ rsp + 0x14c0 ]
or r13, [ rsp + 0x1d90 ]
or r13, [ rsp + 0x1fe8 ]
or r13, [ rsp + 0x2228 ]
or r13, [ rsp + 0x2780 ]
or r13, [ rsp + 0x27d0 ]
or r13, [ rsp + 0x2c20 ]
or r13, [ rsp + 0x3658 ]
or r13, [ rsp + 0x3c8 ]
or r13, [ rsp + 0xe08 ]
or r14, r10
or r14, r11
or r14, r12
or r14, r13
or r14, r15
or r14, r8
or r14, r9
or r14, rax
or r14, rbp
or r14, rcx
or r14, rdx
or r14, rsi
or r14, [ rsp + 0x13e8 ]
or r14, [ rsp + 0x17b0 ]
or r14, [ rsp + 0x18c8 ]
or r14, [ rsp + 0x1aa0 ]
or r14, [ rsp + 0x1e58 ]
or r14, [ rsp + 0x2088 ]
or r14, [ rsp + 0x20e8 ]
or r14, [ rsp + 0x2498 ]
or r14, [ rsp + 0x2a10 ]
or r14, [ rsp + 0x2da0 ]
or r14, [ rsp + 0x32c0 ]
or r14, [ rsp + 0x34f8 ]
or r14, [ rsp + 0x3600 ]
or r14, [ rsp + 0x3a8 ]
or r14, [ rsp + 0x600 ]
or r14, [ rsp + 0x848 ]
or r14, [ rsp + 0xdc8 ]
or r15, r10
or r15, r11
or r15, r13
or r15, r8
or r15, r9
or r15, rax
or r15, rbp
or r15, rbx
or r15, rcx
or r15, rdi
or r15, rdx
or r15, rsi
or r15, [ rsp + 0x1910 ]
or r15, [ rsp + 0x1968 ]
or r15, [ rsp + 0x1b58 ]
or r15, [ rsp + 0x1d0 ]
or r15, [ rsp + 0x30c8 ]
or r15, [ rsp + 0x3110 ]
or r15, [ rsp + 0x3140 ]
or r15, [ rsp + 0x8f8 ]
or r15, [ rsp + 0xb70 ]
or r15, [ rsp + 0xbe0 ]
or r15, [ rsp + 0xd50 ]
or r8, r11
or r8, r12
or r8, r13
or r8, r14
or r8, r15
or r8, r9
or r8, rax
or r8, rbp
or r8, rbx
or r8, rcx
or r8, rdi
or r8, rdx
or r8, [ rsp + 0x1270 ]
or r8, [ rsp + 0x14b0 ]
or r8, [ rsp + 0x1700 ]
or r8, [ rsp + 0x1730 ]
or r8, [ rsp + 0x1c08 ]
or r8, [ rsp + 0x1fe0 ]
or r8, [ rsp + 0x2110 ]
or r8, [ rsp + 0x2500 ]
or r8, [ rsp + 0x2e48 ]
or r8, [ rsp + 0x3380 ]
or r8, [ rsp + 0x3488 ]
or r8, [ rsp + 0x38e8 ]
or r8, [ rsp + 0x440 ]
or r8, [ rsp + 0x6b8 ]
or r8, [ rsp + 0xb90 ]
or r8, [ rsp + 0xe18 ]
or r8, [ rsp + 0xea0 ]
or r8, [ rsp + 0xf78 ]
or r8, [ rsp + 0xfe0 ]
or r9, r10
or r9, r11
or r9, r12
or r9, r14
or r9, r15
or r9, r8
or r9, rax
or r9, rbp
or r9, rbx
or r9, rcx
or r9, rdi
or r9, rsi
or r9, [ rsp + 0x1030 ]
or r9, [ rsp + 0x1b70 ]
or r9, [ rsp + 0x2310 ]
or r9, [ rsp + 0x2318 ]
or r9, [ rsp + 0x26f8 ]
or r9, [ rsp + 0x27c8 ]
or r9, [ rsp + 0x27d8 ]
or r9, [ rsp + 0x3860 ]
or r9, [ rsp + 0x3958 ]
or r9, [ rsp + 0xf70 ]
or rax, r10
or rax, r11
or rax, r12
or rax, r14
or rax, r15
or rax, r8
or rax, r9
or rax, rbp
or rax, rbx
or rax, rcx
or rax, rdx
or rax, rsi
or rax, [ rsp + 0x1198 ]
or rax, [ rsp + 0x11e8 ]
or rax, [ rsp + 0x2b10 ]
or rax, [ rsp + 0x2b70 ]
or rax, [ rsp + 0x2ea0 ]
or rax, [ rsp + 0x3118 ]
or rax, [ rsp + 0x3288 ]
or rax, [ rsp + 0x34b8 ]
or rax, [ rsp + 0x35f0 ]
or rax, [ rsp + 0x3700 ]
or rax, [ rsp + 0x4b0 ]
or rax, [ rsp + 0x978 ]
or rax, [ rsp + 0xb88 ]
or rbp, r10
or rbp, r12
or rbp, r13
or rbp, r15
or rbp, r8
or rbp, r9
or rbp, rax
or rbp, rsi
or rbp, [ rsp + 0x1470 ]
or rbp, [ rsp + 0x1970 ]
or rbp, [ rsp + 0x1f80 ]
or rbp, [ rsp + 0x20a0 ]
or rbp, [ rsp + 0x2878 ]
or rbp, [ rsp + 0x29d0 ]
or rbp, [ rsp + 0x2df8 ]
or rbp, [ rsp + 0x2ec8 ]
or rbp, [ rsp + 0x30d8 ]
or rbp, [ rsp + 0x3320 ]
or rbp, [ rsp + 0x3360 ]
or rbp, [ rsp + 0x3500 ]
or rbp, [ rsp + 0x37a0 ]
or rbp, [ rsp + 0x5f0 ]
or rbp, [ rsp + 0x858 ]
or rbp, [ rsp + 0x980 ]
or rbx, r10
or rbx, r11
or rbx, r12
or rbx, r14
or rbx, r15
or rbx, r8
or rbx, r9
or rbx, rbp
or rbx, rcx
or rbx, rdi
or rbx, rdx
or rbx, rsi
or rbx, [ rsp + 0x12d0 ]
or rbx, [ rsp + 0x1388 ]
or rbx, [ rsp + 0x1890 ]
or rbx, [ rsp + 0x1980 ]
or rbx, [ rsp + 0x2248 ]
or rbx, [ rsp + 0x22c8 ]
or rbx, [ rsp + 0x2dc0 ]
or rbx, [ rsp + 0x3098 ]
or rbx, [ rsp + 0x32d8 ]
or rbx, [ rsp + 0x3618 ]
or rbx, [ rsp + 0x3758 ]
or rbx, [ rsp + 0x620 ]
or rbx, [ rsp + 0x730 ]
or rbx, [ rsp + 0x8b8 ]
or rbx, [ rsp + 0xa60 ]
or rbx, [ rsp + 0xec0 ]
or rcx, r10
or rcx, r11
or rcx, r12
or rcx, r13
or rcx, r14
or rcx, r15
or rcx, r8
or rcx, r9
or rcx, rbp
or rcx, rbx
or rcx, rdi
or rcx, rdx
or rcx, rsi
or rcx, [ rsp + 0x1000 ]
or rcx, [ rsp + 0x1238 ]
or rcx, [ rsp + 0x1248 ]
or rcx, [ rsp + 0x1790 ]
or rcx, [ rsp + 0x1b38 ]
or rcx, [ rsp + 0x1d58 ]
or rcx, [ rsp + 0x1e88 ]
or rcx, [ rsp + 0x1f8 ]
or rcx, [ rsp + 0x2058 ]
or rcx, [ rsp + 0x228 ]
or rcx, [ rsp + 0x2460 ]
or rcx, [ rsp + 0x2940 ]
or rcx, [ rsp + 0x2ce8 ]
or rcx, [ rsp + 0x3040 ]
or rcx, [ rsp + 0x3208 ]
or rcx, [ rsp + 0x35b8 ]
or rcx, [ rsp + 0xd98 ]
or rdi, r10
or rdi, r11
or rdi, r12
or rdi, r13
or rdi, r14
or rdi, r15
or rdi, r8
or rdi, r9
or rdi, rax
or rdi, rbp
or rdi, rcx
or rdi, rdx
or rdi, rsi
or rdi, [ rsp + 0x1080 ]
or rdi, [ rsp + 0x14d0 ]
or rdi, [ rsp + 0x18f8 ]
or rdi, [ rsp + 0x2038 ]
or rdi, [ rsp + 0x2b80 ]
or rdi, [ rsp + 0x3740 ]
or rdi, [ rsp + 0x38a0 ]
or rdi, [ rsp + 0x580 ]
or rdi, [ rsp + 0x640 ]
or rdi, [ rsp + 0x728 ]
or rdi, [ rsp + 0x850 ]
or rdi, [ rsp + 0xf20 ]
or rdx, r10
or rdx, r12
or rdx, r13
or rdx, r14
or rdx, r15
or rdx, r8
or rdx, r9
or rdx, rax
or rdx, rbp
or rdx, rbx
or rdx, rdi
or rdx, rsi
or rdx, [ rsp + 0x1078 ]
or rdx, [ rsp + 0x1688 ]
or rdx, [ rsp + 0x1ce0 ]
or rdx, [ rsp + 0x21a8 ]
or rdx, [ rsp + 0x2428 ]
or rdx, [ rsp + 0x2620 ]
or rdx, [ rsp + 0x2b18 ]
or rdx, [ rsp + 0x2c80 ]
or rdx, [ rsp + 0x2ed0 ]
or rdx, [ rsp + 0x3748 ]
or rdx, [ rsp + 0xa0 ]
or rdx, [ rsp + 0xbd0 ]
or rdx, [ rsp + 0xd68 ]
or rsi, r10
or rsi, r11
or rsi, r12
or rsi, r13
or rsi, r14
or rsi, r15
or rsi, r8
or rsi, rax
or rsi, rbp
or rsi, rbx
or rsi, rcx
or rsi, rdi
or rsi, rdx
or rsi, [ rsp + 0x16b8 ]
or rsi, [ rsp + 0x178 ]
or rsi, [ rsp + 0x1b80 ]
or rsi, [ rsp + 0x1d40 ]
or rsi, [ rsp + 0x22b0 ]
or rsi, [ rsp + 0x2560 ]
or rsi, [ rsp + 0x2760 ]
or rsi, [ rsp + 0x2bb8 ]
or rsi, [ rsp + 0x2c50 ]
or rsi, [ rsp + 0xc78 ]
or r10, r11
or r10, rdi
or r12, r11
or r13, r10
or r14, r8
or r14, rdi
or r15, r10
or r15, r11
or r8, r10
or r8, r11
or r8, rdi
or r9, r10
or r9, rdi
or rax, r10
or rax, rbp
or rbx, r11
or rbx, rdi
or rcx, r11
or rcx, rdi
or rdx, r10
or al, 0x0
or ax, 0xe1
or eax, 0xe11
or sil, 0x0
or si, 0xe1
or esi, 0xe11
or rax, 0xfffee12
or rax, 0xff6ee12
or rax, 0xf66ee12
or rax, 0x666ee12
or rax, 0x6666ee12
or rax, -0x1
or rax, -0xfffee12
or rax, -0xff6ee12
or rax, -0xf66ee12
or rax, -0x666ee12
or rax, -0x6666ee12
or rbp, -0xfffee12
or rbp, 0xfffee12
or rbp, 0xff6ee12
or rbp, 0xf66ee12
or rbp, 0x666ee12
or rbp, 0x6666ee12
or rbp, -0xf
or rbp, -0xe
or rbp, -0xd
or rbp, -0x7
or rbp, -0x4
or rbp, -0x3
or rbp, -0x2
or rbp, -0xff
or rbp, -0xef
or rbp, -0xdf
or rbp, -0xcf
or rbp, -0xbf
or rbp, -0xaf
or rbp, -0x9f
or rbp, -0x8f
or rbp, -0x7f
or rbp, -0x3e
or rbp, -0x6f
or rbp, -0x5f
or rbp, -0x4f
or rbp, -0x1f
or rbp, -0xfa
or rbp, -0xf9
or rbp, -0xf8
or rbp, -0xf7
or rbp, -0xf6
or rbp, -0xf5
or rbp, -0xf4
or rbp, -0xf3
or rbp, -0xf2
or rbp, -0xf1
or rbp, -0xf66
or rbp, -0x666ee
or rbp, -0x6666ee12
or r13, -0xfffee12
or r13, 0xfffee12
or r13, 0xff6ee12
or r13, 0xf66ee12
or r13, 0x666ee12
or r13, 0x6666ee12
or r13, -0x1
or r13, -0xfffee12
or r13, -0xff6ee12
or r13, -0xf66ee12
or r13, -0x666ee12
or r13, -0x6666ee12
or rax, 0x12
or rax, 0xe12
or rax, 0x66ee12
or rax, 0x66ee12
or rax, 0x6ee12
or sp, 0x34ef
or r8w, 0x1
or rax, [ rbx ]
or rax, [ rbx + 0x10 ]
or rax, 0x0 
or rax, 0x0 ; with a comment
or r12, r14
or r12, rbx
or r12, [ rsp + 0x10 ]
or rax, 0xfff
or rax, r15
or rax, rbp
or rbp, r12
or rbp, r8
or rbp, r9
or rbx, r9
or rbx, rdi
or rdi, r10
or rdx, r14
or rsp, 0x138 
or rsp, 0x48 
or rsp, 0x50 
or rsp, 0x80 
or eax, ebx
or eax, [rbx]
or eax, dword [rsp]
or eax, dword [rbx]
or eax, [rsp]
