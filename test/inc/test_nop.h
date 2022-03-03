#define CODE                                                                                                           \
    "%define nop2  db 0x66, 0x90                                                       ; 66 nop;\n"                    \
    "%define nop3  db 0x0f, 0x1f, 0x00                                                 ;    nop DWORD ptr [EAX];\n"    \
    "%define nop4  db 0x0f, 0x1f, 0x40, 0x00                                           ;    nop DWORD ptr [EAX + "     \
    "00H];\n"                                                                                                          \
    "%define nop5  db 0x0f, 0x1f, 0x44, 0x00, 0x00                                     ;    nop DWORD ptr [EAX + "     \
    "EAX*1 + 00H];\n"                                                                                                  \
    "%define nop6  db 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00                               ; 66 nop DWORD ptr [EAX + "     \
    "EAX*1 + 00H];\n"                                                                                                  \
    "%define nop7  db 0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00                         ;    nop DWORD ptr [EAX + "     \
    "00000000H];\n"                                                                                                    \
    "%define nop8  db 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00                   ;    nop DWORD ptr [EAX + "     \
    "EAX*1 + 00000000H];\n"                                                                                            \
    "%define nop9  db 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00             ; 66 nop WORD PTR "             \
    "[rax+rax*1+0x0];\n"                                                                                               \
    "%define nop10 db 0x66, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00       ; data16 nop WORD PTR "         \
    "[rax+rax*1+0x0];\n"                                                                                               \
    "%define nop11 db 0x66, 0x66, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 ; data16 data16 nop WORD PTR "  \
    "[rax+rax*1+0x0];\n"                                                                                               \
    "; this is a single byte nop so there is not need for a macro  ;\n"                                                \
    "nop ;\n"                                                                                                          \
    ""
