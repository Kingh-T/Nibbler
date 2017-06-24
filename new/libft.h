#ifndef LIBFT_H
#define LIBFT_H

#include <vector>
#include "../../.brew/include/SDL2/SDL.h"
#include "Food.h"
#include "Snake.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SNAKE_SEGMENT_SIZE = 10;
const int INITIAL_SNAKE_SIZE = 5;
const int GAME_SPEED = 50;
bool DEBUG = false;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Segment {
    SDL_Rect space;
    Direction direction;
};

void Init();
void close();
void FoodCollision(Snake &snake, Food &food);
void WallCollision(Snake &snake);
void SelfCollision(Snake &snake);

#endif
