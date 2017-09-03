#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "board.h"
#include "grid.h"

int main(void){
  int board[BOARD_SIZE][BOARD_SIZE];
  char grid[BOARD_SIZE][BOARD_SIZE];
  char input, c;
  int num_characters;
  initialize_board(board);
  print_board_integers(board);
  printf("\n");
  initialize_grid(grid);
  print_grid(grid);
  
  while(1){
    // main game loop
    print_grid(grid);
    printf("press r to reveal, f to flag, v to verify, or q to quit \n");

    // ensure single character input without storing in memory
    num_characters = 0;
    input = getchar();
    while(c!='\n'){
      c = getchar();
      num_characters++;
    }
    if(num_characters > 1){
      input = '\0'; // goto default in switch statement
    }

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
