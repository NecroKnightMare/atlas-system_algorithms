#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pathfinding.h"

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

	printf("Checking coordinates [%d, %d]\n", x, y);

	if (!is_valid(map, rows, cols, x, y, visited))
		return (0);

	visited[x][y] = 1;

	point = malloc(sizeof(*point));
	if (!point)
		return (0);
	point->x = x;
	point->y = y;
	if (!queue_push_back(path, point))
	{
		free(point);
		return (0);
	}

	if (x == target->x && y == target->y)
		return (1);

	if (backtrack(map, rows, cols, x, y + 1, target, path, visited) ||
	backtrack(map, rows, cols, x + 1, y, target, path, visited) ||
	backtrack(map, rows, cols, x, y - 1, target, path, visited) ||
	backtrack(map, rows, cols, x - 1, y, target, path, visited))
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
	queue_t *path;
	char **visited;
	int i;

	path = queue_create();
	if (!path)
		return (NULL);

	visited = malloc(sizeof(char *) * rows);
	if (!visited)
	{
		free(path);
		return (NULL);
	}
	for (i = 0; i < rows; i++)
	{
		visited[i] = calloc(cols, sizeof(char));
		if (!visited[i])
		{
			while (i--)
				free(visited[i]);
			free(visited);
			free(path);
			return (NULL);
		}
	}

	if (!backtrack(map, rows, cols, start->x, start->y, target, path, visited))
	{
		for (i = 0; i < rows; i++)
			free(visited[i]);
		free(visited);
		free(path);
		return (NULL);
	}
	for (i = 0; i < rows; i++)
		free(visited[i]);
	free(visited);

	return (path);
}
