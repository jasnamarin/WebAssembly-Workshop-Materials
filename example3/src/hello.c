#include "../h/hello.h"
#include <stdio.h>
#include <string.h>

void drawSquares(SDL_Renderer* renderer) {
    for (int x = 0; x < W_WIDTH; x += CELL) {
        for (int y = 0; y < 1 + HEIGHT * CELL; y += CELL) {
            // draw one square
            SDL_Rect iterator = { x, y, CELL, CELL };
            char r = rand() % 255;
            char g = rand() % 255;
            char b = rand() % 255;
            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderFillRect(renderer, &iterator);
        }
    }
    SDL_RenderPresent(renderer);
}

void displayText(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color)
{
    char txt[6];
    strcpy(txt, "HELLO");

    SDL_Rect textRect = { CELL * 8,CELL * 2,(WIDTH - 7) * CELL,(HEIGHT - 2) * CELL };
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, txt, color);
    SDL_Texture* t = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_QueryTexture(t, NULL, NULL, &textRect.w, &textRect.h);
    SDL_RenderCopy(renderer, t, NULL, &textRect);
    SDL_RenderPresent(renderer);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(t);
}

SDL_Color getRandomColor()
{
    char r = rand() % 255;
    char g = rand() % 255;
    char b = rand() % 255;

    SDL_Color color = { r, g, b };

    return color;
}