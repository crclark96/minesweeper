#include "stdio.h"
#include "board.h"
#include "grid.h"

int main(void){
  int board[BOARD_SIZE][BOARD_SIZE];
  char grid[BOARD_SIZE][BOARD_SIZE];
  initialize_board(board);
  print_board_integers(board);
  return 0;
}
