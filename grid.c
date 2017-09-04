#include <stdio.h>
#include <assert.h>
#include "grid.h"
#include "board.h"
#include "input.h"

int initialize_grid(char grid[][BOARD_SIZE]){
  // initialize character grid to represent game board

  for (int i=0;i<BOARD_SIZE;i++){
    for (int j=0;j<BOARD_SIZE;j++){
      grid[i][j] = '-';
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

int reveal_grid(char grid[][BOARD_SIZE], \
                int board[][BOARD_SIZE]){
  int x,y;
  get_coords(&x, &y);
  
  return 0;
}
int flag_grid(char grid[][BOARD_SIZE]){
  int x,y;
  get_coords(&x, &y);
  grid[x][y] = 'F';
  return 0;
}
int verify_grid(char grid[][BOARD_SIZE], int board[][BOARD_SIZE]){return 0;}
