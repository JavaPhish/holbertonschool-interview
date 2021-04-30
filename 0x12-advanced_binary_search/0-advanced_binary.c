#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_array - Prints the binary search tree array
 * @array: The array to print
 * @len: The size of the array
 *
 * Return: None
 */
void print_array(int *array, size_t len)
{
	int i;

	printf("Searching in array:");

	for (i = 0; i < (int)len; i++)
	{
		if (i == 0)
			printf(" %d", array[i]);
		else
			printf(", %d", array[i]);
	}

	printf("\n");
}

/**
 * binary_search - bin search
 * @array: The array to search
 * @value: the value searching for
 * @index: The index currently tracked
 * @len: Length of the tree/array
 *
 * Return: Index or -1 on failure
 */
int binary_search(int *array, int value, int index, size_t len)
{
	int split;

	/*
	 * Essentially just split the array in half, compare each side (Its sorted)
	 * continue recursively until we reach the left most index of value
	 * Return said index
	 */

	print_array(array, len);

	if (len == 1)
	{
		if (array[0] == value)
			return (index);

		return (-1);
	}

	if (len == 2)
	{
		if (array[0] == value)
			return (index);
		return (binary_search(array + 1, value, index + 1, 1));
	}

	split = (len - 1) / 2;

	if (array[split] >= value)
		return (binary_search(array, value, index, split + 1));

	return (binary_search(array + 1 + split,
				    value, index + 1 + split,
				    len - (split + 1)));
}

/**
 * advanced_binary - Advanced binary search (recursive)
 * @size: Size of the binary tree
 * @value: The value we're searching for
 *
 * Return: The node containing value
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (binary_search(array, value, 0, size));
}
