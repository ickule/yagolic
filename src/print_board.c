#include <stdio.h>

#include "board.h"

void print_board(int *board, int rows, int cols) {
  char representation;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (board[i * cols + j]) {
        representation = '*';
      } else {
        representation = ' ';
      }
      printf(" %c ", representation);
    }
    printf("\n");
  }
}
