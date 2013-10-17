#! /usr/bin/python

import sys

def get_x_dir(x):
    if x == 0:
        return None
    return 'R' if x > 0 else 'L'

def get_y_dir(y):
    if y == 0:
        return None
    return 'U' if y > 0 else 'D'

if __name__ == '__main__':
    sys.stdin.readline()
    bombs = []

    d = 0
    for line in sys.stdin.readlines():
        x, y = map(int, line.split())
        if x == 0 or y == 0:
            d += 1
        bombs.append((x, y))

    bombs.sort(lambda a, b: abs(a[0]) + abs(a[1]) - abs(b[0]) - abs(b[1]))

    print len(bombs) * 6 - 2 * d

    for b in bombs:
        x, y = b
        x_dir = get_x_dir(x)
        if x_dir != None:
            print '1 %d %s' % (abs(x), x_dir)
        y_dir = get_y_dir(y)
        if y_dir != None:
            print '1 %d %s' % (abs(y), y_dir)
        print '2'
        # go back to (0, 0)
        if x_dir != None:
            print '1 %d %s' % (abs(x), get_x_dir(-x))
        if y_dir != None:
            print '1 %d %s' % (abs(y), get_y_dir(-y))
        print '3'
