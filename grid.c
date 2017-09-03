#include <stdio.h>
#include <assert.h>
#include "grid.h"
#include "board.h"

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
                int board[][BOARD_SIZE]){return 0;}
int flag_grid(char grid[][BOARD_SIZE]){
  char indices[] = {'0','1','2','3','4','5','6','7','8','9',    \
                    'a','b','c','d','e','f'};
  int x,y;
  printf("enter x index: ");
  char index = getchar();
  assert('\n' == getchar()); // get newline
  for(int i=0;i<sizeof(indices)/sizeof(char);i++){
    if(indices[i] == index){
      x = i;
      break;
    }
  }
  printf("enter y index: ");
  index = getchar();
  assert('\n' == getchar()); // get newline
  for(int i=0;i<sizeof(indices)/sizeof(char);i++){
    if(indices[i] == index){
      y = i;
      break;
    }
  }
  grid[x][y] = 'F';
  return 0;
}
int verify_grid(char grid[][BOARD_SIZE], int board[][BOARD_SIZE]){return 0;}
