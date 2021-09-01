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

/*assembles file argv[1] and prints machinecode linewise per instruction.*/
#include <assemblyline.h>

#include <fcntl.h> //open
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr,
            "\nUSAGE:\n\t%s file.asm"
            "\n\nDESCRIPTION:\n\t"
            "accepts file.asm as parameter, will print out hex of "
            "the assembled machinecode, to compare with nasm list output.\n",
            argv[0]);
    return 1;
  }

  assemblyline_t al = asm_create_instance(NULL, 0);

  FILE *in_file = fopen(argv[1], "r");

  struct stat sb;
  stat(argv[1], &sb);

  char *file_contents = malloc(sb.st_size);

  while (fscanf(in_file, "%[^\n] ", file_contents) != EOF) {
    if (assemble_str(al, file_contents) == EXIT_FAILURE) {
      fprintf(stderr, "failed to assemble %s\n", argv[1]);
      return 1;
    }
    u_int8_t *code = asm_get_buffer(al);
    int off = asm_get_offset(al);

    for (int i = 0; i < off; i++) {
      printf("%02x", *(code + i));
    }
    if (off > 0)
      printf("\n");
    asm_set_offset(al, 0);
  }

  fclose(in_file);
  asm_destroy_instance(al);
  return 0;
}
