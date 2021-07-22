#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
int valid_node(const binary_tree_t *node, int min_val, int max_val, int *height);
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;
	if (tree == NULL)
		return (0);
	
	return valid_node(tree, INT_MAX, 0, &height);	
}

int valid_node(const binary_tree_t *node, int max_val, int min_val, int *height)
{
	if (node == NULL)
		return (1);

	if(node->n >= max_val || node->n <= min_val)
		return (0);
	
	if (!valid_node(node->left, node->n, min_val, height) ||
		!valid_node(node->right, max_val, node->n, height))
		return (0);
	return (1);
}
