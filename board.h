#ifndef BOARD_H
#define BOARD_H

//#define BOARD_SIZE 16
//#define NUM_MINES 32

int increment_surroundings(int **board, int BOARD_WIDTH, int BOARD_HEIGHT, int x, int y);
int initialize_board(int **board, int BOARD_WIDTH, int BOARD_HEIGHT, int NUM_MINES);
int print_board_integers(int **board, int BOARD_WIDTH, int BOARD_HEIGHT);

#endif
