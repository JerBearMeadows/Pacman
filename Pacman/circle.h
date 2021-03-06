#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"
#include <cmath>

enum DIRECTION {STOP, RIGHT, LEFT, UP, DOWN};

using namespace std;

class Circle
{
    private:
        double radius;
        Point center;
        Color color;

    public:
        Circle();
        Circle(double r, Point cent);
        Circle(double r, Point cent, Color col);
        bool eaten;

        void setRadius(const double r);
        void setCenter(const Point p);
        void setColor(const Color c);

        double getRadius() const;
        Point getCenter() const;
        Color getColor() const;

        void draw(SDL_Plotter&) const;
        void erase(SDL_Plotter&) const;
};

#endif // CIRCLE_H_INCLUDED
