#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "board.h"
#include "grid.h"
#include "input.h"

struct Board{
  int height;
  int width;
  int num_mines;
  char** grid;
  int** board;
};

int main(int argc, char* argv[]){
  if(argc != 4){
    printf("You must call ./minesweeper followed by the 3 arguments: width, height, num_mines\n");
    return(0);
  }
  
  struct Board board;

  board.width = strtol(argv[1], NULL, 10);
  board.height = strtol(argv[2], NULL, 10);;
  board.num_mines = strtol(argv[3], NULL, 10);

  if(errno == ERANGE){
  	printf("range error\n");
  	return 0;
  }

  if(board.width>16 || board.height>16 || board.num_mines>=(board.height*board.width)/4){
  	printf("That is not a valid size\n");
  	printf("the board can not be larger than 16 by 16 and you can not have more mines than 1/4th of the spaces\n");
  	return(0);
  }

  // sscanf(argv[1], "%d", &board.width);
  // sscanf(argv[2], "%d", &board.height);
  // sscanf(argv[3], "%d", &board.num_mines);


  board.board =  (int**) malloc(sizeof(*board.board)*board.width);
  for(int i = 0; i<board.width; i++){
  	board.board[i] = (int*)malloc(sizeof(*board.board[i])*board.height);
  }
  board.grid =  (char**) malloc(sizeof(*board.grid)*board.width);
  for(int i = 0; i<board.width; i++){
  	board.grid[i] = (char*)malloc(sizeof(*board.grid[i])*board.height);
  }
  char input, c;
  int num_characters;
  initialize_board(board.board,board.width, board.height, board.num_mines);
  print_board_integers(board.board,board.width, board.height);
  printf("\n");
  initialize_grid(board.grid, board.width, board.height);
  
  int bFirstMove = 1;
  
  while(1){
    // main game loop
    print_grid(board.grid, board.width, board.height);
    printf("press r to reveal, f to flag, v to verify, or q to quit \n");

    input = single_char_input();
    switch(input){
    int x,y;
    case 'r':

      get_coords(&x,&y, board.width, board.height);
      if(reveal_grid(board.grid,board.board, board.width, board.height, board.num_mines, x, y, &bFirstMove)){ // return of 1 means game over
          print_grid(board.grid, board.width, board.height);
          printf("you exploded! \n");
          exit(0);
        }
      break;
    case 'f':
      flag_grid(board.grid, board.width, board.height);
      break;
    case 'v':
      if(verify_grid(board.grid,board.board, board.width, board.height)){
      	printf("Congratualtions You Won!\n");
      	exit(0);
      }
      else{
      	printf("sorry you are not correct. Keep trying\n");
      }
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
  for (int i = 0; i < board.width; i++){
    int* currentIntPtr = board.board[i];
    free(currentIntPtr);
    char* currentIntPtr2 = board.grid[i];
    free(currentIntPtr2);
	}
  return 0;
}
