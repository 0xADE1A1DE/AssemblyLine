#define CODE                                                                                                           \
    "lea rax, [rax];\n"                                                                                                \
    "lea rax, [ 1*rax];\n"                                                                                             \
    "lea rax, [ 2*rax];\n"                                                                                             \
    "lea rax, [ 4*rax];\n"                                                                                             \
    "lea rax, [ 8*rax];\n"                                                                                             \
    "lea rax, [ 1*r10];\n"                                                                                             \
    "lea rax, [ 2*r11];\n"                                                                                             \
    "lea rax, [ 4*rcx];\n"                                                                                             \
    "lea eax, [ 8*eax];\n" 
