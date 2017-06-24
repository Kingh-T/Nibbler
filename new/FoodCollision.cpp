#include "libft.h"

void FoodCollision(Snake &snake, Food &food) {
    int x_snake = snake.m_GetHeadX();
    int y_snake = snake.m_GetHeadY();
    int x_food = food.m_GetX();
    int y_food = food.m_GetY();
    if (x_snake == x_food && y_snake == y_food) {
        snake.m_AppendSegment();
        food.m_Generate();
    }
}