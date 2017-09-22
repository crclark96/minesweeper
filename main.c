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

  if(BOARD_WIDTH>16 || BOARD_HEIGHT>16 || NUM_MINES>=(BOARD_HEIGHT*BOARD_WIDTH)/4){
  	printf("the board can not be larger than 16 by 16 and you can not have more mines than 1/4th of the spaces\n");
  	return(0);
  }

  // sscanf(argv[1], "%d", &BOARD_WIDTH);
  // sscanf(argv[2], "%d", &BOARD_HEIGHT);
  // sscanf(argv[3], "%d", &NUM_MINES);


  int **board =  (int**) malloc(sizeof(int*)*BOARD_WIDTH);
  for(int i = 0; i<BOARD_WIDTH; i++){
  	board[i] = (int*)malloc(sizeof(int)*BOARD_HEIGHT);
  }
  char **grid =  (char**) malloc(sizeof(char*)*BOARD_WIDTH);
  for(int i = 0; i<BOARD_WIDTH; i++){
  	grid[i] = (char*)malloc(sizeof(char)*BOARD_HEIGHT);
  }
  char input, c;
  int num_characters;
  initialize_board(board,BOARD_WIDTH, BOARD_HEIGHT, NUM_MINES);
  print_board_integers(board,BOARD_WIDTH, BOARD_HEIGHT);
  printf("\n");
  initialize_grid(grid, BOARD_WIDTH, BOARD_HEIGHT);
  
  while(1){
    // main game loop
    print_grid(grid, BOARD_WIDTH, BOARD_HEIGHT);
    printf("press r to reveal, f to flag, v to verify, or q to quit \n");

    input = single_char_input();

    switch(input){
    case 'r':
      reveal_grid(grid,board, BOARD_WIDTH, BOARD_HEIGHT);
      break;
    case 'f':
      flag_grid(grid, BOARD_WIDTH, BOARD_HEIGHT);
      break;
    case 'v':
      verify_grid(grid,board, BOARD_WIDTH, BOARD_HEIGHT);
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
  for (int i = 0; i < BOARD_WIDTH; i++){
    int* currentIntPtr = board[i];
    free(currentIntPtr);
    char* currentIntPtr2 = grid[i];
    free(currentIntPtr2);
	}
  return 0;
}
