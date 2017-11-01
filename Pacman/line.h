#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"

class Line
{
    private:
        Point point1, point2;
        Color color;

        bool slope(double& m) const;
        bool intercept(double& b) const;

    public:
        Line(Point, Point);
        Line(Point, Point, Color);

        void setP1(const Point& p);
        void setP2(const Point& p);
        void setColor(const Color& c);

        Point getP1() const;
        Point getP2() const;
        Color getColor() const;

        void draw(SDL_Plotter&) const;
};

#endif // LINE_H_INCLUDED
