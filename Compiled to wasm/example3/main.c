#include "h/hello.h"

int main()
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 1;

    if (SDL_CreateWindowAndRenderer(W_WIDTH, W_HEIGHT, 0, &window, &renderer) < 0)
        return 1;

    if (TTF_Init() < 0)
        return 1;
    font = TTF_OpenFont("font/gamecontinue.ttf", 100);

    SDL_Color color = { 240,240,240 };

    
    mainloopArgument* args = (mainloopArgument*)malloc(sizeof(mainloopArgument));
    args->color = color;
    args->renderer = renderer;
    args->font = font;
    emscripten_set_main_loop_arg(mainLoop, args, 5, 1);
    
 /*   
    SDL_bool quit = SDL_FALSE;
    while (!quit) {
        drawSquares(renderer);
        displayText(renderer, font, color);
        SDL_Delay(500);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                quit = SDL_TRUE;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    color = getRandomColor();
                    break;
                }
            }
        }
    }
*/
    free(args);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();

    return 0;
}