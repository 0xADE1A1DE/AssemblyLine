SECTION .text
GLOBAL test
test:
bzhi r9, rax, rax
bzhi r9, rcx, rcx
bzhi r9, rdx, rdi
bzhi r9, rsp, r8
bzhi r9, r12, r10
bzhi r9, rax, rsi
bzhi rsp, rax, rsi
bzhi r9, [rsp + 0x28], r9
bzhi r11, [rsp + 0x8], r11
bzhi r11, r13, r11
