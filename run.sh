#! /bin/bash -ex

PROG=`ls $1/*.cc`
TEST=$1/input

g++ -std=c++11 $PROG -o a.out
./a.out < $TEST
