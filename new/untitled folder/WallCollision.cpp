#include "libft.h"

void WallCollision(Snake &snake) {
    if (snake.m_GetHeadX() > SCREEN_WIDTH || snake.m_GetHeadX() < 0
        || snake.m_GetHeadY() > SCREEN_HEIGHT || snake.m_GetHeadY() < 0) {
        exit (-1);
    }
}

