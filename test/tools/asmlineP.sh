#!/usr/bin/env bash

# error out on any error
set -e

tool=./tools/asmline
# should not error out without option to '-r'
${tool} -r <<EOF
ret
EOF

# should not error out without option to '-P /dev/stdout'

${tool} -P /dev/stdout <<EOF
ret
EOF
