#if !defined(REDBALL_HPP)
#define REDBALL_HPP
#include "ball.hpp"

class redball : public ball
{
public:
    redball(int, int, int);
    void draw();
    void undraw();
};

#endif // REDBALL_HPP