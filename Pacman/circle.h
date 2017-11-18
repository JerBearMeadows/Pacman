#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"
#include <cmath>

using namespace std;

enum DIRECTION {STOP, RIGHT, LEFT, UP, DOWN};

class Circle
{
    private:
        double radius;
        Point center;
        Color color;
        int speed = 1;
        DIRECTION dir = STOP;

    public:
        Circle();
        Circle(double r, Point cent);
        Circle(double r, Point cent, Color col);

        void setRadius(const double r);
        void setCenter(const Point p);
        void setColor(const Color c);
        void setSpeed(const int s);
        void setDirection(DIRECTION d);

        double getRadius() const;
        Point getCenter() const;
        Color getColor() const;
        int getSpeed() const;
        DIRECTION getDirection() const;

        void draw(SDL_Plotter&) const;
        void move(SDL_Plotter&);
        void erase(SDL_Plotter&) const;

        bool collision(Circle c) const;
};

#endif // CIRCLE_H_INCLUDED
