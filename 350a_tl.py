#! /usr/bin/python

import sys

if __name__ == '__main__':
    sys.stdin.readline()
    correct_sol = map(int, sys.stdin.readline().split())
    wrong_sol = map(int, sys.stdin.readline().split())
    max_sol = max(correct_sol)
    lower = max(max_sol, min(correct_sol) * 2)
    upper = min(wrong_sol)

    if max_sol >= upper:
        print -1
    elif lower < upper:
        print lower
    else:
        print -1
