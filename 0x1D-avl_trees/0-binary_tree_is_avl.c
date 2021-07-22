#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
int valid_node(const binary_tree_t *node, int min_val, int max_val, int, int);
int abs_val(int val);
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree:  a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	static int height_left;
	static int height_right;

	if (tree == NULL)
		return (0);

	return (valid_node(tree, INT_MAX, 0, height_left, height_right));
}

int valid_node(const binary_tree_t *node, int max_val,
		int min_val, int height_left, int height_right)
{
	if (node == NULL)
		return (1);

	if (node->n >= max_val || node->n <= min_val)
		return (0);

	if (!valid_node(node->left, node->n, min_val, height_left++, height_right) ||
		!valid_node(node->right, max_val, node->n, height_left, height_right++))
		return (0);
	if (abs_val(height_left - height_right) > 2)
		return (0);

	return (1);
}
/**
 * abs_val - absolute value
 * @val: the value to convert to absolute
 * Return: the absolute value
 */
int abs_val(int val)
{
	if (val < 0)
		return (val * -1);
	return (val);
}
