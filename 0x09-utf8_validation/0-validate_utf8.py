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
        # if bin(byte_data).split('b')[1].zfill(8)[0] is "0":
        #    continue
        byte = bin(byte_data).split('b')[1].zfill(8)[-8:]
        # print(byte)
        if next_bytes > 0:
            # print("!!")
            if byte[:2] is not "10":
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
