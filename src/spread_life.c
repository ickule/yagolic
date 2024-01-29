#include "spread_life.h"

void spread_life(int *board, int rows, int cols)
/* Scan the field and applies the rules to it */
{
  int neighbours;
  int *old_board;
  old_board = malloc(rows * cols * sizeof *board);

  copy_board(rows, cols, board, old_board);
  for (int x = 0; x < rows; x++) {
    for (int y = 0; y < cols; y++) {
      neighbours = count_neighbours(x, y, old_board, rows, cols);
      if (old_board[x * cols + y]) {
        /* The cell is alive */
        if (neighbours < 2 || neighbours > 3)
        /* Cell dies if there are less than 2 or more than 3 neighbours */
        {
          board[x * cols + y] = 0;
        }
      } else {
        /* The cell is dead */
        if (neighbours == 3)
        /* Cell comes to life if there is exactly 3 neighbours */
        {
          board[x * cols + y] = 1;
        }
      }
    }
  }
  free(old_board);
}
