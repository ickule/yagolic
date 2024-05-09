#include <assert.h>
#include <stdlib.h>

#include "board.h"
#include "null_pointer_check.h"

board_t copy_board(board_t board) {
  assert(board.cells != NULL);

  short *cells = malloc(board.rows * board.cols * sizeof(short));

  NULL_POINTER_CHECK(cells);

  for (unsigned char i = 0; i < board.rows; ++i) {
    for (unsigned char j = 0; j < board.cols; ++j) {
      cells[i * board.cols + j] = board.cells[i * board.cols + j];
    }
  }

  return (board_t){board.rows, board.cols, cells};
}
