#!/usr/bin/python3
"""
validUTF8
"""


def validUTF8(data):
    """ UTF-8 Validator """

    bytes = 0

    for num in data:
        octet = format(num, '#010b')[-8:]

        if bytes == 0:

            for oct in octet:
                if oct == '0':
                    break
                bytes += 1

            if bytes == 0:
                continue

            if bytes > 4 or bytes < 2:
                return False

        else:
            if ("10" != octet[0:2]):
                return False

        bytes -= 1

    if bytes == 0:
        return True
    return False
