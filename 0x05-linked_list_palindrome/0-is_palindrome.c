#include <stdlib.h>
#include "lists.h"

int is_equal(listint_t **head);
int is_palindrome(listint_t **head)
{
	listint_t **shead;

	shead = head;
	return is_equal(shead);
}

/**
 * is_palindrome - hecks if a singly linked list is a palindrome
 * @head: pointer to list to check
 * Return: 1 if is palindrome 0 if not
 */
int is_equal(listint_t **head)
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
		/*thead->next = NULL;*/
		free(thead);
		/**thead = '\0';*/
		temp->next = NULL;
		free(c);
		/*free(c);*/
		return (is_palindrome(head));

	}

}
