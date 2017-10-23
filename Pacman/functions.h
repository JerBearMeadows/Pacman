#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

//Stores all function prototypes

#include "headers.h"

const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;

void drawPacman(SDL_Plotter& g, int ul_x, int ul_y);
void clearPacman(SDL_Plotter& g, int ul_x, int ul_y);
void movePacman(int& ul_x, int& ul_y, int dir);

void drawBlinky(SDL_Plotter& g, int ul_x, int ul_y);
void clearBlinky(SDL_Plotter& g, int ul_x, int ul_y);

void drawInky(SDL_Plotter& g, int ul_x, int ul_y);
void clearInky(SDL_Plotter& g, int ul_x, int ul_y);

void drawPinky(SDL_Plotter& g, int ul_x, int ul_y);
void clearPinky(SDL_Plotter& g, int ul_x, int ul_y);

void drawClyde(SDL_Plotter& g, int ul_x, int ul_y);
void clearClyde(SDL_Plotter& g, int ul_x, int ul_y);

#endif // FUNCTIONS_H_INCLUDED
