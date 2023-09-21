#!/usr/bin/python3
"""
make change: bottom up method
"""


def makeChange(coins, total):
    """
    make change: bottom up method
    """
    if total < 0:
        return 0
    dp = [float('inf')] * (total + 1)
    dp[0] = 0
    for coin in coins:
        for sub_total in range(coin, total + 1):
            dp[sub_total] = min(dp[sub_total], dp[sub_total - coin] + 1)
    if dp[total] == float('inf'):
        return -1
    return dp[total]
