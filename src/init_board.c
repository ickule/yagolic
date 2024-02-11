#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"

/* Initialise an array of cells of the board with random dead or alive state*/
void random_init_board(board_t board) {
  srand(time(0));

  for (int x = 0; x < board.rows; x++) {
    for (int y = 0; y < board.cols; y++) {
      /* Generate a random 1 or 0 based on the last bit of the int returned by rand() */
      board.cells[x * board.cols + y] = rand() & 1;
    }
  }
}

/* Initialise a board by asking user for its dimensions and populating it with random random dead or
 * alive cells */
board_t init_board(int *cells) {
  int rows = -1, cols = -1;
  char user_input;

  system("clear");
  printf("Welcome to this game of life! \n\n");

  while (1) {
    printf("How many ROWS shall your board have ?\n");
    scanf("%d", &rows); // NOLINT acanf_s is not implemented in gnu c standard
    printf("How many COLUMNS shall your board have ?\n");
    scanf("%d", &cols); // NOLINT acanf_s is not implemented in gnu c standard
    system("clear");
    if (rows * cols > 0 && rows * cols <= BOARD_MAX_SIZE) {
      break;
    } else {
      printf("The board cannot be bigger than %d cells. Please enter new size.\n", BOARD_MAX_SIZE);
    }
  }

  while ((user_input = getchar()) != '\n' && user_input != EOF)
    ; /* discard the trailing '\n' character */

  board_t board = {rows, cols, cells};

  random_init_board(board);

  return board;
}
