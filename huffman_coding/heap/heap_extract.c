#include <stdlib.h>
#include "heap.h"

/**
 * swap_data - swap data between two nodes
 * @a: first node
 * @b: second node
 */

static void swap_data(binary_tree_node_t *a, binary_tree_node_t *b)
{
	void *temp;

	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

/**
 * get_last_node - finds the last node in the heap size path
 * @heap: pointer to the heap
 * Return: pointer to the last node
 */

static binary_tree_node_t *get_last_node(heap_t *heap)
{
	binary_tree_node_t *node;
	size_t path;
	unsigned int depth;

	node = heap->root;
	path = heap->size;
	depth = 0;

	while ((path >> depth) > 1)
		depth++;
	while (depth--)
		node = (path >> depth) & 1 ? node->right : node->left;

	return (node);	
}

/**
 * bubble_down - restores MIN heap property
 * @heap: pointer to the heap
 * @node: node to bubble down
 */

static void bubble_down(heap_t *heap, binary_tree_node_t *node)
{
	binary_tree_node_t *child;

	while (node)
	{
		child = node;
		if (node->left && heap->data_cmp(node->left->data, child->data) < 0)
			child = node->left;
		if (node->right && heap->data_cmp(node->right->data, child->data) < 0)
			child = node->right;

		if (child == node)
			break;
			
		swap_data(node, child);
		node = child;
	}
}

/**
 * heap_extract - extracts root value and rebalances tree
 * * @heap: pointer to the heap
 * Return: pointer to the extracted data or NULL on failure
 */

void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *last_node, *parent;
	void *data;

	if (!heap || !heap->root)
		return (NULL);

	data = heap->root->data;

	if (heap->size == 1)
	{
		free(heap->root);
		heap->root = NULL;
		heap->size--;
		return (data);
	}

	last_node = get_last_node(heap);
	heap->root->data = last_node->data;

	parent = last_node->parent;
	if (parent->left == last_node)
		parent->left = NULL;
	else
		parent->right = NULL;
	free(last_node);

	heap->size--;
	bubble_down(heap, heap->root);

	return (data);
}
