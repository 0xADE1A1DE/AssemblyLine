/**
 * Copyright 2021 University of Adelaide
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

/**
 * commandline-tool for generating and optionally executing machine code from a
 * x64 assembly string/file
 */
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

enum run { DONT_RUN, RUN, RUN_WITH_ARG };

const char *asm_version = PACKAGE_STRING;

void err_print_usage(char *error_msg) {
  fprintf(
      stderr,
      "%s\nUsage: asmline [-r] [-p] [-c CHUNK_SIZE>1] [-o "
      "ELF_FILENAME_NO_EXT] [-h] [-v] path/to/file.asm\n\n"
      "  -r, --return\n"
      "\tExecutes assembly code and prints out the contents of the rax "
      "register (return register)\n\n"
      "  -p, --print\n"
      "\tWhen assembling path/to/file.asm the corresponding machine code "
      "will be printed to stdout.\n\n"
      "  -c, --chunk CHUNK_SIZE>1\n"
      "\tSets a given CHUNK_SIZE boundary in bytes. Nop padding will be used "
      "to ensure no instruction\n"
      "\topcode will cross the specified CHUNK_SIZE "
      "boundary.\n\n"
      "  -o, --object FILENAME\n"
      "\tGenerates a binary file from path/to/file.asm called "
      "FILENAME.bin in the current directory.\n\n"
      "  -h, --help\n"
      "\tPrints usage information to stdout and exits.\n\n"
      "  -v, --version\n"
      "\tPrints version information to stdout and exits.\n\n",
      error_msg);
  exit(EXIT_FAILURE);
}

void print_version() {

  printf("%s\n"
         "Copyright 2021 University of Adelaide\n\n"
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

int create_bin_file(assemblyline_t al, char *file_name) {

  FILE *write_ptr = fopen(strcat(file_name, ".bin"), "wb");

  if (write_ptr == NULL)
    return EXIT_FAILURE;

  fwrite(asm_get_buffer(al), sizeof(uint8_t), asm_get_offset(al), write_ptr);
  fclose(write_ptr);

  return EXIT_SUCCESS;
}

void execute_get_ret_value(void *function, long *arguments[]) {

  long result = 0;
  if (arguments == NULL) {
    long (*f)() = function;
    result = f();
  } else {
    long (*f)(long *, long *, long *, long *, long *, long *) = function;
    result = f(arguments[0], arguments[1], arguments[2], arguments[3],
               arguments[4], arguments[5]);
  }
  printf("\nthe value is 0x%lx\n", result);
}

int main(int argc, char *argv[]) {

  int opt, create_bin = 0;
  enum run get_ret = DONT_RUN;
  int chunk_size;
  char *write_file = NULL;
  long *arguments[6];
  int argnum = 0;
  int arglen = 0;

  static struct option long_options[] = {/* These options set a flag. */
                                         {"version", no_argument, 0, 'v'},
                                         {"help", no_argument, 0, 'h'},
                                         {"return", no_argument, 0, 'r'},
                                         {"argument", no_argument, 0, 'a'},
                                         {"len", no_argument, 0, 'l'},
                                         {"num", no_argument, 0, 'n'},
                                         {"print", no_argument, 0, 'p'},
                                         {"chunk", required_argument, 0, 'c'},
                                         {"object", required_argument, 0, 'o'},
                                         {0, 0, 0, 0}};

  /* getopt_long stores the option index here. */
  int option_index = 0;

  if (argc < 2 && isatty(fileno(stdin)))
    err_print_usage("Error: invalid number of arguments\n");

  assemblyline_t al = asm_create_instance(NULL, 0);
  while ((opt = getopt_long(argc, argv, "hvral:n:pc:o:", long_options,
                            &option_index)) != -1) {
    switch (opt) {

    case 'v':
      print_version();
      break;

    case 'h':
      err_print_usage("");
      break;

    case 'l':
      if (check_digit(optarg))
        goto err_len;
      arglen = atoi(optarg);
      if (arglen > 0)
        break;
    err_len:
      err_print_usage(
          "Error: [-l LEN] expects an integer. Will call "
          "functon with (a[LEN], b[LEN], ... NUM[LEN]). NUM must be <=6.\n");
      break;

    case 'n':
      if (check_digit(optarg))
        goto err_num;
      argnum = atoi(optarg);
      if (argnum > 0 || argnum <= 6)
        break;
    err_num:
      err_print_usage(
          "Error: [-n NUM] expects an integer 0 < NUM <= 6. Will call "
          "functon with (a[LEN], b[LEN], ... NUM[LEN])..\n");
      break;

    case 'a':
      get_ret = RUN_WITH_ARG;
      break;

    case 'r':
      get_ret = RUN;
      break;

    case 'p':
      asm_set_debug(al, true);
      break;

    case 'c':
      if (check_digit(optarg))
        err_print_usage("Error: [-c CHUNK_SIZE>1] expects an integer\n");
      chunk_size = atoi(optarg);
      asm_set_chunk_size(al, chunk_size);
      break;

    case 'o':
      if (strchr(optarg, '.'))
        err_print_usage("elf filename cannot have an extension\n");
      create_bin = 1;
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

  long (*func)() = asm_get_code(al);

  switch (get_ret) {
  case RUN:
    execute_get_ret_value(func, NULL);
    break;
  case RUN_WITH_ARG:
    if (argnum < 1 || arglen < 1) {
      fprintf(stderr, "invalid combination of -a -l -n\n");
      exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (int i = 0; i < 6; i++) {
      arguments[i] = malloc(arglen * sizeof(long));
      for (int j = 0; j < arglen; j++) {
        arguments[i][j] = rand() | ((long)rand()) >> 32;
      }
    }

    fprintf(stderr, "num: %d, len:%d\n", argnum, arglen);
    execute_get_ret_value(func, arguments);

    for (int i = 0; i < argnum; i++) {
      free(arguments[i]);
    }
    break;
  default:
    // intentionally blank
    break;
  }

  if (create_bin) {
    if (create_bin_file(al, write_file) == EXIT_FAILURE) {
      fprintf(stderr, "failed to create test.bin\n");
      exit(EXIT_FAILURE);
    }
  }

  exit(EXIT_SUCCESS);
}
