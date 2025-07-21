#include <stdlib.h>
#include "graphs.h"

/**
 * graph_delete - frees a graph and all its vertices and edges
 * @graph: pointer to the graph to delete
 */

void graph_delete(graph_t *graph)
{
	vertex_t *vertex, *next_vertex;
	edge_t *edge, *next_edge;

	if(!graph)
		return;
	vertex = graph->vertices;
	while (vertex)
	{
		edge = vertex->edges;
		while (edge)
		{
			next_edge = edge->next;
			free(edge);
			edge = next_edge;
		}
	next_vertex = vertex->next;
	free(vertex->content);
	free(vertex);
	vertex = next_vertex;
	}
	free(graph);
}
