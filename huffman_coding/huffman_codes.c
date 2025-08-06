#include <stdlib.h>
#include "heap.h"
#include "huffman.h"

/**
 * print_codes - recursively traverses huffma tree and prints codes
 * @node: current node in the Huffman tree
 * @code: buffer to store the current code
 * @depth: current depth in the tree
 */

static void print_codes(binary_tree_node_t *node, char *code, size_t depth)
{
	symbol_t *symbol;

	if (!node)
		return;

	if (!node->left && !node->right)
	{
		symbol = (symbol_t *)node->data;
		if (symbol && symbol->data != -1)
		{
			code[depth] = '\0';
			printf("%c: %s\n", symbol->data, code);
		}
		return;
	}
	code[depth] = '0';
	print_codes(node->left, code, depth + 1);

	code[depth] = '1';
	print_codes(node->right, code, depth + 1);
}

/**
 * huffman_codes - builds tree and prints code for symbols
 * @data: Array of characters
 * @freq: Array of frequencies
 * @size: Size of arrays
 * Return: 1 = success, 0 = failure
 */

int huffman_codes(char *data, size_t *freq, size_t size)
{
	binary_tree_node_t *root;
	char *code;

	if (!data || !freq || size == 0)
		return (0);

	root = huffman_tree(data, freq, size);
	if (!root)
		return (0);

	code = malloc(size + 1);
	if (!code)
	{
		binary_tree_delete(root, free);
		return (0);
	}

	print_codes(root, code, 0);

	free(code);
	binary_tree_delete(root, free);
	return (1);
}
