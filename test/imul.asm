SECTION .text
GLOBAL test
test:
imul r10, [ rsi + 0x18 ], 0x13
imul r11, [ rsi + 0x20 ], 0x13
imul r11, [ rsi + 0x20 ], 0x2
imul r12, r12, 0x13
imul r12, r12, 0x13
imul r12, r15, 0x2
imul r12, [ rsi + 0x10 ], 0x2
imul r12, [ rsi + 0x8 ], 0x2
imul r13, r15, 0x2
imul r13, [ rsi + 0x18 ], 0x13
imul r14, [ rsi + 0x20 ], 0x2
imul r14, [ rsi + 0x8 ], 0x2
imul r15, [ rsi + 0x18 ], 0x13
imul r15, [ rsi + 0x18 ], 0x2
imul r15, [ rsi + 0x20 ], 0x13
imul r9, [ rsi + 0x10 ], 0x2
imul rax, [ rsi + 0x18 ], 0x2
imul rbp, [ rsi + 0x18 ], 0x2
imul rbx, r13, 0x2
imul rbx, [ rsi + 0x20 ], 0x2
imul rbx, [ rsi + 0x8 ], 0x2
imul rcx, r10, 0x2
imul rcx, r11, 0x2
imul rdi, [ rsi + 0x10 ], 0x2
imul rdx, r11, 0x2
imul rbx, rax
imul ebx, eax
imul bx, ax
imul bl
imul rax, [rax]
imul rax, [rbx]
imul rax, [rcx]
imul rax, [rdx]
imul rax, [rdi]
imul rax, [r8]
imul rax, [r9]
imul rax, [r10]
imul rax, [r11]
imul rax, [r12]
imul rax, [r13]
imul rax, [r14]
imul rax, [r15]
imul rax, [rsp]
imul rax, [rsi]
imul rax, [rbp]
imul rbx, [rax]
imul rbx, [rbx]
imul rbx, [rcx]
imul rbx, [rdx]
imul rbx, [rdi]
imul rbx, [r8]
imul rbx, [r9]
imul rbx, [r10]
imul rbx, [r11]
imul rbx, [r12]
imul rbx, [r13]
imul rbx, [r14]
imul rbx, [r15]
imul rbx, [rsp]
imul rbx, [rsi]
imul rbx, [rbp]
imul rcx, [rax]
imul rcx, [rbx]
imul rcx, [rcx]
imul rcx, [rdx]
imul rcx, [rdi]
imul rcx, [r8]
imul rcx, [r9]
imul rcx, [r10]
imul rcx, [r11]
imul rcx, [r12]
imul rcx, [r13]
imul rcx, [r14]
imul rcx, [r15]
imul rcx, [rsp]
imul rcx, [rsi]
imul rcx, [rbp]
imul rdx, [rax]
imul rdx, [rbx]
imul rdx, [rcx]
imul rdx, [rdx]
imul rdx, [rdi]
imul rdx, [r8]
imul rdx, [r9]
imul rdx, [r10]
imul rdx, [r11]
imul rdx, [r12]
imul rdx, [r13]
imul rdx, [r14]
imul rdx, [r15]
imul rdx, [rsp]
imul rdx, [rsi]
imul rdx, [rbp]
imul rdi, [rax]
imul rdi, [rbx]
imul rdi, [rcx]
imul rdi, [rdx]
imul rdi, [rdi]
imul rdi, [r8]
imul rdi, [r9]
imul rdi, [r10]
imul rdi, [r11]
imul rdi, [r12]
imul rdi, [r13]
imul rdi, [r14]
imul rdi, [r15]
imul rdi, [rsp]
imul rdi, [rsi]
imul rdi, [rbp]
imul r8, [rax]
imul r8, [rbx]
imul r8, [rcx]
imul r8, [rdx]
imul r8, [rdi]
imul r8, [r8]
imul r8, [r9]
imul r8, [r10]
imul r8, [r11]
imul r8, [r12]
imul r8, [r13]
imul r8, [r14]
imul r8, [r15]
imul r8, [rsp]
imul r8, [rsi]
imul r8, [rbp]
imul r9, [rax]
imul r9, [rbx]
imul r9, [rcx]
imul r9, [rdx]
imul r9, [rdi]
imul r9, [r8]
imul r9, [r9]
imul r9, [r10]
imul r9, [r11]
imul r9, [r12]
imul r9, [r13]
imul r9, [r14]
imul r9, [r15]
imul r9, [rsp]
imul r9, [rsi]
imul r9, [rbp]
imul r10, [rax]
imul r10, [rbx]
imul r10, [rcx]
imul r10, [rdx]
imul r10, [rdi]
imul r10, [r8]
imul r10, [r9]
imul r10, [r10]
imul r10, [r11]
imul r10, [r12]
imul r10, [r13]
imul r10, [r14]
imul r10, [r15]
imul r10, [rsp]
imul r10, [rsi]
imul r10, [rbp]
imul r11, [rax]
imul r11, [rbx]
imul r11, [rcx]
imul r11, [rdx]
imul r11, [rdi]
imul r11, [r8]
imul r11, [r9]
imul r11, [r10]
imul r11, [r11]
imul r11, [r12]
imul r11, [r13]
imul r11, [r14]
imul r11, [r15]
imul r11, [rsp]
imul r11, [rsi]
imul r11, [rbp]
imul r12, [rax]
imul r12, [rbx]
imul r12, [rcx]
imul r12, [rdx]
imul r12, [rdi]
imul r12, [r8]
imul r12, [r9]
imul r12, [r10]
imul r12, [r11]
imul r12, [r12]
imul r12, [r13]
imul r12, [r14]
imul r12, [r15]
imul r12, [rsp]
imul r12, [rsi]
imul r12, [rbp]
imul r13, [rax]
imul r13, [rbx]
imul r13, [rcx]
imul r13, [rdx]
imul r13, [rdi]
imul r13, [r8]
imul r13, [r9]
imul r13, [r10]
imul r13, [r11]
imul r13, [r12]
imul r13, [r13]
imul r13, [r14]
imul r13, [r15]
imul r13, [rsp]
imul r13, [rsi]
imul r13, [rbp]
imul r14, [rax]
imul r14, [rbx]
imul r14, [rcx]
imul r14, [rdx]
imul r14, [rdi]
imul r14, [r8]
imul r14, [r9]
imul r14, [r10]
imul r14, [r11]
imul r14, [r12]
imul r14, [r13]
imul r14, [r14]
imul r14, [r15]
imul r14, [rsp]
imul r14, [rsi]
imul r14, [rbp]
imul r15, [rax]
imul r15, [rbx]
imul r15, [rcx]
imul r15, [rdx]
imul r15, [rdi]
imul r15, [r8]
imul r15, [r9]
imul r15, [r10]
imul r15, [r11]
imul r15, [r12]
imul r15, [r13]
imul r15, [r14]
imul r15, [r15]
imul r15, [rsp]
imul r15, [rsi]
imul r15, [rbp]
imul rsp, [rax]
imul rsp, [rbx]
imul rsp, [rcx]
imul rsp, [rdx]
imul rsp, [rdi]
imul rsp, [r8]
imul rsp, [r9]
imul rsp, [r10]
imul rsp, [r11]
imul rsp, [r12]
imul rsp, [r13]
imul rsp, [r14]
imul rsp, [r15]
imul rsp, [rsp]
imul rsp, [rsi]
imul rsp, [rbp]
imul rsi, [rax]
imul rsi, [rbx]
imul rsi, [rcx]
imul rsi, [rdx]
imul rsi, [rdi]
imul rsi, [r8]
imul rsi, [r9]
imul rsi, [r10]
imul rsi, [r11]
imul rsi, [r12]
imul rsi, [r13]
imul rsi, [r14]
imul rsi, [r15]
imul rsi, [rsp]
imul rsi, [rsi]
imul rsi, [rbp]
imul rbp, [rax]
imul rbp, [rbx]
imul rbp, [rcx]
imul rbp, [rdx]
imul rbp, [rdi]
imul rbp, [r8]
imul rbp, [r9]
imul rbp, [r10]
imul rbp, [r11]
imul rbp, [r12]
imul rbp, [r13]
imul rbp, [r14]
imul rbp, [r15]
imul rbp, [rsp]
imul rbp, [rsi]
imul rbp, [rbp]
imul eax, [eax]
imul eax, [ebx]
imul eax, [ecx]
imul eax, [edx]
imul eax, [edi]
imul eax, [r8d]
imul eax, [r9d]
imul eax, [r10d]
imul eax, [r11d]
imul eax, [r12d]
imul eax, [r13d]
imul eax, [r14d]
imul eax, [r15d]
imul eax, [esp]
imul eax, [esi]
imul eax, [ebp]
imul ebx, [eax]
imul ebx, [ebx]
imul ebx, [ecx]
imul ebx, [edx]
imul ebx, [edi]
imul ebx, [r8d]
imul ebx, [r9d]
imul ebx, [r10d]
imul ebx, [r11d]
imul ebx, [r12d]
imul ebx, [r13d]
imul ebx, [r14d]
imul ebx, [r15d]
imul ebx, [esp]
imul ebx, [esi]
imul ebx, [ebp]
imul ecx, [eax]
imul ecx, [ebx]
imul ecx, [ecx]
imul ecx, [edx]
imul ecx, [edi]
imul ecx, [r8d]
imul ecx, [r9d]
imul ecx, [r10d]
imul ecx, [r11d]
imul ecx, [r12d]
imul ecx, [r13d]
imul ecx, [r14d]
imul ecx, [r15d]
imul ecx, [esp]
imul ecx, [esi]
imul ecx, [ebp]
imul edx, [eax]
imul edx, [ebx]
imul edx, [ecx]
imul edx, [edx]
imul edx, [edi]
imul edx, [r8d]
imul edx, [r9d]
imul edx, [r10d]
imul edx, [r11d]
imul edx, [r12d]
imul edx, [r13d]
imul edx, [r14d]
imul edx, [r15d]
imul edx, [esp]
imul edx, [esi]
imul edx, [ebp]
imul edi, [eax]
imul edi, [ebx]
imul edi, [ecx]
imul edi, [edx]
imul edi, [edi]
imul edi, [r8d]
imul edi, [r9d]
imul edi, [r10d]
imul edi, [r11d]
imul edi, [r12d]
imul edi, [r13d]
imul edi, [r14d]
imul edi, [r15d]
imul edi, [esp]
imul edi, [esi]
imul edi, [ebp]
imul r8d, [eax]
imul r8d, [ebx]
imul r8d, [ecx]
imul r8d, [edx]
imul r8d, [edi]
imul r8d, [r8d]
imul r8d, [r9d]
imul r8d, [r10d]
imul r8d, [r11d]
imul r8d, [r12d]
imul r8d, [r13d]
imul r8d, [r14d]
imul r8d, [r15d]
imul r8d, [esp]
imul r8d, [esi]
imul r8d, [ebp]
imul r9d, [eax]
imul r9d, [ebx]
imul r9d, [ecx]
imul r9d, [edx]
imul r9d, [edi]
imul r9d, [r8d]
imul r9d, [r9d]
imul r9d, [r10d]
imul r9d, [r11d]
imul r9d, [r12d]
imul r9d, [r13d]
imul r9d, [r14d]
imul r9d, [r15d]
imul r9d, [esp]
imul r9d, [esi]
imul r9d, [ebp]
imul r10d, [eax]
imul r10d, [ebx]
imul r10d, [ecx]
imul r10d, [edx]
imul r10d, [edi]
imul r10d, [r8d]
imul r10d, [r9d]
imul r10d, [r10d]
imul r10d, [r11d]
imul r10d, [r12d]
imul r10d, [r13d]
imul r10d, [r14d]
imul r10d, [r15d]
imul r10d, [esp]
imul r10d, [esi]
imul r10d, [ebp]
imul r11d, [eax]
imul r11d, [ebx]
imul r11d, [ecx]
imul r11d, [edx]
imul r11d, [edi]
imul r11d, [r8d]
imul r11d, [r9d]
imul r11d, [r10d]
imul r11d, [r11d]
imul r11d, [r12d]
imul r11d, [r13d]
imul r11d, [r14d]
imul r11d, [r15d]
imul r11d, [esp]
imul r11d, [esi]
imul r11d, [ebp]
imul r12d, [eax]
imul r12d, [ebx]
imul r12d, [ecx]
imul r12d, [edx]
imul r12d, [edi]
imul r12d, [r8d]
imul r12d, [r9d]
imul r12d, [r10d]
imul r12d, [r11d]
imul r12d, [r12d]
imul r12d, [r13d]
imul r12d, [r14d]
imul r12d, [r15d]
imul r12d, [esp]
imul r12d, [esi]
imul r12d, [ebp]
imul r13d, [eax]
imul r13d, [ebx]
imul r13d, [ecx]
imul r13d, [edx]
imul r13d, [edi]
imul r13d, [r8d]
imul r13d, [r9d]
imul r13d, [r10d]
imul r13d, [r11d]
imul r13d, [r12d]
imul r13d, [r13d]
imul r13d, [r14d]
imul r13d, [r15d]
imul r13d, [esp]
imul r13d, [esi]
imul r13d, [ebp]
imul r14d, [eax]
imul r14d, [ebx]
imul r14d, [ecx]
imul r14d, [edx]
imul r14d, [edi]
imul r14d, [r8d]
imul r14d, [r9d]
imul r14d, [r10d]
imul r14d, [r11d]
imul r14d, [r12d]
imul r14d, [r13d]
imul r14d, [r14d]
imul r14d, [r15d]
imul r14d, [esp]
imul r14d, [esi]
imul r14d, [ebp]
imul r15d, [eax]
imul r15d, [ebx]
imul r15d, [ecx]
imul r15d, [edx]
imul r15d, [edi]
imul r15d, [r8d]
imul r15d, [r9d]
imul r15d, [r10d]
imul r15d, [r11d]
imul r15d, [r12d]
imul r15d, [r13d]
imul r15d, [r14d]
imul r15d, [r15d]
imul r15d, [esp]
imul r15d, [esi]
imul r15d, [ebp]
imul esp, [eax]
imul esp, [ebx]
imul esp, [ecx]
imul esp, [edx]
imul esp, [edi]
imul esp, [r8d]
imul esp, [r9d]
imul esp, [r10d]
imul esp, [r11d]
imul esp, [r12d]
imul esp, [r13d]
imul esp, [r14d]
imul esp, [r15d]
imul esp, [esp]
imul esp, [esi]
imul esp, [ebp]
imul esi, [eax]
imul esi, [ebx]
imul esi, [ecx]
imul esi, [edx]
imul esi, [edi]
imul esi, [r8d]
imul esi, [r9d]
imul esi, [r10d]
imul esi, [r11d]
imul esi, [r12d]
imul esi, [r13d]
imul esi, [r14d]
imul esi, [r15d]
imul esi, [esp]
imul esi, [esi]
imul esi, [ebp]
imul ebp, [eax]
imul ebp, [ebx]
imul ebp, [ecx]
imul ebp, [edx]
imul ebp, [edi]
imul ebp, [r8d]
imul ebp, [r9d]
imul ebp, [r10d]
imul ebp, [r11d]
imul ebp, [r12d]
imul ebp, [r13d]
imul ebp, [r14d]
imul ebp, [r15d]
imul ebp, [esp]
imul ebp, [esi]
imul ebp, [ebp]
imul ax, word [eax]
imul ax, word [ebx]
imul ax, word [ecx]
imul ax, word [edx]
imul ax, word [edi]
imul ax, word [r8d]
imul ax, word [r9d]
imul ax, word [r10d]
imul ax, word [r11d]
imul ax, word [r12d]
imul ax, word [r13d]
imul ax, word [r14d]
imul ax, word [r15d]
imul ax, word [esp]
imul ax, word [esi]
imul ax, word [ebp]
imul bx, word [eax]
imul bx, word [ebx]
imul bx, word [ecx]
imul bx, word [edx]
imul bx, word [edi]
imul bx, word [r8d]
imul bx, word [r9d]
imul bx, word [r10d]
imul bx, word [r11d]
imul bx, word [r12d]
imul bx, word [r13d]
imul bx, word [r14d]
imul bx, word [r15d]
imul bx, word [esp]
imul bx, word [esi]
imul bx, word [ebp]
imul cx, word [eax]
imul cx, word [ebx]
imul cx, word [ecx]
imul cx, word [edx]
imul cx, word [edi]
imul cx, word [r8d]
imul cx, word [r9d]
imul cx, word [r10d]
imul cx, word [r11d]
imul cx, word [r12d]
imul cx, word [r13d]
imul cx, word [r14d]
imul cx, word [r15d]
imul cx, word [esp]
imul cx, word [esi]
imul cx, word [ebp]
imul dx, word [eax]
imul dx, word [ebx]
imul dx, word [ecx]
imul dx, word [edx]
imul dx, word [edi]
imul dx, word [r8d]
imul dx, word [r9d]
imul dx, word [r10d]
imul dx, word [r11d]
imul dx, word [r12d]
imul dx, word [r13d]
imul dx, word [r14d]
imul dx, word [r15d]
imul dx, word [esp]
imul dx, word [esi]
imul dx, word [ebp]
imul di, word [eax]
imul di, word [ebx]
imul di, word [ecx]
imul di, word [edx]
imul di, word [edi]
imul di, word [r8d]
imul di, word [r9d]
imul di, word [r10d]
imul di, word [r11d]
imul di, word [r12d]
imul di, word [r13d]
imul di, word [r14d]
imul di, word [r15d]
imul di, word [esp]
imul di, word [esi]
imul di, word [ebp]
imul r8w, word [eax]
imul r8w, word [ebx]
imul r8w, word [ecx]
imul r8w, word [edx]
imul r8w, word [edi]
imul r8w, word [r8d]
imul r8w, word [r9d]
imul r8w, word [r10d]
imul r8w, word [r11d]
imul r8w, word [r12d]
imul r8w, word [r13d]
imul r8w, word [r14d]
imul r8w, word [r15d]
imul r8w, word [esp]
imul r8w, word [esi]
imul r8w, word [ebp]
imul r9w, word [eax]
imul r9w, word [ebx]
imul r9w, word [ecx]
imul r9w, word [edx]
imul r9w, word [edi]
imul r9w, word [r8d]
imul r9w, word [r9d]
imul r9w, word [r10d]
imul r9w, word [r11d]
imul r9w, word [r12d]
imul r9w, word [r13d]
imul r9w, word [r14d]
imul r9w, word [r15d]
imul r9w, word [esp]
imul r9w, word [esi]
imul r9w, word [ebp]
imul r10w, word [eax]
imul r10w, word [ebx]
imul r10w, word [ecx]
imul r10w, word [edx]
imul r10w, word [edi]
imul r10w, word [r8d]
imul r10w, word [r9d]
imul r10w, word [r10d]
imul r10w, word [r11d]
imul r10w, word [r12d]
imul r10w, word [r13d]
imul r10w, word [r14d]
imul r10w, word [r15d]
imul r10w, word [esp]
imul r10w, word [esi]
imul r10w, word [ebp]
imul r11w, word [eax]
imul r11w, word [ebx]
imul r11w, word [ecx]
imul r11w, word [edx]
imul r11w, word [edi]
imul r11w, word [r8d]
imul r11w, word [r9d]
imul r11w, word [r10d]
imul r11w, word [r11d]
imul r11w, word [r12d]
imul r11w, word [r13d]
imul r11w, word [r14d]
imul r11w, word [r15d]
imul r11w, word [esp]
imul r11w, word [esi]
imul r11w, word [ebp]
imul r12w, word [eax]
imul r12w, word [ebx]
imul r12w, word [ecx]
imul r12w, word [edx]
imul r12w, word [edi]
imul r12w, word [r8d]
imul r12w, word [r9d]
imul r12w, word [r10d]
imul r12w, word [r11d]
imul r12w, word [r12d]
imul r12w, word [r13d]
imul r12w, word [r14d]
imul r12w, word [r15d]
imul r12w, word [esp]
imul r12w, word [esi]
imul r12w, word [ebp]
imul r13w, word [eax]
imul r13w, word [ebx]
imul r13w, word [ecx]
imul r13w, word [edx]
imul r13w, word [edi]
imul r13w, word [r8d]
imul r13w, word [r9d]
imul r13w, word [r10d]
imul r13w, word [r11d]
imul r13w, word [r12d]
imul r13w, word [r13d]
imul r13w, word [r14d]
imul r13w, word [r15d]
imul r13w, word [esp]
imul r13w, word [esi]
imul r13w, word [ebp]
imul r14w, word [eax]
imul r14w, word [ebx]
imul r14w, word [ecx]
imul r14w, word [edx]
imul r14w, word [edi]
imul r14w, word [r8d]
imul r14w, word [r9d]
imul r14w, word [r10d]
imul r14w, word [r11d]
imul r14w, word [r12d]
imul r14w, word [r13d]
imul r14w, word [r14d]
imul r14w, word [r15d]
imul r14w, word [esp]
imul r14w, word [esi]
imul r14w, word [ebp]
imul r15w, word [eax]
imul r15w, word [ebx]
imul r15w, word [ecx]
imul r15w, word [edx]
imul r15w, word [edi]
imul r15w, word [r8d]
imul r15w, word [r9d]
imul r15w, word [r10d]
imul r15w, word [r11d]
imul r15w, word [r12d]
imul r15w, word [r13d]
imul r15w, word [r14d]
imul r15w, word [r15d]
imul r15w, word [esp]
imul r15w, word [esi]
imul r15w, word [ebp]
imul sp, word [eax]
imul sp, word [ebx]
imul sp, word [ecx]
imul sp, word [edx]
imul sp, word [edi]
imul sp, word [r8d]
imul sp, word [r9d]
imul sp, word [r10d]
imul sp, word [r11d]
imul sp, word [r12d]
imul sp, word [r13d]
imul sp, word [r14d]
imul sp, word [r15d]
imul sp, word [esp]
imul sp, word [esi]
imul sp, word [ebp]
imul si, word [eax]
imul si, word [ebx]
imul si, word [ecx]
imul si, word [edx]
imul si, word [edi]
imul si, word [r8d]
imul si, word [r9d]
imul si, word [r10d]
imul si, word [r11d]
imul si, word [r12d]
imul si, word [r13d]
imul si, word [r14d]
imul si, word [r15d]
imul si, word [esp]
imul si, word [esi]
imul si, word [ebp]
imul bp, word [eax]
imul bp, word [ebx]
imul bp, word [ecx]
imul bp, word [edx]
imul bp, word [edi]
imul bp, word [r8d]
imul bp, word [r9d]
imul bp, word [r10d]
imul bp, word [r11d]
imul bp, word [r12d]
imul bp, word [r13d]
imul bp, word [r14d]
imul bp, word [r15d]
imul bp, word [esp]
imul bp, word [esi]
imul bp, word [ebp]
imul rax
imul rbx
imul rcx
imul rdx
imul rdi
imul r8
imul r9
imul r10
imul r11
imul r12
imul r13
imul r14
imul r15
imul rsp
imul rsi
imul rbp
imul eax
imul ebx
imul ecx
imul edx
imul edi
imul r8d
imul r9d
imul r10d
imul r11d
imul r12d
imul r13d
imul r14d
imul r15d
imul esp
imul esi
imul ebp
imul ax
imul bx
imul cx
imul dx
imul di
imul r8w
imul r9w
imul r10w
imul r11w
imul r12w
imul r13w
imul r14w
imul r15w
imul sp
imul si
imul bp
imul al
imul bl
imul cl
imul dl
imul dl
imul r8b
imul r9b
imul r10b
imul r11b
imul r12b
imul r13b
imul r14b
imul r15b
imul spl
imul sil
imul bpl
