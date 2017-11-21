#include "font.h"

void plotLetter(char letter[MAX_ROW][MAX_COL],int row,
                int col,Point p,SDL_Plotter& g, int scale)
{
    for(int r = 0; r < row; r ++){
        for(int c = 0; c < col; c++){
            if(letter[r][c] == '1'){

             for(int y = 0; y < scale; y++){
                for(int x = 0; x< scale; x ++){
                        g.plotPixel(p.x +c* scale+x, p.y+r*scale + y,rand(),rand(),rand());
                }
             }
            }
        }
    }
}
