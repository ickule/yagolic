#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "null_pointer_check.h"

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
void dfs(unsigned char x, unsigned char y, board_t board, short *visited, short group_number) {
  assert(board.cells != NULL);
  assert(x <= board.rows);
  assert(y <= board.cols);
  assert(visited != NULL);

  /* Mark current cell as visited and assign group number */
  visited[x * board.cols + y] = group_number;

  /* Iterate over neighbouring cells in a 3x3 grid around the current cell (x, y) */
  /* Loop variable type need to be able to hold 1 more value that the max of type for x and y*/
  for (short i = x - 1; i <= x + 1; ++i) {
    for (short j = y - 1; j <= y + 1; ++j) {
      /* Check if the neighbor is within the bounds and is 1 and not visited */
      if (i >= 0 && i < board.rows && j >= 0 && j < board.cols &&
          board.cells[i * board.cols + j] == 1 && !visited[i * board.cols + j]) {
        dfs(i, j, board, visited, group_number);
      }
    }
  }
}

/* Function to find connected cells and tagging them with a group number */
void find_groups(board_t board, short *visited) {
  assert(board.cells != NULL);
  assert(visited != NULL);

  /* Max group number on a 255*255 board is 16384*/
  short group_number = 0;

  for (unsigned char i = 0; i < board.rows; ++i) {
    for (unsigned char j = 0; j < board.cols; ++j) {
      /* If current cell is not visited and has value 1, increment group number and start DFS
       * traversal */
      if (board.cells[i * board.cols + j] == 1 && !visited[i * board.cols + j]) {
        ++group_number;
        dfs(i, j, board, visited, group_number);
      }
    }
  }
}

/* Print the board with colours*/
void print_cells_with_colours(board_t board, short *visited) {
  assert(board.cells != NULL);
  assert(visited != NULL);

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
      printf("%s", get_colour(visited[i * board.cols + j]));
      printf(" %c ", representation);
      printf("%s", ANSI_COLOR_RESET);
    }
    printf("\n");
  }
}

void print_board(board_t board) {
  assert(board.cells != NULL);

  /* visited will be used to store the group number */
  /* and the fact that the cell has been visited already by the DFS */
  short *visited = calloc(board.rows * board.cols, sizeof(short));
  NULL_POINTER_CHECK(visited);

  find_groups(board, visited);

  print_cells_with_colours(board, visited);

  free(visited);
}
