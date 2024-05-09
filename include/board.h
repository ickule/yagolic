#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

typedef struct {
  unsigned char rows;
  unsigned char cols;
  short *cells;
} board_t;

/* Copies the board */
board_t copy_board(board_t board);

/* Print the board on the command line */
void print_board(board_t board);

/* Initialise a board by asking user for its dimensions and populating it with random random dead or
 * alive cells */
board_t init_board();

/* Scan the board and spread life according to Conway's rules */
void spread_life(board_t board);

#endif /* BOARD_H_INCLUDED */
