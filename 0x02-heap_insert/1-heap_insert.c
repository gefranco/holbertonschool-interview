#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
void insert_left_node(heap_t **node, heap_t **current, int value, int count);
void insert_right_node(heap_t **node, heap_t **current, int value, int count);
/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: Pointer to the root node
 * @value: Integer stored in the node
 * Return: created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	static int count;
	heap_t *node, *current;
	int *n_path;
	int i;

	count++;
	node = malloc(sizeof(heap_t));
	if (count == 1)
	{
		*root = node;
		(*root)->n = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return (*root);
	}
	n_path = path(count);
	i = 0;
	current = *root;

	i = get_current_node(&current, n_path);
	if (n_path[i] == 0)
	{
		/*node->parent = current;
		node->n = value;
		current->left = node;
		node->left = NULL;
		node->right = NULL;*/
		if(value > (*root)->n)
			*root = node;
		insert_left_node(&node, &current, value, count);
		
		return (node);

	}
	else if(n_path[i] == 1)
	{
		/*node->parent = current;
		node->n = value;
		current->right = node;
		node->left = NULL;
		node->right = NULL;*/
		if(value > (*root)->n)
		{
			/*heap_t *left;*/
			
			/*root = binary_tree_node(NULL, 98);
        		root->left = binary_tree_node(root, 12);
        		root->left->left = binary_tree_node(root->left, 6);
        		root->left->right = binary_tree_node(root->left, 16);
			*/
			/*new_node = (*root)->right->left;
        		new_node = malloc(sizeof(heap_t));
                        new_node->n = (*root)->right->left->n;
			new_node->parent = (*root)->right;*/
			/*left = (*root)->left;*/
			
			node->n = value; 
			node->right = *root;
			node->parent = NULL;
			node->left = binary_tree_node(node, (*root)->left->n);
			node->left->left = binary_tree_node(node->left,(*root)->left->left->n);
			node->left->right = binary_tree_node(node->right,(*root)->left->right->n);
			/*(*root)->left = NULL;	*/
			(*root)->left = binary_tree_node(*root, (*root)->right->left->n);
			(*root)->right->left = NULL;
			/*(*root)->parent = node;
			*root = node;*/
			*root = node;
		}
		else
			insert_right_node(&node, &current, value, count);
		return (node);
	}
	return (node);
}
/*
heap_t *change(heap_t **root, heap_t mayor, heap_t menor)
{
	
}
*/
void insert_left_node(heap_t **node, heap_t **current, int value, int count)
{
	heap_t *tmp;
	tmp = *current;
	if (value > (*current)->n)
	{
		(*node)->n = value;
		(*node)->left = *current;
		(*node)->right = (*current)->right;
		(*node)->parent = (*current)->parent;
		if((*current)->parent && (count/2) % 2 > 0)/*fix*/
			(*current)->parent->right = *node;
		else if ((*current)->parent)
			(*current)->parent->left = *node;		
		(*current)->parent = *node;
		/*(*current)->left = NULL;*/
		*current = tmp;
		(*current)->left = NULL;
                (*current)->right = NULL;
	}
	else
	{
		(*node)->parent = *current;
		(*node)->n = value;
		(*current)->left = *node;
		(*node)->left = NULL;
		(*node)->right = NULL;
	}
	/*if(value > current->n)
                {
                        node->left = current;
                        current->parent = node;
                        node->parent = NULL;
                        current->left = NULL;
                        current = node;
                }
                else
                {
                        (*root)->left = node;
                        node->parent = *root;
                }
	*/
}
void insert_right_node(heap_t **node, heap_t **current, int value, int count)
{
	heap_t *new_node;
        new_node = malloc(sizeof(heap_t));
	new_node->n = (*current)->n;
        if (value > (*current)->n)
        {
                (*node)->n = value;
                (*node)->right = new_node;
                (*node)->left = (*current)->left;
                (*node)->parent = (*current)->parent;
                if((*current)->parent && (count/2) % 2 == 0)/*fix*/
                        (*current)->parent->left = *node;
                else if ((*current)->parent)
                        (*current)->parent->right = *node;
                /*(*current)->left = NULL;*/
               /* *current = tmp;*/
               	
                new_node->parent = *node;
		new_node->left = NULL;
                new_node->right = NULL;
        }
	else
	{
		(*node)->parent = *current;
		(*node)->n = value;
		(*current)->right = *node;
		(*node)->left = NULL;
		(*node)->right = NULL;
	}
}
/**
 * get_current_node - traverse the path to the node to insert a newone
 * @current: Pointer to the root node
 * @n_path: path to traverse 0-left 1-right
 * Return: the position of the node
 */
int get_current_node(heap_t **current, int *n_path)
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
 * print_path - helper function
 * @path: --
 * Return nothing
 */
void print_path(int *path)
{
	int i = 0;

	while (path[i] != -1)
	{
		printf("%d  ", path[i]);
		i++;
	}
}
/**
 * path - The path to go to the node to insert a newone
 * @count: the position of the node
 * Return: array of 1 and 0 representing the path
 */

int *path(int count)
{
	int j;
	int i = 0;
	int *path;

	int bkcount = count * 2;

	count = count * 2;
	while ((count = count / 2) > 1)
	{
		i++;
	}

	path = malloc(sizeof(int) * i + 1);

	path[i] = -1;
	for (j = i - 1; (bkcount = bkcount / 2) > 1 ; j--)
	{
		path[j] = bkcount % 2;
	}
	return (path);
}
