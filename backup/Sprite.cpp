#include "Sprite.hpp"

Sprite::Sprite(SDL_Renderer* renderer, SDL_Rect player, int x, int y, int scale, std::vector<int> tailX, std::vector<int> tailY, int tailLength)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0 , 255);
    player.w = scale;
    player.h = scale;

    for (int i = 0; i < tailLength; i++){
        player.x = tailX[i];
        player.y = tailY[i];
        SDL_RenderFillRect(renderer, &player);
    }
    player.x = x;
    player.y = y;

    SDL_RenderFillRect(renderer, &player);
}

void Sprite::update() {

}

void Sprite::draw(SDL_Surface *destination) {
    SDL_BlitSurface(image, NULL, destination, &snake);
}