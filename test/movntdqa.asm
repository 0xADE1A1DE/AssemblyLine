SECTION .text
GLOBAL test
test:
movntdqa xmm0,    [rsi ]
movntdqa xmm7,    [esi ]
movntdqa xmm2,    [rbp ]
movntdqa xmm6,    [ebp ]
movntdqa xmm1,    [r12 ]
movntdqa xmm2,    [r12d ]
movntdqa xmm3,    [r11 ]
movntdqa xmm4,    [r11d ]
