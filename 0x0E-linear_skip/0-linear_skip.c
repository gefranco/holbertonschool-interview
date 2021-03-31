#include "search.h"
#include <math.h>
skiplist_t *linear_skip(skiplist_t *list, int value)
{

	skiplist_t *last;

	while (list->express)
	{
		last = list;
		list = list->express;

		printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
		if (value < list->n)
		{
			printf("Value found between indexes [%ld] and [%ld]\n",
				last->index, list->index);
			while (last->index != list->index)
			{
				printf("Value checked at index [%ld] = [%d]\n", last->index, last->n);
				if (value == last->n)
					return (last);
				last = last->next;
			}
		}
		else if (!list->express)
		{
			printf("Value found between indexes [%ld] and [%ld]\n",
                                list->index, list->index - 1 + (list->index - last->index));
                        while (list)
                        {
                                printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
                                if (value == list->n)
                                        return (list);
				if (!list->next)	
					return(NULL);
				list = list->next;
                        }
		}
	}


	return (NULL);
}
