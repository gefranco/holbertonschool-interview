#!/usr/bin/python3


def validUTF8(data):

    next_bytes = 0
    for byte_data in data:
        if bin(byte_data).split('b')[1].zfill(8)[0] is "0":
            continue
        if next_bytes > 0:
            # print("!!")
            if bin(byte_data).split('b')[1].zfill(8)[:2] is not "10":
                return False
            next_bytes -= 1
        byte = bin(byte_data).split('b')[1].zfill(8)
        # print(bin(byte_data).split('b')[1].zfill(8))
        for bit in byte:
            if bit is "1":
                next_bytes += 1
            else:
                break
    return True
