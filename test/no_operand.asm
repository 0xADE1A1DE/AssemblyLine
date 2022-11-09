SECTION .text
GLOBAL test
test:
sfence
lfence
mfence
xend
rdpmc
rdtsc
rdtscp
clc
cpuid
ret