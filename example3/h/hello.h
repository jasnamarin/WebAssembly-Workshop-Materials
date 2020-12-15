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

SDL_Window* window;
SDL_Renderer* renderer;
TTF_Font* font;

void drawSquares();
void displayText(SDL_Color color);
SDL_Color getRandomColor();

#endif