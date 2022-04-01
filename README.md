# Assemblyline

An ultra-lightweight C library and binary for generating machine code of x86\_64 assembly language and executing on the fly without invoking another compiler, assembler or linker. <br> 
* Support for MMX, SSE2, AVX, and AVX2 instruction sets.
* Supports Scaled Index addressing mode (SIB) with the following syntax:  
`[base + index*scale +\- offset]`, `[base + scale*index +\- offset]`  
`[scale*index +\- offset]`
* Supports pointer: byte, word, dword, qword
* Memory chunk alignment by using nop-padding (similar to gcc).
* Different modes for assembling instructions.  
`NASM`: binary output will match that of nasm as closely as possible (default for SIB).  
`STRICT`: binary output will be in an 'as is' state in respect to the instruction.  
`SMART`: intructions could be manipulated to ensure binary output matches nasm (default).  
please refer to [tools/README.md](/tools/README.md) **Different Modes of Assembly** section for more information
* Easy to use command-line tool `asmline` (refer to [tools/README.md](/tools/README.md)) 
* High instruction compatibility and easy to add new instructions (refer to [src/README.md](src/README.md))    

## How to use

To get a stable release clone the repo from a tag or download the tarball. <br> 
***note: refer to [/src/instructions.c](/src/instructions.c) for a complete list of supported instructions***

1. `$ bash autogen.sh` to generate configure file 
1. `$ ./configure` to generate Makefiles.
1. `$ make` to compile
1. `$ sudo make install` to install it
1. `$ gcc -o executable your_program.c -lassemblyline` to compile a c program using assemblyline<br><br>   

## Example
  
***note: refer to [/src/assemblyline.h](/src/assemblyline.h) or run `$ man libassemblyline` for more information***

1. Include the required header files and preprocessors
    ```c
    #include <stdint.h> // uint8_t
    #include <sys/mman.h> // mmap
    #include <assemblyline.h>
    #define BUFFER_SIZE 300
    ```
1. Allocate an executable buffer of sufficient size (> 20 bytes) using mmap
    ```c
    // the machine code will be written to this location
    uint8_t *mybuffer = mmap(NULL, sizeof(uint8_t) * BUFFER_SIZE,
        PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    ```
1. Create an instance of assemblyline_t and attach `mybuffer` or set it to NULL for internal memory allocation   
   (will `realloc` if the internal buffer size is insufficient)
    ```c
    // external memory allocation
    assemblyline_t al = asm_create_instance(mybuffer, BUFFER_SIZE);
    // internal memory allocation
    assemblyline_t al = asm_create_instance(NULL, 0);
    ```
1. OPTIONAL: Enable debug mode to print the machine code in hex to stdout.
    ```c
    asm_set_debug(al, true);
    ```
1. OPTIONAL: Set a chunk size boundary to ensure that no instruction opcode will cross the specified chunk boundary length.
    **note**: refer to instructions: `nop, nop2, ..., nop11` on [/src/instructions.c](/src/instructions.c)
    ```c
    // It will use the appropriate `nop` instruction for the remaining bytes to fill the chunk boundry.
    int chunk_size = 16;
    asm_set_chunk_size(al, chunk_size);
    ```
1. Assemble a file or string containing x64 assembly code. The machine code will be written to `mybuffer` or the internal buffer.
   You can call those functions sequentially; the new machine code will be appended at the end.
    ```c
    asm_assemble_file(al, "./path/to/x64_file.asm");
    asm_assemble_str(al, "mov rax, 0x0\nadd rax, 0x2; adds two");
    asm_assemble_str(al, "sub rax, 0x1; subs one\nret");
    ```
1. Get the start address of the buffer containing the start of the assembly program
    ```c
    void (*func)() = asm_get_code(al);
    // you can then call the function
    int result = func();
    ```
1. Free all memory associated with assembyline (external buffer is not freed)
    ```c
    asm_destroy_instance(al);
    ```
1. Full example:
    ```c
    #include <stdio.h>
    #include <stdint.h>
    #include <sys/mman.h>
    #include <assemblyline.h>
    #define BUFFER_SIZE 300
    
    int main() {
      uint8_t *mybuffer = mmap(NULL, sizeof(uint8_t) * BUFFER_SIZE,
	  PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    
      assemblyline_t al = asm_create_instance(mybuffer, BUFFER_SIZE); 
    
      asm_set_chunk_size(al, 16); 
    
      asm_assemble_str(al, "mov rax, 0x0\nadd rax, 0x2; adds two");
      asm_assemble_str(al, "sub rax, 0x1; subs one\nret");
 
      int (*func)() = asm_get_code(al);
    
      int result = func();
      printf("The result is: %d\n", result); 
      // prints "The result is: 1\n"

      asm_destroy_instance(al);
    }
    ```
    <br>
## Test files

`$ make check` to run all test suites (repo must be cloned for this to work)

* To run only one testsuite `TESTS=seto.asm make -e check`, then check `./test/seto.log`
* Or run the `./al_nasm_compare.sh seto.asm` in the `test` directory
* Adding a new test: add the testfile e.g. `sub.asm` to the directory and add `sub.asm` to the `TESTS`-variable in `./Makefile.am`
then run `$ make clean check`. Finally, add `Makefile.am` and `sub.asm` to git.<br><br> 

## Command-line tool: asmline

Please refer to: [tools/README.md](/tools/README.md)<br><br>     
  
## Adding new instructions

To add support for new instructions please refer to: [src/README.md](/src/README.md)<br><br>  

## Acknowledgements
#### Authors:
* Chitchanok Chuengsatiansup (University of Adelaide)
* Daniel Genkin (Georgia Tech)
* Joel Kuepper (University of Adelaide)
* Markus Wagner (University of Adelaide)
* David Wu (University of Adelaide)  
* Yuval Yarom (University of Adelaide)


#### This project was supported by:  
* The Air Force Office of Scientific Research (AFOSR) under award number FA9550-20-1-0425
* An ARC Discovery Early Career Researcher Award (project number DE200101577) 
* An ARC Discovery Project (project number DP210102670)  
* The Blavatnik ICRC at Tel-Aviv University  
* the Defense Advanced Research Projects Agency (DARPA) and Air Force Research Laboratory (AFRL) under contracts FA8750-19-C-0531 and HR001120C0087
* the National Science Foundation under grant CNS-1954712
* Gifts from AMD, Google, and Intel  
