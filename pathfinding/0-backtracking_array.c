#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pathfinding.h"
#include "directions.h"

/**
 * is_valid - checks if cell is within range and walkable
 */
static int is_valid(int x, int y, int rows, int cols)
{
	return (x >= 0 && x < cols && y >= 0 && y < rows);
}

/**
 * backtrack - backtracks path recursively
 */

static int backtrack(char **map, int rows, int cols,
	int x, int y, point_t const *target, char **visited, queue_t *path)
{
	point_t *point;
	int dir_count, i;
	direction_t *dirs;

	dirs = get_directions(&dir_count);

	if (!is_valid(x, y, rows, cols) || map[y][x] == '1' || visited[y][x])
		return (0);

	printf("Checking coordinates [%d, %d]\n", x, y);
	visited[y][x] = 1;

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

	for (i = 0; i < dir_count; i++)
	{
		int new_x = x + dirs[i].dx;
		int new_y = y + dirs[i].dy;

		if (backtrack(map, rows, cols, new_x, new_y, target, visited, path))
			return (1);
	}
	
	free(dequeue(path));
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
		free(dequeue(path));
		visited[start->y][start->x] = 0;
		return (0);
	}

	free_visited(visited, rows);
	return (path);
}
