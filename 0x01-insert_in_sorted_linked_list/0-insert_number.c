#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a node into a sorted linked list
 * @head: The list to insert into
 * @number: The value of the node to insert
 *
 * Return: The newly created node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL;
	listint_t *temp = NULL;
	listint_t *srch = (*head);

	/* Check if the list is valid */
	if (!*head)
		return (NULL);

	/* Create the new node and assign it */
	new = malloc(sizeof(listint_t));
	new->n = number;

	if (!new)
		return (NULL);

	/* Traverse the list until we find a lesser value or the end */
	while (srch->next != NULL)
	{
		if (srch->next->n > number)
			break;

		srch = srch->next;
	}

	/* Place the node */
	temp = srch->next;
	srch->next = new;
	new->next = temp;

	return (new);
}
