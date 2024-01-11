#include "../include/spreadLife.h"
#include <stdio.h>

void spreadLife(int *board, int rows, int cols)
/* Scan the field and applies the rules to it */
{
  int neighbours;
  int *oldBoard;
  oldBoard = malloc(rows * cols * sizeof *board);

  copyBoard(rows, cols, board, oldBoard);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      neighbours = countNeighbours(i, j, oldBoard, rows, cols);
      if (oldBoard[i * cols + j]) {
        /* The cell is alive */
        if (neighbours < 2 || 3 < neighbours)
        /* Cell dies if there are less than 2 or more than 3 neighbours */
        {
          board[i * cols + j] = 0;
        }
      } else {
        /* The cell is dead */
        if (neighbours == 3)
        /* Cell comes to life if there is exactly 3 neighbours */
        {
          board[i * cols + j] = 1;
        }
      }
    }
  }
  free(oldBoard);
}
