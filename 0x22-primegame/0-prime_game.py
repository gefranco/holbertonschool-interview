#!/usr/bin/python3
"""
...
"""


def isWinner(x, nums):
    """
    ...
    """
    if x <= 0 or nums is None or len(nums) < x:
        return None
    index = 0
    maria_points = 0
    ben_points = 0
    while index < x:
        array_primes = []
        array_nums = []
        maria_turn = True
        get_array_nums(array_nums, nums[index])
        get_primes(array_primes, nums[index])

        while len(array_nums) != 1 and len(array_primes) > 0:
            remove(array_nums, array_primes)

            maria_turn = not maria_turn
        index += 1
        if maria_turn:
            ben_points += 1
        else:
            maria_points += 1
    if maria_points > ben_points:
        return "Maria"
    elif ben_points > maria_points:
        return "Ben"
    else:
        return None
    return "Ben"


def remove(array_nums, array_primes):
    """
    ...
    """
    remove_multiples(array_primes.pop(0), array_nums)


def get_array_nums(array, n):
    """
    ...
    """
    for i in range(1, n + 1):
        array.append(i)


def remove_multiples(n, array):
    """
    ...
    """
    i = 1
    length = len(array)
    while i < length:
        if (array[i] % n == 0):
            array.remove(array[i])
            length -= 1
            continue
        i += 1


def get_primes(array, n):
    """
    ...
    """
    for number in range(2, n + 1):
        prime = True
        for div in range(2, number):
            if (number % div == 0):
                prime = False
                break
        if prime:
            array.append(number)
