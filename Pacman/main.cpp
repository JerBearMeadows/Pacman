#include <iostream>
#include "line.h"
#include "point.h"
#include "SDL_Plotter.h"

using namespace std;


int main(int argc, char** argv)
{
    SDL_Plotter g(1000, 1000);
    Line lineOne(Point(20, 20), Point(21, 900));

    while(!g.getQuit()){
        if(g.kbhit()){

            switch(g.getKey()){
                case 'P': lineOne.draw(cout);
                          lineOne.draw(g);
                          g.update();
                          break;
                case 'R': lineOne.setColor(Color(200, 15, 15));
                          lineOne.draw(g);
                          g.update();
                          break;

            }
        }
    }


    return 0;
}
