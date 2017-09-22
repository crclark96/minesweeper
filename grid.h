#ifndef GRID_H
#define GRID_H

#include "board.h"

int initialize_grid(char **grid, int BOARD_WIDTH, int BOARD_HEIGHT);
int print_grid(char **grid, int BOARD_WIDTH, int BOARD_HEIGHT);
int reveal_grid(char **grid, \
                int **board, int BOARD_WIDTH, int BOARD_HEIGHT);
int flag_grid(char **grid, int BOARD_WIDTH, int BOARD_HEIGHT);
int verify_grid(char **grid, int **board, int BOARD_WIDTH, int BOARD_HEIGHT);
int check_surroundings(char **grid, \
                       int **board, int x, int y, int BOARD_WIDTH, int BOARD_HEIGHT);

#endif
