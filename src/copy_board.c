#include <stdlib.h>

#include "board.h"

board_t copy_board(board_t board) {
  int *cells = malloc(board.rows * board.cols * sizeof(int));
  for (int i = 0; i < board.rows; i++) {
    for (int j = 0; j < board.cols; j++) {
      cells[i * board.cols + j] = board.cells[i * board.cols + j];
    }
  }

  return (board_t){board.rows, board.cols, cells};
}
