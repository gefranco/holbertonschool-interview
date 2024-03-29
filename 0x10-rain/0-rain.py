#!/usr/bin/python3
"""
calculate how much water will be retained after it rains
"""


def rain(walls):
    """
    Function that calculate how much water will be retained after it rains
    """
    wall_1 = 0
    wall_2 = 0
    collect_water = 0
    indice_1 = 0
    indice_2 = 0
    indice = 0
    while indice < len(walls):
        if walls[indice] > 0 and wall_1 == 0:
            wall_1 = walls[indice]
            indice_1 = indice
        elif walls[indice] > 0 and wall_2 == 0:
            wall_2 = walls[indice]
            indice_2 = indice
            if greater_wall(wall_2, walls[indice_2:-1]):
                while indice < len(walls) and wall_2 < wall_1:
                    wall_2 = walls[indice]
                    indice += 1
                    indice_2 = indice
        if wall_1 > 0 and wall_2 > 0:
            collect_water += collect(
                    walls[indice_1:indice_2], wall_1, wall_2)
            wall_1 = wall_2
            indice_1 = indice_2
            wall_2 = 0
        indice += 1
    return collect_water


def collect(water, wall_1, wall_2):
    """
    Function that collect the water between two walls
    """
    amount = wall_2 if wall_1 > wall_2 else wall_1
    total_water = 0
    for part_water in water:
        if amount - part_water > 0:
            total_water += amount - part_water
    return total_water


def greater_wall(greater_wall, walls):
    """
    Function that check if there is a greater wall
    """
    for wall in walls:
        if wall > greater_wall:
            return True
    return False
