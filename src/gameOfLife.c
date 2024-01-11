#include "../include/gameOfLife.h"

int main() {
  int rows, cols, i = 0, exit = 0;
  char sc = 1;
  int *board;

  system("clear");
  printf("Welcome to this game of life! \n\n");
  printf("How many ROWS shall your board have ?\n");
  scanf("%d", &rows); // NOLINT acanf_s is not implemented in gnu c standard
  printf("How many COLUMNS shall your board have ?\n");
  scanf("%d", &cols); // NOLINT acanf_s is not implemented in gnu c standard
  while ((sc = getchar()) != '\n' && sc != EOF)
    ; // discard the trailing '\n' character
  system("clear");

  board = calloc(rows * cols, sizeof *board);

  randomInitBoard(board, rows, cols);

  while (exit != 1) {
    printf("This is your board after %d turns\n", i);
    printBoard(board, rows, cols);
    printf("Please press ENTER to see the new generation or 'q' to quit.\n");
    while ((sc = getchar()) != '\n' && sc != EOF) {
      if (sc == 'q' || sc == 'Q') {
        exit = 1;
      }
    }
    system("clear");
    spreadLife(board, rows, cols);
    i++;
  }

  free(board);

  return 0;
}
