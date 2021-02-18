#!/usr/bin/python3
"""
validateUTF8 method file container
"""


def validUTF8(data):
    """
    Method that validates if a set of data is UTF8 encoded
    """
    next_bytes = 0
    for byte_data in data:
        byte = bin(byte_data).split('b')[1].zfill(8)[-8:]
        if next_bytes > 0:
            bit_2 = byte[:2]
            if bit_2 != "10":
                return False
            next_bytes -= 1
            if next_bytes is 1:
                next_bytes = 0
            continue
        if byte[0] is "0":
            continue
        # print(bin(byte_data).split('b')[1].zfill(8))
        # print(byte)
        for bit in byte:
            if bit is "1":
                next_bytes += 1
            else:
                break
        if next_bytes > 4:
            return False
    return True
