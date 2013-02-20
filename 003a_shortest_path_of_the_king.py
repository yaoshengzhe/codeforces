#! /usr/bin/python

import sys

def shortest_path(x1, y1, x2, y2):
    path = []
    if x1 == x2:
        offset = y1 - y2
        while offset != 0:
            if offset < 0:
                path.append('U')
                offset += 1
            else:
                path.append('D')
                offset -= 1
    elif y1 == y2:
        offset = x1 - x2
        while offset != 0:
            if offset < 0:
                path.append('R')
                offset += 1
            else:
                path.append('L')
                offset -= 1
    else:
        sgn = 1.0 * (y1 - y2) / (x1 - x2)
        if sgn > 0:
            if y1 > y2:
                path.append('LD')
                path.extend(shortest_path(x1-1, y1-1, x2, y2))
            else:
                path.append('RU')
                path.extend(shortest_path(x1+1, y1+1, x2, y2))
        else:
            if y1 > y2:
                path.append('RD')
                path.extend(shortest_path(x1+1, y1-1, x2, y2))
            else:
                path.append('LU')
                path.extend(shortest_path(x1-1, y1+1, x2, y2))
    return path

if __name__ == '__main__':
    a = sys.stdin.readline()
    b = sys.stdin.readline()
    x1, y1 = ord(a[0]) - ord('a') + 1, int(a[1])
    x2, y2 = ord(b[0]) - ord('a') + 1, int(b[1])
    path = shortest_path(x1, y1, x2, y2)
    print len(path)
    for i in path:
        print i
