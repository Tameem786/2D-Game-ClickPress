#if !defined(BALL_HPP)
#define BALL_HPP

class ball
{
protected:
    int x, y, r;
    int point;
    char letter;

public:
    ball(int, int, int);
    virtual void draw() = 0;
    virtual void undraw() = 0;
    void setPoint(int);
    void setPosition(int, int);
    int getX() const;
    int getY() const;
    int getPoint() const;
    void setletter(char);
};

#endif // BALL_HPP
