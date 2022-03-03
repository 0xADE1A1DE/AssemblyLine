#define CODE                                                                                                           \
    "nop DWORD ptr [EAX];\n"                                                                                           \
    "nop DWORD ptr [EAX + 0x00];\n"                                                                                    \
    "nop DWORD ptr [EAX + EAX*1 + 0x00];\n"                                                                            \
    "nop DWORD ptr [EAX + 0x0000000];\n"                                                                               \
    "nop DWORD ptr [EAX + EAX*1 + 0x0000000];\n"                                                                       \
    "nop QWORD ptr [rax+rax*1+0x0];\n"                                                                                 \
    "nop ;\n"                                                                                                          \
    ""

/*
"66 nop;\n" \
"66 nop DWORD ptr [EAX + EAX*1 + 00H];\n"
"66 nop WORD PTR [rax+rax*1+0x0];\n"
"data16 nop WORD PTR [rax+rax*1+0x0];\n"
"data16 data16 nop WORD PTR "
*/
