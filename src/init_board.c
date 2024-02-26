#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"
#include "null_pointer_check.h"

/* Clear the input buffer from unused characters, including '\n' */
void clear_input_buffer() {
  char leftover;

  while ((leftover = getchar()) != '\n' && leftover != EOF) {
  }
}

/* Ask the user for number*/
int get_number_from_user() {
  int input;

  while (!scanf("%d", &input) || input <= 1) { // NOLINT
    /* scanf_s is not implemented in gnu c standard */
    printf("Your input is invalid, it should be an whole number bigger than 1.\n");
    clear_input_buffer();
  }
  clear_input_buffer();

  return input;
}

/* Initialise an array of cells with random dead or alive state*/
int *random_init_cells(int rows, int cols) {
  assert(rows > 0);
  assert(cols > 0);

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

  system("clear");

  printf("Welcome to this game of life! \n\n");
  printf("How many ROWS shall your board have ?\n");
  rows = get_number_from_user();
  printf("How many COLUMNS shall your board have ?\n");
  cols = get_number_from_user();

  system("clear");

  return (board_t){rows, cols, random_init_cells(rows, cols)};
}
