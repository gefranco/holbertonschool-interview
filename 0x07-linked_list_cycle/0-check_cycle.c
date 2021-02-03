#include <stdio.h>
#include "lists.h"
int check_cycle(listint_t *list)
{
	listint_t *current, *faster;

	current = list;
	if (list->next)
		faster = list->next->next;

	while (current != NULL && faster != NULL)
	{
		if (current == faster)
		{
			return (1);
		}
		current = current->next;
		if (faster->next)
			faster = faster->next->next;
	}
	return (0);
}
