#include <stdlib.h>
#include "heap.h"

/**
 * swap_data - swaps two data pointers between two nodes
 * @a: first node
 * @b: second node
 */

void swap_data(binary_tree_node_t *a, binary_tree_node_t *b)
{
	void *temp;

	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

/**
 * bubble_up - restores min heap property by moving the node up
 * @heap: pointer to the heap
 * @node: new node to bubble up
 */

void bubble_up(heap_t *heap, binary_tree_node_t *node)
{
	while (node->parent && heap->data_cmp(node->data, node->parent->data) < 0)
	{
		swap_data(node, node->parent);
		node = node->parent;
	}
}

/**
 * find_insertion_parent - uses BFS to find the parent node for insertion
 * @heap: pointer to the heap
 *
 * Return: parent node for insertion
 */

static binary_tree_node_t *find_insertion_parent(heap_t *heap)
{
	size_t size, path;
	binary_tree_node_t *node;
	unsigned int bits;

	size = heap->size;
	path = size + 1;
	node = heap->root;
	bits = 0;

	while ((path >> bits) > 1)
		bits++;

	while (bits-- > 1)
	{
		if ((path >> bits) & 1)
			node = node->right;
		else
			node = node->left;
	}
	return (node);
}

/**
 * heap_insert - inserts a new node into the heap
 * @heap: pointer to the heap
 * @data: pointer to the data to store
 *
 *Return: pointer to the new node, or NULL on failure
 */

binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *new_node, *parent;

	if (!heap || !data)
		return (NULL);

	if (!heap->root)
	{
		heap->root = binary_tree_node(NULL, data);
		if (!heap->root)
			return (NULL);
		heap->size++;
		return (heap->root);
	}
	parent = find_insertion_parent(heap);
	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, data);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	bubble_up(heap, new_node);
	heap->size++;
	return (new_node);
}
