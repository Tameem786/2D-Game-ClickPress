// Member 1 : Zaman Tameem Uz - A18CS4059
// Member 2 : Tasif Ahmed - A18CS4055

#include "ball.hpp"
#include "blueball.hpp"
#include "redball.hpp"
#include "controller.hpp"
#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <winbgim.h>
#include <fstream>

using namespace std;

int main()
{
    int w = getmaxwidth();
    int h = getmaxheight();
    int i = 0;
    int time = 250;
    char ans;
    string player1, player2;

    cout << "Game Rules:" << endl;
    cout << "1. Blue ball is for player 1 & Red ball for player 2" << endl;
    cout << "2. Player 1 need to type letters in the blue ball to change player 2's red ball's location and get point" << endl;
    cout << "3. Player 2 need to click the red ball before Player 1 type his/her letter and change the position and get the point" << endl;
    cout << "4. If Player 2 click his/her ball before Player 1 type his letter, then Player 1's letter will change." << endl;
    cout << "5. If any of Player give wrong input, one point will be deducted" << endl;
    cout << endl;
    cout << "Player 1: ";
    cin >> player1;
    cout << "Player 2: ";
    cin >> player2;
    cout << "Do you want to start the game [y/n]? ";
    cin >> ans;
    if (ans == 'y' || ans == 'Y')
    {
        initwindow(w, h, "Ball");

        POINT cursorposition;
        int mouse_x, mouse_y;

        blueball blue(300, 300, 40);
        redball red(500, 300, 40);
        controller ctrl1;
        controller ctrl2;

        ctrl1.setBall(&blue);
        ctrl2.setBall(&red);

        const int SIZE = 26;
        char letters[SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                              'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        while (1)
        {
            ctrl1.setLetter(letters[i]);
            ctrl1.showBall();
            ctrl2.showBall();
            GetCursorPos(&cursorposition);
            mouse_x = cursorposition.x;
            mouse_y = cursorposition.y;

            setcolor(YELLOW);
            setbkcolor(BLACK);
            bgiout << player1 << ": " << ctrl1.showPoint() << "  |  " << player2 << ": " << ctrl2.showPoint();
            outstreamxy(100, 10);
            bgiout << "Time Left:  " << time << "s";
            outstreamxy(600, 0);

            if (kbhit())
            {
                int ch = getch();
                for (int j = 97; j <= 122; j++)
                {
                    if (ch == j)
                    {
                        if (ch == int(letters[i]) + 32)
                        {
                            ctrl2.hideBall();
                            ctrl1.addPoint(1);
                            ctrl2.setPos((rand() % (w - 100)) + 1, (rand() % (h - 100)) + 1);
                            i = (rand() % 25) + 1;
                            break;
                        }
                        else
                        {
                            ctrl1.minusPoint(1);
                            break;
                        }
                    }
                }
            }
            if (GetAsyncKeyState(VK_LBUTTON))
            {
                if ((mouse_x > ctrl2.getX() - 40) && (mouse_x < ctrl2.getX() + 40) && (mouse_y > ctrl2.getY() - 40) && (mouse_y < ctrl2.getY() + 40))
                {
                    ctrl2.hideBall();
                    ctrl2.addPoint(1);
                    ctrl2.setPos((rand() % (w - 100)) + 1, (rand() % (h - 100)) + 1);
                    i = (rand() % 25) + 1;
                }
            }
            if (time == 0)
            {
                cleardevice();
                bgiout << "GAME OVER";
                outstreamxy(w / 2, h / 2);
                bgiout << player1 << ": " << ctrl1.showPoint();
                outstreamxy(w / 2, (h / 2) + 20);
                bgiout << player2 << ": " << ctrl2.showPoint();
                outstreamxy(w / 2, (h / 2) + 45);
                if (ctrl2.showPoint() > ctrl1.showPoint())
                {
                    bgiout << player2 << " Wins";
                    outstreamxy(w / 2, (h / 2) + 70);
                    if (getch())
                        break;
                }
                else if (ctrl2.showPoint() < ctrl1.showPoint())
                {
                    bgiout << player1 << " Wins";
                    outstreamxy(w / 2, (h / 2) + 70);
                    if (getch())
                        break;
                }
                else
                {
                    bgiout << "Draw";
                    outstreamxy(w / 2, h / 2);
                    if (getch())
                        break;
                }
            }
            delay(200);
            time = time - 1;
        }
    }

    else
        return 0;

    getch();
    closegraph();
}
