#include <stdio.h>
void toppling(int grid[3][3], int positions[3][3]);
int stable_grid(int grid[3][3]);
/**
 * print_grid - print a 3x3 array
 * @grid: the array to print
 */
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
/**
 * get_positions - search the position in which a toggle need to be made
 * @grid: array to search in
 * @positions: array to save the positions
 */
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
/**
 * sandpiles_sum - sum two sandpiles
 * @grid1: sandpile 1
 * @grid2: sandpile 2
 */
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

/**
 * stable_grid - look at array number greater than 3 to find if is not stable
 * @grid: the array
 * Return: 1 if stable or 0 if not
 */
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

/**
 * toppling - 'topple' each of the position given in positions
 * @grid: the array to do the 'toppling'
 * @positions: the arry with the positions
 */
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
