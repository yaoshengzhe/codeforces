#! /bin/bash

PROGRAM=$1
TEST=$2

set -e

g++ $PROGRAM -o a.out
./a.out < $TEST
