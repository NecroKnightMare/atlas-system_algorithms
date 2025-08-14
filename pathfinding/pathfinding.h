#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "queues.h"
#include "graphs.h"

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;

/**
 * struct direction_s - Structure storing movement direction
 *
 * @dx: Change in X coordinate
 * @dy: Change in Y coordinate
 */
typedef struct direction_s
{
	int dx;
	int dy;
} direction_t;

direction_t *get_directions(int *count);

/**
 * struct dijkstra_node_s - Helper structure for Dijkstra's algorithm
 * @vertex: Pointer to the graph vertex
 * @distance: Current shortest distance from start
 * @visited: Flag indicating if the vertex has been visited
 * @prev: Pointer to previous vertex in the shortest path
 */
typedef struct dijkstra_node_s
{
    vertex_t *vertex;
    size_t distance;
    int visited;
    struct dijkstra_node_s *prev;
} dijkstra_node_t;

/*prototype functions*/
queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target);
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target);
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start, vertex_t const *target);

#endif /* PATHFINDING_H */
