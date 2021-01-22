#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
int compare(listint_t *current, listint_t **head);
/**
 * is_palindrome - hecks if a singly linked list is a palindrome
 * @head: pointer to list to check
 * Return: 1 if is palindrome 0 if not
 */
int is_palindrome(listint_t **head)
{
	return (compare(*head, head));
}

int compare(listint_t *current, listint_t **head)
{
	if (!(current))
		return 1;

	if(compare(current->next, head))
	{
		if (current->n == (*head)->n)
		{
			(*head) = (*head)->next;
			return 1;
		}
	}
	return 0;
}
