#!/usr/bin/python3
""" - determines if all the boxes can be opened 
- Return True if all boxes can be opened, else return False
"""

def canUnlockAll(boxes):
    n = len(boxes)
    unlocked = set([0])  # Start with the first box unlocked
    keys = list(boxes[0])
    while keys:
        key = keys.pop()  # Get and remove the last key from the list
        if key < n and key not in unlocked:
            unlocked .add(key) # Unlock the box
            keys.extend(boxes[key]) # Add keys found in this newly unlocked box
    return len(unlocked) == n


   
