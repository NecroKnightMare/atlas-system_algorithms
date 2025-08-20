#include <stdlib.h>
#include "nary_trees.h"

/**
 * nary_tree_delete - Deletes an N-ary tree
 * @tree: Pointer to the root node of the tree
 */
void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *child, *tmp;

	if (!tree)
		return;

	child = tree->children;
	while (child)
	{
		tmp = child;
		child = child->next;
		nary_tree_delete(tmp);
	}

	free(tree->content);
	free(tree);
}
