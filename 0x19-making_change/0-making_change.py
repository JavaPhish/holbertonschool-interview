#!/usr/bin/python3
"""
Coins
"""


def makeChange(coins, total):
    """ Min nmber of coins needed to make total """

    coin_count = 0

    if (total <= 0):
        return (-1)

    coins.sort(reverse=True)
    for coin in coins:

        """ If its possible to get this number """
        if (total % coins[-1] != 0):
            return (-1)

        while (coin <= total):
            total = total - coin
            coin_count += 1

    return (coin_count)
