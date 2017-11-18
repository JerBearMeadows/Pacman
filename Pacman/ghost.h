#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED

#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"
#include "circle.h"
#include "cstdlib"

using namespace std;

class Ghost
{
    private:
        double radius;
        Point center;
        Color color;
        int speed;
        DIRECTION dir = STOP;

    public:
        Ghost();
        Ghost(Circle);

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
        bool collision(Circle c) const;
        void collide(SDL_Plotter&);
        void erase(SDL_Plotter&) const;
};

#endif // GHOST_H_INCLUDED
