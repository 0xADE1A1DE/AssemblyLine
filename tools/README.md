## Command-line tool: asmline

***note: run `$ asmline`, `$ asmline --help` or `$ man asmline` to view usage information***
```
USAGE:
	asmline [-r] [-p] [-P FILENAME] [-c CHUNK_SIZE>1] [-o ELF_FILENAME_NO_EXT] [-n] [-t] [-s] [-h] [-v] path/to/file.asm

DESCRIPTION:
	Generates machine code from a file or stdin containing x64 assembly instructions. 
        Machine code could be executed directly without the need for an executable file format. 
```
### Features:

#### Create binary file from assembly code

1. `$ asmline -o FILENAME path/to/file.asm` to output the generated machine code into a binary file (FILENAME.bin)
    ```
    -o --object FILENAME
            Generates a binary file from path/to/file.asm called FILENAME.bin in 
            the current directory.
    ```
1. The above call will generate a binary file FILENAME.bin and the command below could be used to create an ELF file.
    ```bash
    $ objcopy --input-target=binary --globalize-symbol=FILENAME --rename-section .data=.text --output-target=elf64-x86-64 FILENAME.bin FILENAME.o
    ```
**Generating an ELF file from `FILENAME.bin` example:**
1. Create an assembly program
    ```bash
    $ cat jump.asm
    mov rcx, 0x123
    jmp 0x4
    add rcx, 1
    mov rax, rcx
    ret
    ```
1. Generate bin file with asmline
    ```bash
    $ asmline -o jump path/to/jump.asm 
    ```
1. Generate a jump.o file from jump.bin
    ```bash
    $ objcopy --input-target=binary --redefine-sym _binary_jump_bin_start=jump --rename-section .data=.text --output-target=elf64-x86-64 jump.bin jump.o 
    ```    
2. Now we can run `$ objdump` on jump.o to see the symbols in the ELF file  
**NOTE:** the starting label `0000000000000000 g       .text	0000000000000000 jump` is going to be linked within a driver function  
    ```bash
    $ objdump -t jump.o
    jump.o:     file format elf64-x86-64

    SYMBOL TABLE:
    0000000000000000 l    d  .text	0000000000000000 .text
    0000000000000000 g       .text	0000000000000000 jump
    000000000000000f g       .text	0000000000000000 _binary_jump_bin_end
    000000000000000f g       *ABS*	0000000000000000 _binary_jump_bin_size
    ```   
    
#### Print assembled machine code to stdout

1. `$ asmline -p path/to/file.asm` to write the generated machine code from `file.asm` to stdout
    ```
    -p --print
            The corresponding machine code will be printed to stdout in hex form.
            Output is similar to `objdump`: Byte-wise delimited by space and linebreaks after 7 bytes.
            If -c is given, the chunks are delimited by '|' and each chunk is on one line.
    ```
1. The above call will output machine code in the hexadecimal format given `path/to/file.asm`.


#### Print assembled machine code to a file

1. `$ asmline -P FILENAME path/to/file.asm` to write the generated machine code from `file.asm` to FILENAME
    ```
    -P, --printfile FILENAME
            The corresponding machine code will be printed to FILENAME in binary form.
            Can be set to '/dev/stdout' to write to stdout.
    ```
1. The above call will output machine code in binary format to FILENAME given `path/to/file.asm`.

#### Chunk size fitting

1. `$ asmline -c CHUNK_SIZE>1 path/to/file.asm` to appy chunk size fitting when assembling `path/to/file.asm`.
    ```
    -c --chunk CHUNK_SIZE>1
            Sets a given CHUNK_SIZE boundary in bytes. Nop padding will be used to 
            ensure no instruction opcode crosses the specified CHUNK_SIZE boundary.
    ```
1. A specific chunk size could be specified for instruction alignment (chunk sizes must be greater than 1),
1. Assemblyline will ensure no instruction opcode crosses the chunk size boundary by applying nop padding

#### Executing machine code directly from memory

1. `$ asmline --return path/to/file.asm` to directly execute `path/to/file.asm` given the following options: 
    ```
    -r --return
            Executes assembly code and prints out the contents of the 
            rax register (return value register).
    ```
1. `-r` executes assembly program specified by `path/to/file.asm` and print out the return value of that program

### Different modes of assembly
When moving immediate values to a 64-bit register, if immediate value is less than or equal to 0x7fffffff (max signed 32-bit)
nasm will interpret 'mov rax, IMM' as 'mov eax, IMM'. The following three settings allow the user to control this behavior.

#### Set assembly mode to NASM

1. `$ asmline -n path/to/file.asm` to ensure the generated machine code from `file.asm` matches nasm 
    ```
    -n, --nasm
            Enables nasm-style mov-immediate register-size optimization.
            ex: if immediate size for mov is less than or equal to max signed 32 bit assemblyline
                will emit code to mov to the 32-bit register rather than 64-bit.
            That is: "mov rax,0x7fffffff" as "mov eax,0x7fffffff" -> b8 ff ff ff 7f
            note: rax got optimized to eax for faster immediate to register transfer and
                  produces a shorter instruction. 
    ```

#### Set assembly mode to STRICT

1. `$ asmline -t path/to/file.asm` to ensure the generated machine code from `file.asm` is in an 'as is' state 
    ```
    -t, --strict
            Disables nasm-style mov-immediate register-size optimization.
            ex: even if immediate size for mov is less than or equal to max signed 32 bit assemblyline.
                will pad the immediate to fit 64-bit
            That is: "mov rax,0x7fffffff" as "mov rax,0x000000007fffffff"
                      -> 48 b8 ff ff ff 7f 00 00 00 00
            note: rax got optimized to eax for faster immediate to register transfer
                  and produces a shorter instruction.
    ```

#### Set assembly mode to SMART

1. `$ asmline -s path/to/file.asm` to ensure the generated machine code from `file.asm` can manually be set to  
disable nasm mode (this is enabled by default). 
    ```
    -s, --smart
            The immediate value will be checked for leading 0's.
            Immediate must be zero padded to 64-bits exactly to ensure it will not optimize.
            This is currently set as default.
            ex: "mov rax, 0x000000007fffffff" ->  48 b8 ff ff ff 7f 00 00 00 00
                "mov rax, 0x7fffffff" -> b8 ff ff ff 7f
    ```