#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * heap_sort - Heap sort an array
 * @array: The array to sort
 * @size: the size of the array
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int s_heap, swap;

	for (s_heap = size / 2 - 1; s_heap >= 0; s_heap--)
		sift_down(array, (int)size, s_heap, (int)size);

	for (s_heap = size - 1; s_heap > 0; s_heap--)
	{
		swap = array[0];
		array[0] = array[s_heap];
		array[s_heap] = swap;
		print_array(array, (int)size);
		sift_down(array, s_heap, 0, (int)size);
	}
}

/**
 * sift_down - Converts array to a max heap
 * @array: The array to convert
 * @start: start of heap
 * @len: the size of the array
 * @heap_len: Length of the heap
 *
 * Return: Nothing
 *
 */
void sift_down(int *array, int heap_len, int start, int len)
{
	int swap, left, right, max = start;

	left = 2 * start + 1;
	right = 2 * start + 2;

	if (left < heap_len && array[left] > array[max])
		max = left;

	if (heap_len > right && array[right] > array[max])
		max = right;

	if (max != start)
	{
		swap = array[start];
		array[start] = array[max];
		array[max] = swap;
		print_array(array, len);
		sift_down(array, heap_len, start, max);
	}
}
