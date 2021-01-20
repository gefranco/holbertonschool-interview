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
		free(c);
		return (0);
	}
	else
	{
		thead = *head;
		*head = (*head)->next;
		temp->next = NULL;
		free(thead);
		free(c);
		return (is_palindrome(head));

	}

}
