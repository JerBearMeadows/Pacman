#include <iostream>

#include "SDL_Plotter.h"
#include "functions.h"

using namespace std;

int main(int argc, char ** argv)
{
    SDL_Plotter g(1000,1000);
    int x,y, xd, yd;
    int R, G, B;
    int dir = 0;
    char key;
    x = y = 500;

    while (!g.getQuit())
    {
        drawBlinky(g, 250, 250);
        drawInky(g, 250, 750);
        drawPinky(g, 750, 250);
        drawClyde(g, 750, 750);
    	drawPacman(g, x, y);
    	g.update();
    	g.Sleep(10);
    	clearPacman(g, x, y);
    	movePacman(x, y, dir);

    	if(g.kbhit())
        {
    	    key = g.getKey();
    	    switch(key)
    	    {
    	        case RIGHT_ARROW: dir = RIGHT; break;
    	        case LEFT_ARROW: dir = LEFT; break;
    	        case UP_ARROW: dir = UP; break;
    	        case DOWN_ARROW: dir = DOWN; break;
    	    }
    	}
    }
}
