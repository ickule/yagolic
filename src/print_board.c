#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "board.h"

/* ANSI escape codes for coloured output */
const char *ANSI_COLOR_RESET = "\x1b[0m";
const char *ANSI_COLOR_RED = "\x1b[31m";
const char *ANSI_COLOR_GREEN = "\x1b[32m";
const char *ANSI_COLOR_YELLOW = "\x1b[33m";
const char *ANSI_COLOR_BLUE = "\x1b[34m";
const char *ANSI_COLOR_MAGENTA = "\x1b[35m";
const char *ANSI_COLOR_CYAN = "\x1b[36m";

/* Function to get ANSI colour code based on group number */
const char *get_colour(short group_number) {
  switch (group_number % 6) {
  case 1:
    return ANSI_COLOR_RED;
  case 2:
    return ANSI_COLOR_GREEN;
  case 3:
    return ANSI_COLOR_YELLOW;
  case 4:
    return ANSI_COLOR_BLUE;
  case 5:
    return ANSI_COLOR_MAGENTA;
  case 0:
    return ANSI_COLOR_CYAN;
  default:
    return ANSI_COLOR_RESET;
  }
}

/* Function to perform DFS traversal */
void dfs(unsigned char x, unsigned char y, board_t board, short group_number) {
  assert(board.cells != NULL);
  assert(x <= board.rows);
  assert(y <= board.cols);

  /* Mark current cell as visited and assign group number */
  board.cells[x * board.cols + y] = group_number;

  /* Iterate over neighbouring cells in a 3x3 grid around the current cell (x, y) */
  /* Loop variable type need to be able to hold 1 more value that the max of type for x and y*/
  for (short i = x - 1; i <= x + 1; ++i) {
    for (short j = y - 1; j <= y + 1; ++j) {
      /* Check if the neighbour is within the bounds and is alive and not visited (i.e. equal to 1)
       */
      if (i >= 0 && i < board.rows && j >= 0 && j < board.cols && !(i == x && j == y) &&
          board.cells[i * board.cols + j] == 1) {
        dfs(i, j, board, group_number);
      }
    }
  }
}

/* Function to find connected cells and tagging them with a group number */
void find_groups(board_t board) {
  assert(board.cells != NULL);

  /* Max group number on a 255*255 board is 16384*/
  /* 1 is reserved to indicate than a cell is alive and has not been visited so it cannot be used
   * for group number */
  short group_number = 1;

  for (unsigned char i = 0; i < board.rows; ++i) {
    for (unsigned char j = 0; j < board.cols; ++j) {
      /* If current cell is not visited and has value 1, increment group number and start DFS
       * traversal */
      if (board.cells[i * board.cols + j] == 1) {
        ++group_number;
        dfs(i, j, board, group_number);
      }
    }
  }
}

/* Print the board with colours*/
void print_cells_with_colours(board_t board) {
  assert(board.cells != NULL);

  char representation;

  for (unsigned char i = 0; i < board.rows; ++i) {
    for (unsigned char j = 0; j < board.cols; ++j) {
      if (board.cells[i * board.cols + j]) {
        representation = '*';
      } else {
        /* NOTE: All empty cells are in group number '0' which will get assigned a colour */
        /* but it does not matter as we are using an invisible character*/
        representation = ' ';
      }
      printf("%s", get_colour(board.cells[i * board.cols + j]));
      printf(" %c ", representation);
      printf("%s", ANSI_COLOR_RESET);
    }
    printf("\n");
  }
}

void print_board(board_t board) {
  assert(board.cells != NULL);

  find_groups(board);

  print_cells_with_colours(board);
}
