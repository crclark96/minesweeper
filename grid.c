#include <stdio.h>
#include <assert.h>
#include "grid.h"
#include "board.h"
#include "input.h"

#define UNKNOWN_CHAR '-'
#define EMPTY_CHAR ' '
#define MINE_CHAR '*'

int initialize_grid(char grid[][BOARD_SIZE]){
  // initialize character grid to represent game board

  for (int i=0;i<BOARD_SIZE;i++){
    for (int j=0;j<BOARD_SIZE;j++){
      grid[i][j] = UNKNOWN_CHAR;
    }
  }

  return 0;
}

int print_grid(char grid[][BOARD_SIZE]){
  char indices[] = {'0','1','2','3','4','5','6','7','8','9',\
                    'a','b','c','d','e','f'};
  printf(" ");
  for (int i=0;i<BOARD_SIZE;i++){
    printf(" %c",indices[i]);
  }
  printf("\n");
  for (int i=0;i<BOARD_SIZE;i++){
    printf("%c ",indices[i]);
    for (int j=0;j<BOARD_SIZE;j++){
      printf("%c ",grid[j][i]);
    }
    printf("\n");
  }
  return 0;
}

int check_surroundings(char grid[][BOARD_SIZE], \
                       int board[][BOARD_SIZE], int x, int y){
  int x_coords[] = {x-1,x,x+1};
  int y_coords[] = {y-1,y,y+1};
  if(x < BOARD_SIZE && y < BOARD_SIZE && x >= 0 && y >= 0){
    if(board[x][y] == 0){
      grid[x][y] = EMPTY_CHAR;
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          if(grid[x_coords[i]][y_coords[j]] == UNKNOWN_CHAR)
            check_surroundings(grid,board,x_coords[i],y_coords[j]);
        }
      }
    }
  }
  return 0;
}

// This method returns 1 if a bomb was picked, 0 otherwise
int reveal_grid(char grid[][BOARD_SIZE], \
                int board[][BOARD_SIZE]){
  int x,y;
  get_coords(&x, &y);
  switch(board[x][y]){
  case 9:
    grid[x][y] = MINE_CHAR;
    return 1; 
  case 0:
    grid[x][y] = EMPTY_CHAR;
    check_surroundings(grid,board,x,y);
    break;
  default:
    grid[x][y] = board[x][y] + '0'; // convert int to char repr
    break;
  }
  return 0;
}
int flag_grid(char grid[][BOARD_SIZE]){
  int x,y;
  get_coords(&x, &y);
  grid[x][y] = 'F';
  return 0;
}

// TODO: this function should verify that all mines have been flagged
int verify_grid(char grid[][BOARD_SIZE], int board[][BOARD_SIZE]){
  int verify = 1; //if any of the mines are not flagged verify will be changed to 0
 for (int i=0;i<BOARD_SIZE;i++){
    for (int j=0;j<BOARD_SIZE;j++){
      if(grid[i][j] == 'F'){
        if(board[i][j] != 9){
          verify = 0; //if a space is incorrectly flagged then the grid is not verified
        }
      }
      if(board[i][j] == 9){
        if(grid[i][j] != 'F'){
          verify = 0; // if the board has a mine that is not flagged on the grid then the grid is not verified
        }
      }
    }
  }
  return verify;
}
