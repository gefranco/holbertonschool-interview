#include <stdio.h>
#include "lists.h"

int is_palindrome(listint_t **head)
{
	listint_t **n, *c, *temp;

	if (!*head || (*head)->next == NULL)
		return (1);
	n = head;
	c = *head;

	while (c->next)
	{
		temp = c;
		c = c->next;
	}

	if ((*n)->n != c->n)
	{
		printf("not");
		return (0);
	}
	else
	{
		*head = (*head)->next;

		temp->next = NULL;
		return (is_palindrome(head));

	}

}
