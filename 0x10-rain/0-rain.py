def rain(walls):
	rain = 0
	wall_1 = 0
	rain_collected = 0
	rain_count = 0;
	
	first_wall = 0;
	for wall in walls:
		if wall > wall_1:
			first_wall = 1
			wall_1 = wall
			if first_wall == 1:
				rain_count = wall_1
			continue
		if wall <  wall_1:
			rain_collected += rain_count
			
	return rain_collected;
