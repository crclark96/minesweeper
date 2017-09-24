#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "board.h"
#include "grid.h"
#include "input.h"

int main(int argc, char* argv[]){
  if(argc != 4){
    printf("You must call ./minesweeper followed by the 3 arguments: BOARD_WIDTH, BOARD_HEIGHT, NUM_MINES\n");
    return(0);
  }
  


  int BOARD_WIDTH = strtol(argv[1], NULL, 10);
  int BOARD_HEIGHT = strtol(argv[2], NULL, 10);;
  int NUM_MINES = strtol(argv[3], NULL, 10);

  if(errno == ERANGE){
  	printf("range error\n");
  	return 0;
  }

  if(BOARD_WIDTH <= 0 || BOARD_HEIGHT <= 0 || NUM_MINES <= 0 || BOARD_WIDTH>16 || BOARD_HEIGHT>16 || NUM_MINES>=(BOARD_HEIGHT*BOARD_WIDTH)/4){
  	printf("That is not a valid size\n");
  	printf("the board can not be larger than 16 by 16 and you can not have more mines than 1/4th of the spaces\n");
  	return(0);
  }

  // sscanf(argv[1], "%d", &BOARD_WIDTH);
  // sscanf(argv[2], "%d", &BOARD_HEIGHT);
  // sscanf(argv[3], "%d", &NUM_MINES);


  int **board =  (int**) malloc(sizeof(*board)*BOARD_WIDTH);
  for(int i = 0; i<BOARD_WIDTH; i++){
  	board[i] = (int*)malloc(sizeof(*board[i])*BOARD_HEIGHT);
  }
  char **grid =  (char**) malloc(sizeof(*grid)*BOARD_WIDTH);
  for(int i = 0; i<BOARD_WIDTH; i++){
  	grid[i] = (char*)malloc(sizeof(*grid[i])*BOARD_HEIGHT);
  }
  char input, c;
  int num_characters;
  initialize_board(board,BOARD_WIDTH, BOARD_HEIGHT, NUM_MINES);
  print_board_integers(board,BOARD_WIDTH, BOARD_HEIGHT);
  printf("\n");
  initialize_grid(grid, BOARD_WIDTH, BOARD_HEIGHT);
  
  int bFirstMove = 1;
  
  while(1){
    // main game loop
    print_grid(grid, BOARD_WIDTH, BOARD_HEIGHT);
    printf("press r to reveal, f to flag, or q to quit. Once all mines are flagged correctly, you win!\n");

    input = single_char_input();
    switch(input){
    int x,y;
    case 'r':

      get_coords(&x,&y, BOARD_WIDTH, BOARD_HEIGHT);
      if(reveal_grid(grid,board, BOARD_WIDTH, BOARD_HEIGHT, NUM_MINES, x, y, &bFirstMove)){ // return of 1 means game over
          print_grid(grid, BOARD_WIDTH, BOARD_HEIGHT);
          printf("you exploded! \n");
          exit(0);
        }
      break;
    case 'f':
      flag_grid(grid, BOARD_WIDTH, BOARD_HEIGHT);
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
    if(verify_grid(grid,board,BOARD_WIDTH,BOARD_HEIGHT)){
      print_grid(grid, BOARD_WIDTH, BOARD_HEIGHT);
      printf("Congratulations You Won!\n");
      exit(0);
    }
  }
  for (int i = 0; i < BOARD_WIDTH; i++){
    int* currentIntPtr = board[i];
    free(currentIntPtr);
    char* currentIntPtr2 = grid[i];
    free(currentIntPtr2);
	}
  return 0;
}
