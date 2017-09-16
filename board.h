#ifndef BOARD_H
#define BOARD_H

#define BOARD_WIDTH 16
#define BOARD_HEIGHT 16
#define BOARD_SIZE 16

#define NUM_MINES 32

int increment_surroundings(int board[][BOARD_SIZE], int x, int y);
int initialize_board(int board[][BOARD_SIZE]);
int print_board_integers(int board[][BOARD_SIZE]);

#endif
