#!/usr/bin/python3
""" Reads stdin """

import sys

if __name__ == "__main__":
    r_lines = 0
    t_file_size = 0

    s_codes = {'200': 0,
            '301': 0,
            '400': 0,
            '401': 0,
            '403': 0,
            '404': 0,
            '405': 0,
            '500': 0}


    try:
        for line in sys.stdin:

            """ Split each input into its own index for parsing """
            line = line.split(' ')

            if (len(line) != 9):
                continue

            """ Add file size """
            t_file_size += int(line[-1])

            """ Check status code """
            if (line[-2] in (s_codes.keys())):
                s_codes[line[-2]] += 1
            else:
                continue

            """ increase line count """
            r_lines += 1
            if (r_lines == 9):
                print("File size: {}".format(t_file_size))
                for key in sorted(s_codes.keys()):
                    if (s_codes[key] != 0):
                        print("{}: {}".format(key, s_codes[key]))
                r_lines = 0

    except KeyboardInterrupt:
        print("File size: {}".format(t_file_size))
        for key in sorted(s_codes.keys()):
            if (s_codes[key] != 0):
                print("{}: {}".format(key, s_codes[key]))
            r_lines = 0
