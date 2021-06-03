#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * fine_listint_loop - Finds the starting node in a loop in a linked list
 * @head: The list to check
 *
 * Return: The node starting a loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle, *hare;

	/* No loop if no more than one node */
	if (!head || !head->next)
		return (NULL);

	hare = head;
	turtle = head;

	turtle = turtle->next;
	hare = hare->next->next;

	/* Search if a loop even exists */
	while (hare && hare->next)
	{
		if (turtle == hare)
			break;

		turtle = turtle->next;
		hare = hare->next->next;
	}

	if (hare != turtle)
		return (NULL);

	/* Search for the loops location using the meeting point */
	turtle = head;

	while (turtle != hare)
	{
		turtle = turtle->next;
		hare = hare->next;
	}

	return (hare);
}
