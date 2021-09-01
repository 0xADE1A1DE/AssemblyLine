SECTION .text
GLOBAL test
test:
sub rsp, 0x48 
push r10;
add r10, [ rsp + 0x0 ]
pop r10
add rsp, 0x48 
ret
