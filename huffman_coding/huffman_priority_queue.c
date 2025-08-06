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
	binary_tree_node_t *node_a, *node_b;
	size_t freq_a, freq_b;

	node_a = (binary_tree_node_t *)a;
	node_b = (binary_tree_node_t *)b;
	sym_a = node_a->data;
	sym_b = node_b->data;
	freq_a = sym_a ? sym_a->freq : 0;
	freq_b = sym_b ? sym_b->freq : 0;

	if (freq_a != freq_b)
		return (freq_a - freq_b);
	
	if (sym_a && sym_b)
		return ((int)sym_a->data - (int)sym_b->data);

	if (sym_a && !sym_b)
		return (-1);

	if (!sym_a && sym_b)
		return (1);

	return (node_a > node_b) - (node_a < node_b);
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
