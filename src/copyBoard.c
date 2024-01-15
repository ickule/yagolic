#include "copyBoard.h"

void copyBoard(int rows, int cols, int *board, int *copy)
/* Copies board into copy */
{
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      copy[i * cols + j] = board[i * cols + j];
    }
  }
}
