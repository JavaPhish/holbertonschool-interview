#!/usr/bin/python3
""" Min operations """


def minOperations(n):
    """ Finds the smallest amount of operations """
    ops = 0
    temp = n - 1
    max = 0
    """ Find max value you can divide N by """
    if (n <= 0):
        return 0

    while (n > 3):
        if (n % temp == 0):
            ops += n / temp
            n = n / temp
        else:
            temp -= 1

    return ops + temp
