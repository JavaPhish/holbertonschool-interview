#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * slide_line - 2048
 * @line: the line to slide
 * @size: The size of the line
 * @direction: The direction to slide
 *
 * Return: 1 on success, otherwise
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		return (slide_left(line, size));
	}
	else if (direction == SLIDE_RIGHT)
	{
		return (slide_right(line, size));
	}
	return (0);
}

/**
 * slide_left - Slides left
 * @line: The line
 * @size: The size of the line
 *
 * Return: 1 on success
 */
int slide_left(int *line, size_t size)
{
	int loop, y;

	/* Add all same touching values */
	for (loop = 0; loop < (int)size; loop++)
		if (line[loop] != 0)
			for (y = loop + 1; y < (int)size; y++)
				if (line[y] == line[loop])
				{
					line[loop] += line[y];
					line[y] = 0;
					break;
				}
	/* Push all values to the right/together */
	for (loop = 0; loop < (int)size - 1; loop++)
		if (line[loop] == 0)
			for (y = loop + 1; y < (int)size; y++)
				if (line[y] != 0)
				{
					line[loop] = line[y];
					line[y] = 0;
					break;
				}
	return (1);
}

/**
 * slide_right - Slides right
 * @line: The line
 * @size: The size of the line
 *
 * Return: 1 on success
 */
int slide_right(int *line, size_t size)
{
	int loop, y;

	/* Add all same touching values */
	for (loop = (int)size; loop >= 0; loop--)
		if (line[loop] != 0)
			for (y = loop - 1; y >= 0; y--)
				if (line[y] == line[loop])
				{
					line[loop] += line[y];
					line[y] = 0;
					break;
				}
	/* Push all values to the right/together */
	for (loop = (int)size - 1; loop >= 0 ; loop--)
		if (line[loop] == 0)
			for (y = loop; y >= 0; y--)
				if (line[y] != 0)
				{
					line[loop] = line[y];
					line[y] = 0;
					break;
				}
	return (1);
}
