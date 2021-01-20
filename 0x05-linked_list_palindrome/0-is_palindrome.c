#include <stdlib.h>
#include "lists.h"

int is_palindrome(listint_t **head)
{
	listint_t *c, *temp, *thead = NULL;

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
		thead = *head;
		*head = (*head)->next;
		temp->next = NULL;
		free(thead);
		return (is_palindrome(head));

	}

}
