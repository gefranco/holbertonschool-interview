#include "list.h"
#include <stdlib.h>
#include <string.h>
/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: A pointer to the head of the linkd list
 * @str: the string to copy into the node
 * Return: pointer to the created node
 */
List *add_node_end(List **list, char *str)
{
	List *node, *tmp = *list;

	if (!list)
		return (NULL);
	if (!*list)
	{
		node = malloc(sizeof(List));
		if (!node)
			return (NULL);
		node->str = strdup(str);
		if (str != NULL && node->str == NULL)
		{
			free(node);
			return (NULL);
		}
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
	if (!node)
		return (NULL);
	node->str = strdup(str);
	if (str != NULL && node->str == NULL)
	{
		free(node);
		return (NULL);
	}
	tmp->next = node;
	node->prev = tmp;
	node->next = *list;
	(*list)->prev = node;
	return (node);
}

/**
 * add_node_begin - Add a new node to the beginning of a double linked list
 * @list: A pointer to the head of the linkd list
 * @str: the string to copy into the node
 * Return: pointer to the created node
 */
List *add_node_begin(List **list, char *str)
{
	List *node, *tmp = *list;

	if (!list)
		return (NULL);
	node = malloc(sizeof(List));
	if (!node)
		return (NULL);
	node->str = strdup(str);
	if (str != NULL && node->str == NULL)
	{
		free(node);
		return (NULL);
	}

	if (!*list)
	{
		node->next = node;
		node->prev = node;
		*list = node;
		return (node);
	}
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
