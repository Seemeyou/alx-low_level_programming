#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_grid - frees array
 * @grid: grid
 * @height: height of grid
 * Description: frees memory
 * Return: none
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
