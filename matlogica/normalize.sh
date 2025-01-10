#!/bin/bash

cd $(dirname "$(readlink -f "$0")")/..
WORKDIR=$(pwd)

# For all files in the repository:
#   remove BOM
#   convert line endings to LF
#   add newline at the end if missing

git ls-files --cached --modified --others --exclude-standard -- "$@" | xargs -d '\n' sed -i '1s/^\xEF\xBB\xBF//; s/\r$//; $a\'
