//Stores all code to create functions

#include "functions.h"

/*
Description: Drawing Pacman
Return: A Pacman to the screen
Precondition: No Pacman
Postcondition: Pacman drawn
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
/*
Description: Erasing Pacman from screen
Return: A clear pacman
Precondition: A Pacman on the screen
Postcondition: Pacman not on the screen
*/
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
/*
Description: Moving Pacman
Return: Directional movement
Precondition: Pac man standing still
Postcondition: Pac man moving according to arrows
*/
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
/*
Description: Ghost being drawn
Return: A ghost
Precondition: Whitespace
Postcondition: A Ghost with a color
*/
void drawGhost(SDL_Plotter& g, int ul_x, int ul_y, int R, int G, int B)
{
    for (int x = 1; x <= 25; x++)
    {
        for (int y = 1; y <= 25; y++)
        {
            g.plotPixel(ul_x + x, ul_y + y, R, G, B);
        }
    }
    return;
}
/*
Description: Erasing ghost
Return: Whitespace
Precondition: A drawn ghost
Postcondition: Whitespace
*/
void clearGhost(SDL_Plotter& g, int ul_x, int ul_y)
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
