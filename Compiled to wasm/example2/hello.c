#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <emsripten.h>

#define CELL 36
#define WIDTH 23
#define HEIGHT 7
#define W_WIDTH (WIDTH * CELL)
#define W_HEIGHT (HEIGHT * CELL)

typedef struct coor {
    int x, y;
} coordinates;

coordinates hello[51] = { {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {4,1}, {4,2}, {4,3}, {4,4}, {4,5}, {6,1}, {6,2}, {6,3}, {6,4}, {6,5},
    {10,1}, {10,2}, {10,3}, {10,4}, {10,5}, {14,1}, {14,2}, {14,3}, {14,4}, {14,5}, {18,1}, {18,2}, {18,3}, {18,4}, {18,5},
    {21,1}, {21,2}, {21,3}, {21,4}, {21,5}, {2,3}, {3,3}, {7,3}, {8,3}, {7,1}, {8,1}, {7,5}, {8,5}, {11,5}, {12,5}, {15,5}, 
    {16,5}, {19,1}, {19,5}, {20,1}, {20,5} };
SDL_Color letters = { 250, 250, 250, 255 };

SDL_Window* window;
SDL_Renderer* renderer;

void drawSquares() {
    for (int x = 0; x < W_WIDTH; x += CELL) {
        for (int y = 0; y < 1 + HEIGHT * CELL; y += CELL) {

            // draw one square
            SDL_Rect iterator = { x, y, CELL, CELL };
            char r = rand() % 255;
            char g = rand() % 255;
            char b = rand() % 255;
            SDL_SetRenderDrawColor(renderer, r, g, b, 255);

            for (int i = 0; i < 51; i++) {
                if (hello[i].x == x / CELL && hello[i].y == y / CELL)
                    SDL_SetRenderDrawColor(renderer, letters.r, letters.g, letters.b, letters.a);
            }

            SDL_RenderFillRect(renderer, &iterator);
        }
    }
    SDL_RenderPresent(renderer);
}

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 1;

    if (SDL_CreateWindowAndRenderer(W_WIDTH, W_HEIGHT, 0, &window, &renderer) < 0)
        return 1;

/*
    SDL_bool quit = SDL_FALSE;
    while (!quit) {
        drawSquares();
        SDL_Delay(500);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                quit = SDL_TRUE;
                break;
            }
        }
    }
*/
    emscripten_set_main_loop(drawSquares, 2, 1);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}