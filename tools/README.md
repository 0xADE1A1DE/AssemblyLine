# asmline

***note: run `$ asmline`, `$ asmline --help` or `$ man asmline` to view usage information***
```
USAGE:
	asmline [OPTIONS]... FILE

DESCRIPTION: Assembles FILE into memory
```
## Features:

### Create binary file from assembly code

1. `$ asmline -o FILENAME path/to/file.asm` to output the generated machine code into a binary file (FILENAME.bin)
    ```
    -o --object FILENAME
            Generates a binary file from path/to/file.asm called FILENAME.bin in the current directory.
    ```
1. The above call will generate a binary file FILENAME.bin and the command below could be used to create an ELF file.
    ```bash
    $ objcopy \
    --input-target=binary \
    --globalize-symbol=FILENAME \
    --rename-section .data=.text \
    --output-target=elf64-x86-64 \
    FILENAME.bin FILENAME.o
    ```

#### Example

1. Create an assembly program
    ```asm
    ; jump.asm
    mov rcx, 0x123
    jmp 0x4
    add rcx, 1
    mov rax, rcx
    ret
    ```
1. Generate bin file with asmline
    ```bash
    $ asmline -o jump jump.asm 
    ```
1. Generate a jump.o file from jump.bin
    ```bash
    $ objcopy \
    --input-target=binary \
    --redefine-sym _binary_jump_bin_start=jump \
    --rename-section .data=.text \
    --output-target=elf64-x86-64 \
    jump.bin jump.o 
    ```    
1. Now we can run `$ objdump` on `jump.o` to see the symbols in the ELF file  
    ```bash
    $ objdump -t jump.o

    jump.o:     file format elf64-x86-64

    SYMBOL TABLE:
    0000000000000000 l    d  .text	0000000000000000 .text
    0000000000000000 g       .text	0000000000000000 jump
    000000000000000f g       .text	0000000000000000 _binary_jump_bin_end
    000000000000000f g       *ABS*	0000000000000000 _binary_jump_bin_size

    $ objdump -D jump.o 
    
    jump.o:     file format elf64-x86-64
    
    
    Disassembly of section .text:
    
    0000000000000000 <jump>:
       0:   b9 23 01 00 00          mov    $0x123,%ecx
       5:   eb 04                   jmp    b <jump+0xb>
       7:   48 83 c1 01             add    $0x1,%rcx
       b:   48 89 c8                mov    %rcx,%rax
       e:   c3                      ret
    
    ```   
    
### Print assembled machine code to stdout (in ASCII-hex)

`$ asmline -p path/to/file.asm` to write the generated machine code from `path/to/file.asm` to stdout
```
-p --print
        The corresponding machine code will be printed to stdout in hex form.
        Output is similar to `objdump`: Byte-wise delimited by space and linebreaks after 7 bytes.
        If -c is given, the chunks are delimited by '|' and each chunk is on one line.
```
#### Example
```bash
$ asmline -p jump.asm
b9 23 01 00 00 
eb 04 
48 83 c1 01 
48 89 c8 
c3 
```

### Print assembled machine code to a file (in binary)

`$ asmline -P FILENAME path/to/file.asm` to write the generated machine code from `path/to/file.asm` to FILENAME
 ```
 -P, --printfile FILENAME
         The corresponding machine code will be printed to FILENAME in binary form.
         Can be set to '/dev/stdout' to write to stdout (similar to -p, --print).
 ```

#### Example

```bash
$ asmline -Pjump.bin jump.asm && xxd -p jump.bin 
b923010000eb044883c1014889c8c3
```

### Chunk size fitting

`$ asmline -c CHUNK_SIZE>1 path/to/file.asm` to appy chunk size fitting when assembling `path/to/file.asm`.
 ```
 -c --chunk CHUNK_SIZE>1
         Sets a given CHUNK_SIZE boundary in bytes. Nop padding will be used to 
         ensure no instruction opcode crosses the specified CHUNK_SIZE boundary.
 ```
**Note:** A specific chunk size could be specified for instruction alignment (chunk sizes must be greater than 1), AssemblyLine will ensure no instruction opcode crosses the chunk size boundary by applying nop padding.

