#include "../../.brew/include/SDL2/SDL.h"
#include "Sprite.hpp"
#include <iostream>
#define FPS 30
#define WINDOW_WIDTH 400
#define WINDOW_HEIGH 200

int main()
{
    Uint32 ticks;
    Uint32 color2;
    Uint32 color;
    SDL_Event event;
    bool running = true;
    int x, y, width, height;
    SDL_Window *window = NULL;
    SDL_Surface *tablet = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Nibblder",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                WINDOW_WIDTH,
                                WINDOW_HEIGH,
                                SDL_WINDOW_RESIZABLE);
    if (!window){
        std::cout << "Window generation failed: " << SDL_GetError() << std::endl;
    }

    tablet = SDL_GetWindowSurface(window);
    color = SDL_MapRGB(tablet->format, 255, 255, 255);
    color2 = SDL_MapRGB(tablet->format, 0, 255, 0);
    Sprite snake(color2, WINDOW_WIDTH / 5, WINDOW_HEIGH / 5, 48, 64);
    SDL_FillRect(tablet, NULL, color);
    snake.draw(tablet);
    //update()
    SDL_UpdateWindowSurface(window);
    //SDL_SetWindowBordered(window, SDL_FALSE);
    
    while (running) {
        ticks = SDL_GetTicks();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }

        if ((1000 / FPS) > SDL_GetTicks() - ticks) {
            SDL_Delay(1000 / FPS - (SDL_GetTicks() - ticks));
        }
    }

    SDL_Delay(5000);
    SDL_DestroyWindow(window);
    SDL_Quit();
}