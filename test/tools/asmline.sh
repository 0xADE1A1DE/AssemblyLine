#!/usr/bin/env bash

# error out on any error
set -e

tool=./tools/asmline
# should not error out without option to '-r'
${tool} -r <<EOF
ret
EOF

# should not error out without option to '--rand'
${tool} --rand <<EOF
ret
EOF

# should still run with '--rand'
${tool} --rand <<EOF
mov rax, [rsi]
ret
EOF

# try to dereference args 0..6
${tool} -r <<EOF
mov rax, [rdi]
mov rax, [rsi]
mov rax, [rdx]
mov rax, [rcx]
mov rax, [r8]
mov rax, [r9]
ret
EOF

# try to save something to args 0..6
${tool} -r <<EOF
mov rax, 0xDEADBEEF
mov [rdi], rax
mov [rsi], rax
mov [rdx], rax
mov [rcx], rax
mov [r8], rax
mov [r9], rax
ret
EOF

# try to save something to args 0..6 (default length is 10, so rdi..rdi+0x50)
# should pretty much not segfault out
${tool} -r <<EOF
mov rax, 0xDEADBEEF

mov [rdi + 0x00], rax
mov [rdi + 0x08], rax
mov [rdi + 0x10], rax
mov [rdi + 0x18], rax
mov [rdi + 0x20], rax
mov [rdi + 0x28], rax
mov [rdi + 0x30], rax
mov [rdi + 0x38], rax
mov [rdi + 0x40], rax
mov [rdi + 0x48], rax

mov [rsi + 0x00], rax
mov [rsi + 0x08], rax
mov [rsi + 0x10], rax
mov [rsi + 0x18], rax
mov [rsi + 0x20], rax
mov [rsi + 0x28], rax
mov [rsi + 0x30], rax
mov [rsi + 0x38], rax
mov [rsi + 0x40], rax
mov [rsi + 0x48], rax

mov [rdx + 0x00], rax
mov [rdx + 0x08], rax
mov [rdx + 0x10], rax
mov [rdx + 0x18], rax
mov [rdx + 0x20], rax
mov [rdx + 0x28], rax
mov [rdx + 0x30], rax
mov [rdx + 0x38], rax
mov [rdx + 0x40], rax
mov [rdx + 0x48], rax

mov [rcx + 0x00], rax
mov [rcx + 0x08], rax
mov [rcx + 0x10], rax
mov [rcx + 0x18], rax
mov [rcx + 0x20], rax
mov [rcx + 0x28], rax
mov [rcx + 0x30], rax
mov [rcx + 0x38], rax
mov [rcx + 0x40], rax
mov [rcx + 0x48], rax

mov [r8 + 0x00], rax
mov [r8 + 0x08], rax
mov [r8 + 0x10], rax
mov [r8 + 0x18], rax
mov [r8 + 0x20], rax
mov [r8 + 0x28], rax
mov [r8 + 0x30], rax
mov [r8 + 0x38], rax
mov [r8 + 0x40], rax
mov [r8 + 0x48], rax

mov [r9 + 0x00], rax
mov [r9 + 0x08], rax
mov [r9 + 0x10], rax
mov [r9 + 0x18], rax
mov [r9 + 0x20], rax
mov [r9 + 0x28], rax
mov [r9 + 0x30], rax
mov [r9 + 0x38], rax
mov [r9 + 0x40], rax
mov [r9 + 0x48], rax
ret
EOF

# now with -r11, we shall be able to write to the 11th place
# should pretty much not segfault out
${tool} -r11 <<EOF
mov rax, 0xDEADBEEF

mov [rdi + 0x00], rax
mov [rdi + 0x50], rax
ret
EOF

# or -r=11

${tool} -r=11 <<EOF
mov rax, 0xDEADBEEF

mov [rdi + 0x00], rax
mov [rdi + 0x50], rax
ret
EOF

ret=$(
  ${tool} -b 3 <<EOF
mov rax, 0xDEADBEEF
mov [rdi + 0x50], rax
ret
EOF
)
test "${ret}" -eq 2
