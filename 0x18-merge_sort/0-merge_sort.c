#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two intervals together
 * @array: The array
 * @temp: Temp array to transfer from
 * @start:beginning of the merge
 * @mid: THe mid point
 * @end: THe end of the merge
 */
void merge(int *array, int *temp, int start, int mid, int end)
{
	int i, left, right;

	printf("Merging...\n");
	printf("[left]: ");

	print_array(temp + start, mid - start);

	printf("[right]: ");

	print_array(temp + mid, end - mid);

	for (i = left = start, right = mid; i < end; i++)
	{
		if (left < mid && (right >= end || temp[left] <= temp[right]))
			array[i] = temp[left++];
		else
			array[i] = temp[right++];
	}

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge_driver - Determines where to divide the array to conquer
 * @array: The array
 * @temp: Temp array to transfer from
 * @start: minimum
 * @end: Size
 */
void merge_driver(int *array, int *temp, int start, int end)
{
	int mid;

	if (end - start <= 1)
		return;

	mid = (start + end) / 2;
	merge_driver(temp, array, start, mid);
	merge_driver(temp, array, mid, end);
	merge(array, temp, start, mid, end);
}

/**
 * merge_sort - Top down merge sort
 * @array: The array to sort
 * @size: The size of it
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size <= 1)
		return;

	temp = malloc(size * sizeof(*temp));

	if (!temp)
		return;

	memcpy(temp, array, size * sizeof(*temp));
	merge_driver(array, temp, 0, size);
	free(temp);
}
