#include "search.h"
#include <math.h>
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev;
	size_t last_index;
	/*while(list)
	{
				
		printf("%ld\n", list->index);
		list = list->express;
	}
	*/
	while (list->express)
	{
		prev = list;
		list = list->express;
		printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
		if (list->n > value)
		{
			printf("Value found between indexes [%ld] and [%ld]\n",
				prev->index, list->index);
			while (prev->index <= list->index)
			{
				printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);
				if (value == prev->n)
					return (prev);
				prev = prev->next;
			}
		}
	}
	prev = list;
	last_index = list->index - 1;
	while (prev)
	{
		prev = prev->next;
		last_index++;
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
                                list->index, last_index);
	while(list)
	{
		printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
                if (value == list->n)
                	return (list);
		list = list->next;
	}
	return (NULL);
}
