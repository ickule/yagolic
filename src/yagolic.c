#include <stdio.h>
#include <stdlib.h>

#include "board.h"

int main() {
  int turns = 0;
  char user_input;

  board_t board = init_board();

  while (1) {
    printf("This is your board after %d turns\n", turns);
    print_board(board);
    printf("Please press ENTER to see the new generation or 'q' to quit.\n");
    user_input = getchar();
    system("clear");
    if (user_input == 'q' || user_input == 'Q') {
      break;
    }
    spread_life(board);
    ++turns;
  }

  free(board.cells);

  return 0;
}
