#!/usr/bin/python3
"""
script with the function minOperations(n)
"""


def minOperations(n):
    """
    calc the fewest number of op needed to result in exactly n H characters
    """
    numbers = []
    bn = 2
    while bn <= n:
        if n % bn == 0:
            n = n / bn
            numbers.append(bn)
        else:
            bn += 1
    return sum(numbers)
