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

#endif // COLOR_H_INCLUDED
