#include "random_init_board.h"

void random_init_board(int *board, int rows, int cols)
/* Initialise the board with a random dead or alive state */
{
  srand(time(0));
  for (int x = 0; x < rows; x++) {
    for (int y = 0; y < cols; y++) {
      /* Generate a random 1 or 0 based on the last bit of the int returned by rand() */
      board[x * cols + y] = rand() & 1;
    }
  }
}
