#!/usr/bin/python3
"""
Basic pascal triangle algo
"""


def pascal_triangle(n):
    """ Main function """

    final = []

    row = [1]
    temp = [0]

    for x in range(n):
        final.append(row)
        row = [l + r for l, r in zip(row + temp, temp + row)]

    return final
