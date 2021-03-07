#! /bin/bash -ex

PROG=`ls $1/* | grep -v "\.test$"`
TEST=$1/tmp.test

g++ -std=c++11 $PROG -o a.out
./a.out < $TEST
