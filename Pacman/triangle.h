#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"
#include "line.h"
#include "circle.h"
#include "pacman.h"

class Triangle
{
    private:
        Point point1, point2, point3;
        Color color;

    public:
        Triangle();
        Triangle(Point p1, Point p2, Point p3);
        Triangle(Point p1, Point p2, Point p3, Color c);

        void setPoint1(const Point);
        void setPoint2(const Point);
        void setPoint3(const Point);
        void setColor(const Color&);

        Point getPoint1() const;
        Point getPoint2() const;
        Point getPoint3() const;
        Color getColor() const;

        void draw(SDL_Plotter&) const;
        void follow(Pacman, SDL_Plotter&);
        void erase(SDL_Plotter&) const;
};

#endif // TRIANGLE_H_INCLUDED
