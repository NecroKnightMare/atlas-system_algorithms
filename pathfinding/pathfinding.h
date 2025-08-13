#ifndef PATHFINDING_H
#define PATHFINDING_H_

#include <stddef.h>
#include "queues.h"

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

/*additional struct for vertex and edge*/
typedef struct vertex_s {
	char *content;
	size_t index;
	linked_list_t *edges;
	int visited;
} vertex_t;

typedef struct edge_s {
	vertex_t *dest;
	int weight;
} edge_t;

/*prototype functions*/
queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target);

#endif /* PATHFINDING_H */