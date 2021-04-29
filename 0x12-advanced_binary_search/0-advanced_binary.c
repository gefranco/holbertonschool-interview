#include "search_algos.h"
#include <stdio.h>
int binary_search(int *array, int value, int start, int end);
/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: array of integers
 * @size: size of the array
 * @value: the value to search
 * Return: value's index or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	(void) value;
	if (size < 1)
		return (-1);

	return (binary_search(array, value, 0, size - 1));
}
/**
 * binary_search - searches for a value in a sorted array of integers
 * @array: array of integers
 * @start: start index
 * @end: end index
 * @value: the value to search
 * Return: value's index or -1 if not found
 */
int binary_search(int *array, int value, int start, int end)
{
	int i, middle;

	/*printf("start: %d end: %d\n", start, end);*/
	if ((end - start < 0))
		return (-1);
	printf("Searching in array: ");
	for (i = start; i < end; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("%d\n", array[i]);

	middle = (start + end) / 2;
	if (value == array[start])
	{
		return (start);
	}
	/*else if (value == array[middle]) return middle;*/
	else if (value > array[middle])
		return (binary_search(array, value, middle + 1, end));
	else if (value <= array[middle + 1])
		return (binary_search(array, value, start, middle));
	return (-1);
}
