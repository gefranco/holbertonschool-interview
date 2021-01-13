#include <stdio.h>
void toppling(int grid[3][3], int positions[3][3]);
int stable_grid(int grid[3][3]);

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

void get_positions(int grid[3][3], int positions[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				positions[i][j] = 1;
		}
	}

}

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

	int i, j;
	int positions[3][3] = {
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}

	while (!stable_grid(grid1))
	{
		printf("=\n");

		print_grid(grid1);

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				positions[i][j] = 0;
		get_positions(grid1, positions);
		toppling(grid1, positions);
	}
}


int stable_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

void toppling(int grid[3][3], int positions[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (positions[i][j])
			{
				grid[i][j] = grid[i][j] - 4;
				if (j - 1 >= 0) /*left*/
					grid[i][j - 1] = grid[i][j - 1] + 1;
				if (j + 1 < 3) /*right*/
					grid[i][j + 1] = grid[i][j + 1] + 1;
				if (i - 1 >= 0)/*up*/
					grid[i - 1][j] = grid[i - 1][j] + 1;
				if (i + 1 < 3)/*down*/
					grid[i + 1][j] = grid[i + 1][j] + 1;
			}
		}
	}
}
