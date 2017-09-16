#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "grid.h"
#include "input.h"

int main(void){
  int board[BOARD_WIDTH][BOARD_HEIGHT];
  char grid[BOARD_WIDTH][BOARD_HEIGHT];
  char input, c;
  int num_characters;
  initialize_board(board);
  print_board_integers(board);
  printf("\n");
  initialize_grid(grid);
  
  int bFirstMove = 1;
  
  while(1){
    // main game loop
    print_grid(grid);
    printf("press r to reveal, f to flag, v to verify, or q to quit \n");

    input = single_char_input();
    switch(input){
    int x,y;
    case 'r':
      get_coords(&x,&y);
      if(reveal_grid(grid,board, x, y, &bFirstMove)){ // return of 1 means game over
          print_grid(grid);
          printf("you exploded! \n");
          exit(0);
        }
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
