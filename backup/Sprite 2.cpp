#include "Sprite.hpp"

Sprite::Sprite(Uint32 color, int x, int y, int w = 48, int h = 64)
{
    origin_x = 0;
    origin_y = 0;

    image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
    SDL_FillRect(image, NULL, color);
    snake = image->clip_rect;
    snake.x = x - origin_x;
    snake.y = y - origin_y;
}

void Sprite::update() {

}

void Sprite::draw(SDL_Surface *destination) {
    SDL_BlitSurface(image, NULL, destination, &snake);
}