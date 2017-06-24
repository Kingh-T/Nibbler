#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include "libft.h"

class Food {
    SDL_Rect m_food;
    public:
        Food();
        int m_GetX();
        int m_GetY();
        void m_Generate();
        void m_Draw();
        void m_Update();

};


#endif
