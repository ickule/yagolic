#include "board.h"

int count_neighbours(int x, int y, int *board, int rows, int cols) {
  int neighbours = 0;

  /* Iterate over neighbouring cells in a 3x3 grid around the current cell (x, y) */
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      /* Check if the neighbouring cell is within the bounds of the board */
      if (i >= 0 && i < rows && j >= 0 && j < cols && !(i == x && j == y)) {
        neighbours += board[i * cols + j];
      }
    }
  }

  return neighbours;
}
