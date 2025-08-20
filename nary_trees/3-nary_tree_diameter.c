#include "nary_trees.h"
#include <stdlib.h>

/**
 * max_depths - helper to find two largest depths among children
 * @node: current node
 * @diameter: pointer to current max diameter
 * Return: depth of current node
 */
static size_t max_depths(nary_tree_t const *node, size_t *diameter)
{
	size_t max1 = 0, max2 = 0, depth;
	nary_tree_t *child;

	if (!node)
		return (0);

	child = node->children;
	while (child)
	{
		depth = max_depths(child, diameter);
		if (depth > max1)
		{
			max2 = max1;
			max1 = depth;
		}
		else if (depth > max2)
		{
			max2 = depth;
		}
		child = child->next;
	}

	if (*diameter < max1 + max2)
		*diameter = max1 + max2;

	return (max1 + 1);
}

/**
 * nary_tree_diameter - computes diameter of N-ary tree
 * @root: pointer to root node
 * Return: diameter of tree
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t diameter = 0;

	if (!root)
		return (0);

	max_depths(root, &diameter);
	return (diameter);
}