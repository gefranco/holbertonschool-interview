#include <stdlib.h>
#include "slide_line.h"
#include <stdio.h>

int merge_right(int *line, size_t size);
int merge_left(int *line, size_t size);
int slide_right(int *line, size_t size);
int slide_left(int *line, size_t size);

int slide_line(int *line, size_t size, int direction)
{
	(void) line;
	(void) size;
	(void) direction;
	if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		merge_right(line, size);
		slide_right(line, size);
	}
	else
	{
		slide_left(line, size);
		merge_left(line, size);
		slide_left(line, size);
	}
	return (1);
}

int slide_left(int *line, size_t size)
{
	size_t i, j;
        j = 0;
        for(i = 0; i < size; i++)
        {
                if (line [i] != 0 && i != j)
                {
                        line[j] = line[i];

                        line[i] = 0;
                        j += 1;
                }
                else if (line[i] != 0)
                {
                        j+=1;
                        continue;
                }
        }
	return 1;
}
int merge_left(int *line, size_t size)
{
	size_t i;
	for (i = 0; i < size; i++)
        {
                if (line[i] == line[i + 1])
                {
                        line[i] = line[i] + line[i + 1];
                        /*line[i + 1] = line[i + 2];*/
                        line[i + 1] = 0;
                }
        }
	return 1;
}
int slide_right(int *line, size_t size)
{
	size_t i, j;
        j = size - 1;
        for(i = size - 1; (i + 1) > 0; i--)
        {
                if (line [i] != 0 && i != j)
                {
                        line[j] = line[i];

                        line[i] = 0;
                        j -= 1;
                }
                else if (line[i] != 0)
                {
                        j-=1;
                        continue;
                }
        }
	return 1;	
}

int merge_right(int *line, size_t size)
{
        size_t i;
        for (i = size - 1; (i + 1) > 0; i--)
        {
                if (line[i] == line[i - 1])
                {
                        line[i] = line[i] + line[i - 1];
                        /*line[i + 1] = line[i + 2];*/
                        line[i - 1] = 0;
                }
        }
        return 1;
}
