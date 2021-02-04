#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - Checks if a linked list has a cycle in it
 * @list: The list to check
 *
 * Return: 1 if the list contains a linked list
 */
int check_cycle(listint_t *list)
{
	listint_t *tail = list;
	listint_t *head = list;

	/*
	 * if the list is null, nothings there
	 * so no cycle (technically)
	 */
	if (!list)
		return (0);


	while (head->next != NULL && tail->next != NULL)
	{
		/*
		 * Head moves twice as fast as tail
		 */
		head = head->next;
		if (head == NULL)
			return (0);

		head = head->next;
		if (head == NULL)
			return (0);

		tail = tail->next;


		/*
		* If tail and head ever meet, the head has cycled
		* and a cycle exists
		*/
		if (head == tail)
		return (1);
	}

	/*
	 * If we made it here, we looped through
	 * whole list without issue AKA no cycle
	 */
	return (0);
}
