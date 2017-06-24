#ifndef SPRITE_HPP
# define SPRITE_HPP

#include "../../.brew/include/SDL2/SDL.h"
#include <iostream>

class Sprite {
    SDL_Surface *image;
    SDL_Rect snake;
    int origin_x;
    int origin_y;
    
    public:
        Sprite(Uint32 color, int x, int y, int w, int h);
        void update();
        void draw(SDL_Surface *destination); 
};

#endif