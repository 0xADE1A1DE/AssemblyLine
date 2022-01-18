/**
 * Copyright 2022 University of Adelaide
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*command-tool for generating machine code from a x64 assembly file*/
#include <assemblyline.h>
#if HAVE_CONFIG_H
#include <config.h> // from autotools
#endif
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char *asm_version = PACKAGE_STRING;

void err_print_usage(char *error_msg) {
  fprintf(
      stderr,
      "%s\nUsage: asmline "
      "[-r] [-R LEN] [-p] [-P FILENAME] [-o FILENAME_NO_EXT] [-c CHUNK_SIZE>1] "
      "[-n] [-t] [-s] [-h] [-v] "
      "[path/to/file.asm]\n\n"
      "  -r, --return\n"
      "\tAssembles given code. Then executes it with six parameters to "
      "heap-allocated memory.\n\tEach pointer points to an array of ten 64-bit "
      "elements which can be dereferenced in the asmcode.\n\tAfter execution, "
      "it prints out the contents of the return (rax) register and frees the "
      "heap-memory.\n\n"
      "  -R LEN, --Return LEN\n"
      "\tlike -r, but allocates LEN elements instead of 10.\n\n"
      "  -p, --print\n"
      "\tThe corresponding machine code will be printed to stdout in hex "
      "form.\n"
      "\tOutput is similar to `objdump`: Byte-wise delimited by space and "
      "linebreaks after 7 bytes.\n\tIf -c is given, the chunks are "
      "delimited by '|' and each chunk is on one line.\n\n"
      "  -P, --printfile FILENAME\n"
      "\tThe corresponding machine code will be printed to FILENAME in binary "
      "form.\n\tCan be set to '/dev/stdout' to write to stdout.\n\n"
      "  -o, --object FILENAME\n"
      "\tThe corresponding machine code will be printed to FILENAME.bin in "
      "binary.\n\n"
      "  -c, --chunk CHUNK_SIZE>1\n"
      "\tSets a given CHUNK_SIZE boundary in bytes. Nop padding will be used "
      "to ensure no instruction\n"
      "\topcode will cross the specified CHUNK_SIZE boundary.\n\n"
      "  -n, --nasm\n"
      "\tEnables nasm-style mov-immediate register-size optimization.\n"
      "\tex: if immediate size for mov is less than or equal to max "
      "signed 32 bit assemblyline\n"
      "\t    will emit code to mov to the 32-bit register rather than 64-bit.\n"
      "\tThat is: \"mov rax,0x7fffffff\" as \"mov eax,0x7fffffff\" "
      "-> b8 ff ff ff 7f\n"
      "\tnote: rax got optimized to eax for faster immediate to register "
      "transfer\n"
      "\t      and produces a shorter instruction\n\n"
      "  -t, --strict\n"
      "\tDisables nasm-style mov-immediate register-size optimization.\n"
      "\tex: even if immediate size for mov is less than or equal to max "
      "signed 32 bit assemblyline.\n"
      "\t    will pad the immediate to fit 64-bit\n"
      "\tThat is: \"mov rax,0x7fffffff\" as \"mov rax,0x000000007fffffff\"\n"
      "\t          -> 48 b8 ff ff ff 7f 00 00 00 00\n\n"
      "  -s, --smart\n"
      "\tThe immediate value will be checked for leading 0's.\n"
      "\tImmediate must be zero padded to 64-bits exactly to ensure\n"
      "\tit will not optimize. This is currently set as default.\n"
      "\tex: \"mov rax, 0x000000007fffffff\" ->  48 b8 ff ff ff 7f 00 00 00 "
      "00\n"
      "\t    \"mov rax, 0x7fffffff\" -> b8 ff ff ff 7f\n\n"
      "  -h, --help\n"
      "\tPrints usage information to stdout and exits.\n\n"
      "  -v, --version\n"
      "\tPrints version information to stdout and exits.\n\n",
      error_msg);
  exit(EXIT_FAILURE);
}

void print_version() {

  printf("%s\n"
         "Copyright 2022 University of Adelaide\n\n"
         "Licensed under the Apache License, Version 2.0 (the \"License\");\n"
         "You may obtain a copy of the License at\n\n"
         "\thttp://www.apache.org/licenses/LICENSE-2.0\n\n"
         "Unless required by applicable law or agreed to in writing, software\n"
         "distributed under the License is distributed on an \"AS IS\" BASIS,\n"
         "WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or "
         "implied.\n"
         "See the License for the specific language governing permissions and\n"
         "limitations under the License.\n\n"
         "Written by David Wu and Joel Kuepper\n",
         asm_version);
  exit(EXIT_SUCCESS);
}

int check_digit(char *optarg) {
  int len = strlen(optarg);
  for (int i = 0; i < len; i++)
    if (optarg[i] < '0' || optarg[i] > '9')
      return EXIT_FAILURE;
  return EXIT_SUCCESS;
}

