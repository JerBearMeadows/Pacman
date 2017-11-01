#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    SDL_Plotter g(1000,1000);
    int dir = 0;

    Rectangle background;
    background.setupperLeft(Point(0, 0));
    background.setlowerRight(Point(999, 999));
    background.setColor(Color(0, 0, 0));
    background.draw(g);
    g.update();

    Triangle test;
    test.setVertex(Point(100, 100));
    test.setPoint1(Point(150, 100));
    test.setPoint2(Point(200, 300));
    test.setColor(Color(255, 255, 255));
    test.draw(g);
    g.update();

    Circle pacman;
    Point p;
    pacman.setCenter(Point(500, 500));
    pacman.setRadius(20);
    pacman.setColor(Color(200, 200, 20));
    pacman.draw(g);
    g.update();

    while (!g.getQuit())
    {
    	if(g.kbhit())
        {
    	    switch(g.getKey())
    	    {
    	        case RIGHT_ARROW:   dir = 1;
                                    break;
    	        case LEFT_ARROW:    dir = 2;
                                    break;
    	        case UP_ARROW:      dir = 3;
                                    break;
    	        case DOWN_ARROW:    dir = 4;
                                    break;
    	    }
    	}
    	switch (dir)
    	{
        case 1:   pacman.erase(g);
                  p = pacman.getCenter();
                  p.x += 1;
                  pacman.setCenter(p);
                  pacman.draw(g);
                  g.update();
                  g.Sleep(10);
                  break;
        case 2:   pacman.erase(g);
                  p = pacman.getCenter();
                  p.x -= 1;
                  pacman.setCenter(p);
                  pacman.draw(g);
                  g.update();
                  g.Sleep(10);
                  break;
        case 3:   pacman.erase(g);
                  p = pacman.getCenter();
                  p.y -= 1;
                  pacman.setCenter(p);
                  pacman.draw(g);
                  g.update();
                  g.Sleep(10);
                  break;
        case 4:   pacman.erase(g);
                  p = pacman.getCenter();
                  p.y += 1;
                  pacman.setCenter(p);
                  pacman.draw(g);
                  g.update();
                  g.Sleep(10);
                  break;
    	}
    }
}
