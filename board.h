#ifndef BOARD_H
#define BOARD_H

#define BOARD_WIDTH 16
#define BOARD_HEIGHT 16
#define BOARD_SIZE 16

#define NUM_MINES 32

int increment_surroundings(int board[BOARD_WIDTH][BOARD_HEIGHT], int x, int y);
int initialize_board(int board[BOARD_WIDTH][BOARD_HEIGHT]);
int print_board_integers(int board[BOARD_WIDTH][BOARD_HEIGHT]);

#endif
