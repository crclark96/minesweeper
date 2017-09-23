#include "stdio.h"
#include "stdlib.h"
#include "board.h"

int increment_surroundings(struct Board board, int x, int y){
  // increments the surrounding tiles by one so they know how many
  // mines they border
  int x_vals[3] = {x-1,x,x+1};
  int y_vals[3] = {y-1,y,y+1};
  // loop through adjacent coordinates and increment if they are within
  // boundaries
  printf("x: %d, y: %d \n", x, y);
  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      if (x_vals[i] >= 0 && x_vals[i] < board.width \
          && y_vals[j] >= 0 && y_vals[j] < board.height){ 
        if(board.board[x_vals[i]][y_vals[j]] != 9){ //if the tile is not already a mine, increment
          printf("%d, %d \n",x_vals[i],y_vals[j]);
          board.board[x_vals[i]][y_vals[j]]++;
        }
      }
    }
  }
  // no need to decrement original location, because that case is taken care of above (see previous comment)


  return 0;
}

int initialize_board(struct Board board){
  // initialize the board based on definitions above
  for (int i=0;i<board.width;i++){
    for (int j=0;j<board.height;j++){
      board.board[i][j] = 0;
    }
  }
  // place mines
  for (int i=0;i<board.num_mines;i++){
    int x = rand() % board.width;
    int y = rand() % board.height;
    // TODO: allow mines to be placed adjacently
    // (this involves editing the increment_surroundings func as well)
    //if (board.board[x][y] != 0){
      // try again
    //  i--;
    //}
    //else{
      if( board.board[x][y] == 9){ //if a bomb is already here, try again
        i--;
      }else{
        board.board[x][y] = 9;
        increment_surroundings(board, x,y);
      }
    //}
  }
  return 0;
}


int print_board_integers(struct Board board){
  // prints the board's integer representation
  // 9 for mines, numbers for regular tiles
  char indices[] = {'0','1','2','3','4','5','6','7','8','9',\
                    'a','b','c','d','e','f'};
  printf("  ");
  for (int i=0;i<board.width;i++){
    printf("%c ",indices[i]);
  }
  printf("\n");
  for (int i=0;i<board.height;i++){
    printf("%c ",indices[i]);
    for (int j=0;j<board.width;j++){
      printf("%i ",board.board[j][i]);
    }
    printf("\n");
  }
  return 0;
}


