#include <stdlib.h>
#include "lists.h"

int is_palindrome(listint_t **head)
{
	listint_t *c, *temp;

	if (!*head || (*head)->next == NULL)
		return (1);
	c = *head;

	while (c->next)
	{
		temp = c;
		c = c->next;
	}

	if ((*head)->n != c->n)
	{
		return (0);
	}
	else
	{
		*head = (*head)->next;
		free(c);
		temp->next = NULL;
		return (is_palindrome(head));

	}

}
