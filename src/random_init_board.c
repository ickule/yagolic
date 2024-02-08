#include <stdlib.h>
#include <time.h>

#include "board.h"

void random_init_board(int *board, int rows, int cols) {
  srand(time(0));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      /* Generate a random 1 or 0 based on the last bit of the int returned by rand() */
      board[i * cols + j] = rand() & 1;
    }
  }
}
