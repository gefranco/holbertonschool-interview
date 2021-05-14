#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
int count(binary_tree_t *root);
int *path(int count);
int swap(binary_tree_t **current);
int get_current_node(binary_tree_t **current, int *n_path);
int reorder(binary_tree_t *current);

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: a double pointer to the root node of the heap
 * Return: 0 on fail, node n otherwise
 */
int heap_extract(heap_t **root)
{

	binary_tree_t *current;
	int data;
	int *n_path;
	int c;

	if (!root || !*root)
		return (0);
	c = count(*root);
	if (c == 1)
	{
		data = (*root)->n;
		/*free(*root);*/
		free(*root);
		*root = NULL;
		return (data);
	}


	current = *root;
	n_path = path(c);
	get_current_node(&current, n_path);

	if (current->left)
		current = current->left;
	data = (*root)->n;
	(*root)->n = current->n;

	if (current->parent->right == current)
		current->parent->right = NULL;
	else
		current->parent->left = NULL;
	free(current);
	free(n_path);
	current = *root;

	reorder(current);
	return (data);

}
/**
 * path - The path to go from the root to the node to insert a newone
 * @count: total nodes
 * Return: array of 1 and 0 representing the path
 */
int *path(int count)
{
	int j;
	int i = 0;
	int *path = NULL;

	int bkcount = count * 2;

	count = count * 2;
	while ((count = count / 2) > 1)
	{
		i++;
	}

	path = malloc(sizeof(int) * (i + 1));

	path[i] = -1;

	for (j = i - 1; (bkcount = bkcount / 2) > 1 ; j--)
	{
		path[j] = bkcount % 2;
	}
	return (path);
}
/**
 * get_current_node - traverse the path to the node to insert a newone
 * @current: Pointer to the root node
 * @n_path: path to traverse 0-left 1-right
 * Return: the position of the node
 */
int get_current_node(binary_tree_t **current, int *n_path)
{
	int i = 0;

	while (n_path[i] != -1)
	{
		if ((*current)->left == NULL || (*current)->right == NULL)
			return (i);
		if (n_path[i] == 0)
			*current = (*current)->left;
		else if (n_path[i] == 1)
			*current = (*current)->right;
		i++;
	}
	return (i);
}
/**
 * swap - swap the value of the node with his parent's value
 * @current: Pointer to the root node
 * Return: 0 on success
 */
int swap(binary_tree_t **current)
{
	int data;

	data = (*current)->parent->n;
	{
		(*current)->parent->n = (*current)->n;
		(*current)->n = data;
	}
	return (0);
}
/**
 * reorder - reorder a Min Binary Heap
 * @current: a pointer to current node
 * Return:  a pointer to the data
 */
int reorder(binary_tree_t *current)
{
	while (current->left || current->right)
	{
		if (!current->right ||
			current->left->n > current->right->n)
		current = current->left;
		else
			current = current->right;
		if (current->parent->n < current->n)
			swap(&current);
	}
	return (0);
}

/**
 * count - count the nodes in a binary tree
 * @root: a pointer to the root node of the tree
 * Return: 0 on fail, number of nodes otherwise
 */
int count(binary_tree_t *root)
{
	int c = 1;

	if (root == NULL)
		return (0);
	c += count(root->left);
	c += count(root->right);
	return (c);
}
