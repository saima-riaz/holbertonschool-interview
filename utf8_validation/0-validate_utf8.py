#!/usr/bin/python3

def validUTF8(data):
    num_bytes = 0

    for num in data:
        byte = num & 0xFF

        if num_bytes == 0:
            """how many bytes the character will use"""
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
            # Expecting continuation bytes
            if (byte >> 6) != 0b10:
                return False
            num_bytes -= 1

    return num_bytes == 0
# Testing the function with provided test cases


if __name__ == "__main__":
    print(validUTF8([65]))  # True
    print(validUTF8
          ([80, 121, 116, 104,
            111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]))  # True
    print(validUTF8([229, 65, 127, 256]))  # False
