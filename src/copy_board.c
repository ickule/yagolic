#include "copy_board.h"

void copy_board(int rows, int cols, int *board, int *copy)
/* Copies board into copy */
{
  for (int x = 0; x < rows; x++) {
    for (int y = 0; y < cols; y++) {
      copy[x * cols + y] = board[x * cols + y];
    }
  }
}
