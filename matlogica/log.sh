#!/bin/bash

DIRNAME=$(dirname "$(readlink -f "$0")")

echo "[$(date '+%Y-%m-%d %H:%M:%S')] $1" >> $DIRNAME/integration.log
