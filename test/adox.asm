SECTION .text
GLOBAL test
test:
adox r10, r14
adox r10, r9
adox r10, rcx
adox r11, r12
adox r11, r15
adox r11, r9
adox r11, rbx
adox r12, r10
adox r12, r13
adox r12, r15
adox r12, rbp
adox r13, r11
adox r13, r12
adox r13, r15
adox r13, rbp
adox r13, [ rsp + 0x68 ]
adox r14, r10
adox r14, r15
adox r14, rax
adox r14, rcx
adox r14, rdi
adox r15, r11
adox r15, r13
adox r15, r8
adox r15, rdx
adox r8, r10
adox r8, r13
adox r8, r9
adox r8, rbp
adox r8, rsi
adox r9, r11
adox r9, r12
adox r9, r13
adox r9, r15
adox r9, rax
adox r9, rcx
adox r9, [ rsp + 0x28 ]
adox rax, r10
adox rax, r12
adox rax, r15
adox rax, r8
adox rax, rbp
adox rbp, rax
adox rbp, [ rsp + 0x10 ]
adox rbx, r11
adox rbx, r8
adox rbx, r9
adox rbx, r9
adox rbx, rax
adox rbx, rdi
adox rcx, r12
adox rcx, r9
adox rcx, rax
adox rcx, rbp
adox rcx, rbp
adox rdi, r13
adox rdi, rax
adox rdi, rbx
adox rdi, rcx
adox rdx, r8
adox rdx, r9
adox rdx, rax
adox rdx, rcx
adox rdx, rsi
adox rsi, rdi
