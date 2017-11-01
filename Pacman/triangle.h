#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"

class Triangle
{
    private:
        Point vertex, point1, point2;
        Color color;

    public:
        void setVertex(const Point v);
        void setPoint1(const Point p);
        void setPoint2(const Point p);
        void setColor(const Color& c);

        Point getVertex() const;
        Point getPoint1() const;
        Point getPoint2() const;
        Color getColor() const;

        void draw(SDL_Plotter&) const;
        void erase(SDL_Plotter&) const;
};

#endif // TRIANGLE_H_INCLUDED
