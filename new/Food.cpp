#include "Food.h"
#include "libft.h"

Food::Food() {
    m_Generate();
}

int Food::m_GetX() {
    return (m_food.x);
}

int Food::m_GetY() {
    return (m_food.y);
}

void Food::m_Generate() {
    int tmpX = std::rand() % SCREEN_WIDTH;
    int tmpY = std::rand() % SCREEN_HEIGHT;
    while(tmpX % SNAKE_SEGMENT_SIZE != 0) {
        ++tmpX;
    }
    while(tmpY % SNAKE_SEGMENT_SIZE != 0) {
        ++tmpY;
    }
    m_food.x = tmpX - SNAKE_SEGMENT_SIZE;
    m_food.y = tmpY - SNAKE_SEGMENT_SIZE;
    m_food.w = SNAKE_SEGMENT_SIZE;
    m_food.h = SNAKE_SEGMENT_SIZE;
}

void Food::m_Draw() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RendderFillRect(renderer, &m_food);
}

void Food::m_Update() {
    m_Draw();
}
