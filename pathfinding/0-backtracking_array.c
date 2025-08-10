#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pathfinding.h"

/**
 * is_valid - checks if cell is within range and walkable
 */
static int is_valid(char **map, char **visited, int rows, int cols,
	int x, int y)
{
	return (x >= 0 && x < rows && y >= 0 && y < cols &&
		map[x][y] == '0' && visited[x][y] == '0');
}

/**
 * backtrack - backtracks path recursively
 */

static int backtrack(char **map, char **visited, int rows, int cols,
	int x, int y, point_t const *target, queue_t *path)
{
	point_t *point;

	printf("Checking coordinates [%d, %d]\n", x, y);

	if (!is_valid(map, visited, rows, cols, x, y))
		return (0);

	visited[x][y] = '1';

	point = malloc(sizeof(*point));
	if (!point)
		return (0);
	point->x = x;
	point->y = y;
	queue_push_back(path, point);

	if (x == target->x && y == target->y)
		return (1);

	if (backtrack(map, visited, rows, cols, x, y + 1, target, path) ||
	backtrack(map, visited, rows, cols, x + 1, y, target, path) ||
	backtrack(map, visited, rows, cols, x, y - 1, target, path) ||
	backtrack(map, visited, rows, cols, x - 1, y, target, path))
		return (1);
	
	free(dequeue(path));
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
	char **visited;
	queue_t *path;
	int i;

	visited = malloc(sizeof(char *) * rows);
	if (!visited)
		return (NULL);

	for (i = 0; i < rows; i++)
	{
		visited[i] = calloc(cols + 1, sizeof(char));
		if (!visited[i])
		{
			while (i--)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		memset(visited[i], '0', cols);
	}

	path = queue_create();
	if (!path)
	{
		for (i = 0; i < rows; i++)
			free(visited[i]);
		free(visited);
		return (NULL);
	}

	if (!backtrack(map, visited, rows, cols,
	start->x, start->y, target, path))
	{
		queue_delete(path);
		path = NULL;
	}

	for (i = 0; i < rows; i++)
		free(visited[i]);
	free(visited);

	return (path);
}
