#include "pathfinding.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int backtrack(vertex_t *current, vertex_t *target,
                     queue_t *path, char **visited, size_t count)
{
    printf("Checking %s\n", current->content);

    for (size_t i = 0; i < count; i++)
        if (visited[i] == current->content)
            return 0;

    visited[count++] = (char *)current->content;

    if (current == target)
    {
        enqueue(path, strdup(current->content));
        return 1;
    }

    edge_t *edge = current->edges;
    while (edge)
    {
        if (backtrack(edge->dest, target, path, visited, count))
        {
            enqueue(path, strdup(current->content));
            return 1;
        }
        edge = edge->next;
    }

    return 0;
}
