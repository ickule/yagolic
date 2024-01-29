#include "print_board.h"

void print_board(int *board, int rows, int cols)
/* Print the board on the command line */
{
  char representation;
  for (int x = 0; x < rows; x++) {
    for (int y = 0; y < cols; y++) {
      if (board[x * cols + y]) {
        representation = '*';
      } else {
        representation = ' ';
      }
      printf(" %c ", representation);
    }
    printf("\n");
  }
}