int create_bin_file(assemblyline_t al, const char *file_name) {
  void *buffer = asm_get_buffer(al);
  int len = asm_get_offset(al);
  FILE *write_ptr = fopen(file_name, "wb");

  if (write_ptr == NULL)
    return EXIT_FAILURE;

  fwrite(buffer, sizeof(uint8_t), len, write_ptr);

  fclose(write_ptr);

  return EXIT_SUCCESS;
}
void execute_get_ret_value(void *function, int arglen) {
  uint64_t *arguments[6];

  uint64_t result = 0;
  if (arglen == 0) {
    uint64_t (*f)() = function;
    result = f();
  } else {
    // allocate 6 args with arglen uint64_t's
    for (int i = 0; i < 6; i++) {
      arguments[i] = malloc(arglen * sizeof(uint64_t));
    }
    // cast
    uint64_t (*f)(uint64_t *, uint64_t *, uint64_t *, uint64_t *, uint64_t *,
                  uint64_t *) = function;
    // call
    result = f(arguments[0], arguments[1], arguments[2], arguments[3],
               arguments[4], arguments[5]);
    // free args
    for (int i = 0; i < 6; i++) {
      free(arguments[i]);
    }
  }
  printf("\nthe value is 0x%lx\n", result);
}

enum OUTPUT { NONE, BIN_FILE, GENERIC_FILE };
enum run { DONT_RUN, RUN };

int main(int argc, char *argv[]) {

  int opt;
  enum OUTPUT create_bin = NONE;
  char *write_file = NULL;

  // for running (with arguments)
  enum run get_ret = DONT_RUN;
  int arglen = 10;

  static struct option long_options[] = {
      /* These options set a flag. */
      {"version", no_argument, 0, 'v'},
      {"help", no_argument, 0, 'h'},
      {"return", no_argument, 0, 'r'},
      {"Return", no_argument, 0, 'R'},
      {"print", no_argument, 0, 'p'},
      {"printfile", required_argument, 0, 'P'},
      {"nasm", no_argument, 0, 'n'},
      {"strict", no_argument, 0, 't'},
      {"smart", no_argument, 0, 's'},
      {"chunk", required_argument, 0, 'c'},
      {"object", required_argument, 0, 'o'},
      {0, 0, 0, 0}};

  /* getopt_long stores the option index here. */
  int option_index = 0;

  if (argc < 2 && isatty(fileno(stdin)))
    err_print_usage("Error: invalid number of arguments\n");

  assemblyline_t al = asm_create_instance(NULL, 0);
  while ((opt = getopt_long(argc, argv, "hvrR:ntspP:c:o:", long_options,
                            &option_index)) != -1) {
    switch (opt) {
    case 'v':
      print_version();
      break;
    case 'h':
      err_print_usage("");
      break;
    case 'R':
      if (check_digit(optarg)) {
        arglen = atoi(optarg);
      }
    case 'r':
      get_ret = RUN;
      break;
    case 'p':
      asm_set_debug(al, true);
      break;
    case 'n':
      nasm_mov_imm_handling(al);
      break;
    case 't':
      strict_mov_imm_handling(al);
      break;
    case 's':
      smart_mov_imm_handling(al);
      break;
    case 'c':
      if (check_digit(optarg))
        err_print_usage("Error: [-c CHUNK_SIZE>1] expects an integer\n");
      int chunk_size = atoi(optarg);
      asm_set_chunk_size(al, chunk_size);
      break;
    case 'P':
      create_bin = GENERIC_FILE;
      write_file = optarg;
      break;
    case 'o':
      if (strchr(optarg, '.'))
        err_print_usage("elf filename cannot have an extension\n");
      create_bin = BIN_FILE;
      write_file = optarg;
      break;

    default: /* '?' */
      err_print_usage("");
    }
  }

  if (optind >= argc) {
    // check is stdin is provided via pipe
    if (!isatty(fileno(stdin))) {
      char *line = NULL;
      size_t size = 100;
      while (getline(&line, &size, stdin) != -1) {
        if (assemble_str(al, line) == EXIT_FAILURE) {
          fprintf(stderr, "failed to assemble instruction: %s\n", line);
          exit(EXIT_FAILURE);
        }
      }
      free(line);
    } else {
      err_print_usage("Error: Expected path/to/file.asm after options\n");
    }
  } else {
    if (assemble_file(al, argv[optind]) == EXIT_FAILURE) {
      fprintf(stderr, "failed to assemble file: %s\n", argv[optind]);
      exit(EXIT_FAILURE);
    }
  }

  if (get_ret == RUN) {
    void *func = asm_get_code(al);
    execute_get_ret_value(func, arglen);
  }

  switch (create_bin) {
  case NONE:
    break;
  case BIN_FILE: {
    const char *filename = strcat(write_file, ".bin");
    if (create_bin_file(al, filename) == EXIT_FAILURE) {
      fprintf(stderr, "failed to create %s\n", filename);
      exit(EXIT_FAILURE);
    }
    break;
  }
  case GENERIC_FILE: {
    if (create_bin_file(al, write_file) == EXIT_FAILURE) {
      fprintf(stderr, "failed to create %s\n", write_file);
      exit(EXIT_FAILURE);
    }
  }
  }

  exit(EXIT_SUCCESS);
}
