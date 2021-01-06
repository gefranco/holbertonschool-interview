#!/usr/bin/python3
def minOperations(n):
    numbers = []
    bn = 2
    while bn <= n:
        if n % bn == 0:
            n = n / bn
            numbers.append(bn)
        else:
            bn += 1
    return sum(numbers)
