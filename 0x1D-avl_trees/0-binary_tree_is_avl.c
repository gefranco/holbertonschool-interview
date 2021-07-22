#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
int valid_node(const binary_tree_t *node, int min_val, int max_val, int, int);
int abs_val(int val);
int binary_tree_is_avl(const binary_tree_t *tree)
{
	static int height_left = 0;
	static int height_right = 0;
	if (tree == NULL)
		return (0);
	
	return valid_node(tree, INT_MAX, 0, height_left, height_right);	
}

int valid_node(const binary_tree_t *node, int max_val, int min_val, int height_left, int height_right)
{
	if (node == NULL)
		return (1);

	if(node->n >= max_val || node->n <= min_val)
		return (0);
	
	if (!valid_node(node->left, node->n, min_val, height_left++, height_right) ||
		!valid_node(node->right, max_val, node->n, height_left, height_right++))
		return (0);
	if (abs_val(height_left - height_right) > 2)
		return (0);
		
	return (1);
}
int abs_val(int val)
{
	if(val < 0)
		return (val * -1);
	return (val);	
}
