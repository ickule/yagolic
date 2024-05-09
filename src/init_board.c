#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"
#include "clear_screen.h"
#include "null_pointer_check.h"

/* Clear the input buffer from unused characters, including '\n' */
void clear_input_buffer() {
  char leftover;

  while ((leftover = getchar()) != '\n' && leftover != EOF) {
  }
}

/* Ask the user for number*/
unsigned char get_number_from_user() {
  /* Input is bigger that return type to check for max value*/
  unsigned short input;

  while (!scanf("%hu", &input) || input <= 1 || input > UCHAR_MAX) { // NOLINT
    /* scanf_s is not implemented in gnu c standard */
    printf("Your input is invalid, it should be an whole number between 2 and %d.\n", UCHAR_MAX);
    clear_input_buffer();
  }
  clear_input_buffer();

  return input;
}

/* Initialise an array of cells with random dead or alive state*/
short *random_init_cells(unsigned char rows, unsigned char cols) {
  srand(time(0));

  short *cells = malloc(rows * cols * sizeof(short));

  NULL_POINTER_CHECK(cells);

  for (unsigned char i = 0; i < rows; ++i) {
    for (unsigned char j = 0; j < cols; ++j) {
      /* Generate a random 1 or 0 based on the last bit of the int returned by rand() */
      cells[i * cols + j] = rand() & 1;
    }
  }

  return cells;
}

/* Initialise a board by asking user for its dimensions and populating it with random random dead or
 * alive cells */
board_t init_board() {
  unsigned char rows, cols;

  clear_screen();

  printf("Welcome to this game of life! \n\n");
  printf("How many ROWS shall your board have ?\n");
  rows = get_number_from_user();
  printf("How many COLUMNS shall your board have ?\n");
  cols = get_number_from_user();

  clear_screen();

  return (board_t){rows, cols, random_init_cells(rows, cols)};
}
