#include "GameElements.hpp"

void    GameElements::createWindow()
 {
    SDL_Window *window;
    SDL_Event event;
    Uint32 firstTick;
    bool running = true;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Nibblder",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                400,
                                200,
                                SDL_WINDOW_RESIZABLE);
    if (!window){
        std::cout << "Window generation failed: " << SDL_GetError() << std::endl;
    }

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }
        this->capFrameRate(firstTick);
    }

    SDL_Delay(5000);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void    GameElements::capFrameRate(Uint32 firstTick)
{
     if ((1000 / FPS) > SDL_GetTicks() - firstTick) {
            SDL_Delay(1000 / FPS - (SDL_GetTicks() - firstTick));
        }
}