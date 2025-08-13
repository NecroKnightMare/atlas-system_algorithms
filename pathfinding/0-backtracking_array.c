#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pathfinding.h"


static const int directions[4][4][2] = {
    {{0, 1}, {1, 0}, {0, -1}, {-1, 0}},/* RIGHT → BOTTOM → LEFT → TOP*/
    {{1, 0}, {0, 1}, {0, -1}, {-1, 0}}, /*BOTTOM → RIGHT → LEFT → TOP*/
    {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}, /*LEFT → BOTTOM → RIGHT → TOP*/
    {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}  /*TOP → RIGHT → BOTTOM → LEFT*/
};

/**
 * is_valid - checks if cell is within range and walkable
 */
static int is_valid(char **map, int rows, int cols,
	int x, int y, char **visited){
	return (x >= 0 && x < rows && y >= 0 && y < cols &&
		map[x][y] == '0' && visited[x][y] == 0);
}

/**
 * backtrack - backtracks path recursively
 */

static int backtrack(char **map, int rows, int cols,
	int x, int y, point_t const *target, queue_t *path, char **visited)
{
	point_t *point;
	int direction_order;

	direction_order = 0;
	if (!is_valid(map, rows, cols, x, y, visited))
		return (0);

	printf("Checking coordinates [%d, %d]\n", x, y);
	visited[x][y] = 1;

	point = malloc(sizeof(*point));
	if (!point)
		return (0);
	point->x = x;
	point->y = y;

	if (!queue_push_back(path, point))
	{
		free(point);
		visited[x][y] = 0;
		return (0);
	}

	if (x == target->x && y == target->y)
		return (1);

for (int i = 0; i < 4; i++)
{
    int nx = x + directions[direction_order][i][0];
    int ny = y + directions[direction_order][i][1];

    if (backtrack(map, rows, cols, nx, ny, target, path, visited))
        return 1;
}
	
	free(dequeue(path));
	visited[x][y] = 0;
	return (0);
}

/**
 * backtracking_array - searches for first path from 2d array
 * @map: pointer to 2d array
 * @start: stores address of start point
 * @target: stores address of target
 * Return: path
 */

queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target)
{
    queue_t *path;
	char **visited;
	int i, direction_order;

	path = NULL;
	visited = NULL;
    for (direction_order = 0; direction_order < 4; direction_order++)
    {
		visited = malloc(sizeof(char *) * rows);
        if (!visited)
            return (NULL);
        for (i = 0; i < rows; i++)
        {
            visited[i] = calloc(cols, sizeof(char));
            if (!visited[i])
            {
                while (i--)
                    free(visited[i]);
                free(visited);
                return (NULL);
            }
        }

        path = queue_create();
        if (!path)
        {
            for (i = 0; i < rows; i++)
                free(visited[i]);
            free(visited);
            return (NULL);
        }

        if (backtrack(map, rows, cols, start->x, start->y, target, path, visited))
        {
            for (i = 0; i < rows; i++)
                free(visited[i]);
            free(visited);
            return (path);
        }

        for (i = 0; i < rows; i++)
            free(visited[i]);
        free(visited);
        free(path);
        path = NULL;
    }

    return (NULL);
}
// 	queue_t *path;
// 	char **visited;
// 	int i;

// 	path = queue_create();
// 	if (!path)
// 		return (NULL);

// 	visited = malloc(sizeof(char *) * rows);
// 	if (!visited)
// 	{
// 		free(path);
// 		return (NULL);
// 	}
// 	for (i = 0; i < rows; i++)
// 	{
// 		visited[i] = calloc(cols, sizeof(char));
// 		if (!visited[i])
// 		{
// 			while (i--)
// 				free(visited[i]);
// 			free(visited);
// 			free(path);
// 			return (NULL);
// 		}
// 	}

// 	if (!backtrack(map, rows, cols, start->x, start->y, target, path, visited))
// 	{
// 		for (i = 0; i < rows; i++)
// 			free(visited[i]);
// 		free(visited);
// 		free(path);
// 		return (NULL);
// 	}
// 	for (i = 0; i < rows; i++)
// 		free(visited[i]);
// 	free(visited);

// 	return (path);
// }
