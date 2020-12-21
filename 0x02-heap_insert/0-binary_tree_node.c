#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Binary tree node
 * @parent: Pointer to the parent node
 * @value: Integer stored in the node
 * Return created node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;
	(void) value;
	(void) parent;
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	if (parent == NULL)
		node->parent = NULL;
	else
		node->parent = parent;
	node->n = value;
	return (node);
}
