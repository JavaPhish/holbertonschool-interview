#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * linear_skip - Linear searches a skip list
 * @list: The list
 * @value: The value we are searching for
 *
 * Return: Pointer to node containing value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node = list->express, *tail = list;

	if (!list)
		return (NULL);
	/* Find the correct express node */
	while (node)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)node->index, node->n);
		if (node->n >= value)
		{
			printf("Value found between indexes [%d] and [%d]\n",
			       (int)tail->index, (int)node->index);
			break;
		}
		if (node->express == NULL)
		{
			tail = node;
			while (node->next)
				node = node->next;
			printf("Value found between indexes [%d] and [%d]\n",
			       (int)tail->index, (int)node->index);
			break;
		}
		tail = node;
		node = node->express;
	}
	/* Search the section indicated by the express lanes */
	while (tail)
	{
		if (tail->n == value)
		{
			printf("Value checked at index [%d] = [%d]\n",
				 (int)tail->index, tail->n);
			return (tail);
		}
		printf("Value checked at index [%d] = [%d]\n",
			 (int)tail->index, tail->n);
		tail = tail->next;
	}
	return (NULL);
}
