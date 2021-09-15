#!/usr/bin/env bash

# is an assmebly-printing binary. It prints like ../tools/asmline -p <file.asm but without linebreak at 7
AP=./asm_to_stdout

test -z "${1}" && echo "Call with ${0} /path/to/file.asm" && exit 1
test -f "${1}" || (echo "Argument is set to ${1}, but it's not a file." && exit 1)
# test -f "${1}" ||
test -x "${AP}" || echo "${AP} is not an executable file."
test -x "${AP}" || exit 1

# Diff'ing output of AP with  output of nasm after a little translations
diff --ignore-trailing-space --side-by-side --left-column \
  <(${AP} "${1}") \
  <(
    # delete everything until \S*:, which means symbol:
    e1='1,/\S*:/d'

    # delete all lines containing 'define'
    e2='/define/d'

    # nasm output is someling like
    #     23 0000002D 66660F1F8400000000-     nop10
    #     23 00000036 00
    # this massive regex matches the entire line and emits the instruction in lowecase
    e3='s/^[[:space:]]*[[:digit:]]\+ [[:xdigit:]]\+ \([[:xdigit:]-]\+\)[[:space:]]\+[^$]\+/\L\1/g'

    nasm -f elf64 "${1}" -l /dev/stdout |
      sed -e "${e1}" -e "${e2}" -e "${e3}" |
      # then we are left with
      #66660f1f8400000000-
      #00
      # The idea is to translate all linebreaks into -
      tr -- '\n' '-' |
      # then delete the '--', and translate - back to \n
      sed -e 's/--//g' -e 's/-/\n/g'
  )
