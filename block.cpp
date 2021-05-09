#include "block.h"
// https://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/
// Pieces definition
char mPieces[7 /*kind */][4 /* rotation */][5 /* horizontal blocks */][5 /* vertical blocks */] =
{
    // Square
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        }
       },

    // I
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        }
       }
      ,
    // L
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // L mirrored
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // N
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 2, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },



       {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // N mirrored
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 2, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // T
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        }
       }
};

/*
Displays the current piece by adding it to the renderer.
*/
void Block::draw_piece(int PX, int PY, int Ppiece, int Protation, SDL_Renderer*& renderer) {

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (mPieces[Ppiece][Protation][j][i] != 0)
            {
                SDL_Rect r;
                r.x = PX * BLOCK_PIXEL + i * BLOCK_PIXEL;
                r.y = PY * BLOCK_PIXEL + j * BLOCK_PIXEL;
                r.w = BLOCK_PIXEL;
                r.h = BLOCK_PIXEL;

                SDL_RenderFillRect(renderer, &r);
            }
        }
    }
}

/*
Displays the current board by adding it to the renderer.
*/
void Block::draw_board(int mBoard[BOARD_SIZE][BOARD_SIZE], SDL_Renderer*& renderer) {

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (mBoard[j][i] == 1)
            {
                SDL_Rect r;
                r.x = i * BLOCK_PIXEL;
                r.y = j * BLOCK_PIXEL;
                r.w = BLOCK_PIXEL;
                r.h = BLOCK_PIXEL;

                SDL_RenderFillRect(renderer, &r);
            }
        }
    }
}

/*
Creates a random piece by using random
*/
void Block::new_piece() {
    Ppiece = rand() % 6; // random number between 0 and 6
    Protation = rand() % 3; // random number between 0 and 3

    PX = 0;
    PY = 0;
}

/*
Sets all Board values to 0
*/
void Block::board_init(int mBoard[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            mBoard[i][j] = 0;
        }
    }
}

/*
Adds the current piece to the board
*/
void Block::save_piece(int mBoard[BOARD_SIZE][BOARD_SIZE], int PX, int PY, int Ppiece, int Protation) {
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (mPieces[Ppiece][Protation][j][i] != 0)
            {
                mBoard[PY + j][PX + i] = 1;
            }
        }
    }
}

/*
Checks if movements are possible. Looks for borders and other blocks.
returns 0 if there is a collision with borders
returns 1 if there is no collision
returns 2 if there is a collision with a piece
*/
int Block::checkpossible(int mBoard[BOARD_SIZE][BOARD_SIZE], int PX, int PY, int Ppiece, int Protation) {
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (mPieces[Ppiece][Protation][j][i] != 0)
            {
                // if there is a collision with other blocks
                if (mPieces[Ppiece][Protation][j][i] == mBoard[PY + j][PX + i])
                {
                    return 2;
                }

                // if piece reached first line
                if ((PY + j) > 15) {
                    // piece will be moved one too many times if position won't be corrected with this offset
                    PY -= 1;
                    // save piece to board and create a new piece
                    save_piece(mBoard, PX, PY, Ppiece, Protation);
                    new_piece();
                    return 0;
                }

                // if piece reached the upper end
                if ((PY + j) < 0) {
                    return 0;
                }

                // if piece reached the right
                else if ((PX + i) > 15) {
                    return 0;
                }

                // if piece reached the left
                else if ((PX + i) < 0) {
                    return 0;
                }

            }
        }
    }

    return 1;
}

/*
Clears all lines that are already completed. First it searches for complete lines, adds them to a vector and then deletes them.
*/
void Block::clear_possible(int mBoard[BOARD_SIZE][BOARD_SIZE]) {
    bool check;
    std::vector<int> vector_lines;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        check = true;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            // checks if every block in one line does indeed have the value 1, if yes, then check will remain true
            if (mBoard[i][j] == 0) {
                check = false;

            }
        }

        // check passed, adding line to vector
        if (check == true) {
            vector_lines.push_back(i);
        }
    }

    // deleting all lines that are found previously (and are contained inside the vector)
    if (vector_lines.empty() == false) {
        for (std::size_t i = 0; i < vector_lines.size(); ++i) {
            for (int j = vector_lines[i]; j > 0; j--) {
                for (int n = 0; n < BOARD_SIZE; n++) {
                    mBoard[j][n] = mBoard[j - 1][n];
                }
            }
        }
    }
}

