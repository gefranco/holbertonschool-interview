#!/usr/bin/python3
"""
...
"""


def island_perimeter(grid):
    """
    ...
    """
    perimeter = 0
    for x in range(0, len(grid)):
        for y in range(0, len(grid[x])):
            if grid[x][y] is 1:
                if x - 1 < 0:
                    perimeter += 1
                if x + 1 >= len(grid):
                    perimeter += 1
                if y - 1 < 0:
                    perimeter += 1
                if y + 1 >= len(grid[x]):
                    perimeter += 1
                if x - 1 >= 0 and grid[x - 1][y] is 0:
                    perimeter += 1
                if x + 1 < len(grid) and grid[x + 1][y] is 0:
                    perimeter += 1
                if y - 1 > 0 and grid[x][y - 1] is 0:
                    perimeter += 1
                if y + 1 < len(grid[x]) and grid[x][y + 1] is 0:
                    perimeter += 1

    return perimeter
