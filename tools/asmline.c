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
#include <time.h>
#include <unistd.h>

#define DEFAULT_ARG_LEN 10
#define BUFFER_SIZE 100
enum OUTPUT { NONE, BIN_FILE, GENERIC_FILE };
enum run { DONT_RUN = 0, RUN = 1, RUN_RAND = 2 };

typedef enum {

  NASM_MOV_IMM = 128,
  STRICT_MOV_IMM,
  NASM_SIB,
  STRICT_SIB,
  NASM_SIB_INDEX_BASE_SWAP,
  STRICT_SIB_INDEX_BASE_SWAP,
  NASM_SIB_NO_BASE,
  STRICT_SIB_NO_BASE,
  SMART_MOV_IMM
} asm_options;

const char *asm_version = PACKAGE_STRING;
static int mov_imm = 0;
static int sib_all = 0;
static int sib_swap = 0;
static int sib_no_base = 0;

void err_print_usage(char *error_msg) {
  fprintf(
      stderr,
      "%s\nUsage: asmline "
      "[OPTIONS]... path/to/file.asm\n\n"

      "  -r[=LEN], --return[=LEN]\n"
      "\tAssembles given code. Then executes it with six parameters to "
      "heap-allocated memory.\n\tEach pointer points to an array of LEN 64-bit "
      "elements which can be dereferenced \n\tin the asm-code, where LEN "
      "defaults "
      "to 10.\n\tAfter execution, it prints out the contents of the return "
      "(rax) register and frees  \n\tthe heap-memory.\n\n"

      "  --rand \n"
      "\tImplies -r and will additionally initialize the memory from with "
      "random data. \n\t-r=11 can be used to alter LEN.\n\n"

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

      "  -b, --breaks CHUNK_BOUNDARY>1\n"
      "\tGiven a CHUNK_BOUNDARY, counts the number of instructions where\n"
      "\ttheir opcode crosses the specified CHUNK_BOUNDARY size in bytes.\n\n"

      "  --nasm-mov-imm\n"
      "\tEnables nasm-style mov-immediate register-size handling.\n"
      "\tex: if immediate size for mov is less than or equal to max "
      "signed 32 bit assemblyline\n"
      "\t    will emit code to mov to the 32-bit register rather than 64-bit.\n"
      "\tThat is: \"mov rax,0x7fffffff\" as \"mov eax,0x7fffffff\" "
      "-> b8 ff ff ff 7f\n"
      "\tnote: rax got optimized to eax for faster immediate to register "
      "transfer\n"
      "\t      and produces a shorter instruction\n\n"

      "  --strict-mov-imm\n"
      "\tDisables nasm-style mov-immediate register-size handling.\n"
      "\tex: even if immediate size for mov is less than or equal to max "
      "signed 32 bit assemblyline.\n"
      "\t    will pad the immediate to fit 64-bit\n"
      "\tThat is: \"mov rax,0x7fffffff\" as \"mov rax,0x000000007fffffff\"\n"
      "\t          -> 48 b8 ff ff ff 7f 00 00 00 00\n\n"

      "  --smart-mov-imm\n"
      "\tThe immediate value will be checked for leading 0's.\n"
      "\tImmediate must be zero padded to 64-bits exactly to ensure\n"
      "\tit will not optimize. This is currently set as default.\n"
      "\tex: \"mov rax, 0x000000007fffffff\" ->  48 b8 ff ff ff 7f 00 00 00 "
      "00\n\n"

      "  --nasm-sib-index-base-swap\n"
      "\tIn SIB addressing if the index register is esp or rsp then\n"
      "\tthe base and index registers will be swapped.\n"
      "\tThat is: \"lea r15, [rax+rsp]\" -> \"lea r15, [rsp+rax]\"\n\n"
      "  --strict-sib-index-base-swap\n"
      "\tIn SIB addressing the base and index registers will not be swapped\n"
      "\teven if the index register is esp or rsp.\n\n"

      "  --nasm-sib-no-base\n"
      "\tIn SIB addressing if there is no base register present and scale\n"
      "\tis equal to 2; the base register will be set to the index register\n"
      "\tand the scale will be reduced to 1.\n"
      "\tThat is: \"lea r15, [2*rax]\" -> \"lea r15, [rax+1*rax]\"\n\n"
      "  --strict-sib-no-base\n"
      "\tIn SIB addressing when there is no base register present the index\n"
      "\tand scale would not change regardless of scale value.\n"
      "\tThat is: \"lea r15, [2*rax]\" -> \"lea r15, [2*rax]\"\n\n"

      "  --nasm-sib\n"
      "\tequivalent to --nasm-sib-index-base-swap --nasm-sib-no-base\n\n"
      "  --strict-sib\n"
      "\tequivalent to --strict-sib-index-base-swap --strict-sib-no-base\n\n"

      "  -n, --nasm\n"
      "\tequivalent to --nasm-mov-imm --nasm-sib\n\n"

      "  -t, --strict\n"
      "\tequivalent to --strict-mov-imm --strict-sib\n\n"

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

void print_chunk_brks(int total_chunk_brks, bool debug, int chunk_boundary) {

  printf("%d", total_chunk_brks);
  if (debug)
    printf(" instructions break a chunk boundary of %d bytes", chunk_boundary);
  printf("\n");
}

void execute_get_ret_value(void *function, int arglen, enum run mode) {
  uint64_t *arguments[6];

  uint64_t result = 0;
  if (arglen == 0) {
    uint64_t (*f)() = function;
    result = f();
  } else {
    // allocate 6 args with arglen uint64_t's
    for (int arg_idx = 0; arg_idx < 6; arg_idx++) {
      arguments[arg_idx] = calloc(arglen, sizeof(uint64_t));
      if (mode & RUN_RAND)
        for (int qword_idx = 0; qword_idx < arglen; qword_idx++) {

          uint64_t rand_val = rand();           // lo_limb
          rand_val |= ((uint64_t)rand()) << 32; // hi_limb
          arguments[arg_idx][qword_idx] = rand_val;
        }
    }
    // cast
    uint64_t (*f)(uint64_t *, uint64_t *, uint64_t *, uint64_t *, uint64_t *,
                  uint64_t *) = function;
    // call
    result = f(arguments[0], arguments[1], arguments[2], arguments[3],
               arguments[4], arguments[5]);
    // free args
    for (int i = 0; i < 6; i++)
      free(arguments[i]);
  }
  printf("\nthe value is 0x%lx\n", result);
}

int main(int argc, char *argv[]) {

  int opt;
  enum OUTPUT create_bin = NONE;
  char bin_ext[] = ".bin";
  char *param_file = NULL;
  char *bin_file = NULL;
  char *write_file = NULL;
  int chunk_boundary = 0;
  int total_chunk_brks = 0;
  bool debug = false;

  // for running (with arguments)
  enum run get_ret = DONT_RUN;
  int arglen = DEFAULT_ARG_LEN;

  struct option long_options[] = {
      /* These options set a flag. */
      {"nasm-mov-imm", no_argument, &mov_imm, NASM_MOV_IMM},
      {"strict-mov-imm", no_argument, &mov_imm, STRICT_MOV_IMM},
      {"smart-mov-imm", no_argument, &mov_imm, SMART_MOV_IMM},
      {"nasm-sib", no_argument, &sib_all, NASM_SIB},
      {"strict-sib", no_argument, &sib_all, STRICT_SIB},
      {"nasm-sib-index-base-swap", no_argument, &sib_swap,
       NASM_SIB_INDEX_BASE_SWAP},
      {"strict-sib-index-base-swap", no_argument, &sib_swap,
       STRICT_SIB_INDEX_BASE_SWAP},
      {"nasm-sib-no-base", no_argument, &sib_no_base, NASM_SIB_NO_BASE},
      {"strict-sib-no-base", no_argument, &sib_no_base, STRICT_SIB_NO_BASE},
      {"version", no_argument, 0, 'v'},
      {"help", no_argument, 0, 'h'},
      {"rand", no_argument, (int *)&get_ret, RUN_RAND},
      {"return", optional_argument, 0, 'r'},
      {"print", no_argument, 0, 'p'},
      {"printfile", required_argument, 0, 'P'},
      {"nasm", no_argument, 0, 'n'},
      {"strict", no_argument, 0, 't'},
      {"smart", no_argument, 0, 's'},
      {"chunk", required_argument, 0, 'c'},
      {"breaks", required_argument, 0, 'b'},
      {"object", required_argument, 0, 'o'},
      {0, 0, 0, 0}};

  /* getopt_long stores the option index here. */
  int option_index = 0;

  if (argc < 2 && isatty(fileno(stdin)))
    err_print_usage("Error: invalid number of arguments\n");

  assemblyline_t al = asm_create_instance(NULL, 0);
  while ((opt = getopt_long(argc, argv, "hvr::ntspP:c:b:o:", long_options,
                            &option_index)) != -1) {
    switch (opt) {
    case 0:
      // intentionally blank for the options with implicit flag setting by
      // getopt_long, like --rand
      break;
    case 'v':
      print_version();
      break;
    case 'h':
      err_print_usage("");
      break;
    case 'r':
      // if there is a optional argument, try to parse it and set the arg len
      if (optarg && !check_digit(optarg))
        arglen = atoi(optarg);
      get_ret |= RUN;
      break;
    case 'p':
      debug = true;
      asm_set_debug(al, true);
      break;
    case 'n':
      asm_set_all(al, NASM);
      break;
    case 't':
      asm_set_all(al, STRICT);
      break;
    case 's':
      asm_set_all(al, SMART);
      break;
    case 'c':
      if (check_digit(optarg))
        err_print_usage("Error: [-c CHUNK_SIZE>1] expects an integer\n");
      int chunk_size = atoi(optarg);
      asm_set_chunk_size(al, chunk_size);
      break;

    case 'b':
      if (check_digit(optarg))
        err_print_usage("Error: [-b CHUNK_BOUNDARY>1] expects an integer\n");
      chunk_boundary = atoi(optarg);
      break;

    case 'P':
      create_bin = GENERIC_FILE;
      param_file = optarg;
      break;
    case 'o':
      if (strchr(optarg, '.'))
        err_print_usage("elf filename cannot have an extension\n");
      create_bin = BIN_FILE;
      param_file = optarg;
      break;

    default: /* '?' */
      if (mov_imm || sib_swap || sib_no_base || sib_all)
        break;
      err_print_usage("");
    }
  }

  switch (mov_imm) {
  case 0:
    break;
  case NASM_MOV_IMM:
    asm_mov_imm(al, NASM);
    break;
  case STRICT_MOV_IMM:
    asm_mov_imm(al, STRICT);
    break;
  case SMART_MOV_IMM:
    asm_mov_imm(al, SMART);
    break;
  default:
    break;
  }

  switch (sib_swap) {
  case 0:
    break;
  case NASM_SIB_INDEX_BASE_SWAP:
    asm_sib_index_base_swap(al, NASM);
    break;
  case STRICT_SIB_INDEX_BASE_SWAP:
    asm_sib_index_base_swap(al, STRICT);
    break;
  default:
    break;
  }

  switch (sib_no_base) {
  case 0:
    break;
  case NASM_SIB_NO_BASE:
    asm_sib_no_base(al, NASM);
    break;
  case STRICT_SIB_NO_BASE:
    asm_sib_no_base(al, STRICT);
    break;
  default:
    break;
  }

  switch (sib_all) {
  case 0:
    break;
  case NASM_SIB:
    asm_sib_no_base(al, NASM);
    asm_sib_index_base_swap(al, NASM);
    break;
  case STRICT_SIB:
    asm_sib_no_base(al, STRICT);
    asm_sib_index_base_swap(al, STRICT);
    break;
  default:
    break;
  }

  if (optind >= argc) {
    // check is stdin is provided via pipe
    if (!isatty(fileno(stdin))) {
      char *line = NULL;
      size_t size = BUFFER_SIZE;
      if (!chunk_boundary) {
        while (getline(&line, &size, stdin) != -1) {
          if (asm_assemble_str(al, line)) {
            fprintf(stderr, "failed to assemble instruction: %s\n", line);
            exit(EXIT_FAILURE);
          }
        }
      } else {
        while (getline(&line, &size, stdin) != -1) {
          int chunk_brks = 0;
          if (asm_assemble_string_counting_chunks(al, line, chunk_boundary,
                                                  &chunk_brks)) {
            fprintf(stderr, "failed to assemble instruction: %s\n", line);
            exit(EXIT_FAILURE);
          }
          total_chunk_brks += chunk_brks;
        }
        print_chunk_brks(total_chunk_brks, debug, chunk_boundary);
      }
      free(line);
    } else
      err_print_usage("Error: Expected path/to/file.asm after options\n");
  } else {
    if (!chunk_boundary) {
      if (asm_assemble_file(al, argv[optind])) {
        fprintf(stderr, "failed to assemble file: %s\n", argv[optind]);
        exit(EXIT_FAILURE);
      }
    } else {
      if (asm_assemble_file_counting_chunks(al, argv[optind], chunk_boundary,
                                            &total_chunk_brks)) {
        fprintf(stderr, "failed to assemble file: %s\n", argv[optind]);
        exit(EXIT_FAILURE);
      }
      print_chunk_brks(total_chunk_brks, debug, chunk_boundary);
    }
  }

  if (get_ret != DONT_RUN) {
    // initialize the randomiser if needed
    if (get_ret & RUN_RAND)
      srand(time(NULL));
    void *func = asm_get_code(al);
    execute_get_ret_value(func, arglen, get_ret);
  }

  switch (create_bin) {
  case NONE:
    exit(EXIT_SUCCESS);
    break;
  case BIN_FILE: {
    size_t bin_file_len = strlen(param_file) + strlen(bin_ext) + 1;
    bin_file = calloc(bin_file_len, sizeof(char));
    sprintf(bin_file, "%s%s", param_file, bin_ext);
    write_file = bin_file;
  } break;
  case GENERIC_FILE:
    write_file = param_file;
    break;
  }
  if (asm_create_bin_file(al, write_file)) {
    fprintf(stderr, "failed to create %s\n", param_file);
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}