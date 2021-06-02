#include "lists.h"

/**
 * find_listint_loop -  finds the loop in a linked list
 * @head: head linked list pointer
 * Return: node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first, *second;
	
	if (!head)
		return (NULL);
	
	first = head->next;
	second = head;
	while (first->next)
	{
		first = first->next->next;
		second = second->next;
		if (first == second)
			return (first);
	}

	return (NULL);
}
