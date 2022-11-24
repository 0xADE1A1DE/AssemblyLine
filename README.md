# AssemblyLine
![Unit Tests](https://github.com/0xADE1A1DE/AssemblyLine/actions/workflows/c-check.yml/badge.svg)
![Code Style](https://github.com/0xADE1A1DE/AssemblyLine/actions/workflows/clang-format-check.yml/badge.svg)
![Version](https://img.shields.io/github/v/release/0xADE1A1DE/AssemblyLine?logo=github&style=flat)
![AUR Version](https://img.shields.io/aur/version/assemblyline-bin?logo=github&style=flat)



An ultra-lightweight C library and binary for generating machine code of x86\_64 assembly language and executing on the fly without invoking another compiler, assembler or linker.

* Easy to use C library `libassemblyline`.
* Print or run assembly code with our cli tool `asmline` (see [tools/README.md](/tools/README.md)) 
* Support for MMX, SSE2, AVX, and AVX2 instruction sets.
* Supports Scaled Index addressing mode (SIB) with the following syntax:  
`[base + index*scale +\- offset]`, `[base + scale*index +\- offset]`  
`[scale*index +\- offset]`, `[constant]`
* Supports pointer: byte, word, dword, and qword
* Supports multi-length nop instructions (by using `nop{2..11}` as the instruction)  
  see [test/nop.asm](test/nop.asm) for more information
* Supports jump instructions without labels: short, long, and far
* Memory chunk alignment by using nop-padding.
* Command line completion (zsh, bash) for `asmline`
* Different modes for assembling instructions.  
`NASM`: binary output will match that of nasm as closely as possible (default for SIB).  
`STRICT`: binary output will be in an 'as is' state in respect to the instruction.  
`SMART`: instructions could be manipulated to ensure binary output matches nasm (default).  
  See [tools/README.md](/tools/README.md) **Different Modes of Assembly** section for more information
* `man`-pages for `asmline` and `libassemblyline`
* High instruction compatibility and easy to add new instructions (see [src/README.md](src/README.md), and [/src/instructions.c](src/instructions.c) for a list of supported instructions.   

## How to Install

We have packages in the [AUR](https://aur.archlinux.org/packages/assemblyline-bin).<br>
Otherwise clone this repo or get a [stable release tarball](https://github.com/0xADE1A1DE/AssemblyLine/releases). <br> 

```bash
$ ./autogen.sh # when `git clone`d
$ ./configure && \
make  && \
sudo make install
```
## Usage

1. `$ cc your_program.c -lassemblyline` to use the library and compile a C program using assemblyline<br><br>   
1. `$ echo -e "mov rax, 0xADE1A1DE\nret" | asmline -r` to use our asmline-cli tool<br> (Will print 'the value is 0xade1a1de')<br>


## Jumpstart library
  
Full code example:<br>
```c
#include <assemblyline.h> // all assemblyline functions
#include <stdint.h>       // uint8_t
#include <stdio.h>        // printf
#include <sys/mman.h>     // mmap

int main() {
  const int buffer_size = 300; // bytes
  uint8_t *mybuffer = mmap(NULL, sizeof(uint8_t) * buffer_size,
                           PROT_READ | PROT_WRITE | PROT_EXEC,
                           MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

  assemblyline_t al = asm_create_instance(mybuffer, buffer_size);

  asm_assemble_str(al, "mov rax, 0x0\nadd rax, 0x2; adds two");
  asm_assemble_str(al, "sub rax, 0x1; subs one\nret");

  int (*func)() = asm_get_code(al);

  int result = func();
  printf("The result is: %d\n", result);
  // prints "The result is: 1\n"

  asm_destroy_instance(al);
  munmap(mybuffer, buffer_size);
}
```

Lets dissect the example (and give alternatives):

1. Include the required header files and preprocessors
    ```c
    #include <assemblyline.h> // all assemblyline functions
    #include <stdint.h>       // uint8_t
    #include <stdio.h>        // printf
    #include <sys/mman.h>     // mmap
    ```
1. Allocate an executable buffer of sufficient size (> 20 bytes) using mmap
    ```c
    // the machine code will be written to this location
   const int buffer_size = 300; // bytes
   uint8_t *mybuffer = mmap(NULL, sizeof(uint8_t) * buffer_size,
                            PROT_READ | PROT_WRITE | PROT_EXEC,
                            MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    ```
1. Create an instance of assemblyline\_t and attach `mybuffer` (or `NULL, 0` for internal memory allocation)
    ```c
    // manual memory allocation
    assemblyline_t al = asm_create_instance(mybuffer, buffer_size);

    // assemblyline-managed memory allocation
    assemblyline_t al = asm_create_instance(NULL, 0);
    ```

1. Assemble a file or string containing. The machine code will be written to `mybuffer` (or the internal buffer).
   Call those functions sequentially; subsequent new machine code will be appended at the end of the last instruction.
   Separate instructions with `\n`.
    ```c
    asm_assemble_file(al, "./path/to/x64_file.asm");
    asm_assemble_str(al, "mov rax, 0x0\nadd rax, 0x2; adds two");
    asm_assemble_str(al, "sub rax, 0x1; subs one\nret");
    ```
1. Get the start address of the buffer containing the start of the assembly program
    ```c
    void (*func)() = asm_get_code(al);

    // call the function
    int result = func();
    ```
1. Free all memory associated with assembyline (an external buffer is not freed)
    ```c
    asm_destroy_instance(al);
    munmap(mybuffer, buffer_size);
    ```
    <br>

**Note: for more information see [/src/assemblyline.h](/src/assemblyline.h) or run `$ man libassemblyline` for more information**

## Jumpstart Cli-tool: asmline

The general usage is `asmline [OPTIONS]... FILE`. `asmline --help` for all options.

```asm
; jump.asm
mov rcx, 0x123
jmp 0x4
add rcx, 1
mov rax, rcx
ret
```
Use `-p` for printing ASCII-hex to `stdout`

```bash
$ asmline -p jump.asm
b9 23 01 00 00 
eb 04 
48 83 c1 01 
48 89 c8 
c3 
```
Or pipe directly into it, use `-r` to run the code:
```bash
$ echo -n 'mov rax, 0xC0FFEE\nret' | asmline -pr
b8 ee ff c0 00 
c3 

# the value is 0xc0ffee
```

See [tools/README.md](/tools/README.md) for more info.<br><br>     

## Adding new instructions

To add support for new instructions see [src/README.md](/src/README.md) for more info.<br><br>  

## Test files

`$ make check` to run all test suites (repo must be cloned for this to work)

* To run only one test suite `TESTS=seto.asm make -e check`, then check `./test/seto.log`
* Or run the `./al_nasm_compare.sh seto.asm` in the `test` directory
* Adding a new test: add the test file e.g. `sub.asm` to the directory and add `sub.asm` to the `TESTS`-variable in `./Makefile.am`
then run `$ make clean check`. Finally, add `Makefile.am` and `sub.asm` to git.<br><br> 

  
## Contributing

We welcome any kind of contribution. Feel free to open issues if something is broken or you'd need feature. Or open up a PR if you've enhanced AssemblyLine already and want to see it here.

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
* Data61, CSIRO
* the Defense Advanced Research Projects Agency (DARPA) and Air Force Research Laboratory (AFRL) under contracts FA8750-19-C-0531 and HR001120C0087
* the National Science Foundation under grant CNS-1954712
* Gifts from AMD, Google, and Intel  
