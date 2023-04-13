#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    i = 0
    n_div = 2
    if n < 1 or type(n) is not int:
        return 0
    while n > 1:
        if n % n_div == 0:
            n = n / n_div
            i = i + n_div
        else:
            n_div = n_div + 1
    return

