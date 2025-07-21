#include <stdlib.h>
#include <string.h>
#include "graphs.h"

/**
 * append_edge - Helper function to append an edge to a vertex's edge
 * @from: Pointer to the source vertex
 * @to: Pointer to the destination vertex
 *
 * Return: 1 on success, 0 on failure
 */

static int append_edge(vertex_t *from, vertex_t *to)
{
	edge_t *new_edge, *tail;

	new_edge = malloc(sizeof(edge_t));
	if (!new_edge)
		return (0);
	new_edge->dest = to;
	new_edge->next = NULL;

	if (!from->edges)
	{
		from->edges = new_edge;
	}
	else
	{
		tail = from->edges;
		while (tail->next)
			tail = tail->next;
		tail->next = new_edge;
	}
	from->nb_edges++;
	return (1);
}

/**
 * graph_add_edge - adds edge between two vertices
 * @graph: pointer to graph
 * @src: string id source vertex
 * @dest: string id to destination vertex
 * @type: type of edge
 * (unidirectional or bidirectional)
 *
 * Return: 1(success), 0(failure)
 */

int graph_add_edge(graph_t *graph,
	const char *src, const char *dest, edge_type_t type)
{
	vertex_t *from = NULL, *to = NULL, *vertex;

	if (!graph || !src || !dest)
		return (0);
	for (vertex = graph->vertices; vertex; vertex = vertex->next)
	{
		if (!from && strcmp(vertex->content, src) == 0)
			from = vertex;
		if (!to && strcmp(vertex->content, dest) == 0)
			to = vertex;
	}
	if (!from || !to)
		return (0);
	if (!append_edge(from, to))
		return (0);

	if (type == BIDIRECTIONAL && !append_edge(to, from))
		return (0);

	return (1);
}
