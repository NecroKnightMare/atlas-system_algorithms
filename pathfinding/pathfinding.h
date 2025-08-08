#ifndef _PATHFINDING_H_
#define _PATHFINDING_H_

#include "queue.h"

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

/*prototype functions*/
queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target);

#endif /* !_PATHFINDING_H_ */