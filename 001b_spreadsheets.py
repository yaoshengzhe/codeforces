#! /usr/bin/python

import sys
import re

def num2col(num):
    num -= 1
    col = []
    while True:
        remain =  num % 26
        col.append(chr(ord('A') + remain))
        num = (num - remain) / 26 - 1
        if num < 0:
            break

    return ''.join(reversed(col))

def col2num(col):
    num = 0
    for c in col:
        num = num * 26 + ord(c) - ord('A') + 1
    return num

def solve(data):
    m = re.search('R(\d+)C(\d+)', data)
    if m is not None:
        return num2col(int(m.group(2))) + m.group(1)
    else:
        m = re.search('([A-Z]+)(\d+)', data)
        return 'R' + m.group(2) + 'C' + str(col2num(m.group(1)))

def test():
    import random
    for i in range(10000):
        if 0 == random.randint(0, 1):
            input = 'R%dC%d' % (random.randint(1, 10**5), random.randint(1, 10**5))
        else:
            input = '%s%d' % (num2col(random.randint(1, 10**5)), random.randint(1, 10**5))
        print 'input = ' + input
        print 'output = ' + solve(input)

if __name__ == '__main__':
    sys.stdin.readline()
    for line in sys.stdin.readlines():
        print solve(line)
