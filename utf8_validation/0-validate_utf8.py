"""
Module to validate UTF-8 encoding.
This module provides a function, 
validUTF8` that checks if a given dataset
represents valid UTF-8 encoding.
"""

def validUTF8(data):
    num_bytes = 0
    for num in data:
        byte = num & 0xFF
        if num_bytes == 0:
            if (byte >> 7) == 0b0:  # 1-byte character
                continue
            elif (byte >> 5) == 0b110:  # 2-byte character
                num_bytes = 1
            elif (byte >> 4) == 0b1110:  # 3-byte character
                num_bytes = 2
            elif (byte >> 3) == 0b11110:  # 4-byte character
                num_bytes = 3
            else:
                return False  # Invalid starting byte
        else:
            if (byte >> 6) != 0b10:  # Not a valid continuation byte
                return False
            num_bytes -= 1
    return num_bytes == 0
