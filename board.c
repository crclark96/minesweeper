#include "stdio.h"
#include "stdlib.h"

#define BOARD_SIZE 16
#define NUM_MINES 16

int initialize_board(int board[BOARD_SIZE][BOARD_SIZE]){
  // initialize the board based on definitions above
  for (int i=0;i<BOARD_SIZE;i++){
    for (int j=0;j<BOARD_SIZE;j++){
      board[i][j] = 0;
    }
  }
  return 0;
}

int print_board(int board[BOARD_SIZE][BOARD_SIZE]){
  // prints the board's integer representation
  for (int i=0;i<BOARD_SIZE;i++){
    for (int j=0;j<BOARD_SIZE;j++){
      printf("%i ",board[i][j]);
    }
    printf("\n");
  }
  return 0;
}

int main(void){
  int board[BOARD_SIZE][BOARD_SIZE];
  initialize_board(board);
  print_board(board);
  return 0;
}
