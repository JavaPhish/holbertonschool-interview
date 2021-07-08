#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * max - Max value in array
 * @array: The array to search
 * @size: The girth of the array
 *
 * Return: Max
 */
int max(int *array, size_t size)
{
	int max = 0, loop;

	for (loop = 1; loop < (int)size; loop++)
	{
		if (array[loop] > max)
			max = array[loop];
	}

	return (max);
}

/**
 * radix_sort - LSD Implementation of radix sort
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int bucket[10][10], bucket_buffer[10];
	int large, remainder, products = 0, loop, divisor = 1, x, y;

	if (size < 2)
		return;

	large = max(array, size);

	while (large > 0)
	{
		products++;
		large /= 10;
	}

	while (products > 0)
	{
		for (loop = 0; loop < 10; loop++)
			bucket_buffer[loop] = 0;

		for (loop = 0; loop < (int)size; loop++)
		{
			remainder = (array[loop] / divisor) % 10;
			bucket[remainder][bucket_buffer[remainder]] = array[loop];
			bucket_buffer[remainder] += 1;
		}

		loop = 0;
		for (x = 0; x < 10; x++)
		{
			for (y = 0; y < bucket_buffer[x]; y++)
			{
				array[loop] = bucket[x][y];
				loop++;
			}
		}

		divisor *= 10;
		print_array(array, size);
		products--;
	}
}
