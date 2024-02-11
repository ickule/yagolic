#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

static const int BOARD_MAX_SIZE = 1000;

typedef struct {
  int rows;
  int cols;
  int *cells;
} board_t;

/* Copies the board */
void copy_board(board_t board, board_t copy);

/* Print the board on the command line */
void print_board(board_t board);

/* Initialise a board by asking user for its dimensions and populating it with random random dead or
 * alive cells */
board_t init_board(int *cells);

/* Scan the board and spread life according to Conway's rules */
void spread_life(board_t board);

#endif /* BOARD_H_INCLUDED */
