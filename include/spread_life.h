#ifndef SPREAD_LIFE_H_INCLUDED
#define SPREAD_LIFE_H_INCLUDED

#include <stdlib.h>

#include "copy_board.h"
#include "count_neighbours.h"

void spread_life(int *board, int rows, int cols);
/* Scan the board and spread life according to Conway's rules */

#endif /* SPREAD_LIFE_H_INCLUDED */
