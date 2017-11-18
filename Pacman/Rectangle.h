#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"
#include "circle.h"
#include "pacman.h"

class Rectangle
{
    private:
        Point upperLeft, lowerRight;
        Color color;

    public:
        Rectangle();
        Rectangle(Point uL, Point lR);
        Rectangle(Point uL, Point lR, Color c);

        void setUpperLeft(const Point p);
        void setLowerRight(const Point p);
        void setColor(const Color& c);

        Point getUpperLeft() const;
        Point getLowerRight() const;
        Color getColor() const;

        void draw(SDL_Plotter&) const;
        void erase(SDL_Plotter& g);

        bool collision(Pacman) const;
        bool collision(Ghost) const;
};

#endif // RECTANGLE_H_INCLUDED
