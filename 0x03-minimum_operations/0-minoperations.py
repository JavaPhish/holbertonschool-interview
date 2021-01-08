#!/usr/bin/python3
""" Min operations """


def minOperations(n):
    """ Finds the smallest amount of operations """
    ops = 0
    max_div = n - 1
    """ Find max value you can divide N by """
    while (max_div > 1):

        if (n % max_div == 0):
            ops = n / max_div
            n = max_div
            break

        max_div = max_div - 1

    ops = ops + (n - 1)

    return ops
