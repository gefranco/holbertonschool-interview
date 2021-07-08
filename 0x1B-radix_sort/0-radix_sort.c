#include <stdlib.h>
#include "sort.h"


typedef struct List
{
	int number;
	struct List *next;
} List;
List *addNumber(List *init, int number);
int free_list(List *list);
void radix_sort(int *array, size_t size)
{
	

	size_t i, j;
	int digit;
	int exp = 1;
	int max_number = 0;
	int *sorted_array;

	List *node = NULL;
	List *sort[10] = {NULL};

	sorted_array = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
	{
	
		max_number = array[i] > max_number ? array[i] :  max_number;
		sorted_array[i] = array[i];
	}
	while (max_number/exp > 0)
	{
		for (i = 0; i < size; i++)
			sort[i] = NULL;
		/*sorted_array = malloc(sizeof(int) * size);*/
		for (i = 0; i < size; i++)
		{
			digit = sorted_array[i] / exp % 10;
			if (!sort[digit])
				sort[digit] = addNumber(NULL, sorted_array[i]);
			else
				addNumber(sort[digit], sorted_array[i]);
		/*(sort[digit])->number = array[i]; */
			/*printf("%d \n", digit);*/
		}
		for (i = 0, j = 0; i < size; i++)
		{
			if (sort[i])
			{
				node = sort[i];
				while (node)
				{
					/*printf("%d, ", node->number);*/
					sorted_array[j] = node->number;
					node = node->next;
					j++;
				}
			}
		}
		print_array(sorted_array, size);
		exp *= 10;
		/*free_list(sorted_array);*/
	}
}

int free_list(List *list)
{
	List *tmp;
	

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	return (0);
}


List *addNumber(List *init, int number)
{


	List *node = NULL;
	List *tmp = init;
	
	if (!init)
	{
		init = malloc(sizeof(List));
		init->number = number;
		init->next = NULL;
		return (init);
	}

	while(tmp->next)
		tmp = tmp->next;
	node = malloc(sizeof(List));
	node->number = number;
	tmp->next = node;
	node->next = NULL;
	return init;
}
