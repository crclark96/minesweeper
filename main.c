#include "stdio.h"
#include "board.h"

int main(void){
  int board[BOARD_SIZE][BOARD_SIZE];
  initialize_board(board);
  print_board(board);
  return 0;
}
