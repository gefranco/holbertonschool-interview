#include "list.h"
#include <stdio.h>
#include <stdlib.h>
List *add_node_end(List **list, char *str)
{
	List *tmp = *list;
	List *node;

	if (!*list)
	{
		node = malloc(sizeof(List));
		node->str = str;
		node->next = node;
		node->prev = node;

		*list = node;
		return (node);
	}

	while (tmp)
	{
		if (tmp->next == *list)
			break;

		tmp = tmp->next;
	}
	node = malloc(sizeof(List));
	node->str = str;
	tmp->next = node;
	node->prev = tmp;
	node->next = *list;
	(*list)->prev = node;
	return (node);
}

List *add_node_begin(List **list, char *str)
{
	List *tmp = *list;
	List *node;

	if (!*list)
	{
		node = malloc(sizeof(List));
		node->str = str;
		node->next = node;
		node->prev = node;

		*list = node;
		return (node);
	}
	node = malloc(sizeof(List));
	node->str = str;

	node->next = *list;
	(*list)->prev = node;

	while (tmp)
	{
		if (tmp->next == *list)
			break;
		tmp = tmp->next;
	}

	tmp->next = node;
	*list = node;

	if (!(*list)->prev)
		(*list)->prev = tmp;

	return (node);
}
