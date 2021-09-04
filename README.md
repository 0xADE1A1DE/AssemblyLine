# Description

A C library and binary for generating machine code of x86\_64 assembly language and executing on the fly without invoking another compiler, assembler or linker.


# How to use

***note: refer to [/src/instructions.h](https://github.com/0xADE1A1DE/AssemblyLine/tree/main/src/instructions.h) for a complete list of supported instructions***

1. `$ ./configure` or `$ CFLAGS='-g -O3' ./configure` to generate Makefiles.
1. `$ make` to compile
1. `$ make install prefix=$(pwd)` to install it locally or `$ sudo make install` to install globally
1. `$ gcc -o executable your_program.c -lassemblyline` to compile a c program using assemblyline  

# Example

***note: refer to [/src/assemblyline.h](https://github.com/0xADE1A1DE/AssemblyLine/tree/main/src/assemblyline.h) for more information***

1. Include the required header files
    ```c
    #include <stdint.h>
    #include <sys/mman.h>
    #include <assemblyline.h>
    ```
1. Allocate an executable buffer of sufficient size (> 20 bytes) using mmap
    ```c
    uint8_t *mybuffer = mmap(NULL, sizeof(uint8_t) * 300,
    	PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    ```
1. Create an instance of assemblyline_t and attach buffer or set it to NULL for internal memory allocation 
    ```c
    // external memory allocation
    assemblyline_t al = asm_create_instance(mybuffer, 300);
    // internal memory allocation
    assemblyline_t al = asm_create_instance(NULL, 0);
    ```
1. OPTIONAL: Enable debug mode to view machine code
    ```c
    asm_set_debug(al, true);
    ```
1. OPTIONAL: Set a chunk size boundary 
    ```c
    /*this will ensure no instruction opcode will cross the 
    specified chunk boundary length via nop padding*/
    asm_set_chunk_size(al, chunk_size);
    ```
1. Sssemble a file or string containing x64 assembly code (machine code will be written to mybuffer or an internal buffer)
    ```c
    assemble_file(al, /path/to/x64/assembly/file);
    assemble_str(al, string_containing_x64_assembly_code);
    ```
1. Get the start address of the buffer containing the start of the assembly program
    ```c
    void (*funcB)() =(void (*)())(asm_get_code(al));
    ```
1. Free all memory associated with assembyline (external buffer is not freed)
    ```c
    asm_destroy_instance(al);
    ```


# Test files

`$ make check` to run all test suites

* To run only one testsuite `TESTS=seto.asm make -e check`, then check the ./asmcompare.sh /path/to/file.asmeto.log
* Or run the `./al_nasm_compare.sh seto.asm`
* Adding a new test: add the testfile e.g. `sub.asm` to the directory and add `sub.asm` to the `TESTS`-variable in `Makefile.am`
then run `$ make check`. Finally, add `Makefile.am` and `sub.asm` to git.


# Command-line tool: asmline

***note: run tool without any command-line parameters to view usage information ex: `$ asmline` or `$ asmline --help` ***
```
USAGE:
	asmline [-r] [-p] [-c CHUNK_SIZE>2] [-o ELF_FILENAME_NO_EXT] path/to/file.asm

DESCRIPTION:
	Generates machine code from a file containing x64 assembly instructions. 
        Machine code could be executed directly without the need for an executable file format. 
        Obtain command-line instructions for generating an ELF binary file from assembly code.
```
## Features:

### Create ELF file from assembly code

1. `$ asmline -o FILENAME path/to/file.asm` to output the generated machine code into a binary file (FILENAME.bin)
    ```
    -o --object FILENAME
            Generates a binary file from path/to/file.asm called FILENAME.bin in 
            the current directory.
    ```
1. The above call will generate a binary file FILENAME.bin and the command below could be used to create an ELF file.
    ```bash
    $ objcopy --input-target=binary --globalize-symbol=FILENAME --rename-section .data=.text --output-target=elf64-x86-64 FILENAME.bin FILENAME.o
    # link the elf object file with a c program
    $ gcc linker linker.c FILENAME.o
    ```
### Print assembled machine code to stdout

1. `$ asmline -p path/to/file.asm` to write the generated machine code from `file.asm` to stdout
    ```
    -p --print
            When assembling path/to/file.asm the corresponding machine code 
            will be printed to stdout.
    ```
1. The above call will output some machine code in the hexadecimal format given `path/to/file.asm`.

### Chunk size fitting

1. `$ asmline -c CHUNK_SIZE>2 path/to/file.asm` to appy chunk size fitting when assembling `path/to/file.asm`.
    ```
    -c --chunk CHUNK_SIZE>2
            Sets a given CHUNK_SIZE boundary in bytes. Nop padding will be used to 
            ensure no instruction opcode crosses the specified CHUNK_SIZE boundary.
    ```
1. A specific chunk size within a memory block could be specified (chunk sizes less than 2 are invalid),
1. Then a chunk size is given, assemblyline will ensure no instruction opcode crosses the chunk boundary by applying nop padding

### Executing machine code directly from memory

1. `$ asmline --return path/to/file.asm` to directly execute `path/to/file.asm` given the following options:
    ```
    -r --return
            Executes assembly code and prints out the contents of the 
            rax register (return value register).
    ```
1. `-r` executes assembly program specified by `path/to/file.asm` and print out the return value of that program  
  
### al_nasm_compare.sh

####   `./al_nasm_compare.sh /path/to/file.asm`   
1. assemble the given file with assemblyline and output `objdump`-like output
1. assemble the given file with `$ nasm -t elf64 /path/to/file.asm`
1. run `objdump` on the `nasm` generated file and finally run
1. `diff` to see if assemblyline has generated the same machine code as nasm


# How to add new instructions

1. Get the instruction opcode layout and operand encoding format(please refer to: https://www.felixcloutier.com/x86/).
1. Add the new instruction to the asm\_instr enumerator set (found in the enums.h file in the src directory).
1. Add a new entry to INSTR\_TABLE[] for the specific instruction(see below for more details).  

#### Instruction table format: 
```c
struct INSTR_TABLE[] {
  // null terminated string represeantation of an instruction ex: "mov"
  char instr_name[14]               
  // contians the valid operand formats for an instruction (at most 2 for a single operand encoding)
  int opd_format[2]                 
  // asm_instr enumerator for uniquely identifying a single instruction
  int name;                         
  // operand encoding format as an enumerator (determines how instruction operands will be encoded)
  operand_encoding encode_operand;   
  // enumerator for defining the semantic type of an instruction
  instr_type type;                  
  // 'i' index of opcode[i] when an offset is present for a x64 registers, use NA if not applicable  
  int op_offset_i;                  
  // 'i' index of opcode[i] when an offset is present for a register value, use NA if not applicable  
  int rd_offset_i;                    
  // only used for 'M' operand encoding denotes the modRM byte
  int single_reg_r;                  
  // length of instruction opcode  
  int instr_size;                   
  // opcode layout ex: {REX,0x0f,0xa9,REG}
  unsigned int opcode[10];           
}
```




---
## Acknowledgements
#### Developers:

* David Wu (University of Adelaide)  
* Joel Kuepper (University of Adelaide)


#### This project was supported by:  
* The Air Force Office of Scientific Research (AFOSR) under award number FA9550-20-1-0425
* An ARC Discovery Early Career Researcher Award (project number DE200101577) 
* An ARC Discovery Project (project number DP210102670)  
* The Blavatnik ICRC at Tel-Aviv University  
* the Defense Advanced Research Projects Agency (DARPA) and Air Force Research Laboratory (AFRL) under contracts FA8750-19-C-0531 and HR001120C0087
* the National Science Foundation under grant CNS-1954712
* Gifts from AMD, Google, and Intel  
