#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * sandpiles_sum - S
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] = grid1[x][y] + grid2[x][y];
		}
	}
	printf("=\n");
	printGrid(grid1);
	while (isSolved(grid1) == 0)
	{
		if (grid1[1][1] > 3)
		{
			grid1[1][1] -= 4;
			grid1[1][2] += 1, grid1[2][1] += 1, grid1[0][1] += 1, grid1[1][0] += 1;
		}
		/*mids*/
		if (grid1[1][2] > 3)
		{
			grid1[1][2] -= 4;
			grid1[1][1] += 1, grid1[2][2] += 1, grid1[0][2] += 1;
		}
		if (grid1[2][1] > 3)
		{
			grid1[2][1] -= 4;
			grid1[2][0] += 1, grid1[1][1] += 1, grid1[2][2] += 1;
		}
		if (grid1[0][1] > 3)
		{
			grid1[0][1] -= 4;
			grid1[0][0] += 1, grid1[0][2] += 1, grid1[1][1] += 1;
		}
		if (grid1[1][0] > 3)
		{
			grid1[1][0] -= 4;
			grid1[0][0] += 1, grid1[1][1] += 1, grid1[2][0] += 1;
		}

		/* corners */
		if (grid1[0][2] > 3)
		{
			grid1[0][2] -= 4;
			grid1[0][1] += 1, grid1[1][2] += 1;
		}
		if (grid1[2][2] > 3)
		{
			grid1[2][2] -= 4;
			grid1[2][1] += 1, grid1[1][2] += 1;
		}
		if (grid1[0][0] > 3)
		{
			grid1[0][0] -= 4;
			grid1[0][1] += 1, grid1[1][0] += 1;
		}
		if (grid1[2][0] > 3)
		{
			grid1[2][0] -= 4;
			grid1[1][0] += 1, grid1[2][1] += 1;
		}
		printf("=\n");

		printGrid(grid1);
	}

}

/**
 * isSolved - Checks if a grid is balanced/solved
 * @grid: The grid to verify
 *
 * Return: 1 on true, 0 otherwise
 */

int isSolved(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] > 3)
			{
				return (0);
			}
		}
	}

	return (1);
}

/**
 * printGrid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void printGrid(int grid[3][3])
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