#### Example

```
$ asmline --chunk 5 jump.asm -p
b9 23 01 00 00 |
eb 04 0f 1f 00 |
48 83 c1 01 90 |
48 89 c8 c3 
```
**Note:** we see that every instruction for NOP'ed to fit the chunk of size 5.

### Executing machine code directly from memory

`$ asmline --return path/to/file.asm` to directly execute `path/to/file.asm` given the following options: 
```
-r[=LEN], --return[=LEN]
    Assembles given code. Then executes it with six parameters to heap-allocated memory.
    Each pointer points to an array of LEN 64-bit elements which can be dereferenced in the asm-code, where LEN defaults to 10.
    After execution, it prints out the contents of the return (rax) register and frees the heap-memory.

--rand 
     implies -r and will additionally initialize the memory from with random data. -r=11 can be used to alter LEN.
```

#### Example

```asm
; add_one.asm
mov rcx, 0x123
add rcx, 1
mov rax, rcx
ret
```

Execute the file and get return value with asmline
```bash
$ asmline -r add_one.asm
the value is 0x124
```

#### Example 2: Executing an assembly program with arguments from memory example

**Note:** The `-r[=LEN]` will execute assembly code with `6` parameters consisting of `uint64` arrays with length `LEN`, defaulting to `LEN=10`.
That means that `rdi`--`r9` can be dereferenced in the assembly file.

```asm
; adelaide.asm
mov [rdi], 0xADE1A1DE
mov rax, 0xADE1A1DE
mov [rsi], rax
mov [rdx], rax
mov [rcx], rax          ; LEN must be min 1 for this to work, as we access arg3[0]
mov [rcx + 0x08], rax   ; LEN must be min 2 for this to work, as we access arg3[1]
mov [r8], rax
mov [r9], rax
ret
```

```bash
$ asmline -r=2 adelaide.asm
the value is 0xade1a1de
```

**NOTE:** The return value is obvious, but note that the program did not segfault when dereferencing the parameters `rdi`--`r9`.

## Different Modes of Assembly
- `mov-imm` options: When moving immediate values to a 64-bit register, and the immediate value fits into max signed 32-bit (<=`0x7fffffff`) nasm will interpret `mov rax, IMM` as `mov eax, IMM`.  
- `sib-index-base-swap` options: Since the stack pointer register is not scalable in SIB when the index register is set to `rsp` or `esp`, nasm will swap the index and base register to produce a valid instruction.
- `sib-no-base` options: Also in SIB, when no base register is present and the scale is equal to 2; nasm will set the base to the index register and reduce the scale by 1.
ex: `[2 * rax] -> [rax + 1 * rax]` 

#### The settings below allow the user to control the aforementioned behavior.

### Set SIB register swap to NASM

1. `$ asmline --nasm-sib-index-base-swap path/to/file.asm` to ensure the generated machine code from `path/to/file.asm` matches nasm 
    ```
    --nasm-sib-index-base-swap
            In SIB addressing if the index register is esp or rsp then the base and index registers
            will be swapped (this is enabled by default).
            That is: "lea r15, [rax+rsp]" interpreted as "lea r15, [rsp+rax]" -> 4c 8d 3c 04
                     "lea r15, [rsp+rsp]" will produce an error  (base and index cannot be swapped)
    ```

### Set SIB register swap to STRICT

1. `$ asmline --strict-sib-index-base-swap path/to/file.asm` to ensure the generated machine code from `path/to/file.asm` is in an 'as is' state 
    ```
    --strict-sib-index-base-swap
            In SIB addressing the base and index registers will not be swapped even if the
            index register is esp or rsp.
            That is: "lea r15, [rax+rsp]" will be interpreted as "lea r15, [rax+riz]" -> 4c 8d 3c 20
                     riz is a pseudo-register evaluated by GCC to constant 0 and therefore cannot be
                     used in assemblyline as a string ie. assembling "lea r15, [rax+riz]" is invalid
                     "lea r15, [rsp+rsp]" will also produce an error (invalid instruction)
    ```

