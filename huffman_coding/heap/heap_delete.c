#include <stdlib.h>
#include "heap.h"

/**
 * delete_tree - frees a binary tree recursively
 * @node: pointer to current node
 * @free_data: function to free the data in the node
 */

static void delete_tree(binary_tree_node_t *node, void (*free_data)(void *))
{
	if (!node)
		return;

	delete_tree(node->left, free_data);
	delete_tree(node->right, free_data);

	if (free_data)
		free_data(node->data);
	free(node);
}

/**
 * heap_delete - deletes a heap and frees its memory
 * @heap: pointer to the heap to delete
 * @free_data: function to free the data in the nodes
 */

void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;

	delete_tree(heap->root, free_data);
	free(heap);
}
