#!/usr/bin/python3
"""
minimum number of coins needed to make up the total.
"""


def makeChange(coins, total):
    if total <= 0:
        return 0
    
    coins.sort(reverse=True)
    count = 0
    
    for coin in coins:
        if total == 0:
            break
        num_coins = total // coin
        count += num_coins
        total -= num_coins * coin
    
    return count if total == 0 else -1
