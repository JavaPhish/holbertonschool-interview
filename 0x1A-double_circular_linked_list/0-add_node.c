#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


/**
 * add_node_end - Adds node to end of a circly linked list
 * @list: THe list to add to
 * @str: The data to add
 *
 * Return: The address of the new node
 */
List *add_node_end(List **list, char *str)
{
	List *n_start, *node, *new_node;

	if (!list || !str)
		return (NULL);
	if ((*list) == NULL)
	{
		(*list) = malloc(sizeof(List));
		if (!(*list))
			return (NULL);
		(*list)->str = strdup(str);
		return (*list);
	}

	if ((*list)->next == NULL)
	{
		node = malloc(sizeof(List));
		if (!node)
			return (NULL);
		node->str = strdup(str);
		node->prev = (*list);
		node->next = (*list);
		(*list)->next = node;
		return (node);
	}
	n_start = (*list);
	node = (*list);
	while (node->next != n_start)
		node = node->next;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	node->next = new_node;
	new_node->prev = node;
	new_node->next = n_start;
	n_start->prev = new_node;
	new_node->str = strdup(str);

	return (new_node);
}

/**
 * add_node_begin - Adds node to the beginning of a circly linked list
 * @list: The list to add to
 * @str: The data to add
 *
 * Return: The address of the new node
 */
List *add_node_begin(List **list, char *str)
{
	List *head, *tail, *new_node;

	if (!list || !str)
		return (NULL);
	if ((*list) == NULL)
	{
		(*list) = malloc(sizeof(List));
		if (!list)
			return (NULL);
		(*list)->str = str;
		return (*list);
	}
	if ((*list)->next == NULL)
	{
		new_node = malloc(sizeof(List));
		if (!new_node)
			return (NULL);
		new_node->str = str;
		(*list)->next = new_node;
		(*list)->prev = new_node;
		new_node->next = (*list);
		new_node->prev = (*list);
		(*list) = new_node;
		list = &new_node;
		return (new_node);
	}
	head = (*list);
	tail = (*list)->prev;
	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = str;
	new_node->next = head;
	new_node->prev = tail;
	tail->next = new_node;
	head->prev = new_node;
	(*list) = new_node;
	list = &new_node;

	return (new_node);
}
