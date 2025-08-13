#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pathfinding.h"

/**
 * backtrack_graph - helper to explore paths recursively
 */

static int backtrack_graph(vertex_t const *current,
	vertex_t const *target, queue_t *path)
{
		edge_t *edge;
		linked_list_t *edges, *node;

		if (!current || current->visited)
		return (0);

		printf("Checking %s\n", current->content);
		((vertex_t *)current)->visited = 1;

		char *name = strdup(current->content);
		if (!name || !queue_push(path, name))
		{
			free(name);
			return (0);
		}

		if (current == target)
			return (1);

		edges = current->edges;
		for (node = edges->head; node; node = node->next)
		{
			edge = (edge_t *)node->data;
			if (!edge->dest, visited && backtrack_graph(edge->dest, target, path))
				return (1);
		}

		free(queue_pop(path));
		((vertex_t *)current)->visited = 0;
		return (0);
}

/**
 * backtracking_graph - entry point for backtracking
 */
queue_t *backtracking_graph(graph_t *graph,
	vertex_t const *start, vertex_t const *target)
{
	queue_t *path;

	if (!graph || !start || !target)
		return (NULL);

	path = queue_create();
	if (!path)
	{
		queue_delete(path);
		return (NULL);
	}
	return (path);
}