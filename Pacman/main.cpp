#include "SDL_Plotter.h"
#include "point.h"
#include "color.h"
#include "line.h"
#include "circle.h"
#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
    SDL_Plotter g(1000,1000);
    int x,y, xd, yd;
    int R, G, B;
    int dir = 0;
    char key;
    Point p;
    x = y = 500;

    Circle pacman;


    pacman.setCenter(Point(200, 200));
    pacman.setRadius(75);
    pacman.setColor(Color(200, 200, 20));
    pacman.draw(g);
    g.update();

    while (!g.getQuit())
    {
    	if(g.kbhit())
        {
    	    switch(g.getKey())
    	    {
    	        case RIGHT_ARROW: pacman.erase(g);
                                  p = pacman.getCenter();
                                  p.x += 10;
                                  pacman.setCenter(p);
                                  pacman.draw(g);
                                  g.update();
                                  break;
    	        case LEFT_ARROW: pacman.erase(g);
                                 p = pacman.getCenter();
                                 p.x -= 10;
                                 pacman.setCenter(p);
                                 pacman.draw(g);
                                 g.update();
                                 break;
    	        case UP_ARROW: pacman.erase(g);
                               p = pacman.getCenter();
                               p.y -= 10;
                               pacman.setCenter(p);
                               pacman.draw(g);
                               g.update();
                               break;
    	        case DOWN_ARROW: pacman.erase(g);
                                 p = pacman.getCenter();
                                 p.y += 10;
                                 pacman.setCenter(p);
                                 pacman.draw(g);
                                 g.update();
                                 break;
    	    }

    	}
    }
}
