#include <stdlib.h>

#include "board.h"

void copy_board(board_t board, board_t copy) {
  for (int i = 0; i < board.rows; i++) {
    for (int j = 0; j < board.cols; j++) {
      copy.cells[i * board.cols + j] = board.cells[i * board.cols + j];
    }
  }
}
