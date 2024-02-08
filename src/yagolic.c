#include <stdio.h>
#include <stdlib.h>

#include "board.h"

int main() {
  int rows, cols, turns = 0;
  char user_input;
  int *board;

  system("clear");
  printf("Welcome to this game of life! \n\n");
  printf("How many ROWS shall your board have ?\n");
  scanf("%d", &rows); // NOLINT acanf_s is not implemented in gnu c standard
  printf("How many COLUMNS shall your board have ?\n");
  scanf("%d", &cols); // NOLINT acanf_s is not implemented in gnu c standard
  while ((user_input = getchar()) != '\n' && user_input != EOF)
    ; /* discard the trailing '\n' character */
  system("clear");

  board = calloc(rows * cols, sizeof *board);

  random_init_board(board, rows, cols);

  while (1) {
    printf("This is your board after %d turns\n", turns);
    print_board(board, rows, cols);
    printf("Please press ENTER to see the new generation or 'q' to quit.\n");
    user_input = getchar();
    system("clear");
    if (user_input == 'q' || user_input == 'Q') {
      break;
    }
    spread_life(board, rows, cols);
    turns++;
  }

  free(board);

  return 0;
}
