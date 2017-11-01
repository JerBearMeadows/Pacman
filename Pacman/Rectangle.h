#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"

class Rectangle
{
    private:
        Point upperLeft, lowerRight;
        Color color;

    public:
        Rectangle(Point uL, Point lR);
        Rectangle(Point uL, Point lR, Color c);

        void setupperLeft(const Point p);
        void setlowerRight(const Point p);
        void setColor(const Color& c);

        Point getupperLeft() const;
        Point getlowerRight() const;
        Color getColor() const;

        void draw(SDL_Plotter&) const;
};

#endif // RECTANGLE_H_INCLUDED
