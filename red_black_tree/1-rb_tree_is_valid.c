#include "rb_trees.h"
#include <stddef.h>

/**
 * is_valid_helper - Recursively validates Red-Black Tree properties
 * @node: Current node
 * @black_count: Pointer to track black node count in path
 * @path_black: Current path’s black node count
 *
 * Return: 1 if valid, 0 otherwise
 */

 int is_valid_helper(const rb_tree_t *node, int *black_count, int path_black)
{
	int left, right;

	if (node == NULL)
	{
		
	}

}

/**
 * rb_tree_is_valid - checks if tree
 * @tree: pointer to red black tree
 * Return: 1 if tree, 0 if not
 */

int rb_tree_is_valid(const rb_tree_t *tree)
{

}