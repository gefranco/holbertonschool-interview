#ifndef _LISTS_H
#define _LISTS_H

#include <stddef.h>

typedef struct listint_s
{
	int n;
	struct listint_s *next;
	
} listint_t;

listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);

listint_t *find_listint_loop(listint_t *head);

#endif
