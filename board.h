#ifndef BOARD_H
#define BOARD_H

//#define BOARD_SIZE 16
//#define NUM_MINES 32

struct Board{
  int height;
  int width;
  int num_mines;
  char** grid;
  int** board;
};

int increment_surroundings(struct Board board, int x, int y);
int initialize_board(struct Board board);
int print_board_integers(struct Board board);

#endif
