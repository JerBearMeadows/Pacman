#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "mouth.h"
#include "ghost.h"
#include "pacman.h"
#include "font.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WALLNUM = 53;
const int DOTNUM = 200;

int main(int argc, char** argv)
{
    SDL_Plotter g(1001,1001);
    int ulx, uly, lrx, lry, x, y, power[4];
    int eat = 1, count = 0, score = 0;
    int row, col;
    bool powerUp = false, gameOver = false, win = false;
    time_t start, stop;
    ifstream walls, dots;
    string line;
    ifstream S, C, O, R, E;
    char letterS[12][10], letterC[12][10], letterO[12][10], letterR[12][10], letterE[12][10];

    S.open("S.txt");
        S >> row >> col;
        for(int r = 0; r < row ; r ++){
            for(int c = 0 ; c < col; c ++){
                S >> letterS[r][c];
            }
        }

    Rectangle background(Point(0, 0), Point(1000, 1000), Color());
    background.draw(g);

    g.update();
    S.close();

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
    srand(time(NULL));
    for(int i = 0; i < 4; i++)
    {
        power[i] = rand() % 200;
    }
    for(int i = 0; i < DOTNUM; i++)
    {
        dot[i];
        dots >> x >> y;
        dot[i].setCenter(Point(x, y));
        if (i == power[0] || i == power[1] || i == power[2] || i == power[3])
        {
            dot[i].setColor(green);
            dot[i].setRadius(15);
        }
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
    pacman.setSpeed(4);
    Mouth mouth(pacman.getCenter(), Point(pacman.getCenter().x + 25, pacman.getCenter().y - 15), Point(pacman.getCenter().x + 25, pacman.getCenter().y + 15), Color(255, 255, 255));
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
    	    switch(g.getKey())
                {
                case 'S':
                    plotLetter(letterS, row, col, Point(rand()%800+100,rand()%800+100),g,4);
                    g.update();
                    break;
                }
    	}

    	pacman.move(g);

    	if (eat > 0 && pacman.getDirection() != STOP)
        {
            if (count == 5)
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
            if (count == 5)
            {
                eat *= -1;
                count = 0;
            }
            count++;
        }
        if (!blinky.dead)
        {
            blinky.move(g);
        }
        if (!pinky.dead)
        {
            pinky.move(g);
        }
        if (!inky.dead)
        {
            inky.move(g);
        }
        if (!clyde.dead)
        {
            clyde.move(g);
        }
        for (int i = 0; i < WALLNUM; i++)
        {
            if(wall[i].collision(pacman) && (!powerUp || i < 4)){
                pacman.erase(g);
                //cout << i << endl;
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
            else if(powerUp){
                pacman.setColor(white);
                if(wall[i].collision(pacman))
                {
                    wall[i].draw(g);
                    pacman.draw(g);
                }
                if(stop <= time(NULL))
                {
                    if(!wall[i].collision(pacman))
                    {
                        pacman.setColor(yellow);
                        powerUp = false;
                    }
                }
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
                if (i == power[0] || i == power[1] || i == power[2] || i == power[3]){
                    score += 135;
                    powerUp = true;
                    start = time(NULL);
                    stop = start + 7;
                } else{
                    score += 10;
                }
                cout << score << endl;
            }
            if(!dot[i].eaten){
                dot[i].draw(g);
            }
        }

        if(((pacman.collision(blinky) && !blinky.dead) || (pacman.collision(pinky) && !pinky.dead) ||
            (pacman.collision(inky) && !inky.dead) || (pacman.collision(clyde) && !clyde.dead)) && !powerUp){
            gameOver = true;
            g.Sleep(500);
        }
        else if(pacman.collision(blinky) && powerUp){
            blinky.setDirection(STOP);
            blinky.erase(g);
            pacman.draw(g);
            blinky.setDirection(RIGHT);
            if(!blinky.dead)
            {
                score += 50;
            }
            blinky.dead = true;
        }
        else if(pacman.collision(pinky) && powerUp){
            pinky.setDirection(STOP);
            pinky.erase(g);
            pacman.draw(g);
            pinky.setDirection(RIGHT);
            if(!pinky.dead)
            {
                score += 50;
            }
            pinky.dead = true;
        }
        else if(pacman.collision(inky) && powerUp){
            inky.setDirection(STOP);
            inky.erase(g);
            pacman.draw(g);
            inky.setDirection(RIGHT);
            if(!inky.dead)
            {
                score += 50;
            }
            inky.dead = true;
        }
        else if(pacman.collision(clyde) && powerUp){
            clyde.setDirection(STOP);
            clyde.erase(g);
            pacman.draw(g);
            clyde.setDirection(RIGHT);
            if(!clyde.dead)
            {
                score += 50;
            }
            clyde.dead = true;
        }

        if(score == 2500){
            gameOver = true;
            win = true;
        }

        g.update();
        g.Sleep(5);
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
