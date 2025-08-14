#ifndef DIRECTIONS_H
#define DIRECTIONS_H

typedef struct direction_s {
	int dx;
	int dy;
} direction_t;

direction_t *get_directions(int *count);

#endif /* DIRECTIONS_H */
