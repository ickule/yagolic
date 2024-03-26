#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "clear_screen.h"

int main() {
  unsigned char turns = 0;
  char user_input;

  board_t board = init_board();

  while (1) {
    printf("This is your board after %hhu turns\n", turns);
    print_board(board);
    printf("Please press ENTER to see the new generation or 'q' to quit.\n");
    user_input = getchar();
    clear_screen();
    if (user_input == 'q' || user_input == 'Q') {
      break;
    }
    spread_life(board);
    ++turns;
  }

  free(board.cells);

  return 0;
}
