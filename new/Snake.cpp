#include "Snake.h"
#include "Spot.h"

Snake::Snake() : m_currentDirection(RIGHT), m_size(0) {
    for (int i = 0; i < INITIAL_SNAKE_SIZE; i++) {
        m_AppendSegment();
    }
    m_Update();
}

int Snake::m_GetHeadX() {
    return (m_snake.back().space.x);
}

int Snake::m_GetHeadY() {
    return (m_snake.back().space.y);
}

void Snake::m_AppendSegment() {
    ++m_size;
    Segment segment;
    if (m_snake.empty()) {
        segment.space.x = SCREEN_WIDTH / 2;
        segment.space.y =  SCREEN_HEIGHT / 2;
        segment.space.w = SNAKE_SEGMENT_SIZE;
        segment.space.h = SNAKE_SEGMENT_SIZE;
        segment.direction = m_currentDirection;
    }
    else {
        Segment lastSegment = m_snake.back();
        switch (lastSegment.direction) {
            case RIGHT:
                segment.space.x = lastSegment.space.x + SNAKE_SEGMENT_SIZE;
                segment.space.y = lastSegment.space.y;
                break;
            case LEFT:
                segment.space.x = lastSegment.space.x - SNAKE_SEGMENT_SIZE;
                segment.space.y = lastSegment.space.y;
                break;
            case DOWN:
                segment.space.x = lastSegment.space.x;
                segment.space.y = lastSegment.space.y - SNAKE_SEGMENT_SIZE;
                break;
            case UP:
                segment.space.x = lastSegment.space.x;
                segment.space.y = lastSegment.space.y - SNAKE_SEGMENT_SIZE;
                break;
        }
        segment.space.w = SNAKE_SEGMENT_SIZE;
        segment.space.h = SNAKE_SEGMENT_SIZE;
        segment.direction = m_currentDirection;
    }
    m_snake.push_back(segment);
}

void Snake::m_AddSpot() {
   Spot spot;
    Segment segment = m_snake.back();
    spot.m_x = segment.space.x;
    spot.m_y =segment.space.y;
    spot.m_direction = m_currentDirection;
    spot.m_counter = m_size;
    m_spot.push_back(spot);
}

void Snake::m_Move() {
    for (Spot &spot : m_spot) {
        for (Segment &segment : m_snake) {
            if (spot.m_x == segment.space.x && spot.m_y == segment.space.y && spot.m_counter > 0) {
                segment.direction = spot.m_direction;
                --spot.m_counter;
            }
        }
    }

    for (Segment &s : m_snake) {
        switch (s.direction) {
            case RIGHT:
                s.space.x += SNAKE_SEGMENT_SIZE;
                break;
            case LEFT:
                s.space.x -= SNAKE_SEGMENT_SIZE;
                break;
            case DOWN:
                s.space.y += SNAKE_SEGMENT_SIZE;
                break;
            case UP:
                s.space.y -= SNAKE_SEGMENT_SIZE;
                break;
        }
    }
}

void Snake::m_Draw() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (Segment s : m_snake) {
        SDL_RenderFillRect(renderer, &(s.space));
    }
}

void Snake::m_Update() {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_RIGHT:
                m_currentDirection = m_currentDirection != LEFT ? RIGHT : LEFT;
                break;
            case SDLK_LEFT:
                m_currentDirection = m_currentDirection != RIGHT ? LEFT : RIGHT;
                break;
            case SDLK_UP:
                m_currentDirection = m_currentDirection != DOWN ? UP : DOWN;
                break;
            case SDLK_DOWN:
                m_currentDirection = m_currentDirection != UP ? DOWN : UP;
                break;
        }
        m_AddSpot();
    }
    m_Move();
    m_Draw();
}