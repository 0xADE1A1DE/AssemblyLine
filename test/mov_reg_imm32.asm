SECTION .text
GLOBAL test
test:
mov eax, 0x2
mov eax, 0x7f
mov eax, 0x80
mov eax, 0x80
mov eax, 0xff
mov eax, 0x7ff
mov esi, 0x2
mov esi, 0x7f
mov esi, 0x80
mov esi, 0x80
mov esi, 0xff
mov esi, 0x7ff
mov esi, 0x2
mov esi, 0x7f
mov esi, 0x80
mov esi, 0x80
mov esi, 0xff
mov esi, 0x7ff
mov r13d, 0x2
mov r13d, 0x7f
mov r13d, 0x80
mov r13d, 0x80
mov r13d, 0xff
mov r13d, 0x7ff
mov r15w, 0x2
mov r15w, 0x7f
mov r15w, 0x80
mov r15w, 0x80
mov r15w, 0xff
mov r15w, 0x7ff
mov r15b, -0x2
mov r15b, 0x2
mov r15b, 0x7f
mov r15b, 0x80
mov r15b, 0x80
mov r15b, 0xff
mov r10b, -0x2
mov r11b, -0x2
mov r12b, -0x2
mov al, -0x2
mov al, -0x1
mov al, 0x1
mov cl, -0x2
mov cl, -0x1
mov cl, 0x1
mov ax, -0x2
mov ax, -0x1
mov ax, 0x1
mov cx, -0x2efd
mov cx, -0x2efa
mov cx, 0x2efa
mov si, -0x2efd
mov si, -0x2efa
mov si, 0x2efa