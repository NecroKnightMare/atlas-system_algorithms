#include <stdlib.h>
#include <string.h>
#include "graphs.h"

/**
 * graph_add_vertex - Adds a new vertex to the graph
 * @graph: Pointer to graph structure
 * @str: string to store vertex
 *
 * Return: pointer to created vertex, or NULL on failure
 */

vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *vertex, *current;
	char *str_dup;

	if (!graph || !str)
		return (NULL);
	current = graph->vertices;
	while (current)
	{
		if (strcmp(current->content, str) == 0)
			return (NULL); /* San francisco not added */
		current = current->next;
	}
	vertex = malloc(sizeof(vertex_t));
	if (!vertex)
		return (NULL);
	str_dup = strdup(str);
	if (!str_dup)
	{
		free(vertex);
		return (NULL);
	}
	vertex->content = str_dup;
	vertex->index = graph->nb_vertices;
	vertex->edges = NULL;
	vertex->nb_edges = 0;
	vertex->next = NULL;
	if (!graph->vertices)
		graph->vertices = vertex;
	else
	{
		current = graph->vertices;
		while (current->next)
			current = current->next;
		current->next = vertex;
	}
	graph->nb_vertices++;
	return (vertex);
}
