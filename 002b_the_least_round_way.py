#! /usr/bin/python

import sys
import copy

def count_factor(num, factor):
    c = 0
    while num > 0 and num % factor == 0:
        c += 1
        num /= factor
    return c

def optimal_route(trace_table, N):
    route = []
    i, j = N-1, N-1
    while not (i == 0 and j == 0):
        r = trace_table[i][j]
        route.append(r)
        if r == 'R':
            j -= 1
        else:
            i -= 1
    route.reverse()
    return ''.join(route)

def solve(data, N, count_func):
    trace_table = [ [0 for j in range(N)] for i in range(N)]
    table =  [ count_func(i) for i in data[0] ]

    for i in range(1, len(table)):
        table[i] += table[i-1]
        trace_table[0][i] = 'R'

    for i in range(1, N):
        table[0] += count_func(data[i][0])
        trace_table[i][0] = 'D'

        for j in range(1, len(data[i])):
            f = count_func(data[i][j])
            if table[j-1] > table[j]:
                table[j] += f
                trace_table[i][j] = 'D'
            else:
                table[j] = table[j-1] + f
                trace_table[i][j] = 'R'

    return table[-1], optimal_route(trace_table, N)

def solve_zero(data, N):
    for i in range(N):
        for j in range(N):
            if data[i][j] == 0:
                return (1, ''.join(['R' for x in range(j)]) + ''.join(['D' for x in range(N-1)]) + ''.join(['R' for x in range(N - j - 1)]))

    return None

if __name__ == '__main__':
    N = int(sys.stdin.readline())
    data = [ map(int, line.split()) for line in sys.stdin.readlines()]
    a, route_a = solve(data, N, lambda num: count_factor(num, 2))
    b, route_b = solve(data, N, lambda num: count_factor(num, 5))
    ans = (-1, -1)
    if a > b:
        ans = (b, route_b)
    else:
        ans = (a, route_a)

# Special case, matrix may contain 0
    if a > 0 and b > 0:
        r = solve_zero(data, N)
        if r is not None:
            ans = r
    print ans[0]
    print ans[1]
