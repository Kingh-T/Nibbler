#ifndef GAMEELEMENTS_HPP
# define GAMEELEMENTS_HPP

#include "../../.brew/include/SDL2/SDL.h"
#include <iostream>

# define FPS 30

class GameElements {
    public:
        void createWindow();
        void capFrameRate(Uint32 firstTick);
};

#endif