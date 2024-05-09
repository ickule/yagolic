#include <assert.h>
#include <stdlib.h>

#include "board.h"

/* Return the number of neighbours of the (x,y) point */
unsigned char count_neighbours(unsigned char x, unsigned char y, board_t board) {
  assert(board.cells != NULL);
  assert(x <= board.rows);
  assert(y <= board.cols);

  unsigned char neighbours = 0;

  /* Iterate over neighbouring cells in a 3x3 grid around the current cell (x, y) */
  /* Loop variable type need to be able to hold 1 more value that the max of type for x and y*/
  for (short i = x - 1; i <= x + 1; ++i) {
    for (short j = y - 1; j <= y + 1; ++j) {
      /* Check if the neighbouring cell is within the bounds of the board and if the cell is alive
       before considering it a neighbour */
      if (i >= 0 && i < board.rows && j >= 0 && j < board.cols && !(i == x && j == y) &&
          board.cells[i * board.cols + j]) {
        ++neighbours;
      }
    }
  }

  return neighbours;
}

void spread_life(board_t board) {
  assert(board.cells != NULL);

  unsigned char neighbours;
  board_t old_board = copy_board(board);

  for (unsigned char i = 0; i < board.rows; ++i) {
    for (unsigned char j = 0; j < board.cols; ++j) {
      neighbours = count_neighbours(i, j, old_board);
      if (old_board.cells[i * board.cols + j]) {
        /* The cell is alive */
        if (neighbours < 2 || neighbours > 3)
        /* Cell dies if it has less than 2 or more than 3 neighbours */
        {
          board.cells[i * board.cols + j] = 0;
        } else {
          /* Cell stays alive so we reset its value */
          board.cells[i * board.cols + j] = 1;
        }
      } else {
        /* The cell is dead */
        if (neighbours == 3)
        /* Cell comes to life if it has exactly 3 neighbours */
        {
          board.cells[i * board.cols + j] = 1;
        } else {
          /* Cell stays dead so we reset its value */
          board.cells[i * board.cols + j] = 0;
        }
      }
    }
  }

  free(old_board.cells);
}
