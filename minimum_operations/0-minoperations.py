#!/usr/bin/python3
"""Module which contains function"""

def minOperations(n):
    """Calculate the minimum number of operations needed to get exactly n 'H' characters
         Args:
            n: repetitions of H

        Returns:
            number of operations
    """
    if n <= 1:
        return 0

    i= 0
    # Start dividing n by the smallest possible prime factors
    x = 2
    while n > 1:
        while n % x == 0:
            i += x
            n //= x
        x += 1

    return i