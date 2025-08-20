#include "pathfinding.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/**
 * get_node - Retrieves the node associated with a vertex
 * @param v: Pointer to the vertex
 * @param nodes: Array of Dijkstra nodes
 * @param size: Size of the nodes array
 * Return: Pointer to the Dijkstra node associated with the vertex, or NULL
 */
static dijkstra_node_t *get_node(vertex_t *v, dijkstra_node_t *nodes[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        if (nodes[i]->vertex == v)
            return (nodes[i]);
    return (NULL);
}

/**
 * extract_min - Extracts the unvisited node with the smallest distance
 * @param nodes: Array of Dijkstra nodes
 * @param size: Size of the nodes array
 * Return: Pointer to the unvisited Dijkstra node with the smallest distance, or NULL
 */
static dijkstra_node_t *extract_min(dijkstra_node_t *nodes[], size_t size)
{
    dijkstra_node_t *min = NULL;
    for (size_t i = 0; i < size; i++)
    {
        if (!nodes[i]->visited && (!min || nodes[i]->distance < min->distance))
            min = nodes[i];
    }
    return (min);
}

/**
 * build_path - Builds the path from target to start using prev pointers
 * @param target_node: Pointer to the target Dijkstra node
 * Return: Queue containing the path from start to target, or NULL
 */
static queue_t *build_path(dijkstra_node_t *target_node)
{
    queue_t *path = queue_create();
    if (!path)
        return (NULL);

    dijkstra_node_t *current = target_node;
    while (current)
    {
        char *name = strdup(current->vertex->content);
        if (!name || !queue_push_front(path, name))
        {
            free(name);
            queue_delete(path);
            return (NULL);
        }
        current = current->prev;
    }
    return (path);
}

/**
 * dijkstra_graph - Finds the shortest path using Dijkstra's algorithm
 * @param graph: Pointer to the graph
 * @param start: Pointer to the starting vertex
 * @param target: Pointer to the target vertex
 * Return: Queue containing the path from start to target, or NULL
 */
queue_t *dijkstra_graph(graph_t *graph, const vertex_t *start, const vertex_t *target)
{
    if (!graph || !start || !target)
        return (NULL);

    size_t size = graph->nb_vertices;
    dijkstra_node_t *nodes[size];

    vertex_t *v = graph->vertices;
    for (size_t i = 0; i < size && v; i++, v = v->next)
    {
        nodes[i] = malloc(sizeof(dijkstra_node_t));
        if (!nodes[i])
            return NULL;
        nodes[i]->vertex = v;
        nodes[i]->distance = (v == start) ? 0 : SIZE_MAX;
        nodes[i]->visited = 0;
        nodes[i]->prev = NULL;
    }

    while (1)
    {
        dijkstra_node_t *current = extract_min(nodes, size);
        if (!current)
            break;

        current->visited = 1;
        printf("Checking %s, distance from %s is %lu\n",
               current->vertex->content, start->content, current->distance);

        if (current->vertex == target)
        {
            queue_t *path = build_path(current);
            for (size_t i = 0; i < size; i++)
                free(nodes[i]);
            return (path);
        }

        edge_t *e = current->vertex->edges;
        while (e)
        {
            dijkstra_node_t *neighbor = get_node(e->dest, nodes, size);
            if (!neighbor->visited && current->distance + e->weight < neighbor->distance)
            {
                neighbor->distance = current->distance + e->weight;
                neighbor->prev = current;
            }
            e = e->next;
        }
    }

    for (size_t i = 0; i < size; i++)
        free(nodes[i]);
    return (NULL);
}
