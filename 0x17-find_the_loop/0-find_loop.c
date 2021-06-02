#include "lists.h"

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first;
	listint_t *second;

	first = head->next;
	second = head;
	while (first->next)
	{
		first = first->next->next;
		second = second->next;
		if (first == second)
			return (first);
	}
	
	return NULL;
}
