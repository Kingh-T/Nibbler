#include "libft.h"

void close() {
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
}