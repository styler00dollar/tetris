// https://stackoverflow.com/questions/21890627/drawing-a-rectangle-with-sdl2
#include "block.h"

int main(int argc, char** argv)
{
    // init
    srand(time(NULL));
    Block myBlock;
    myBlock.board_init(myBlock.mBoard); // set all fields to 0 (empty)
    myBlock.new_piece();

    // init rendering
    SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
        "Tetris", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        400,
        400,
        SDL_WINDOW_SHOWN
    );

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // black backround
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Clear window
    SDL_RenderClear(renderer);

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    // Render the rect to the screen
    SDL_RenderPresent(renderer);

    SDL_Event event;
    while(true) {
        /* Poll for events */
        while (SDL_PollEvent(&event)) {

            // deletes the current drawn stuff and sets it to the color black
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            // only process pressed keys and not keys that are hold down
            if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
                // switch statement based on pressed key
                switch (event.key.keysym.sym) {
                    SDL_Delay(10);
                case SDLK_DOWN:
                    // detects if a collision with another block occoured during down movement (status code 2)
                    // if a colllision is detected, save block to board and create a new piece
                    if (myBlock.checkpossible(myBlock.mBoard, myBlock.PX, myBlock.PY + 1, myBlock.Ppiece, myBlock.Protation) == 2) {
                        myBlock.save_piece(myBlock.mBoard, myBlock.PX, myBlock.PY, myBlock.Ppiece, myBlock.Protation);
                        myBlock.new_piece();
                    }
                    // if there is no collision, just move the piece normally
                    else {
                        myBlock.PY = myBlock.PY + 1;
                        
                    }
                    break;

                case SDLK_RIGHT:
                    if (myBlock.checkpossible(myBlock.mBoard, myBlock.PX + 1, myBlock.PY, myBlock.Ppiece, myBlock.Protation) == 1) {
                        myBlock.PX = myBlock.PX + 1;
                    }
                    break;

                case SDLK_LEFT:
                    if (myBlock.checkpossible(myBlock.mBoard, myBlock.PX - 1, myBlock.PY, myBlock.Ppiece, myBlock.Protation) == 1) {
                        myBlock.PX = myBlock.PX - 1;
                    }
                    break;

                case SDLK_z:
                    if (myBlock.checkpossible(myBlock.mBoard, myBlock.PX, myBlock.PY, myBlock.Ppiece, (myBlock.Protation + 1) % 4) == 1) {
                        myBlock.Protation = (myBlock.Protation + 1) % 4;
                    }
                    break;

                case SDLK_r:
                    myBlock.new_piece();
                    break;

                case SDLK_s:
                    myBlock.save_piece(myBlock.mBoard, myBlock.PX, myBlock.PY, myBlock.Ppiece, myBlock.Protation);
                    myBlock.new_piece();
                    break;

                case SDL_QUIT:
                    break;

                default:
                    break;
                }
            }
            // remove all completed lines
            myBlock.clear_possible(myBlock.mBoard);

            // set color and render
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

            myBlock.draw_board(myBlock.mBoard, renderer);
            myBlock.draw_piece(myBlock.PX, myBlock.PY, myBlock.Ppiece, myBlock.Protation, renderer);

            SDL_RenderPresent(renderer);
            
        }
    }

    return 0;
}