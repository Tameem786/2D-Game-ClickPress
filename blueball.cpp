#include "blueball.hpp"
#include <iostream>
#include <graphics.h>

blueball::blueball(int _x = 0, int _y = 0, int _r = 0) : ball(_x, _y, _r) {}

void blueball::draw()
{
    setfillstyle(SOLID_FILL, BLUE);
    setcolor(BLUE);
    fillellipse(x, y, r, r);
    // settextstyle(10, HORIZ_DIR, 3);
    setbkcolor(BLUE);
    setcolor(WHITE);
    bgiout << letter;
    outstreamxy(x, y);
    // outtextxy(x, y, "A");
}

void blueball::undraw()
{
    setfillstyle(SOLID_FILL, BLACK);
    setcolor(BLACK);
    fillellipse(x, y, r, r);
}