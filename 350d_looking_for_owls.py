#! /usr/bin/python

import sys
import math
from fractions import Fraction

def distance(a, b):
    return math.sqrt( (a[0] - a[1])**2 + (b[0] - b[1])**2)

def slope(a, b):
    if a[0] == b[0]:
        return -1
    else:
        return Fraction(b[1] - a[1], b[0] - a[0])

def get_segment_slope(a, b):
    if a[1] == b[1]:
        return -1
    else:
        return Fraction(-(b[0] - a[0]), b[1] - a[1])

if __name__ == '__main__':
    N, M = map(int, sys.stdin.readline().split())

    segment_count = {}

    for i in range(N):
        x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
        slp = slope((x1, y1), (x2, y2))
        segment_count[slp] = segment_count.get(slp, 0) + 1

    circles = {}

    for i in range(M):
        x, y, r = map(int, sys.stdin.readline().split())
        if r not in circles:
            circles[r] = []
        circles[r].append((x, y))

    result = 0
    for r, pts in circles.items():
        if len(pts) > 1:
            for i in range(len(pts) - 1):
                for j in range(i+1, len(pts)):
                    if distance(pts[i], pts[j]) > r:
                        slp = get_segment_slope(pts[i], pts[j])
                        result += segment_count.get(slp, 0)
    print result
