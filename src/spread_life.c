#include <stdlib.h>

#include "board.h"

/* Return the number of neighbours of the (x,y) point */
int count_neighbours(int x, int y, board_t board) {
  int neighbours = 0;

  /* Iterate over neighbouring cells in a 3x3 grid around the current cell (x, y) */
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      /* Check if the neighbouring cell is within the bounds of the board */
      if (i >= 0 && i < board.rows && j >= 0 && j < board.cols && !(i == x && j == y)) {
        neighbours += board.cells[i * board.cols + j];
      }
    }
  }

  return neighbours;
}

void spread_life(board_t board) {
  int neighbours;
  board_t old_board = copy_board(board);

  for (int i = 0; i < board.rows; i++) {
    for (int j = 0; j < board.cols; j++) {
      neighbours = count_neighbours(i, j, old_board);
      if (old_board.cells[i * board.cols + j]) {
        /* The cell is alive */
        if (neighbours < 2 || neighbours > 3)
        /* Cell dies if there are less than 2 or more than 3 neighbours */
        {
          board.cells[i * board.cols + j] = 0;
        }
      } else {
        /* The cell is dead */
        if (neighbours == 3)
        /* Cell comes to life if there is exactly 3 neighbours */
        {
          board.cells[i * board.cols + j] = 1;
        }
      }
    }
  }

  free(old_board.cells);
}
