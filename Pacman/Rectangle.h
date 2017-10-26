#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "point.h"

//this is accessing the color still in line.h
#include "line.h"
class Rectangle{
    private:
        Point upperLeft, lowerRight;
        Color color;

    public:

        Rectangle();
        Rectangle(Point, Point);

        void setupperLeft(const Point& p);
        void setlowerRight(const Point& p);
        void setColor(const Color& c);

        Point getupperLeft() const;
        Point getlowerRight() const;
        Color getColor() const;

        void draw(ostream&) const;
        void draw(SDL_Plotter&) const;

};

#endif // RECTANGLE_H_INCLUDED
