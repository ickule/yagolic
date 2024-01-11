#ifndef SPREAD_LIFE_H_INCLUDED
#define SPREAD_LIFE_H_INCLUDED

#include <stdlib.h>

#include "copyBoard.h"
#include "countNeighbours.h"

void spreadLife(int *board, int rows, int cols);
/* Scan the board and spread life according to Conway's rules */

#endif /* SPREAD_LIFE_H_INCLUDED */
