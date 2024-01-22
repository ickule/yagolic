#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"
#include "null_pointer_check.h"

/* Initialise an array of cells with random dead or alive state*/
int *random_init_cells(int rows, int cols) {
  srand(time(0));

  int *cells = malloc(rows * cols * sizeof(int));

  NULL_POINTER_CHECK(cells);

  for (int x = 0; x < rows; x++) {
    for (int y = 0; y < cols; y++) {
      /* Generate a random 1 or 0 based on the last bit of the int returned by rand() */
      cells[x * cols + y] = rand() & 1;
    }
  }

  return cells;
}

/* Initialise a board by asking user for its dimensions and populating it with random random dead or
 * alive cells */
board_t init_board() {
  int rows, cols;
  char user_input;

  system("clear");
  printf("Welcome to this game of life! \n\n");
  printf("How many ROWS shall your board have ?\n");
  scanf("%d", &rows); // NOLINT acanf_s is not implemented in gnu c standard
  printf("How many COLUMNS shall your board have ?\n");
  scanf("%d", &cols); // NOLINT acanf_s is not implemented in gnu c standard
  while ((user_input = getchar()) != '\n' && user_input != EOF)
    ; /* discard the trailing '\n' character */
  system("clear");

  return (board_t){rows, cols, random_init_cells(rows, cols)};
}
