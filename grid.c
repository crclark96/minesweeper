#include "stdio.h"
#include "grid.h"
#include "board.h"

int initialize_grid(char grid[][BOARD_SIZE]){
  // initialize character grid to represent game board

  for (int i=0;i<BOARD_SIZE;i++){
    for (int j=0;i<BOARD_SIZE;j++){
      grid[i][j] = '-';
    }
  }

  return 0;
}
