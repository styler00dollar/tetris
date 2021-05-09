#pragma once
#include <SDL.h>
#include "block.h"
#include "iostream"
#include <stdlib.h>
#include <vector>
#define BLOCK_PIXEL 25
#define BOARD_SIZE 16

class Block {
public:
    int PX;
    int PY;
    int Protation;
    int Ppiece;

    int mBoard[BOARD_SIZE][BOARD_SIZE];

    /*
    // init board with a nearly complete line, for debugging purposes
    int mBoard[BOARD_SIZE][BOARD_SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}
    };
    */

    // draws the current moving piece
    void draw_piece(int PX, int PY, int Ppiece, int Protation, SDL_Renderer*& renderer);
    // draws the saved board
    void draw_board(int mBoard[BOARD_SIZE][BOARD_SIZE], SDL_Renderer*& renderer);

    // saves the moving piece into the coordinate system
    void save_piece(int mBoard[BOARD_SIZE][BOARD_SIZE], int PX, int PY, int Ppiece, int Protation);

    // spawn a new random piece
    void new_piece();

    // check collision with game borders and other pieces
    int checkpossible(int mBoard[BOARD_SIZE][BOARD_SIZE], int PX, int PY, int Ppiece, int Protation);

    // sets all board values to 0
    void board_init(int mBoard[BOARD_SIZE][BOARD_SIZE]);

    // deletes all lines that are completed
    void clear_possible(int mBoard[BOARD_SIZE][BOARD_SIZE]);

};

