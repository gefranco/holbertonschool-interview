#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
listint_t *insert_node(listint_t **head, int number)
{
	
	listint_t *current = *head;
	listint_t *new, *tmp;
	int end = 1;

	new = malloc(sizeof(listint_t));
	if(new == NULL)
		return NULL;
        new->n = number;
	new->next = NULL;
	if (*head == NULL)
	{
        	*head = new;	
		return new;
	}
	if(current->n > number)
	{
		tmp = *head;
		*head = new;
		new->next = tmp;
		return new;
		
	}
	
	while(current->next)
	{
		if(current->next->n > number)
		{
			end = 0;
			break;
		}
		current = current->next;
	}
	printf("current:%d \n",current->n);
	new = malloc(sizeof(listint_t));
	new->n = number;
	if(!end)
	{
		tmp = current->next;
		current->next = new;
		new->next = tmp;
	}
	else
	{
		current->next = new;
	}
	return new;
}
