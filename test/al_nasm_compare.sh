#!/usr/bin/env bash

AP=$(dirname "${0}")/../tools/asmline

test -z "${1}" && echo "Call with ${0} /path/to/file.asm" && exit 1
test ! -f "${1}" && echo "Argument is set to ${1}, but it's not a file." && exit 1
test ! -x "${AP}" && echo "${AP} is not an executable file $(ls -la "${AP}")" && exit 1

# Diff'ing output of AP with output of nasm after a little translations
diff --ignore-trailing-space --side-by-side --left-column \
  <(${AP} -P /dev/stdout <"${1}" | xxd -p | tr -d -- '\n') \
  <(
    # delete everything until \S*:, which means symbol:
    e1='1,/\S*:/d'

    # delete lines containing 'define'
    e2='/define/d'

    # empty     lines in the asm file get output by nasm like this: \^     11      \$.
    #This regex deletes them.
    e3='/^[[:space:]]\+[[:digit:]]\+[[:space:]]\+$/d'

    # commented lines in the asm file get output by nasm like this: \^  11     ; this is a comment\$.
    #This regex deletes them.
    e4='/^[[:space:]]\+[[:digit:]]\+[[:space:]]\+;.*$/d'

    # nasm output is something like
    #     23 0000002D 66660F1F8400000000-     nop10
    #     23 00000036 00
    # this massive regex matches the entire line and emits the instruction in lower case
    e5='s/^[[:space:]]*[[:digit:]]\+ [[:xdigit:]]\+ \([[:xdigit:]]\+\)-\?[[:space:]]\+[^$]\+/\L\1/g'

    # then we are left with
    #66660f1f8400000000
    #00

    # the last tr will join all to one line

    nasm -w-number-overflow -f elf64 "${1}" -l /dev/stdout |
      sed -e "${e1}" -e "${e2}" -e "${e3}" -e "${e4}" -e "${e5}" | tr -d -- '\n'
  )
