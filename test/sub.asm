SECTION .text
GLOBAL test
test:
sub al, 0x0
sub ax, 0xe1
sub eax, 0xe11
sub ax, 0xe2
sub eax, 0xeff
sub ax, 0xe0
sub sil, 0x0
sub si, 0xe1
sub esi, 0xe11
sub rax, 0xfffee12
sub rax, 0xff6ee12
sub rax, 0xf66ee12
sub rax, 0x666ee12
sub rax, 0x6666ee12
sub rax, -0x1
sub rax, -0xfffee12
sub rax, -0xff6ee12
sub rax, -0xf66ee12
sub rax, -0x666ee12
sub rax, -0x6666ee12
sub rbp, -0xfffee12
sub rbp, 0xfffee12
sub rbp, 0xff6ee12
sub rbp, 0xf66ee12
sub rbp, 0x666ee12
sub rbp, 0x6666ee12
sub rbp, -0xf
sub rbp, -0xe
sub rbp, -0xd
sub rbp, -0x7
sub rbp, -0x4
sub rbp, -0x3
sub rbp, -0x2
sub rbp, -0xff
sub rbp, -0xef
sub rbp, -0xdf
sub rbp, -0xcf
sub rbp, -0xbf
sub rbp, -0xaf
sub rbp, -0x9f
sub rbp, -0x8f
sub rbp, -0x7f
sub rbp, -0x3e
sub rbp, -0x6f
sub rbp, -0x5f
sub rbp, -0x4f
sub rbp, -0x1f
sub rbp, -0xfa
sub rbp, -0xf9
sub rbp, -0xf8
sub rbp, -0xf7
sub rbp, -0xf6
sub rbp, -0xf5
sub rbp, -0xf4
sub rbp, -0xf3
sub rbp, -0xf2
sub rbp, -0xf1
sub rbp, -0xf66
sub rbp, -0x666ee
sub rbp, -0x6666ee12
sub r13, -0xfffee12
sub r13, 0xfffee12
sub r13, 0xff6ee12
sub r13, 0xf66ee12
sub r13, 0x666ee12
sub r13, 0x6666ee12
sub r13, -0x1
sub r13, -0xfffee12
sub r13, -0xff6ee12
sub r13, -0xf66ee12
sub r13, -0x666ee12
sub r13, -0x6666ee12
sub rax, 0x12
sub rax, 0xe12
sub rax, 0x66ee12
sub rax, 0x66ee12
sub rax, 0x6ee12
sub r11, r10
sub rsp, 0x138 
sub rsp, 0x48 
sub rsp, 0x50 
sub rsp, 0x80 