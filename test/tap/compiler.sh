#!/usr/bin/env bash

AP=$(dirname "${0}")/../../tools/asmline

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

index=1
while IFS= read -r line; do

  # asmline
  asmline_output=$(${AP} -P /dev/stdout <<<"${line}" | xxd -p)

  # nasm
  # must be in a file
  echo "${line}" >"${tmpfile_line}"
  # regex copied from ../al_nasm_compare.sh
  nasm_output=$(nasm -f elf64 -l /dev/stdout "${tmpfile_line}" |
    sed -e 's/^[[:space:]]*[[:digit:]]\+ [[:xdigit:]]\+ \([[:xdigit:]]\+\)-\?[[:space:]]\+[^$]\+/\L\1/g' |
    tr -d '\n')

  if test "${asmline_output}" = "${nasm_output}"; then
    echo "ok ${index} - ${line}"
  else
    echo "not ok ${index} - ${line} - nasm: ${nasm_output} vs asmline ${nasm_output}"
  fi

  index=$((index + 1))

done <"${tmpfile_clean}"
