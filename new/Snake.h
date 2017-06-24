#ifndef SNAKE_H
#define SNAKE_H


#include "libft.h"
#include "Spot.h"

class Snake {
    std::vector<Segment> m_snake;
    std::vector<Spot> m_spot;
    Direction m_currentDirection;
    int m_size;
    public:
        Snake();
        int m_GetHeadX();
        int m_GetHeadY();
        void m_AppendSegment();
        void m_AddSpot();
        void m_Move();
        void m_Draw();
        void m_Update();

};

#endif
