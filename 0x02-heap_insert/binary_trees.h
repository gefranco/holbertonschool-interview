#ifndef BTREE_H
#define BTREE_H
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t, heap_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
int *path(int count);
void chngndr(heap_t *node, int countrv, int count);
int get_current_index(heap_t **current, int *n_path);
void chngndl(heap_t *node, int countrv, int);
#endif
