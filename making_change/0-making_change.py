#!/usr/bin/python3
def makeChange(coins, total):
    if total < 0:
        return 0  # If total is negative, return 0 as specified

    # Initialize a list to store the minimum number of coins needed to make each total from 0 to 'total'
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # 0 coins are needed to make a total of 0

    # Iterate through each coin and update the dp table
    for coin in coins:
        for sub_total in range(coin, total + 1):
            dp[sub_total] = min(dp[sub_total], dp[sub_total - coin] + 1)

    # If dp[total] is still equal to float('inf'), it means the total cannot be met
    if dp[total] == float('inf'):
        return -1

    return dp[total]
