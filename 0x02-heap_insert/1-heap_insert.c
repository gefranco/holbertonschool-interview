#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: Pointer to the root node
 * @value: Integer stored in the node
 * Return: created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	static int count;
	heap_t *node, *current, *left, *right;
	int *n_path;
	int i, countrv;

	count++;
	node = malloc(sizeof(heap_t));
	if (count == 1)
	{
		*root = node;
		(*root)->n = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*root)->parent = NULL;
		return (*root);
	}
	n_path = path(count);
	i = 0;
	current = *root;
	countrv = count;
	i = get_current_node(&current, n_path);
	if (n_path[i] == 0)
	{printf("LEFT\n");
		
		node->parent = current;
		node->n = value;
		current->left = node;
		node->left = NULL;
		node->right = NULL;
		while( node->n > node->parent->n && node->parent->parent != NULL)
		{
			printf("%d   changinnnnnnnng   --- %d\n", node->n, countrv);
			if(countrv%2 == 0)
				chngndl(node, countrv);
			else
				chngndr(node, countrv);
			/*node->left = node->parent;
			
			node->parent->left = NULL;
			
			node->right = node->parent->right;
			node->parent->right = NULL;

			if(node->parent->parent != NULL)*no es root*
			{
				md = countrv % 2;
				if(md > 1 || (countrv/2)%2 == 0)*left*
					node->parent->parent->left = node;
				else
					node->parent->parent->right = node;			
				node->parent = node->parent->parent;
		
				node->left->parent = node;
			}
			*else*root
			{
				node->parent->parent = node;
				node->parent = NULL;
				*root = node;
				break;
			}*/
			countrv--;
		}
		if(node->parent->parent == NULL && node->parent->n < node->n)
                {printf("changing root!!!!\n");
			if(node->parent->right != NULL)
			{
				right = node->parent->right;
				
                        	right->parent = node;
				
                        }
			node->parent->parent = node;
                        node->parent->left = node->left;
                        if(node->left)
				node->left->parent = node->parent;
                        node->left = node->parent;
			
			 node->parent->right = node->right;
                        if(node->right)                 
                                node->right->parent = node->parent;
                        if(right != NULL)
                       		node->right = right;
			node->parent = NULL;
                        *root = node;


                }

		return (node);

	}
	else
	{printf("RIGHT\n");
		node->parent = current;
		node->n = value;
		current->right = node;
		node->left = NULL;
		node->right = NULL;

		while( node->n > node->parent->n && node->parent->parent != NULL)
		{
			/*chngndr(node, countrv);*/
			if(countrv%2 == 0)
                                chngndl(node, countrv);
                        else
                                chngndr(node, countrv);
	
			/*node->right = node->parent;
			
			node->parent->right = NULL;
			
			node->left = node->parent->left;
			node->parent->left->parent = node;
			node->parent->left = NULL;
			printf("countrvmod2 %d\n", countrv%2);
			if(node->parent->parent != NULL)*no es root*
			{printf("enter****\n");
			md = countrv % 2;
				if(md > 0 && (countrv/2)%2 == 0)
				{
					
					node->parent->parent->left = node;			
					printf("changing node\n");
				
				}
				else
				{printf("?????\n");
					node->parent->parent->right = node;
				}
				node->parent = node->parent->parent;
		
				node->right->parent = node;
			}*/
			/*else*root*
			{
				node->parent->parent = node;
				node->left = node->parent->left;
				node->parent = NULL;
				
				*root = node;
				break;
			}*/
			countrv--;
		}
		if(node->parent->parent == NULL && node->parent->n < node->n)
                {	
			printf("changing root %d", node->parent->left->n);
			left = node->parent->left;
                        node->parent->parent = node;
			node->parent->right = node->right;
			node->right->parent = node->parent;
			node->right = node->parent;
                        node->parent->left = node->left;
			node->left->parent = node->parent;
			node->left = left;
			left->parent = node;
			node->parent = NULL;
                        *root = node;

                }

		return (node);
	}
	return (node);
}
void chngndr(heap_t *node, int countrv)
{
	int md;
			node->right = node->parent;
			
			node->parent->right = NULL;
			
			node->left = node->parent->left;
			node->parent->left->parent = node;
			node->parent->left = NULL;
			printf("countrvmod2 %d\n", countrv%2);
			if(node->parent->parent != NULL)/*no es root*/
			{printf("enter****\n");
			md = countrv % 2;
				if(md > 0 && (countrv/2)%2 == 0)
				{
					
					node->parent->parent->left = node;			
					printf("changing node\n");
				
				}
				else
				{printf("?????\n");
					node->parent->parent->right = node;
				}
				node->parent = node->parent->parent;
		
				node->right->parent = node;
			}
}
void chngndl(heap_t *node, int countrv)
{
	int md;
	printf("changing node left: %d\n", node->n);
			node->left = node->parent;
			
			node->parent->left = NULL;
			
			node->right = node->parent->right;
			node->parent->right = NULL;

			if(node->parent->parent != NULL)/*no es root*/
			{
				md = countrv % 2;
				if(md > 1 || (countrv/2)%2 == 0)/*left*/
					node->parent->parent->left = node;
				else
					node->parent->parent->right = node;			
				node->parent = node->parent->parent;
		
				node->left->parent = node;
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
/*
int isleft(int count)
{
	
}*/
