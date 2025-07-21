#include <stdlib.h>
#include "graphs.h"

/**
 * graph_create - Creates a new graph
 *
 * Return: Pointer to the newly created graph, or NULL on failure
 */

graph_t *graph_create(void)
{
	graph_t *new_graph;

	new_graph = malloc(sizeof(graph_t));

	if (!new_graph)
		return (NULL);

	new_graph->vertices = NULL;
	new_graph->nb_vertices = 0;

	return (new_graph);
}
