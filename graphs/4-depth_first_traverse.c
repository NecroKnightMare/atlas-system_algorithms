#include <stdlib.h>
#include <string.h>
#include "graphs.h"

/**
 * dfs_helper - traverses the graph recursively
 * @v: pointer to the current vertex
 * @depth: current depth in the traversal
 * @action: function pointerto call on each vertices visited
 * @visited: array to keep track of visited vertices
 * @max: pointer to current max depth
 */
static void dfs_helper(const vertex_t *v, size_t depth,
	void (*action)(const vertex_t *, size_t),
	char *visited, size_t *max)
{
	edge_t *edge;
	
	if (!v || visited[v->index])
		return;
	visited[v->index] = 1;
	action(v, depth);

	if (depth > *max)
		*max = depth;

	for (edge = v->edges; edge; edge = edge->next)
	dfs_helper(edge->dest, depth + 1, action, visited, max);
}

/**
 * depth_first_traverse - performs a depth-first traversal from first vertex
 * @graph: pointer to the graph
 * @action: function pointer to call on each vertex visited
 *
 *Return: max (max depth reached during traversal) or 0(failure)
 */
size_t depth_first_traverse(const graph_t *graph,
	void (*action)(const vertex_t *v, size_t depth))
{
	char *visited;
	size_t max = 0;

	if (!graph || !action || !graph->vertices || graph->nb_vertices == 0)
		return (0);

	visited = calloc(graph->nb_vertices, sizeof(char));
	if (!visited)
		return (0);

	dfs_helper(graph->vertices, 0, action, visited, &max);
	free(visited);

	return (max);
}
