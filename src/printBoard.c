#include "printBoard.h"

void printBoard(int *board, int rows, int cols)
/* Print the board on the command line */
{
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
