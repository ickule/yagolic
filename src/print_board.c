#include <assert.h>
#include <stdio.h>

#include "board.h"

void print_board(board_t board) {
  assert(board.cells != NULL);

  char representation;

  for (unsigned char i = 0; i < board.rows; ++i) {
    for (unsigned char j = 0; j < board.cols; ++j) {
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
