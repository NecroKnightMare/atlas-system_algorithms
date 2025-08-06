#include <stdlib.h>
#include "heap.h"
#include "huffman.h"

/**
 * huffman_extract_and_insert - Extracts the two smallest nodes from the heap
 * @priority_queue: Pointer to the priority queue heap
 * Return: 1 on success, 0 on failure
 */

int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *left, *right, *merged;
	symbol_t *combined;

	if (!priority_queue || priority_queue->size < 2)
		return (0);

	left = heap_extract(priority_queue);
	right = heap_extract(priority_queue);

	if (!left || !right)
		return (0);

	combined = symbol_create(-1,
		((symbol_t *)left->data)->freq + ((symbol_t *)right->data)->freq);
	if (!combined)
		return (0);

	merged = binary_tree_node(NULL, combined);
	if (!merged)
	{
		free(combined);
		return (0);
	}

	merged->left = left;
	merged->right = right;

	if (!heap_insert(priority_queue, merged))
		return (0);

	return (1);
}