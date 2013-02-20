#! /usr/bin/python

import sys
import math

if __name__ == '__main__':
    n, m, a = map(int, sys.stdin.readline().split())
    c = int(math.ceil(n*1.0 / a))
    if m - a > 0:
        c += (int(math.ceil( (m-a)*1.0 / a)) * c)
    print c
