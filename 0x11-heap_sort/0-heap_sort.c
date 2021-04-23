#include <stdio.h>
#include "sort.h"
int greater_child(int *array, size_t i_1, size_t i_2);
int swap(int *array, size_t i, size_t i_2);
/**
 * heap_sort - sorts an array in ascending order using the Heap sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	size_t greater;
	size_t i = (size / 2) - 1;
	size_t i_1, i_2, size_2;

	size_2 = size - 1;
	if (!array)
		return;

	i_1 = (i * 2) + 1;
	i_2 = i_1 + 1;

	for (; i + 1 > 0 && size_2 > 1; i--, i_1 = (i * 2) + 1, i_2 = i_1 + 1)
	{
		greater = greater_child(array, i_1, i_2);
		if (array[i] < array[greater])
		{
			swap(array, i, greater);
			print_array(array, size);
			if (greater * 2 < (size_2 - 1))
			{
				i = greater + 1;
			}

		}

		if (i == 0)
		{
			swap(array, i, size_2);
			print_array(array, size);
			size_2 -= 1;
			i = 0 + 1;

		}
	}
}

/**
 * greater_child - return the index of the greater number in an array
 * @array: array of integers
 * @i_1: number's 1 index
 * @i_2: number's 2 index
 * Return: greater number index
 */
int greater_child(int *array, size_t i_1, size_t i_2)
{
	if (array[i_1] > array[i_2])
		return (i_1);
	else
		return (i_2);
}

/**
 * swap - return the index of the greater number in an array
 * @array: array of numbers
 * @i: number's 1 index
 * @i_2: number's 2 index
 * Return: 0 on success
 */
int swap(int *array, size_t i, size_t i_2)
{
	int tmp;

	tmp = array[i];
	array[i] = array[i_2];
	array[i_2] = tmp;


	return (0);
}
