#!/usr/bin/env bash

AP=$(dirname "${0}")/../../tools/asmline

# if ${1} is '--no-nasm', this script will only return the exit code asmline <<<"$line"
nasm=1
test "${1}" = "--no-nasm" && shift && nasm=0

# this option makes the entire pipe fail, if one command fails
# (read: when asmline/nasm gets an unsupported instruction, that should not be piped to xxd/sed respectively )
set -o pipefail

# runs the last pipe (| read) in the current shell to get the variable.
shopt -s lastpipe

#create tmpfiles and prepare for cleanup
tmpfile_line=$(mktemp -t asmline_check.XXXXXX) || exit 1
tmpfile_clean=$(mktemp -t asmline_check.XXXXXX) || exit 1
function clean_tmp_files {
  rm -f "$tmpfile_line"
  rm -f "$tmpfile_clean"
}
trap clean_tmp_files EXIT

#clean input file to tmpfile_clean
sed -e 's/;.*//g' -e '/^$/d' <"${1}" >"${tmpfile_clean}"

#count #instr. and echo number of tests to be executed
echo -n 1..
wc -l <"${tmpfile_clean}"

index=0
while IFS= read -r line; do
  index=$((index + 1))

  # asmline
  ${AP} -P /dev/stdout <<<"${line}" 2>/dev/null |
    xxd -p |
    read -r asmline_output

  test -z "${asmline_output}" && printf "not ok %d - asmline did not output anything for >>%s<<, \n" ${index} "${line}" && continue

  # if we are here, and we are not supposed to invoke nasm, it is ok and we can continue with the next test.
  test "${nasm}" -eq 0 && echo "ok     ${index} - ${line} asmline produced >${asmline_output}<" && continue

  # nasm
  # must be in a file
  echo "${line}" >"${tmpfile_line}"
  # regex copied from ../al_nasm_compare.sh
  nasm -w-number-overflow -f elf64 -l /dev/stdout "${tmpfile_line}" 2>/dev/null |
    sed -e 's/^[[:space:]]*[[:digit:]]\+ [[:xdigit:]]\+ \([[:xdigit:]]\+\)-\?[[:space:]]\+[^$]\+/\L\1/g' |
    tr -d '\n' |
    read -r nasm_output

  test -z "${nasm_output}" && echo "not ok ${index} - ${line}, nasm    did not output anything" && continue

  if test "${asmline_output}" = "${nasm_output}"; then
    echo "ok     ${index} - ${line}"
  else
    echo "not ok ${index} - ${line} - nasm: >${nasm_output}< vs asmline >${asmline_output}<"
  fi

done <"${tmpfile_clean}"
