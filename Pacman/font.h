#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include "SDL_Plotter.h"
#include "point.h"
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_ROW = 12;
const int MAX_COL = 10;

void plotLetter(char letter[MAX_ROW][MAX_COL],int row,int col,Point p,SDL_Plotter& g, int scale);

#endif // FONT_H_INCLUDED
