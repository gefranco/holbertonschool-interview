#include "lists.h"

/**
 * find_listint_loop -  finds the loop in a linked list
 * @head: head linked list pointer
 * Return: node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first, *second;

	if (!head || !head->next)
		return (NULL);

	first = head->next->next;
	second = head->next;
	while (first && second && first->next)
	{
		if (first == second)
		{
			second = head;
			while (second != first)
			{
				second = second->next;
				first = first->next;
			}
			return (second);
		}
		first = first->next->next;
		second = second->next;
	}

	return (NULL);
}
