#include "directions.h"

direction_t *get_directions(int *count)
{
	static direction_t dirs[] = {
		{1, 0},   /*right*/
		{0, 1},   /*down*/
		{-1, 0},  /*left*/
		{0, -1}   /*up*/
		/*Add diagonals if needed: {1, 1}, {-1, -1}, etc.*/
	};

	*count = sizeof(dirs) / sizeof(dirs[0]);
	return dirs;
}
