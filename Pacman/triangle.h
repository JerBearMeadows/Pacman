#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"
#include "line.h"
#include "circle.h"

class Triangle
{
    private:
        Point vertex, point1, point2;
        Color color;

    public:
        Triangle();
        Triangle(Point v, Point p1, Point p2);
        Triangle(Point v, Point p1, Point p2, Color c);

        void setVertex(const Point v);
        void setPoint1(const Point p);
        void setPoint2(const Point p);
        void setColor(const Color& c);

        Point getVertex() const;
        Point getPoint1() const;
        Point getPoint2() const;
        Color getColor() const;

        void draw(SDL_Plotter&) const;
        void follow(Circle c, SDL_Plotter&);
        void erase(SDL_Plotter&) const;
};

#endif // TRIANGLE_H_INCLUDED
