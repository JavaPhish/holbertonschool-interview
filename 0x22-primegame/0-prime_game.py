#!/usr/bin/python3
""" Prime game """


def isWinner(x, nums):
    """ Determines winner of prime game """
    ben = 0
    maria = 0

    if (x == 0):
        return "None"

    if (len(nums) < x):
        return "None"

    for n in nums:
        if (n % 2 == 0 or n == 1):
            ben += 1
        else:
            maria += 1

    if (ben > maria):
        return "Ben"
    elif (ben == maria):
        return "None"
    return "Maria"
