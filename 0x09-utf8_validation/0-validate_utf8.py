#!/usr/bin/python3
"""
validateUTF8 method file container
"""


def validUTF8(data):
    """
    Method that validates if a set of data is UTF8 encoding
    """
    next_bytes = 0
    for byte_data in data:
        # if bin(byte_data).split('b')[1].zfill(8)[0] is "0":
        #    continue
        if next_bytes > 0:
            # print("!!")
            if bin(byte_data).split('b')[1].zfill(8)[:2] is not "10":
                return False
            next_bytes -= 1
        if bin(byte_data).split('b')[1].zfill(8)[0] is "0":
            continue
        byte = bin(byte_data).split('b')[1].zfill(8)
        # print(bin(byte_data).split('b')[1].zfill(8))
        for bit in byte:
            if bit is "1":
                next_bytes += 1
            else:
                break
        if next_bytes > 4:
            return False
    return True
