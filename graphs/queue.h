#ifndef QUEUE_H
#define QUEUE_H

#include "graphs.h"

typedef struct vertex_queue_s
{
    const vertex_t *v;
    size_t depth;
    struct vertex_queue_s *next;
} vertex_queue_t;

vertex_queue_t *enqueue(vertex_queue_t **queue,
                        const vertex_t *v, size_t depth);

void free_queue(vertex_queue_t *head);

#endif /* QUEUE_H */
