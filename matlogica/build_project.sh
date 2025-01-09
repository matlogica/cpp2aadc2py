#!/bin/bash

if [ "$#" -ne 4 ]; then
  echo "Usage: $0 [clang|gcc] [active|passive] [release|debug] <comment>" >&2
  exit 1
fi

set -euo pipefail

cd $(dirname "$(readlink -f "$0")")/..
WORKDIR=$(pwd)

source matlogica/.env

# Compiler
if [ "$1" == "gcc" ]; then
  COMPILER=g++
elif [ "$1" == "clang" ]; then
  COMPILER=$LLVM_INSTALL/bin/clang++
else
  echo "Unsupported compiler: $1" >&2
  exit 1
fi

# active/passive
if [ "$2" == "active" ]; then
  IS_ACTIVE=1
elif [ "$2" == "passive" ]; then
  IS_ACTIVE=0
else
  echo "Should be active or passive. Got: $2" >&2
  exit 1
fi

# release/debug
if [ "$3" == "release" ]; then
  BUILD_TYPE=Release
elif [ "$3" == "debug" ]; then
  BUILD_TYPE=Debug
else
  echo "Should be release or debug. Got: $3" >&2
  exit 1
fi

BUILD_DIR=build_$1_$2_$3
mkdir -p $BUILD_DIR
cd $BUILD_DIR
rm -rf ./*

cmake -G Ninja .. \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
  -DCMAKE_CXX_COMPILER=$COMPILER \
  -DCMAKE_BUILD_TYPE=$BUILD_TYPE
  # -DAADC_DIR=$AADC_DIR \
  # -DAADC_QL=$IS_ACTIVE
ninja

$WORKDIR/matlogica/log.sh "Compiled project with $1 in $2 mode ($3): $4"
