#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * array_to_avl - builds an AVL tree from an array recursibly
 *
 * @array: The array
 * @start: The start index of the array
 * @end: the end index of the array
 * Return: pointer to the root array
 */
avl_t *array_to_avl(int *array, size_t start, size_t end)
{
	avl_t *node;
	size_t midle =  (start + end) / 2;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
	{
		return (NULL);
	}
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	if (start > end)
	{
		return (NULL);
	}
	node->n = array[midle];
	if (midle != start)
		node->left = array_to_avl(array, start, midle - 1);
	if (node->left)
		node->left->parent = node;
	if (midle != end)
		node->right = array_to_avl(array, midle + 1, end);
	if (node->right)
		node->right->parent = node;

	return (node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: The array
 * @size: Size of the array
 * Return: pointer to the root array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (size == 0)
		return (NULL);
	return (array_to_avl(array, 0, size - 1));
}
