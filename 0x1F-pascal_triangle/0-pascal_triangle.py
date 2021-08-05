#!/usr/bin/python3
def pascal_triangle(n):
    vals = []
    i = 0
    temp = 1
    for i in range(0, n):
        inner_vals = []
        for j in range(0, i + 1):
            if j == 0 or j == i:
                inner_vals.append(1)
            else:
                inner_vals.append(0)
        vals.append(inner_vals)
    for i in range(0, n):
        for j in range(0, i + 1):
            if i > 0 and (j != 0 and j != i):
                vals[i][j] = vals[i - 1][j - 1] + vals[i - 1][j]
        temp += 1
    return vals
