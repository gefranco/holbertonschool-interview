#!/usr/bin/python3
"""
script that read from standard input and compute metrics
"""

import sys
if __name__ == "__main__":
    lines_read = 0
    total_size = 0
    stats = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }
# for line in sys.stdin:
    while True:
        try:
            line = input()
            columns = line.split()
            code_size = columns[-2:]
            lines_read += 1
            total_size = total_size + int(code_size[1])
            stats[code_size[0]] = stats[code_size[0]] + 1
            if lines_read == 10:
                print("File size: {:d}".format(total_size))
                for k, v in sorted(stats.items()):
                    if v > 0:
                        print("{}: {}".format(k, v))
                lines_read = 0
        except Exception:
            print("File size: {:d}".format(total_size))
            for k, v in stats.items():
                print(k, v)
