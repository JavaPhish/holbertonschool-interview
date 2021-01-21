#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - recursively checks if a linked list is a palindrome
 * @head: The list to check
 *
 * Return: 1 if true, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	return (is_palindrome_help(&(*head), (*head)));
}

/**
 * is_palindrome_help - recursive driver
 * @left: The left node
 * @right: The right node
 *
 * Return: 1 on success, 0 if not palin
 */
int is_palindrome_help(listint_t **left, listint_t *right)
{
	int temp;

	/* see if we reached end */
	if (right == NULL)
		return (1);

	/* Check if the list matches */
	if (is_palindrome_help(left, right->next) == 0)
		return (0);

	/* Store left and right comparison b4 we change the left node */
	temp = (right->n == (*left)->n);

	*left = (*left)->next;

	/* Return the comparison result */
	return (temp);
}
