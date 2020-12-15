#ifndef _HELLO_H_
#define _HELLO_H_

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdlib.h>

#define CELL 36
#define WIDTH 23
#define HEIGHT 7
#define W_WIDTH (WIDTH * CELL)
#define W_HEIGHT (HEIGHT * CELL)

void drawSquares(SDL_Renderer* renderer);
void displayText(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color);
SDL_Color getRandomColor();

#endif