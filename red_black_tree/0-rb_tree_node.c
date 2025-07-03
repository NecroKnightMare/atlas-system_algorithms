#include "rb_trees.h"
#include <stdlib.h>

/**
 * rb_tree_node - Creates a new red-black tree node
 * @parent: pointer to parent
 * @color: color of node
 * @value: value of node
 * Return: pointer to new node, Null on faiol
 */

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *node;

	node = malloc(sizeof(rb_tree_t));

	if (!node)
	{
		return (NULL);
	}
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->color = color;

	return (node);
}
