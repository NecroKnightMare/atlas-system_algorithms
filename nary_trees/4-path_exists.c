#include "nary_trees.h"
#include <string.h>

/**
 * path_exists - chicks if path exists
 * @root: pointer to root
 * @path: array of strings representing the path
 * Return: 1 if path exists, 0 if not
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
	size_t i = 0;
	nary_tree_t const *current;

	current = root;
	if (!root || !path || !*path[0])
		return (0);
	while (path[i])
	{
		if (!current || !current->content || strcmp(current->content, path[i]) != 0)
			return (0);

		i++;
		if (!path[i])
			return (1);
		current = current->children;
		while (current && strcmp(current->content, path[i]) != 0)
			current = current->next;
	}
	return (0);
}
