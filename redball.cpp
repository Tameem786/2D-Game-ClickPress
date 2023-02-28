#include "redball.hpp"
#include <iostream>
#include <graphics.h>

redball::redball(int _x = 0, int _y = 0, int _r = 0) : ball(_x, _y, _r) {}

void redball::draw()
{
    setfillstyle(SOLID_FILL, RED);
    setcolor(RED);
    fillellipse(x, y, r, r);
}

void redball::undraw()
{
    setfillstyle(SOLID_FILL, BLACK);
    setcolor(BLACK);
    fillellipse(x, y, r, r);
}