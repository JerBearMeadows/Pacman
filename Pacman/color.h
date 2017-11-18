#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct Color
{

    int R, G, B;

    Color()
    {
        R = G = B = 0;
    }
    Color(int r, int g, int b)
    {
        R = r;
        B = b;
        G = g;
    }
};

const Color black =     Color();
const Color white =     Color(255, 255, 255);
const Color red =       Color(255, 0, 0);
const Color green =     Color(0, 255, 0);
const Color blue =      Color(0, 0, 255);
const Color cyan =      Color(0, 255, 255);
const Color magenta =   Color(255, 0, 255);
const Color yellow =    Color(255, 255, 0);
const Color orange =    Color(255, 150, 0);

#endif // COLOR_H_INCLUDED
