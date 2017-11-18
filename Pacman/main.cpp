#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "ghost.h"
#include "pacman.h"
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
    bool gameOver = false, win = false;
    ifstream walls, dots;
    string line;

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
        wall[i].draw(g);
    }
    g.update();

    Circle dot[DOTNUM];
    dots.open("dots.txt");
    getline(dots, line);
    for(int i = 0; i < DOTNUM; i++)
    {
        dot[i];
        dots >> x >> y;
        dot[i].setCenter(Point(x, y));
        dot[i].draw(g);
        g.update();
    }

    Ghost blinky(Circle(20, Point(430, 365), red));
    blinky.draw(g);
    Ghost pinky(Circle(20, Point(477, 365), magenta));
    pinky.draw(g);
    Ghost inky(Circle(20, Point(524, 365), cyan));
    inky.draw(g);
    Ghost clyde(Circle(20, Point(571, 365), orange));
    clyde.draw(g);

    Pacman pacman(Circle(25, Point (500, 565), yellow));
    Triangle mouth(pacman.getCenter(), Point(pacman.getCenter().x + 25, pacman.getCenter().y - 15), Point(pacman.getCenter().x + 25, pacman.getCenter().y + 15), Color(255, 255, 255));
    Point p;
    pacman.draw(g);
    g.update();

    while (!g.getQuit() && !gameOver)
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

        blinky.move(g);
        pinky.move(g);
        inky.move(g);
        clyde.move(g);
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
                wall[i].draw(g);
                pacman.setDirection(STOP);
                pacman.draw(g);
            }
            if(wall[i].collision(blinky)){
                blinky.collide(g);
                wall[i].draw(g);
            }
            if(wall[i].collision(pinky)){
                pinky.collide(g);
                wall[i].draw(g);
            }
            if(wall[i].collision(inky)){
                inky.collide(g);
                wall[i].draw(g);
            }
            if(wall[i].collision(clyde)){
                clyde.collide(g);
                wall[i].draw(g);
            }
        }

        for (int i = 0; i < DOTNUM; i++)
        {
            if(pacman.collision(dot[i]) && !dot[i].eaten)
            {
                dot[i].erase(g);
                dot[i].eaten = true;
                pacman.draw(g);
                score += 10;
                cout << score << endl;
            }
            if(!dot[i].eaten)
            {
                dot[i].draw(g);
            }
        }
        if(pacman.collision(blinky) || pacman.collision(pinky) || pacman.collision(inky) || pacman.collision(clyde))
        {
            gameOver = true;
            g.Sleep(500);
        }

        if (score == 2000)
        {
            gameOver = true;
            win = true;
            g.Sleep(500);
        }

        g.update();
        g.Sleep(10);
    }
    if (win)
    {
        Rectangle gameWin(Point(0, 0), Point(1000, 1000), white);
        gameWin.draw(g);
        cout << "YOU WIN!" << endl;
    }
    else
    {
        Rectangle gameWin(Point(0, 0), Point(1000, 1000), white);
        gameWin.draw(g);
        cout << "YOU LOST!" << endl;
    }

}
