#include <stdlib.h>
#include <string.h>
#include "graphs.h"

/**
 * enqueue - adds vertex to BFS queue
 * @queue: pointer to tail of queue
 * @v: vertex to enqueue
 * @depth: vertex depth
 *
 * Return: pointer to new enqueued node
 */
static vertex_queue_t *enqueue(vertex_queue_t **queue,
	const vertex_t *v, size_t depth)
{
	vertex_queue_t *new;

	new = malloc(sizeof(vertex_queue_t));
	if (!new)
		return (NULL);

	new->v = v;
	new->depth = depth;
	new->next = NULL;

	if (*queue)
	{
		(*queue)->next = new;
	}
	*queue = new;

	return (new);
}

/**
 * breadth_first_traverse - performs a breadth-first traversal on graph
 * @graph: pointer to graph
 * @action: callback functionon visited vertex
 *
 * Return: max depth reached or 0(failure)
 */
size_t breadth_first_traverse(const graph_t *graph,
	void (*action)(const vertex_t *v, size_t depth))
{
	char *visited;
	vertex_queue_t *head, *tail, *temp;
	edge_t *e;
	size_t max_depth = 0;

	if (!graph || !action || graph->nb_vertices == 0)
		return (0);
	visited = calloc(graph->nb_vertices, sizeof(char));
	if (!visited)
		return (0);
	tail = NULL;
	head = enqueue(&tail, graph->vertices, 0);

	if (!head)
	{
		free(visited);
		return (0);
	}
	while (head)
	{
		if (!visited[head->v->index])
		{
			action(head->v, head->depth);
			visited[head->v->index] = 1;
			if (head->depth > max_depth)
				max_depth = head->depth;
			for (e = head->v->edges; e; e = e->next)
			{
				if (!visited[e->dest->index] && !enqueue(&tail, e->dest, head->depth + 1))
				{
					free(visited);
					while (head)
					{
						temp = head;
						head = head->next;
						free(temp);
					}
					return (0);
				}
			}
		}
		temp = head;
		head = head->next;
		free(temp);
	}
	free(visited);
	return (max_depth);
}
