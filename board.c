#include "stdio.h"
#include "stdlib.h"
#include "board.h"

int increment_surroundings(int board[][BOARD_SIZE], int x, int y){
  // increments the surrounding tiles by one so they know how many
  // mines they border
  int x_vals[3] = {x-1,x,x+1};
  int y_vals[3] = {y-1,y,y+1};
  // loop through adjacent coordinates and increment if they are within
  // boundaries
  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      if (x_vals[i] >= 0 && x_vals[i] < 16 \
          && y_vals[j] >= 0 && y_vals[j] < 16){ 
        board[x_vals[i]][y_vals[j]]++;
      }
    }
  }
  // decrement original mine location
  board[x][y]--;

  return 0;
}

int initialize_board(int board[][BOARD_SIZE]){
  // initialize the board based on definitions above
  for (int i=0;i<BOARD_SIZE;i++){
    for (int j=0;j<BOARD_SIZE;j++){
      board[i][j] = 0;
    }
  }
  // place mines
  for (int i=0;i<NUM_MINES;i++){
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;
    if (board[x][y] != 0){
      // try again
      i--;
    }
    else{
      board[x][y] = 9;
      increment_surroundings(board,x,y);
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


