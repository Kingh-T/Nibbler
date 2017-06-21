#ifndef SPRITE_HPP
# define SPRITE_HPP

#include "../../.brew/include/SDL2/SDL.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <string>

class Sprite {
    SDL_Surface *image;
    SDL_Rect snake;
    int origin_x;
    int origin_y;
    
    public:
        Sprite(SDL_Renderer* renderer, SDL_Rect player, int x, int y, int scale, std::vector<int> tailX, std::vector<int> tailY, int tailLength);
        void update();
        void draw(SDL_Surface *destination); 
};

#endif