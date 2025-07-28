#include <stdlib.h>
#include "heap.h"

/**
 * help_create - Creates a new heap structure
 * @data: pointer to function comparing two elements
 *
 *Return: pointer to the newly created heap structure or NULL
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *heap;

	heap = malloc(sizeof(heap_t));
	if (!heap)
		return (NULL);
	heap->size = 0;
	heap->root = NULL;
	heap->data_cmp = data_cmp;

	return (heap);
}
