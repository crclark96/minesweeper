#ifndef GRID_H
#define GRID_H

#include "board.h"

int initialize_grid(char grid[BOARD_WIDTH][BOARD_HEIGHT]);
int print_grid(char grid[BOARD_WIDTH][BOARD_HEIGHT]);
int reveal_grid(char grid[BOARD_WIDTH][BOARD_HEIGHT], \
                int board[BOARD_WIDTH][BOARD_HEIGHT], \
                int x, int y, \
                int *bFirstMove);
int flag_grid(char grid[BOARD_WIDTH][BOARD_HEIGHT]);
int verify_grid(char grid[BOARD_WIDTH][BOARD_HEIGHT], int board[BOARD_WIDTH][BOARD_HEIGHT]);
int check_surroundings(char grid[BOARD_WIDTH][BOARD_HEIGHT], \
                       int board[BOARD_WIDTH][BOARD_HEIGHT], int x, int y);

#endif
