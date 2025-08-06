#include <stdlib.h>
#include "heap.h"
#include "huffman.h"

/**
 * huffman_tree - builds a Huffman tree from given data and frequencies
 * @data: array of characters
 * @freq: array of frequencies
 * @size: size of arrays
 * Return: pointer to the root of the Huffman tree, or NULL on failure
 */

binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *heap;
	binary_tree_node_t *node1, *node2, *new;
	symbol_t *new_symbol;

	if (!data || !freq || size == 0)
		return (NULL);

	heap = huffman_priority_queue(data, freq, size);
	if (!heap)
		return (NULL);

	while (heap->size > 1)
	{
		node1 = heap_extract(heap);
		node2 = heap_extract(heap);
		if (!node1 || !node2)
		{
			heap_delete(heap, free);
			return (NULL);
		}
		new_symbol = symbol_create(-1, ((symbol_t *)node1->data)->freq +
					((symbol_t *)node2->data)->freq);

		if (!new_symbol)
		{
			heap_delete(heap, free);
			return (NULL);
		}

		new = binary_tree_node(NULL, new_symbol);
		if (!new)
		{
			free(new_symbol);
			heap_delete(heap, free);
			return (NULL);
		}
		new->left = node1;
		new->right = node2;
		node1->parent = new;
		node2->parent = new;

		if (!heap_insert(heap, new))
		{
			heap_delete(heap, free);
			return (NULL);
		}
	}
	new = heap_extract(heap);
	heap_delete(heap, free);
	return (new);
}
