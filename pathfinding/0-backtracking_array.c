#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pathfinding.h"

/**
 * is_valid - checks if cell is within range and walkable
 * @x: x coordinate
 * @y: y coordinate
 * @rows: number of rows
 * @cols: number of columns
 * Return: 1 if valid, 0 otherwise
 */
static int is_valid(int x, int y, int rows, int cols)
{
	return (x >= 0 && x < cols && y >= 0 && y < rows);
}

/**
 * backtrack - backtracks path recursively
 * @map: pointer to 2d array
 * @rows: number of rows
 * @cols: number of columns
 * @x: current x coordinate
 * @y: current y coordinate
 * @target: pointer to target point
 * @visited: pointer to 2d array of visited cells
 * @path: pointer to queue for the path
 * Return: 1 if path found, 0 otherwise
 */

static int backtrack(char **map, int rows, int cols,
	int x, int y, point_t const *target, char **visited, queue_t *path)
{
	int i, new_x, new_y;
	point_t *point;
	const int dx[] = {0, 1, 0, -1};
	const int dy[] = {1, 0, -1, 0};

	if (!is_valid(x, y, rows, cols) || map[y][x] == '1' || visited[y][x])
		return (0);

	printf("Checking coordinates [%d, %d]\n", x, y);
	visited[y][x] = 1;

	if (x == target->x && y == target->y)
	{
		point = malloc(sizeof(*point));
		if (!point)
			return (0);
		point->x = x;
		point->y = y;
		queue_push_back(path, point);
		return (1);
	}

	for (i = 0; i < 4; i++)
	{
		new_x = x + dx[i];
		new_y = y + dy[i];

		if (backtrack(map, rows, cols, new_x, new_y, target, visited, path))
		{
			point = malloc(sizeof(*point));
			if (!point)
				return (0);
			point->x = x;
			point->y = y;
			queue_push_front(path, point);
			return (1);
		}
	}

	visited[y][x] = 0;
	return (0);
}

/**
 * alloc_visited - allocates 2d array
 * @rows: number of rows
 * @cols: number of columns
 * Return: pointer to allocated 2d array
 */
static char **alloc_visited(int rows, int cols)
{
	char **visited;
	int r;
	
	visited = NULL;

	visited = malloc(sizeof(*visited) * rows);
	if (!visited)
		return (NULL);
	for (r = 0; r < rows; r++)
	{
		visited[r] = calloc((size_t)cols, sizeof(**visited));
		if (!visited[r])
		{
			while (r--)
				free(visited[r]);
			free(visited);
			return (NULL);
		}
	}
	return (visited);
}

/**
 * free_visited - frees allocated memory for visited cells
 * @visited: pointer to 2d array
 * @rows: number of rows
 */
static void free_visited(char **visited, int rows)
{
	int r;

	if (!visited)
		return;

	for (r = 0; r < rows; r++)
		free(visited[r]);
	free(visited);
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

	if (!map || !start || !target || rows <= 0 || cols <= 0)
		return (NULL);

	path = queue_create();
	if (!path)
		return (NULL);

	visited = alloc_visited(rows, cols);
	if (!visited)
	{
		queue_delete(path);
		return (NULL);
	}

	if (!backtrack(map, rows, cols, start->x, start->y, target, visited, path))
	{
		queue_delete(path);
		path = NULL;
	}

	free_visited(visited, rows);
	return (path);
}
