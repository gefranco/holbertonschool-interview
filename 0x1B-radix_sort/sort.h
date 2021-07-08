#ifndef _SORT_
#define _SORT_
/**
 * struct List - linked list
 * @number: int - (malloc'ed number)
 * @next: points to the next node
 *
 * Description: linked list node structure
 */
typedef struct List
{
	int number;
	struct List *next;
} List;
List *addNumber(List *init, int number);
int free_list(List *list);
void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
#endif
