#! /usr/bin/python

import sys

def find_max_num(v, a, cache):
    if v in cache:
        return cache[v]
    result = [0]
    for i in range(len(a)):
        r = v - a[i]
        if r >= 0:
            if r not in cache:
                cache[r] = find_max_num(r, a, cache)
            result.append(i + 1 + 10*cache[r])
    cache[v] = max(result)
    return cache[v]

if __name__ == '__main__':
    V = int(sys.stdin.readline())
    a = map(int, sys.stdin.readline().split(' '))
    cache = {}
    ans = find_max_num(V, a, cache)
    print ans if ans > 0 else -1
