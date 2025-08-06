#include <stdlib.h>
#include "heap.h"
#include "huffman.h"

/**
 * symbol_cmp - compares function for MIN heap 
 * @a: pointer to first binary_tree_node_t
 * @b: pointer to second binary_tree_node_t
 * Return: negative if a < b, positive if a > b, zero if a == b(MIN behavior)
 */

int symbol_cmp(void *a, void *b)
{
	symbol_t *sym_a, *sym_b;

	sym_a = ((binary_tree_node_t *)a)->data;
	sym_b = ((binary_tree_node_t *)b)->data;

	return (sym_a->freq - sym_b->freq);
}

/**
 * huffman_priority_queue - creates a priority queue using a MIN heap
 * @data: array of characters
 * @freq: array of frequencies
 * @size: number of elements
 * Return: pointer to the created heap, or NULL on failure
 */

heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *heap;
	symbol_t *symbol;
	binary_tree_node_t *node;
	size_t i;

	if (!data || !freq || size == 0)
        return (NULL);

	heap = heap_create(symbol_cmp);
	if (!heap)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		symbol = symbol_create(data[i], freq[i]);
		if (!symbol)
		{
			heap_delete(heap, NULL);
			return (NULL);
		}

		node = binary_tree_node(NULL, symbol);
		if (!node)
		{
			free(symbol);
			heap_delete(heap, NULL);
			return (NULL);
		}
		if (!heap_insert(heap, node))
		{
			free(symbol);
			free(node);
			heap_delete(heap, NULL);
			return (NULL);
		}
	}
	return (heap);
}
