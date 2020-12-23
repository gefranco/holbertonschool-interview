#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>


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
		return *root;
	}
	/*if(count == 2)
	{
		node->parent = *root;
		node->n = value;
		(*root)->left = node;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	
	if(count == 3)
	{
		node->parent = *root;
                node->n = value;
                (*root)->right = node;
                node->left = NULL;
                node->right = NULL;
		return node;
	}*/	
	n_path = path(count);
	i=0;
	current = *root;
	while(n_path[i]!=-1)
	{
		if(current->left == NULL || current->right == NULL)
			break;
		if(n_path[i]==0)
			current=current->left;
		else if(n_path[i]==1)
			current=current->right;
			
		i++;
	}
	
	if(n_path[i] == 0)
	{
		node->parent = current;
                node->n = value;
                current->left = node;
                node->left = NULL;
                node->right = NULL;
                return node;

	}	
	else
	{
		node->parent = current;
                node->n = value;
                current->right = node;
                node->left = NULL;
                node->right = NULL;
                return node;
	}
	return node;
}
void print_path(int *path)
{
	int i = 0;
	while(path[i]!= -1)
	{
		printf("%d  ", path[i]);
		i++;
	}
}
int *path(int count)
{	
	int j;
	int i = 0;
	int *path;
	
	int bkcount = count*2;
	count = count * 2;
	while((count=count/2) > 1)
	{
		
		
		i++;
	}
	
	path = malloc(sizeof(int)*i + 1);
	
	path[i] = -1;	
	for(j = i - 1;(bkcount=bkcount/2) > 1 ;j--)
	{
		path[j] = bkcount%2;
	}	
	return path;
}
