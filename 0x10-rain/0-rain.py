#!/usr/bin/python3
""" Rain problem """


def rain(walls):
    """ Solution """
    water = 0

    left = 0
    right = 0

    for index in range(1, len(walls) - 1):

        """ Find highest wall on left """
        left = walls[index]
        for l in range(index):
            left = max(left, walls[l])

        """ Find highest wall on right """
        right = walls[index]
        for r in range(index + 1, len(walls)):
            right = max(right, walls[r])

        water += (min(left, right) - walls[index])

    return water
