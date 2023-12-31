#include "../include/countNeighbours.h"

int countNeighbours(int x, int y, int *board, int rows, int cols)
// Return the number of neighbours of the (x,y) point
{
  int neighbours = 0;
  if (x == 0 && y == 0) {
    // x = 0 and y = 0 so no (x - 1) nor (y - 1)
    // clang-format off
    neighbours =
      board[x * cols + (y + 1)] +
      board[(x + 1) * cols + y] +
      board[(x + 1) * cols + (y + 1)];
    // clang-format on
  }
  if (x == 0 && 0 < y && y < (cols - 1)) {
    // x = 0 and 0 < y < cols so no (x - 1)
    // clang-format off
    neighbours =
      board[x * cols + (y - 1)] +
      board[x * cols + (y + 1)] +
      board[(x + 1) * cols + (y - 1)] +
      board[(x + 1) * cols + y] +
      board[(x + 1) * cols + (y + 1)];
    // clang-format on
  }
  if (x == 0 && y == (cols - 1)) {
    // x = 0 and y = cols so no (x - 1) nor (y + 1)
    // clang-format off
    neighbours =
      board[x * cols + (y - 1)] +
      board[(x + 1) * cols + (y - 1)] +
      board[(x + 1) * cols + y];
    // clang-format on
  }
  if (0 < x && x < (rows - 1) && y == 0) {
    // 0 < x < rows and y = 0 so no (y - 1)
    // clang-format off
    neighbours =
      board[(x - 1) * cols + y] +
      board[(x - 1) * cols + (y + 1)] +
      board[x * cols + (y + 1)] +
      board[(x + 1) * cols + y] +
      board[(x + 1) * cols + (y + 1)];
    // clang-format on
  }
  if (0 < x && x < (rows - 1) && 0 < y && y < (cols - 1)) {
    // 0 < x < rows and 0 < y < cols
    // clang-format off
    neighbours =
      board[(x - 1) * cols + (y - 1)] +
      board[(x - 1) * cols + y] +
      board[(x - 1) * cols + (y + 1)] +
      board[x * cols + (y - 1)] +
      board[x * cols + (y + 1)] +
      board[(x + 1) * cols + (y - 1)] +
      board[(x + 1) * cols + y] +
      board[(x + 1) * cols + (y + 1)];
    // clang-format on
  }
  if (0 < x && x < (rows - 1) && y == (cols - 1)) {
    // 0 < x < rows and y = cols so no (y + 1)
    // clang-format off
    neighbours =
      board[(x - 1) * cols + (y - 1)] +
      board[(x - 1) * cols + y] +
      board[x * cols + (y - 1)] +
      board[(x + 1) * cols + (y - 1)] +
      board[(x + 1) * cols + y];
    // clang-format on
  }
  if (x == (rows - 1) && y == 0) {
    // x = rows and y = 0 so no (x + 1) nor (y - 1)
    // clang-format off
    neighbours =
      board[(x - 1) * cols + y] +
      board[(x - 1) * cols + (y + 1)] +
      board[x * cols + (y + 1)];
    // clang-format on
  }
  if (x == (rows - 1) && 0 < y && y < (cols - 1)) {
    // x = rows and 0 < y < cols so no (x + 1)
    // clang-format off
    neighbours =
      board[(x - 1) * cols + (y - 1)] +
      board[(x - 1) * cols + y] +
      board[(x - 1) * cols + (y + 1)] +
      board[x * cols + (y - 1)] +
      board[x * cols + (y + 1)];
    // clang-format on
  }
  if (x == (rows - 1) && y == (cols - 1)) {
    // x = rows and y = cols so no (x + 1) nor (y + 1)
    // clang-format off
    neighbours =
      board[(x - 1) * cols + (y - 1)] +
      board[(x - 1) * cols + y] +
      board[x * cols + (y - 1)];
    // clang-format on
  }
  return neighbours;
}
