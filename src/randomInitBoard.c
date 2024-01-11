#include "../include/randomInitBoard.h"

void randomInitBoard(int *board, int rows, int cols)
/* Initialise the board with random alive/dead */
{
  srand(time(0));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      board[i * cols + j] = rand() & 1; /* Give random value based on the rest of int division */
    }
  }
}
