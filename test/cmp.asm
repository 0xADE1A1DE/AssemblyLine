SECTION .text
GLOBAL test
test:
cmp rsp, 0x39a8 
cmp r10, r11
cmp r10, r12
cmp r10, r13
cmp r10, r14
cmp r10, r15
cmp r10, r8
cmp r10, r9
cmp r10, rax
cmp r10, rbp
cmp r10, rbx
cmp r10, rcx
cmp r10, rdi
cmp r10, rdx
cmp r10, rsi
cmp r10, [ rsp + 0x11f0 ]
cmp r10, [ rsp + 0x19f0 ]
cmp r10, [ rsp + 0x1b10 ]
cmp r10, [ rsp + 0x1c10 ]
cmp r10, [ rsp + 0x1c8 ]
cmp r10, [ rsp + 0x1de8 ]
cmp r10, [ rsp + 0x1f90 ]
cmp r10, [ rsp + 0x2708 ]
cmp r10, [ rsp + 0x2970 ]
cmp r10, [ rsp + 0x2e10 ]
cmp r10, [ rsp + 0x30e0 ]
cmp r10, [ rsp + 0x35c0 ]
cmp r10, [ rsp + 0x460 ]
cmp r10, [ rsp + 0x680 ]
cmp r10, [ rsp + 0xb48 ]
cmp r11, r10
cmp r11, r12
cmp r11, r13
cmp r11, r14
cmp r11, r15
cmp r11, r8
cmp r11, r9
cmp r11, rax
cmp r11, rcx
cmp r11, rdi
cmp r11, rsi
cmp r11, [ rsp + 0x14a0 ]
cmp r11, [ rsp + 0x158 ]
cmp r11, [ rsp + 0x1750 ]
cmp r11, [ rsp + 0x2218 ]
cmp r11, [ rsp + 0x24b0 ]
cmp r11, [ rsp + 0x2688 ]
cmp r11, [ rsp + 0x26c0 ]
cmp r11, [ rsp + 0x2920 ]
cmp r11, [ rsp + 0x2938 ]
cmp r11, [ rsp + 0x29b0 ]
cmp r11, [ rsp + 0x3780 ]
cmp r11, [ rsp + 0x37e8 ]
cmp r11, [ rsp + 0xbd8 ]
cmp r12, r10
cmp r12, r11
cmp r12, r13
cmp r12, r14
cmp r12, r15
cmp r12, r9
cmp r12, rax
cmp r12, rbp
cmp r12, rbx
cmp r12, rcx
cmp r12, rdi
cmp r12, rdx
cmp r12, rsi
cmp r12, [ rsp + 0x1048 ]
cmp r12, [ rsp + 0x12a0 ]
cmp r12, [ rsp + 0x1428 ]
cmp r12, [ rsp + 0x16c8 ]
cmp r12, [ rsp + 0x220 ]
cmp r12, [ rsp + 0x23b8 ]
cmp r12, [ rsp + 0x2520 ]
cmp r12, [ rsp + 0x2528 ]
cmp r12, [ rsp + 0x29a8 ]
cmp r12, [ rsp + 0x2be8 ]
cmp r12, [ rsp + 0x910 ]
cmp r13, r11
cmp r13, r12
cmp r13, r15
cmp r13, r8
cmp r13, r9
cmp r13, rax
cmp r13, rbp
cmp r13, rcx
cmp r13, rdi
cmp r13, rdx
cmp r13, rsi
cmp r13, [ rsp + 0x110 ]
cmp r13, [ rsp + 0x14c0 ]
cmp r13, [ rsp + 0x1d90 ]
cmp r13, [ rsp + 0x1fe8 ]
cmp r13, [ rsp + 0x2228 ]
cmp r13, [ rsp + 0x2780 ]
cmp r13, [ rsp + 0x27d0 ]
cmp r13, [ rsp + 0x2c20 ]
cmp r13, [ rsp + 0x3658 ]
cmp r13, [ rsp + 0x3c8 ]
cmp r13, [ rsp + 0xe08 ]
cmp r14, r10
cmp r14, r11
cmp r14, r12
cmp r14, r13
cmp r14, r15
cmp r14, r8
cmp r14, r9
cmp r14, rax
cmp r14, rbp
cmp r14, rcx
cmp r14, rdx
cmp r14, rsi
cmp r14, [ rsp + 0x13e8 ]
cmp r14, [ rsp + 0x17b0 ]
cmp r14, [ rsp + 0x18c8 ]
cmp r14, [ rsp + 0x1aa0 ]
cmp r14, [ rsp + 0x1e58 ]
cmp r14, [ rsp + 0x2088 ]
cmp r14, [ rsp + 0x20e8 ]
cmp r14, [ rsp + 0x2498 ]
cmp r14, [ rsp + 0x2a10 ]
cmp r14, [ rsp + 0x2da0 ]
cmp r14, [ rsp + 0x32c0 ]
cmp r14, [ rsp + 0x34f8 ]
cmp r14, [ rsp + 0x3600 ]
cmp r14, [ rsp + 0x3a8 ]
cmp r14, [ rsp + 0x600 ]
cmp r14, [ rsp + 0x848 ]
cmp r14, [ rsp + 0xdc8 ]
cmp r15, r10
cmp r15, r11
cmp r15, r13
cmp r15, r8
cmp r15, r9
cmp r15, rax
cmp r15, rbp
cmp r15, rbx
cmp r15, rcx
cmp r15, rdi
cmp r15, rdx
cmp r15, rsi
cmp r15, [ rsp + 0x1910 ]
cmp r15, [ rsp + 0x1968 ]
cmp r15, [ rsp + 0x1b58 ]
cmp r15, [ rsp + 0x1d0 ]
cmp r15, [ rsp + 0x30c8 ]
cmp r15, [ rsp + 0x3110 ]
cmp r15, [ rsp + 0x3140 ]
cmp r15, [ rsp + 0x8f8 ]
cmp r15, [ rsp + 0xb70 ]
cmp r15, [ rsp + 0xbe0 ]
cmp r15, [ rsp + 0xd50 ]
cmp r8, r11
cmp r8, r12
cmp r8, r13
cmp r8, r14
cmp r8, r15
cmp r8, r9
cmp r8, rax
cmp r8, rbp
cmp r8, rbx
cmp r8, rcx
cmp r8, rdi
cmp r8, rdx
cmp r8, [ rsp + 0x1270 ]
cmp r8, [ rsp + 0x14b0 ]
cmp r8, [ rsp + 0x1700 ]
cmp r8, [ rsp + 0x1730 ]
cmp r8, [ rsp + 0x1c08 ]
cmp r8, [ rsp + 0x1fe0 ]
cmp r8, [ rsp + 0x2110 ]
cmp r8, [ rsp + 0x2500 ]
cmp r8, [ rsp + 0x2e48 ]
cmp r8, [ rsp + 0x3380 ]
cmp r8, [ rsp + 0x3488 ]
cmp r8, [ rsp + 0x38e8 ]
cmp r8, [ rsp + 0x440 ]
cmp r8, [ rsp + 0x6b8 ]
cmp r8, [ rsp + 0xb90 ]
cmp r8, [ rsp + 0xe18 ]
cmp r8, [ rsp + 0xea0 ]
cmp r8, [ rsp + 0xf78 ]
cmp r8, [ rsp + 0xfe0 ]
cmp r9, r10
cmp r9, r11
cmp r9, r12
cmp r9, r14
cmp r9, r15
cmp r9, r8
cmp r9, rax
cmp r9, rbp
cmp r9, rbx
cmp r9, rcx
cmp r9, rdi
cmp r9, rsi
cmp r9, [ rsp + 0x1030 ]
cmp r9, [ rsp + 0x1b70 ]
cmp r9, [ rsp + 0x2310 ]
cmp r9, [ rsp + 0x2318 ]
cmp r9, [ rsp + 0x26f8 ]
cmp r9, [ rsp + 0x27c8 ]
cmp r9, [ rsp + 0x27d8 ]
cmp r9, [ rsp + 0x3860 ]
cmp r9, [ rsp + 0x3958 ]
cmp r9, [ rsp + 0xf70 ]
cmp rax, r10
cmp rax, r11
cmp rax, r12
cmp rax, r14
cmp rax, r15
cmp rax, r8
cmp rax, r9
cmp rax, rbp
cmp rax, rbx
cmp rax, rcx
cmp rax, rdx
cmp rax, rsi
cmp rax, [ rsp + 0x1198 ]
cmp rax, [ rsp + 0x11e8 ]
cmp rax, [ rsp + 0x2b10 ]
cmp rax, [ rsp + 0x2b70 ]
cmp rax, [ rsp + 0x2ea0 ]
cmp rax, [ rsp + 0x3118 ]
cmp rax, [ rsp + 0x3288 ]
cmp rax, [ rsp + 0x34b8 ]
cmp rax, [ rsp + 0x35f0 ]
cmp rax, [ rsp + 0x3700 ]
cmp rax, [ rsp + 0x4b0 ]
cmp rax, [ rsp + 0x978 ]
cmp rax, [ rsp + 0xb88 ]
cmp rbp, r10
cmp rbp, r12
cmp rbp, r13
cmp rbp, r15
cmp rbp, r8
cmp rbp, r9
cmp rbp, rax
cmp rbp, rsi
cmp rbp, [ rsp + 0x1470 ]
cmp rbp, [ rsp + 0x1970 ]
cmp rbp, [ rsp + 0x1f80 ]
cmp rbp, [ rsp + 0x20a0 ]
cmp rbp, [ rsp + 0x2878 ]
cmp rbp, [ rsp + 0x29d0 ]
cmp rbp, [ rsp + 0x2df8 ]
cmp rbp, [ rsp + 0x2ec8 ]
cmp rbp, [ rsp + 0x30d8 ]
cmp rbp, [ rsp + 0x3320 ]
cmp rbp, [ rsp + 0x3360 ]
cmp rbp, [ rsp + 0x3500 ]
cmp rbp, [ rsp + 0x37a0 ]
cmp rbp, [ rsp + 0x5f0 ]
cmp rbp, [ rsp + 0x858 ]
cmp rbp, [ rsp + 0x980 ]
cmp rbx, r10
cmp rbx, r11
cmp rbx, r12
cmp rbx, r14
cmp rbx, r15
cmp rbx, r8
cmp rbx, r9
cmp rbx, rbp
cmp rbx, rcx
cmp rbx, rdi
cmp rbx, rdx
cmp rbx, rsi
cmp rbx, [ rsp + 0x12d0 ]
cmp rbx, [ rsp + 0x1388 ]
cmp rbx, [ rsp + 0x1890 ]
cmp rbx, [ rsp + 0x1980 ]
cmp rbx, [ rsp + 0x2248 ]
cmp rbx, [ rsp + 0x22c8 ]
cmp rbx, [ rsp + 0x2dc0 ]
cmp rbx, [ rsp + 0x3098 ]
cmp rbx, [ rsp + 0x32d8 ]
cmp rbx, [ rsp + 0x3618 ]
cmp rbx, [ rsp + 0x3758 ]
cmp rbx, [ rsp + 0x620 ]
cmp rbx, [ rsp + 0x730 ]
cmp rbx, [ rsp + 0x8b8 ]
cmp rbx, [ rsp + 0xa60 ]
cmp rbx, [ rsp + 0xec0 ]
cmp rcx, r10
cmp rcx, r11
cmp rcx, r12
cmp rcx, r13
cmp rcx, r14
cmp rcx, r15
cmp rcx, r8
cmp rcx, r9
cmp rcx, rbp
cmp rcx, rbx
cmp rcx, rdi
cmp rcx, rdx
cmp rcx, rsi
cmp rcx, [ rsp + 0x1000 ]
cmp rcx, [ rsp + 0x1238 ]
cmp rcx, [ rsp + 0x1248 ]
cmp rcx, [ rsp + 0x1790 ]
cmp rcx, [ rsp + 0x1b38 ]
cmp rcx, [ rsp + 0x1d58 ]
cmp rcx, [ rsp + 0x1e88 ]
cmp rcx, [ rsp + 0x1f8 ]
cmp rcx, [ rsp + 0x2058 ]
cmp rcx, [ rsp + 0x228 ]
cmp rcx, [ rsp + 0x2460 ]
cmp rcx, [ rsp + 0x2940 ]
cmp rcx, [ rsp + 0x2ce8 ]
cmp rcx, [ rsp + 0x3040 ]
cmp rcx, [ rsp + 0x3208 ]
cmp rcx, [ rsp + 0x35b8 ]
cmp rcx, [ rsp + 0xd98 ]
cmp rdi, r10
cmp rdi, r11
cmp rdi, r12
cmp rdi, r13
cmp rdi, r14
cmp rdi, r15
cmp rdi, r8
cmp rdi, r9
cmp rdi, rax
cmp rdi, rbp
cmp rdi, rcx
cmp rdi, rdx
cmp rdi, rsi
cmp rdi, [ rsp + 0x1080 ]
cmp rdi, [ rsp + 0x14d0 ]
cmp rdi, [ rsp + 0x18f8 ]
cmp rdi, [ rsp + 0x2038 ]
cmp rdi, [ rsp + 0x2b80 ]
cmp rdi, [ rsp + 0x3740 ]
cmp rdi, [ rsp + 0x38a0 ]
cmp rdi, [ rsp + 0x580 ]
cmp rdi, [ rsp + 0x640 ]
cmp rdi, [ rsp + 0x728 ]
cmp rdi, [ rsp + 0x850 ]
cmp rdi, [ rsp + 0xf20 ]
cmp rdx, r10
cmp rdx, r12
cmp rdx, r13
cmp rdx, r14
cmp rdx, r15
cmp rdx, r8
cmp rdx, r9
cmp rdx, rax
cmp rdx, rbp
cmp rdx, rbx
cmp rdx, rdi
cmp rdx, rsi
cmp rdx, [ rsp + 0x1078 ]
cmp rdx, [ rsp + 0x1688 ]
cmp rdx, [ rsp + 0x1ce0 ]
cmp rdx, [ rsp + 0x21a8 ]
cmp rdx, [ rsp + 0x2428 ]
cmp rdx, [ rsp + 0x2620 ]
cmp rdx, [ rsp + 0x2b18 ]
cmp rdx, [ rsp + 0x2c80 ]
cmp rdx, [ rsp + 0x2ed0 ]
cmp rdx, [ rsp + 0x3748 ]
cmp rdx, [ rsp + 0xa0 ]
cmp rdx, [ rsp + 0xbd0 ]
cmp rdx, [ rsp + 0xd68 ]
cmp rsi, r10
cmp rsi, r11
cmp rsi, r12
cmp rsi, r13
cmp rsi, r14
cmp rsi, r15
cmp rsi, r8
cmp rsi, rax
cmp rsi, rbp
cmp rsi, rbx
cmp rsi, rcx
cmp rsi, rdi
cmp rsi, rdx
cmp rsi, [ rsp + 0x16b8 ]
cmp rsi, [ rsp + 0x178 ]
cmp rsi, [ rsp + 0x1b80 ]
cmp rsi, [ rsp + 0x1d40 ]
cmp rsi, [ rsp + 0x22b0 ]
cmp rsi, [ rsp + 0x2560 ]
cmp rsi, [ rsp + 0x2760 ]
cmp rsi, [ rsp + 0x2bb8 ]
cmp rsi, [ rsp + 0x2c50 ]
cmp rsi, [ rsp + 0xc78 ]
cmp r10, r11
cmp r10, rdi
cmp r12, r11
cmp r13, r10
cmp r14, r8
cmp r14, rdi
cmp r15, r10
cmp r15, r11
cmp r8, r10
cmp r8, r11
cmp r8, rdi
cmp r9, r10
cmp r9, rdi
cmp rax, r10
cmp rax, rbp
cmp rbx, r11
cmp rbx, rdi
cmp rcx, r11
cmp rcx, rdi
cmp rdx, r10
cmp al, 0x0
cmp ax, 0xe1
cmp eax, 0xe11
cmp sil, 0x0
cmp si, 0xe1
cmp esi, 0xe11
cmp rax, 0xfffee12
cmp rax, 0xff6ee12
cmp rax, 0xf66ee12
cmp rax, 0x666ee12
cmp rax, 0x6666ee12
cmp rax, -0x1
cmp rax, -0xfffee12
cmp rax, -0xff6ee12
cmp rax, -0xf66ee12
cmp rax, -0x666ee12
cmp rax, -0x6666ee12
cmp rbp, -0xfffee12
cmp rbp, 0xfffee12
cmp rbp, 0xff6ee12
cmp rbp, 0xf66ee12
cmp rbp, 0x666ee12
cmp rbp, 0x6666ee12
cmp rbp, -0xf
cmp rbp, -0xe
cmp rbp, -0xd
cmp rbp, -0x7
cmp rbp, -0x4
cmp rbp, -0x3
cmp rbp, -0x2
cmp rbp, -0xff
cmp rbp, -0xef
cmp rbp, -0xdf
cmp rbp, -0xcf
cmp rbp, -0xbf
cmp rbp, -0xaf
cmp rbp, -0x9f
cmp rbp, -0x8f
cmp rbp, -0x7f
cmp rbp, -0x3e
cmp rbp, -0x6f
cmp rbp, -0x5f
cmp rbp, -0x4f
cmp rbp, -0x1f
cmp rbp, -0xfa
cmp rbp, -0xf9
cmp rbp, -0xf8
cmp rbp, -0xf7
cmp rbp, -0xf6
cmp rbp, -0xf5
cmp rbp, -0xf4
cmp rbp, -0xf3
cmp rbp, -0xf2
cmp rbp, -0xf1
cmp rbp, -0xf66
cmp rbp, -0x666ee
cmp rbp, -0x6666ee12
cmp r13, -0xfffee12
cmp r13, 0xfffee12
cmp r13, 0xff6ee12
cmp r13, 0xf66ee12
cmp r13, 0x666ee12
cmp r13, 0x6666ee12
cmp r13, -0x1
cmp r13, -0xfffee12
cmp r13, -0xff6ee12
cmp r13, -0xf66ee12
cmp r13, -0x666ee12
cmp r13, -0x6666ee12
cmp rax, 0x12
cmp rax, 0xe12
cmp rax, 0x66ee12
cmp rax, 0x66ee12
cmp rax, 0x6ee12
cmp sp, 0x34ef
cmp r8w, 0x1
cmp rax, [ rbx ]
cmp rax, [ rbx + 0x10 ]
cmp rax, 0x0 
cmp rax, 0x0 ; with a comment
cmp r12, r14
cmp r12, rbx
cmp r12, [ rsp + 0x10 ]
cmp rax, 0xfff
cmp rax, r15
cmp rax, rbp
cmp rbp, r12
cmp rbp, r8
cmp rbp, r9
cmp rbx, r9
cmp rbx, rdi
cmp rdi, r10
cmp rdx, r14
cmp rsp, 0x138 
cmp rsp, 0x48 
cmp rsp, 0x50 
cmp rsp, 0x80 
cmp rax, -0xf 
