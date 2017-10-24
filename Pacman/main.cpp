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
        drawGhost(g, 250, 250, 210, 30, 10);
        drawGhost(g, 250, 750, 0, 0, 220);
        drawGhost(g, 750, 250, 180, 60, 100);
        drawGhost(g, 750, 750, 140, 100, 0);
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
