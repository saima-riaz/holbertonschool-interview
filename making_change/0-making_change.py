#!/usr/bin/python3
"""
minimum number of coins needed to make up the total.
"""


def makeChange(coins, total):
    if total <= 0:
        return 0
    
    coins.sort(reverse=True)  # Sort coins in descending order
    num_coins = 0
    
    for coin in coins:
        if total == 0:
            break
        count = total // coin  # Get the max number of this coin we can use
        num_coins += count
        total -= count * coin  # Reduce the total by the used coins
    
    return num_coins if total == 0 else -1
