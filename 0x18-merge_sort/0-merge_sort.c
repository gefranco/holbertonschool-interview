#include "sort.h"
#include <stdio.h>
void merge(int *array, int *left, int *right, size_t size);
void merge_sort(int *array, size_t size)
{
	size_t middle, i;
	int left[100], right[100];

	if (array == NULL || size == 1)
		return;
	middle = size / 2;

	for (i = 0; i < middle; i++)
		left[i] = array[i];
	for (i = middle; i < size; i++)
		right[i - middle] = array[i];

	merge_sort(left, middle);
	merge_sort(right, size - middle);

	merge(array, left, right, size);
}

void merge(int *array, int *left, int *right, size_t size)
{
	int i, j, k;
	int size_left, size_right;

	i = j = k = 0;
	(void)array;

	size_left = size / 2;
	size_right = size - size_left;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);

	while (i < size_left && j < size_right)
	{
		if (left[i] < right[j])
		{
			array[k] = left[i];
			i += 1;
		}
		else
		{
			array[k] = right[j];
			j += 1;
		}
		k += 1;
	}
	while (i < size_left)
	{
		array[k] = left[i];
		k += 1;
		i += 1;
	}
	while (j < size_right)
	{
		array[k] = right[j];
		k += 1;
		j += 1;
	}
	printf("[Done]: ");
	print_array(array, size);
}
