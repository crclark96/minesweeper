#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "board.h"
#include "grid.h"

int main(void){
  int board[BOARD_SIZE][BOARD_SIZE];
  char grid[BOARD_SIZE][BOARD_SIZE];
  char input;
  initialize_board(board);
  print_board_integers(board);
  printf("\n");
  initialize_grid(grid);
  print_grid(grid);
  
  while(1){
    // main game loop
    printf("press r to reveal, f to flag, v to verify, or q to quit \n");
    input = getchar();
    assert('\n' == getchar()); // get newline
    switch(input){
    case 'r':
      reveal_grid(grid,board);
      break;
    case 'f':
      flag_grid(grid);
      break;
    case 'v':
      verify_grid(grid,board);
      break;
    case 'q':
      exit(0);
      break;
    case 'h':
      printf("press r to reveal, f to flag, v to verify, or q to quit \n");
      break;
    default:
      printf("please enter a valid command (r,f,q,h) \n");
      break;
    }
  }

  return 0;
}