### Set SIB no base to NASM

1. `$ asmline --nasm-sib-no-base path/to/file.asm` to ensure the generated machine code from `path/to/file.asm` matches nasm 
    ```
    --nasm-sib-no-base
            In SIB addressing if there is no base register present and scale is equal to 2; 
	    the base register will be set to the index register and the scale will be reduced to 1.
            (this is enabled by default).
            That is: "lea r15, [2*rax]" will be interpreted as "lea r15, [rax+1*rax]" -> 4c 8d 3c 00
    ```

### Set SIB no base to STRICT

1. `$ asmline --strict-sib-no-base path/to/file.asm` to ensure the generated machine code from `path/to/file.asm` is in an 'as is' state 
    ```
    --strict-sib-no-base
            In SIB addressing when there is no base register present the index and scale 
	    would not change regardless of scale value.
            That is: "lea r15, [2*rax]" will be interpreted as "lea r15, [2*rax]" -> 4c 8d 3c 45 00 00 00 00
    ```

### Set mov immediate to NASM

1. `$ asmline --nasm-mov-imm path/to/file.asm` to ensure the generated machine code from `path/to/file.asm` matches nasm 
    ```
    --nasm-mov-imm
            Enables nasm-style mov-immediate register-size optimization.
            ex: if immediate size for mov is less than or equal to max signed 32-bit assemblyline
                will emit code to mov to the 32-bit register rather than 64-bit.
            That is: "mov rax,0x7fffffff" as "mov eax,0x7fffffff" -> b8 ff ff ff 7f
            note: rax got optimized to eax for faster immediate to register transfer and
                  produces a shorter instruction. 
    ```

### Set mov immediate to STRICT

1. `$ asmline --strict-mov-imm path/to/file.asm` to ensure the generated machine code from `path/to/file.asm` is in an 'as is' state 
    ```
    --strict-mov-imm
            Disables nasm-style mov-immediate register-size optimization.
            ex: even if immediate size for mov is less than or equal to max signed 32-bit assemblyline.
                will pad the immediate to fit 64-bit
            That is: "mov rax,0x7fffffff" as "mov rax,0x000000007fffffff"
                      -> 48 b8 ff ff ff 7f 00 00 00 00
            note: rax got optimized to eax for faster immediate to register transfer
                  and produces a shorter instruction.
    ```

### Set mov immediate to SMART

1. `$ asmline --smart-mov-imm path/to/file.asm` to ensure the generated machine code from `path/to/file.asm` can manually be set to  
disable nasm mode (this is enabled by default). 
    ```
    --smart-mov-imm
            The immediate value will be checked for leading 0's.
            Immediate must be zero padded to 64-bits exactly to ensure it will not optimize.
            This is currently set as default.
            ex: "mov rax, 0x000000007fffffff" ->  48 b8 ff ff ff 7f 00 00 00 00
                "mov rax, 0x7fffffff" -> b8 ff ff ff 7f
    ```

### Set all SIB options to NASM

1. `$ asmline --nasm-sib path/to/file.asm` to ensure the generated machine code with SIB from `path/to/file.asm` matches nasm 
    ```
    --nasm-sib
           equivalent to --nasm-sib-no-base --nasm-sib-index-base-swap
    ```

### Set all SIB options to STRICT

1. `$ asmline --strict-sib path/to/file.asm` to ensure the generated machine code with SIB from `path/to/file.asm` is in an 'as is' state 
    ```
    --strict-sib
              equivalent to --strict-sib-no-base --strict-sib-index-base-swap
    ```

### Set all options to NASM

1. `$ asmline --nasm path/to/file.asm` to ensure the generated machine code from `path/to/file.asm` matches nasm 
    ```
    -n, --nasm
           equivalent to --nasm-mov-imm --nasm-sib
    ```

### Set all options to STRICT

1. `$ asmline --strict path/to/file.asm` to ensure the generated machine code from `path/to/file.asm` is in an 'as is' state 
    ```
    -t, --strict
              equivalent to --strict-mov-imm --strict-sib
    ```
