#ifndef GRID_H
#define GRID_H

#include "board.h"

int initialize_grid(char grid[][BOARD_SIZE]);
int print_grid(char grid[][BOARD_SIZE]);
int reveal_grid(char grid[][BOARD_SIZE], \
                int board[][BOARD_SIZE]);
int flag_grid(char grid[][BOARD_SIZE]);
int verify_grid(char grid[][BOARD_SIZE], int board[][BOARD_SIZE]);

#endif
