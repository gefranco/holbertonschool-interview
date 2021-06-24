#!/usr/bin/python3
def makeChange(coins, total):

    total_coins = 0
    total_value = 0

    while total_value != total:
        if not coins:
            return -1
        max_coin = get_max_coin(coins)
        while total_value < total:
            total_value += max_coin
            total_coins += 1
            if (total_value > total):
                total_coins -= 1
                total_value -= max_coin
                break

    return total_coins


def get_max_coin(coins):
    max_coin = coins[0]
    for coin in coins:
        if coin > max_coin:
            max_coin = coin
    coins.remove(max_coin)
    return max_coin
