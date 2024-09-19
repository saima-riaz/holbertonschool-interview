#!/usr/bin/python3
"""Module which contains function to calculate min operations."""


def minOperations(n):
    """Calculate the minimum number of operations
    needed to get exactly n 'H' characters."""
    if n <= 1:
        return 0

    i = 0
    x = 2  # Start dividing n by the smallest possible prime factors

    while n > 1:
        while n % x == 0:
            i += x
            n //= x
        x += 1

    return i
