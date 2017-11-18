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
#include <ctime>

using namespace std;

const int WALLNUM = 53;
const int DOTNUM = 200;

int main(int argc, char** argv)
{
    SDL_Plotter g(1001,1001);
    int ulx, uly, lrx, lry, x, y;
    int eat = 1, count = 0, score = 0;
    ifstream walls, dots;
    string line;
    Color white = Color(255, 255, 255);
    Color yellow = Color(255, 255, 0);
    Color blue = Color(0, 0, 255);

    Rectangle background(Point(0, 0), Point(1000, 1000), Color());
    background.draw(g);

    Rectangle wall[WALLNUM];
    walls.open("walls.txt");
    getline(walls, line);
    for(int i = 0; i < WALLNUM; i++)
    {
        wall[i];
        walls >> ulx >> uly >> lrx >> lry;
        wall[i].setUpperLeft(Point(ulx, uly));
        wall[i].setLowerRight(Point(lrx, lry));
        wall[i].setColor(blue);
        wall[i].draw(g);
    }
    g.update();

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

    Circle pacman(25, Point (500, 565), yellow);
    pacman.setSpeed(2);
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
    	        case RIGHT_ARROW:   pacman.setDirection(RIGHT);
                                    break;
    	        case LEFT_ARROW:    pacman.setDirection(LEFT);
                                    break;
    	        case UP_ARROW:      pacman.setDirection(UP);
                                    break;
    	        case DOWN_ARROW:    pacman.setDirection(DOWN);
                                    break;
    	    }
    	}
    	pacman.move(g);
    	if (eat > 0 && pacman.getDirection() != STOP)
        {
            if (count == 25)
            {
                mouth.follow(pacman, g);
                eat *= -1;
                count = 0;
            } else
            {
                mouth.follow(pacman, g);
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

        for (int i = 0; i < WALLNUM; i++)
        {
            if(wall[i].collision(pacman)){
                pacman.erase(g);
                switch (pacman.getDirection())
                {
                case RIGHT: pacman.setCenter(Point(pacman.getCenter().x - pacman.getSpeed(), pacman.getCenter().y));
                            break;
                case LEFT:  pacman.setCenter(Point(pacman.getCenter().x + pacman.getSpeed(), pacman.getCenter().y));
                            break;
                case UP:    pacman.setCenter(Point(pacman.getCenter().x, pacman.getCenter().y + pacman.getSpeed()));
                            break;
                case DOWN:  pacman.setCenter(Point(pacman.getCenter().x, pacman.getCenter().y - pacman.getSpeed()));
                            break;
                }
                pacman.setDirection(STOP);
                pacman.draw(g);
            }
            wall[i].draw(g);
        }
/*
        for (int i = 0; i < DOTNUM; i++)
        {
            if(dot[i].collision(pacman)){
                dot[i].erase(g);

            }
        }
*/
        g.update();
        g.Sleep(20);
    }
}
