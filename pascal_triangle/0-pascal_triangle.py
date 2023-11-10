#!/usr/bin/python3
"""
0-main
"""


def pascal_triangle(n):
    """
0-main
"""
    if n <= 0:
        return []

    triangle = []
    for i in range(n):
        row = [1]  # First element of each row is always 1
        if triangle:
            last_row = triangle[-1]
            row.extend([sum(pair) for pair in zip(last_row, last_row[1:])])
            row.append(1)  # Last element of each row is always 1
        triangle.append(row)

    return triangle
