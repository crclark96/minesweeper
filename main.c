#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "grid.h"
#include "input.h"

<<<<<<< Updated upstream
int main(void){
  int board[BOARD_SIZE][BOARD_SIZE];
  char grid[BOARD_SIZE][BOARD_SIZE];
=======
int main(int argc, char* argv[]){
  if(argc != 4){
    printf("You must call ./minesweeper followed by the 3 arguments: BOARD_WIDTH, BOARD_HEIGHT, NUM_MINES\n");
    return(0);
  }
  
  int BOARD_WIDTH;
  int BOARD_HEIGHT;
  int NUM_MINES;


  sscanf(argv[1], "%d", &BOARD_WIDTH);
  sscanf(argv[2], "%d", &BOARD_HEIGHT);
  sscanf(argv[3], "%d", &NUM_MINES);


  int board[BOARD_WIDTH][BOARD_HEIGHT];
  char grid[BOARD_WIDTH][BOARD_HEIGHT];
>>>>>>> Stashed changes
  char input, c;
  int num_characters;
  initialize_board(board,BOARD_WIDTH, BOARD_HEIGHT, NUM_MINES);
  print_board_integers(board,BOARD_WIDTH, BOARD_HEIGHT);
  printf("\n");
  initialize_grid(grid);
  
  while(1){
    // main game loop
    print_grid(grid);
    printf("press r to reveal, f to flag, v to verify, or q to quit \n");

    input = single_char_input();

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
