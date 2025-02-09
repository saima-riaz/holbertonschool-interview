#!/usr/bin/python3
"""
minimum number of coins needed to make up the total.
"""


def makeChange(coins, total):
    if total <= 0:
        return 0
    
    coins.sort(reverse=True)  # Start with the largest coin
    count = 0
    
    for coin in coins:
        while total >= coin:
            total -= coin
            count += 1
    
    return count if total == 0 else -1
