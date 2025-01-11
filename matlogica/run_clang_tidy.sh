#!/bin/bash

if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <build_dir> <checks>" >&2
  exit 1
fi

set -euo pipefail

cd $(dirname "$(readlink -f "$0")")/..
WORKDIR=$(pwd)

source matlogica/.env

$LLVM_PROJ/clang-tools-extra/clang-tidy/tool/run-clang-tidy.py -j $NUMCPU -clang-tidy-binary $LLVM_INSTALL/bin/clang-tidy -checks="-*,$2" \
    -header-filter="^$WORKDIR" -p "./$1" -clang-apply-replacements-binary $LLVM_INSTALL/bin/clang-apply-replacements -fix

matlogica/log.sh "Ran clang-tidy('$2') on $1: $(git diff --name-only | wc -l) files modified"
