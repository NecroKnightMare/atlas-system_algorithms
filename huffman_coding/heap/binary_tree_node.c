#include <stdlib.h>
#include "heap.h"

/**
 * binary_tree_node - creates a new binary tree node
 * @parent: pointer to parent node
 * @data: data to store in node
 *
 *Return: pointer to created node or NULL 
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *node;

	node = malloc(sizeof(binary_tree_node_t));
	if (!node)
		return (NULL);
	node->data = data;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
