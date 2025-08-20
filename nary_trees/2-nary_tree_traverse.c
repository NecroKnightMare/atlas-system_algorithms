#include <stdlib.h>
#include <stdio.h>
#include "nary_trees.h"

/**
 * traverse_helper - recursive helper
 * @node: current node
 * @action: function to apply to each node
 * @depth: current depth in the tree
 * Return: max depth
 *
 */
static size_t traverse_helper(const nary_tree_t *node, 
	void(*action)(const nary_tree_t *, size_t), size_t depth)
{
	size_t max_depth = depth;
	size_t child_depth;
	nary_tree_t *child;

	if (!node)
		return (depth);

	if (action)
		action(node, depth);

	child = node->children;
	while (child)
	{
		child_depth = traverse_helper(child, action, depth + 1);
		if (child_depth > max_depth)
			max_depth = child_depth;
		child = child->next;
	}

	return (max_depth);
}

/**
 * nary_tree_traverse - Traverses an N-ary tree and applies a
 * function to each node
 * @tree: pointer to the root of the tree
 * @action: function to apply to each node
 */
size_t nary_tree_traverse(const nary_tree_t *root,
	void(*action)(const nary_tree_t *, size_t))
{
	if (!root)
		return (0);

	return (traverse_helper(root, action, 0));
}
