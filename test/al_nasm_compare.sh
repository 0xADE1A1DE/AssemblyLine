#!/usr/bin/env bash

# is an assmebly-printing binary. It prints like ../tools/asmline -p <file.asm but without linebreak at 7
AP=./asm_to_stdout

test -z "${1}" && echo "Call with ${0} /path/to/file.asm" && exit 1
test -f "${1}" || echo "Argument is set to ${1}, but its not a file."
test -f "${1}" || exit 1
test -x "${AP}" || echo "${AP} is not executable."
test -x "${AP}" || exit 1

diff --ignore-trailing-space --side-by-side --left-column \
  <(${AP} "${1}") \
  <(nasm -f elf64 "${1}" -l /dev/stdout |
    sed -e "1,/.*:/d" -e 's/^[[:space:]]*[[:digit:]]\+ [[:xdigit:]]\+ \([[:xdigit:]]\+\)[[:space:]]\+[^$]\+/\L\1/g' |
    sed -e '/\s*[0-9]*\s*[\%|;].*/d' | sed -e 's/^\s*[0-9]*\s[A-F|0-9]*\s//g'| sed -e 's/\-.*//g' | tr '[:upper:]' '[:lower:]')



#  <(nasm -f elf64 "${1}" -l /dev/stdout | sed -e "1,/.*:/d" -e 's/^[[:space:]]*[[:digit:]]\+ [[:xdigit:]]\+ \([[:xdigit:]]\+\)[[:space:]]\+[^$]\+/\L\1/g' | sed -e '/\s*[0-9]*\s*[\%|;].*/d' | sed -e 's/\-\s.*//g' | sed -e 's/^\s*[0-9]*\s[0-9|A-Z]*\s//g' | sed -e 's/[a-z][a-z][a-z].*//g' | tr '[:upper:]' '[:lower:]')


# nasm -f elf64 mov.asm -l /dev/stdout | sed -e 's/^\s*[0-9]*\s[A-F|0-9]*\s//g' | sed -e 's/[a-z][a-z][a-z].*//g'


# nasm -f elf64 mulx.asm -l /dev/stdout | sed -e 's/^\s*[0-9]*\s[A-F|0-9]*\s//g' | sed -e 's/[a-z][a-z][a-z].*//g' | sed -e '/\s*[\%|;].*/d' | sed -e 's/\-//g' | sed -e '/SECTION/d' | sed -e '/GLOBAL/d' | tr '[:upper:]' '[:lower:]'