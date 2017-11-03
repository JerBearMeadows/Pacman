#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int WALLNUM = 53;
const int DOTNUM = 200;

int main(int argc, char** argv)
{
    SDL_Plotter g(1001,1001);
    int dir = 0, eat = 1, count = 0;
    int ulx, uly, lrx, lry, x, y;
    ifstream walls, dots;
    string line;
    Color white = Color(255, 255, 255);
    Color blue = Color(0, 0, 255);

    Rectangle background(Point(0, 0), Point(1000, 1000), Color());
    background.draw(g);

    Rectangle wall[WALLNUM];
    walls.open("walls.txt");
    getline(walls, line);
    for(int i = 0; i < WALLNUM; i++)
    {
        Rectangle wall[i];
        walls >> ulx >> uly >> lrx >> lry;
        wall[i].setupperLeft(Point(ulx, uly));
        wall[i].setlowerRight(Point(lrx, lry));
        wall[i].setColor(blue);
        wall[i].draw(g);
    }

    Circle dot[DOTNUM];
    dots.open("dots.txt");
    getline(dots, line);
    for(int i = 0; i < DOTNUM; i++)
    {
        Circle dot[i];
        dots >> x >> y;
        dot[i].setCenter(Point(x, y));
        dot[i].setRadius(10);
        dot[i].setColor(white);
        dot[i].draw(g);
        g.update();
    }

    Circle pacman(25, Point (500, 565), Color(250, 250, 20));
    Triangle mouth(pacman.getCenter(), Point(pacman.getCenter().x + 25, pacman.getCenter().y - 15), Point(pacman.getCenter().x + 25, pacman.getCenter().y + 15), Color(255, 255, 255));
    Point p;
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
                  break;
        case 2:   pacman.erase(g);
                  p = pacman.getCenter();
                  p.x -= 1;
                  pacman.setCenter(p);
                  pacman.draw(g);
                  break;
        case 3:   pacman.erase(g);
                  p = pacman.getCenter();
                  p.y -= 1;
                  pacman.setCenter(p);
                  pacman.draw(g);
                  break;
        case 4:   pacman.erase(g);
                  p = pacman.getCenter();
                  p.y += 1;
                  pacman.setCenter(p);
                  pacman.draw(g);
                  break;
    	}
    	if (eat > 0 && dir != 0)
        {
            if (count == 25)
            {
                switch (dir)
                {
                case 0:     mouth.erase(g);
                case 1:     mouth.erase(g);
                            mouth.setVertex(pacman.getCenter());
                            mouth.setPoint1(Point(pacman.getCenter().x + 25, pacman.getCenter().y - 15));
                            mouth.setPoint2(Point(pacman.getCenter().x + 25, pacman.getCenter().y + 15));
                            mouth.draw(g);
                            break;
                case 2:     mouth.erase(g);
                            mouth.setVertex(pacman.getCenter());
                            mouth.setPoint1(Point(pacman.getCenter().x - 25, pacman.getCenter().y - 15));
                            mouth.setPoint2(Point(pacman.getCenter().x - 25, pacman.getCenter().y + 15));
                            mouth.draw(g);
                            break;
                case 3:     mouth.erase(g);
                            mouth.setVertex(pacman.getCenter());
                            mouth.setPoint1(Point(pacman.getCenter().x - 15, pacman.getCenter().y - 25));
                            mouth.setPoint2(Point(pacman.getCenter().x + 15, pacman.getCenter().y - 25));
                            mouth.draw(g);
                            break;
                case 4:     mouth.erase(g);
                            mouth.setVertex(pacman.getCenter());
                            mouth.setPoint1(Point(pacman.getCenter().x - 15, pacman.getCenter().y + 25));
                            mouth.setPoint2(Point(pacman.getCenter().x + 15, pacman.getCenter().y + 25));
                            mouth.draw(g);
                            break;
                }
                eat *= -1;
                count = 0;
            } else
            {
                switch (dir)
                {
                case 0:     mouth.erase(g);
                case 1:     mouth.erase(g);
                            mouth.setVertex(pacman.getCenter());
                            mouth.setPoint1(Point(pacman.getCenter().x + 25, pacman.getCenter().y - 15));
                            mouth.setPoint2(Point(pacman.getCenter().x + 25, pacman.getCenter().y + 15));
                            mouth.draw(g);
                            break;
                case 2:     mouth.erase(g);
                            mouth.setVertex(pacman.getCenter());
                            mouth.setPoint1(Point(pacman.getCenter().x - 25, pacman.getCenter().y - 15));
                            mouth.setPoint2(Point(pacman.getCenter().x - 25, pacman.getCenter().y + 15));
                            mouth.draw(g);
                            break;
                case 3:     mouth.erase(g);
                            mouth.setVertex(pacman.getCenter());
                            mouth.setPoint1(Point(pacman.getCenter().x - 15, pacman.getCenter().y - 25));
                            mouth.setPoint2(Point(pacman.getCenter().x + 15, pacman.getCenter().y - 25));
                            mouth.draw(g);
                            break;
                case 4:     mouth.erase(g);
                            mouth.setVertex(pacman.getCenter());
                            mouth.setPoint1(Point(pacman.getCenter().x - 15, pacman.getCenter().y + 25));
                            mouth.setPoint2(Point(pacman.getCenter().x + 15, pacman.getCenter().y + 25));
                            mouth.draw(g);
                            break;
                }
            }
            count++;
        } else
        {
            if (count == 25)
            {
                mouth.erase(g);
                eat *= -1;
                count = 0;
            }
            count++;
        }
        g.update();
        g.Sleep(10);
    }
}
