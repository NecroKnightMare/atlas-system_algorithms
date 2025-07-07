#include "rb_trees.h"
#include <stddef.h>

/**
 * is_valid_helper - Recursively validates Red-Black tree
 * @node: Current node
 * @black_count: Pointer to black node count in path
 * @path_black: Current black node count
 *
 * Return: 1 if valid, 0 otherwise
 */

 int is_valid_helper(const rb_tree_t *node, int *black_count, int path_black)
{
	int left_valid, right_valid;

	if (node == NULL)
	{
		if (*black_count == -1)
		{
			*black_count = path_black;
		}
		return (path_black == *black_count);
	}

	if ((node->left && node->left->n >= node->n) ||
		(node->right && node->right->n <= node->n))
		{
		return (0);
		}

	if (node->color == RED)
	{
		if ((node->left && node->left->color == RED) ||
			(node->right && node->right->color == RED))
		{
			return (0);
		}
	}

	if (node->color == BLACK)
	{
		path_black++;
	}

	left_valid = is_valid_helper(node->left, black_count, path_black);
	right_valid = is_valid_helper(node->right, black_count, path_black);

	return (left_valid && right_valid);
}

/**
 * rb_tree_is_valid - checks if tree
 * @tree: pointer to red black tree
 * Return: 1 if tree, 0 if not
 */

int rb_tree_is_valid(const rb_tree_t *tree)
{
	int black_count = -1;

	if (!tree)
	{
		return (0);
	}

	if (tree->color != BLACK)
	{
		return (0);
	}

	return (is_valid_helper(tree, &black_count, 0));
}