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
	heap_t *node, *current, *left, *right;
	int *n_path;
	int i, countrv;

	static int count;
	count++;
	if (count == 1)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	
	n_path = path(count);
	i = 0;
	current = *root;
	countrv = count;
	
	i = get_current_index(&current, n_path);
	if (n_path[i] == 0)
	{
		current->left = binary_tree_node(current, value);
		node = current->left;		

	}
	else
	{
		current->right = binary_tree_node(current, value);
		node = current->right;

	}
	
                while(node->n > node->parent->n && node->parent->parent != NULL)
                {
                        if(node == node->parent->left)
                                chngndl(node, countrv, count);
                        else
                                chngndr(node, countrv, count);


                        countrv--;
                }
	if(node->parent->parent == NULL && node->parent->n < node->n &&  node == node->parent->right) 
                {       
			 left = node->parent->left;
                        node->parent->parent = node;
                        node->parent->right = node->right;
                        if(node->right)
				node->right->parent = node->parent;
                        node->right = node->parent;
                        node->parent->left = node->left;
                       	if(node->left)
			 	node->left->parent = node->parent;
                        node->left = left;
                        left->parent = node;
                        node->parent = NULL;
                        *root = node;

                }
	else if(node->parent->parent == NULL && node->parent->n < node->n)
	{
                       right = NULL;
			 if(node->parent->right)
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
	free(n_path);
	return (node);
}
void chngndr(heap_t *node, int countrv, int count)
{
	
	heap_t *tmp = NULL;
	heap_t *rtmp = NULL;
	
	
	rtmp = node->right;
			node->right = node->parent;
			
	if(count > countrv)
	{
		
		node->parent->right = rtmp;
		if(rtmp != NULL)
			rtmp->parent = node->parent;
		
		node->left->parent = node->parent;
		tmp = node->left;
		tmp->parent =  node->parent;
	}


         else
                        {
                                node->parent->right = NULL;
                        }





			/*node->parent->right = NULL;*/
			
			node->left = node->parent->left;
			node->parent->left->parent = node;
			node->parent->left = tmp;
			if(node->parent->parent != NULL)/*no es root*/
			{
				if(node->parent == node->parent->parent->left)
				{
					
					node->parent->parent->left = node;			
				
				}
				else
				{
					node->parent->parent->right = node;
				}
				node->parent = node->parent->parent;
		
				node->right->parent = node;
			}
}
void chngndl(heap_t *node, int countrv, int count)
{
	heap_t *tmp = NULL;	
	heap_t *ltmp = NULL;
	ltmp = node->left;
	node->left = node->parent;
			
	if(count > countrv)
	{
		/*node->parent->left = node->left;*/
		node->parent->left = ltmp;
		ltmp->parent = node->parent;
		if(node->right != NULL)
			node->right->parent = node->parent;
				
		tmp = node->right;
			if(tmp != NULL)
				tmp->parent = node->parent;
				
		node->parent->right->parent = node;
	}
	else
	{
		node->parent->left = NULL;
	}
			/*node->parent->left = NULL;*/
			
	node->right = node->parent->right;
			
	node->parent->right = tmp;

	if(node->parent->parent != NULL)/*no es root*/
	{
		if(node->parent == node->parent->parent->left)	
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
int get_current_index(heap_t **current, int *n_path)
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

/*heap_t *get_current_node(heap_t **node, int *n_path)
{
        heap_t *current;
	int i = 0;
	current = *node;
        while (n_path[i] != -1)
        {
                if (current->left == NULL || current->right == NULL) 
			return (current);
                if (n_path[i] == 0)
                        current = current->left;
                else if (n_path[i] == 1)
                        current = current->right;

                i++;
        }
        return current;
}*/

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
