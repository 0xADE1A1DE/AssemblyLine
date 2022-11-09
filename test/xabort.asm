SECTION .text
GLOBAL test
test:
xabort 0x0
xabort 12
xabort -14
xabort 0x7f
xabort 0x80
xabort 0xff
