#!/usr/bin/python3


def island_perimeter(grid):

    perimeter = 0
    for x in range(0, len(grid)):
        for y in range(0, len(grid[x])):
            if grid[x][y] is 1:
                if grid[x - 1][y] is 0:
                    perimeter += 1
                if grid[x + 1][y] is 0:
                    perimeter += 1
                if grid[x][y - 1] is 0:
                    perimeter += 1
                if grid[x][y + 1] is 0:
                    perimeter += 1

    return perimeter
