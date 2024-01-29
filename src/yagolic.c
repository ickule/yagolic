#include "yagolic.h"

int main() {
  int rows, cols, turns = 0, end = 0;
  char user_input;
  int *board;

  system("clear");
  printf("Welcome to this game of life! \n\n");
  printf("How many ROWS shall your board have ?\n");
  scanf("%d", &rows); // NOLINT acanf_s is not implemented in gnu c standard
  printf("How many COLUMNS shall your board have ?\n");
  scanf("%d", &cols); // NOLINT acanf_s is not implemented in gnu c standard
  while ((user_input = getchar()) != '\n' && user_input != EOF)
    ; /* discard the trailing '\n' character */
  system("clear");

  board = calloc(rows * cols, sizeof *board);

  random_init_board(board, rows, cols);

  while (end != 1) {
    printf("This is your board after %d turns\n", turns);
    print_board(board, rows, cols);
    printf("Please press ENTER to see the new generation or 'q' to quit.\n");
    while ((user_input = getchar()) != '\n' && user_input != EOF) {
      if (user_input == 'q' || user_input == 'Q') {
        end = 1;
      }
    }
    system("clear");
    spread_life(board, rows, cols);
    turns++;
  }

  free(board);

  return 0;
}
