#include <stdio.h>
#include "menger.h"

/**
 * menger - Prints a menger sponge
 * @level: The size of the sponge
 *
 * Return: Nothing...
 */
void menger(int level)
{
	int x, j, dim = 1, fract;

	for (x = 0; x < level; x++)
		dim *= 3;

	for (x = 0; x < dim; x++)
	{
		for (j = 0; j < dim; j++)
		{
			for (fract = dim / 3; fract; fract /= 3)
				if ((x % (fract * 3)) / fract == 1)
					if ((j % (fract * 3)) / fract == 1)
						break;

			if (fract)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
