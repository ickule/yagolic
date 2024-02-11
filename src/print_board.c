#include <stdio.h>

#include "board.h"

void print_board(board_t board) {
  char representation;

  for (int i = 0; i < board.rows; i++) {
    for (int j = 0; j < board.cols; j++) {
      if (board.cells[i * board.cols + j]) {
        representation = '*';
      } else {
        representation = ' ';
      }
      printf(" %c ", representation);
    }
    printf("\n");
  }
}
