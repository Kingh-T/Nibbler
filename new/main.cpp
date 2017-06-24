#include "libft.h"

int main() {
    Init();
    bool quit = false;
    Snake snake;
    Food food;

    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
        snake.m_Update();
        food.m_Update();
        FoodCollision(snake, food);
        WallCollision(snake);
        SelfCollision(snake);
        SDL_RenderPresent(renderer);
        SDL_Delay(GAME_SPEED);
    }
    close();
    return 0;
}