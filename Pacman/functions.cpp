//Stores all code to create functions

#include "functions.h"

/*
Description:
Return:
Precondition:
Postcondition:
*/
void drawPacman(SDL_Plotter& g, int ul_x, int ul_y)
{
    for (int x = 1; x <= 25; x++)
    {
        for (int y = 1; y <= 25; y++)
        {
            g.plotPixel(ul_x + x, ul_y + y, 230, 250, 10);
        }
    }
    return;
}
void clearPacman(SDL_Plotter& g, int ul_x, int ul_y)
{
    for (int x = 1; x <= 25; x++)
    {
        for (int y = 1; y <= 25; y++)
        {
            g.plotPixel(ul_x + x, ul_y + y, 255, 255, 255);
        }
    }
    return;
}
void movePacman(int& ul_x, int& ul_y, int dir)
{
    switch (dir)
    {
        case RIGHT: ul_x++; break;
        case LEFT: ul_x--; break;
        case UP: ul_y--; break;
        case DOWN: ul_y++; break;
    }
    return;
}


void drawBlinky(SDL_Plotter& g, int ul_x, int ul_y)
{
    for (int x = 1; x <= 25; x++)
    {
        for (int y = 1; y <= 25; y++)
        {
            g.plotPixel(ul_x + x, ul_y + y, 230, 10, 10);
        }
    }
    return;
}
void clearBlinky(SDL_Plotter& g, int ul_x, int ul_y)
{
    for (int x = 1; x <= 25; x++)
    {
        for (int y = 1; y <= 25; y++)
        {
            g.plotPixel(ul_x + x, ul_y + y, 255, 255, 255);
        }
    }
    return;
}

void drawInky(SDL_Plotter& g, int ul_x, int ul_y)
{
    for (int x = 1; x <= 25; x++)
    {
        for (int y = 1; y <= 25; y++)
        {
            g.plotPixel(ul_x + x, ul_y + y, 10, 100, 230);
        }
    }
    return;
}
void clearInky(SDL_Plotter& g, int ul_x, int ul_y)
{
    for (int x = 1; x <= 25; x++)
    {
        for (int y = 1; y <= 25; y++)
        {
            g.plotPixel(ul_x + x, ul_y + y, 255, 255, 255);
        }
    }
    return;
}

void drawPinky(SDL_Plotter& g, int ul_x, int ul_y)
{
    for (int x = 1; x <= 25; x++)
    {
        for (int y = 1; y <= 25; y++)
        {
            g.plotPixel(ul_x + x, ul_y + y, 240, 50, 180);
        }
    }
    return;
}
void clearPinky(SDL_Plotter& g, int ul_x, int ul_y)
{
    for (int x = 1; x <= 25; x++)
    {
        for (int y = 1; y <= 25; y++)
        {
            g.plotPixel(ul_x + x, ul_y + y, 255, 255, 255);
        }
    }
    return;
}

void drawClyde(SDL_Plotter& g, int ul_x, int ul_y)
{
    for (int x = 1; x <= 25; x++)
    {
        for (int y = 1; y <= 25; y++)
        {
            g.plotPixel(ul_x + x, ul_y + y, 250, 100, 10);
        }
    }
    return;
}
void clearClyde(SDL_Plotter& g, int ul_x, int ul_y)
{
    for (int x = 1; x <= 25; x++)
    {
        for (int y = 1; y <= 25; y++)
        {
            g.plotPixel(ul_x + x, ul_y + y, 255, 255, 255);
        }
    }
    return;
}

