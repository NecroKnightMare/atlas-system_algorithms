#include "pathfinding.h"
#include "queues.h"
#include "graphs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * backtrack - Recursively searches for a path from current to target
 *
 * @current: Current vertex being visited
 * @target: Target vertex to reach
 * @path: Queue to store the path
 * @visited: Array of visited vertex names
 * @count: Number of visited vertices
 *
 * Return: 1 if path found, 0 otherwise
 */
static int backtrack(vertex_t *current, vertex_t *target, queue_t *path,
	vertex_t **visited, size_t count)
{
	size_t i;
	edge_t *edge;

	if (!current || !target || !path || !visited)
		return (0);

	for (i = 0; i < count; i++)
		if (visited[i] == current)
			return (0);

	visited[count++] = current;
	printf("Checking %s\n", current->content);

	if (current == target)
	{
		queue_push_front(path, strdup(current->content));
		return (1);
	}

	for (edge = current->edges; edge; edge = edge->next)
	{
		if (backtrack(edge->dest, target, path, visited, count))
		{
			queue_push_front(path, strdup(current->content));
			return (1);
		}
	}

	return (0);
}

/**
 * backtracking_graph - Finds a path from start to target using backtracking
 *
 * @graph: Pointer to the graph
 * @start: Starting vertex
 * @target: Target vertex
 *
 * Return: Queue containing the path, or NULL on failure
 */
queue_t *backtracking_graph(graph_t *graph,
	const vertex_t *start, const vertex_t *target)
{
	queue_t *path;
	/*size_t max_vertices;*/
	vertex_t **visited;

	if (!graph || !start || !target)
		return (NULL);

	path = queue_create();
	if (!path)
		return (NULL);

	/*max_vertices = graph->nb_vertices;*/
	visited = malloc(sizeof(vertex_t *) * graph->nb_vertices);
	if (!visited)
	{
		queue_delete(path);
		return (NULL);
	}

	if (!backtrack((vertex_t *)start, (vertex_t *)target, path, visited, 0))
	{
		free(visited);
		queue_delete(path);
		return (NULL);
	}

	free(visited);
	return (path);
}
