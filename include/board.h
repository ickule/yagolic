#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

/* Copies the board */
void copy_board(int rows, int cols, int *board, int *copy);

/* Print the board on the command line */
void print_board(int *array, int rows, int cols);

/* Initialise the board with a random dead or alive state */
void random_init_board(int *board, int rows, int cols);

/* Scan the board and spread life according to Conway's rules */
void spread_life(int *board, int rows, int cols);

#endif /* BOARD_H_INCLUDED */
