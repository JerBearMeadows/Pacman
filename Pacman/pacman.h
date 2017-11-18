#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"
#include "circle.h"
#include "ghost.h"

class Pacman
{
    private:
        double radius;
        Point center;
        Color color;
        int speed;
        DIRECTION dir = STOP;

    public:
        Pacman();
        Pacman(Circle);

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
        bool collision(Ghost g) const;
};

#endif // PACMAN_H_INCLUDED
