SECTION .text
GLOBAL test
test:
%define nop2  db 0x66, 0x90                                                       ; 66 nop
%define nop3  db 0x0f, 0x1f, 0x00                                                 ;    nop DWORD ptr [EAX]
%define nop4  db 0x0f, 0x1f, 0x40, 0x00                                           ;    nop DWORD ptr [EAX + 00H]
%define nop5  db 0x0f, 0x1f, 0x44, 0x00, 0x00                                     ;    nop DWORD ptr [EAX + EAX*1 + 00H]
%define nop6  db 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00                               ; 66 nop DWORD ptr [EAX + EAX*1 + 00H]
%define nop7  db 0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00                         ;    nop DWORD ptr [EAX + 00000000H]
%define nop8  db 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00                   ;    nop DWORD ptr [EAX + EAX*1 + 00000000H]
%define nop9  db 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00             ; 66 nop WORD PTR [rax+rax*1+0x0]
%define nop10 db 0x66, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00       ; data16 nop WORD PTR [rax+rax*1+0x0]
%define nop11 db 0x66, 0x66, 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 ; data16 data16 nop WORD PTR [rax+rax*1+0x0]
; NOTE: macros are only needed in test scripts (multi-length nops are already predefined in assemblyline)
nop ; this is a single byte nop so there is not need for a macro  
nop2
nop3
nop4
nop5
nop6
nop7
nop8
nop9
nop10
nop11
