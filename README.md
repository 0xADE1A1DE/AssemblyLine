# Assemblyline

A C library and binary for generating machine code of x86\_64 assembly language and executing on the fly without invoking another compiler, assembler or linker.


## How to use

***note: refer to [/src/instructions.c](https://github.com/0xADE1A1DE/AssemblyLine/tree/main/src/instructions.c) for a complete list of supported instructions***

1. `$ ./configure` or `$ CFLAGS='-g -O3' ./configure` to generate Makefiles.
1. `$ make` to compile
1. `$ make install prefix=$(pwd)` to install it locally or `$ sudo make install` to install globally
1. `$ gcc -o executable your_program.c -lassemblyline` to compile a c program using assemblyline  

## Example

***note: refer to [/src/assemblyline.h](https://github.com/0xADE1A1DE/AssemblyLine/tree/main/src/assemblyline.h) for more information***

1. Include the required header files and preprocessors
    ```c
    #include <stdint.h>
    #include <sys/mman.h>
    #include <assemblyline.h>
    #define BUFFER_SIZE 300
    ```
1. Allocate an executable buffer of sufficient size (> 20 bytes) using mmap
    ```c
    // the machince code will be written to this location
    uint8_t *mybuffer = mmap(NULL, sizeof(uint8_t) * BUFFER_SIZE,
    	PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    ```
1. Create an instance of assemblyline_t and attach `mybuffer` or set it to NULL for internal memory allocation (will `realloc` if it was too small)
    ```c
    // external memory allocation
    assemblyline_t al = asm_create_instance(mybuffer, BUFFER_SIZE);
    // internal memory allocation
    assemblyline_t al = asm_create_instance(NULL, 0);
    ```
1. OPTIONAL: Enable debug mode to print the machinecode in hex to stdout.
    ```c
    asm_set_debug(al, true);
    ```
1. OPTIONAL: Set a chunk size boundary to ensure that no instruction opcode will cross the specified chunk boundary length.
    *** note: refer instructions `nop, nop2, ..., nop11`
    ```c
    // It will use the appropriate `nop` instruction for the remaining bytes to fill the chunk boundry.
    int chunk_size = 16;
    asm_set_chunk_size(al, chunk_size);
    ```
1. Assemble a file or string containing x64 assembly code. The machine code will be written to `mybuffer` or the internal buffer. You can call those functions sequentially; the new machinecode will be appended at the end.
    ```c
    assemble_file(al, "./path/to/x64_file.asm");
    assemble_str(al, "mov rax, 0x0\nadd rax, 0x2; adds two");
    assemble_str(al, "sub rax, 0x1; subs one\nret");
    ```
1. Get the start address of the buffer containing the start of the assembly program
    ```c
    void (*func)() =(void (*)())(asm_get_code(al));
    // you can then call the function
    int result = func();
    ```
1. Free all memory associated with assembyline (external buffer is not freed)
    ```c
    asm_destroy_instance(al);
    ```
1. Full example:
    ```c
    #include <stdint.h>
    #include <sys/mman.h>
    #include <assemblyline.h>
    #define BUFFER_SIZE 300
    
    uint8_t *mybuffer = mmap(NULL, sizeof(uint8_t) * BUFFER_SIZE,
    	PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    
    assemblyline_t al = asm_create_instance(mybuffer, BUFFER_SIZE); 
    
    asm_set_chunk_size(al, 16); 
    
    assemble_str(al, "mov rax, 0x0\nadd rax, 0x2; adds two");
    assemble_str(al, "sub rax, 0x1; subs one\nret");
 
    void (*func)() =(void (*)())(asm_get_code(al));
    
    int result = func();
    printf("The result is: %d\n", result); 
    // prints "The result is: 1\n"

    asm_destroy_instance(al);
    ```

## Test files

`$ make check` to run all test suites

* To run only one testsuite `TESTS=seto.asm make -e check`, then check the ./al_nasm_compare.sh /path/to/file.asmeto.log
* Or run the `./al_nasm_compare.sh seto.asm`
* Adding a new test: add the testfile e.g. `sub.asm` to the directory and add `sub.asm` to the `TESTS`-variable in `Makefile.am`
then run `$ make check`. Finally, add `Makefile.am` and `sub.asm` to git.


## Command-line tool: asmline

***note: run `$ asmline` or `$ asmline --help` to view usage information***
```
USAGE:
	asmline [-r] [-p] [-c CHUNK_SIZE>1] [-o ELF_FILENAME_NO_EXT] path/to/file.asm

DESCRIPTION:
	Generates machine code from a file containing x64 assembly instructions. 
        Machine code could be executed directly without the need for an executable file format. 
        Obtain command-line instructions for generating an ELF binary file from assembly code.
```
### Features:

#### Create ELF file from assembly code

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
#### Print assembled machine code to stdout

1. `$ asmline -p path/to/file.asm` to write the generated machine code from `file.asm` to stdout
    ```
    -p --print
            When assembling path/to/file.asm the corresponding machine code 
            will be printed to stdout.
    ```
1. The above call will output some machine code in the hexadecimal format given `path/to/file.asm`.

#### Chunk size fitting

1. `$ asmline -c CHUNK_SIZE>1 path/to/file.asm` to appy chunk size fitting when assembling `path/to/file.asm`.
    ```
    -c --chunk CHUNK_SIZE>1
            Sets a given CHUNK_SIZE boundary in bytes. Nop padding will be used to 
            ensure no instruction opcode crosses the specified CHUNK_SIZE boundary.
    ```
1. A specific chunk size within a memory block could be specified (chunk sizes less must be greater than 1),
1. Then a chunk size is given, assemblyline will ensure no instruction opcode crosses the chunk boundary by applying nop padding

#### Executing machine code directly from memory

1. `$ asmline --return path/to/file.asm` to directly execute `path/to/file.asm` given the following options:
    ```
    -r --return
            Executes assembly code and prints out the contents of the 
            rax register (return value register).
    ```
1. `-r` executes assembly program specified by `path/to/file.asm` and print out the return value of that program  
  
## How to add new instructions

1. Get the instruction opcode layout and operand encoding format (please refer to the [intel manual](https://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-instruction-set-reference-manual-325383.pdf)).
1. Add the new instruction to the asm\_instr enumerator set found in the [/src/enums.h](https://github.com/0xADE1A1DE/AssemblyLine/tree/main/src/enums.h).
1. Add a new entry to INSTR\_TABLE[] [/src/instructions.h](https://github.com/0xADE1A1DE/AssemblyLine/tree/main/src/enums.h) while maintaining alphabetical order  

#### Instruction table format: 
```c
struct INSTR_TABLE[] {
  
  /* null-terminated string representation of an instruction ex: "mov"
   * subsequent instructions of the same name with a different operand
   * encoding will be placed contiguously with the first instance of the
   * instuction and will have the '\0' string
   */
  char instr_name[MAX_INSTR_LEN];

  // asm_instr enumerator for uniquely identifying a instruction
  int name;

  /* contains the valid operand formats for an instruction that maps
   * to the same operand enccoding (at most 2 for a single operand encoding)
   * ex: rr (instr reg,reg) && rm (instr reg, [mem]) -> RM
   */
  int opd_format[VALID_OPERAND_FORMATS];

  /* operand encoding format as an enumerator (determines how instruction
   * operands will be encoded) in assemblyline the 'I' character op/en will be
   * ignored unless it is standalone ex: MI -> M , RMI -> RM , I -> I
   */
  operand_encoding encode_operand;

  /* enumerator for defining the semantic type of an instruction
   * where special encoding is required ( currently, only applicable for 
   * SHIFT, DATA_TRANSFER, and CONTROLFLOW type instructions) 
   * else set this to 'OTHER'
   */
  instr_type type;

  /* 'i' index of opcode[i] when a byte changes in the opcode depending
   * on the register size for the instruction
   * (set this value to NA if not applicable to the instruction)
   */
  int op_offset_i;

  /* 'i' index of opcode[i] when an offset is present for a REG value denoted as
   * '+ rd' in the intel manual section 3.1.1.1 
   * (set this value to NA if not applicable to the instruction)
   */
  int rd_offset_i;

  /* used for instructions with a single register operand denoted as '/digit'
   * in the intel manual section 3.1.1.1
   * (set this value to NA if not applicable to the instruction)
   */
  int single_reg_r;

  // number of bytes in the opcode[MAX_OPCODE_LEN] field
  int instr_size;

  /* displacement for the W0 prefix (following byte after the vector extension prefix VEX)
   * check intel manual section 3.1.1.2
   * (set this value to NA if not applicable to the instruction)
   */
  int w0_disp;

  /* opcode layout for an instruction ex: {REX,0x0f,0xa9,REG}
   * REX and REG are placeholders for the prefix and register values
   * more can be found in enums.h op_encoding
   */
  unsigned int opcode[MAX_OPCODE_LEN];                 
}
```

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
