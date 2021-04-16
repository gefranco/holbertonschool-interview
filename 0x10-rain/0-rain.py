#!/usr/bin/python3
def rain(walls):
	wall_1 = 0;
	wall_2 = 0;

	collect_water = 0;
	indice_1 = 0
	indice_2 = 0
	indice = 0;
	for wall in walls:
		if wall > 0 and wall_1 == 0:
			wall_1 = wall
			indice_1 = indice
		elif wall > 0 and wall_2 == 0:
			wall_2 = wall;
			indice_2 = indice
		if wall_1 > 0 and wall_2 > 0:
			collect_water +=collect(walls[indice_1 + 1 : indice_2], wall_1, wall_2)
			wall_1 = wall_2
			indice_1 = indice_2
			wall_2 = 0
		indice += 1
	return collect_water

def collect(water, wall_1, wall_2):
	amount = wall_2 if wall_1 > wall_2 else wall_1
	total_water = 0
	for part_water in water:
		total_water += amount - part_water
	return total_water
