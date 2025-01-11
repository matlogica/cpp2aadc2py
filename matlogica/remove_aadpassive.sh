#!/bin/bash

if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <build_dir>" >&2
  exit 1
fi

set -euo pipefail

cd $(dirname "$(readlink -f "$0")")/..
WORKDIR=$(pwd)

source matlogica/.env

IDOUBLE_H=$AADC_DIR/aadc/include/aadc/idouble.h

cp $IDOUBLE_H $IDOUBLE_H.bak

# changes AAD_PASSIVE macro to function AAD_PASSIVE() so it can be detected by clang-tidy

sed -i 's/#define AAD_PASSIVE/double AAD_PASSIVE(double ival);\ndouble AAD_PASSIVE(idouble ival);\n\/\/#define AAD_PASSIVE/' $IDOUBLE_H

matlogica/run_clang_tidy.sh $1 'matlogica-active-remove-aadpassive'

mv -f $IDOUBLE_H.bak $IDOUBLE_H
