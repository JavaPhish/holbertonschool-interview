#!/usr/bin/python3
""" Rotates a 2d matrix """


def rotate_2d_matrix(matrix):
    """ Rotates a 2d matrix """

    buffer = []

    """ Create a buffer of rotated values by looping
        through from x: 0 and y: Length until x: Length and y: 0 """
    for column in range(len(matrix)):
        row_buffer = []

        for row in range(len(matrix) - 1, - 1, - 1):
            row_buffer.append(matrix[row][column])
            # print(row_buffer) (Debug print)
        buffer.append(row_buffer)

    # Copy the buffer into the given matrix
    for x in range(0, len(matrix)):
        for y in range(0, len(matrix)):
            matrix[x][y] = buffer[x][y]

    return matrix
