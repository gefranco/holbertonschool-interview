#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - hecks if a singly linked list is a palindrome
 * @head: pointer to list to check
 * Return: 1 if is palindrome 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *c, *temp, *thead;

	if (!*head || (*head)->next == NULL)
		return (1);
	c = *head;

	while (c->next)
	{
		temp = c;
		c = c->next;
	}
	/*printf("[%d, %d]\n", (*head)->n, c->n);*/
	if ((*head)->n != c->n)
	{

		return (0);
	}
	else
	{
		thead = *head;

		*head = (*head)->next;
		thead->next = NULL;
		free_listint(thead);
		/**thead = '\0';*/
		temp->next = NULL;
		free_listint(c);
		/*free(c);*/
		return (is_palindrome(head));

	}

}
