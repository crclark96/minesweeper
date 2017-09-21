#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 16
#define NUM_MINES 32

<<<<<<< Updated upstream
int increment_surroundings(int board[][BOARD_SIZE], int x, int y);
int initialize_board(int board[][BOARD_SIZE]);
int print_board_integers(int board[][BOARD_SIZE]);
=======
//#define NUM_MINES 32

int increment_surroundings(int **board, int BOARD_WIDTH, int BOARD_HEIGHT, int x, int y);
int initialize_board(int **board, int BOARD_WIDTH, int BOARD_HEIGHT);
int print_board_integers(int **board, int BOARD_WIDTH, int BOARD_HEIGHT);
>>>>>>> Stashed changes

#endif
