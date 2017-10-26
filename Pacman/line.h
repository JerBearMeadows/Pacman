#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include <ostream>
#include "SDL_Plotter.h"
#include "point.h"
using namespace std;

struct Color{
    int R, G, B;

    Color(){
        R = G = B = 0;
    }

    Color(int r, int g, int b){
        R = r;
        G = g;
        B = b;
    }
};


class Line{
    private:
        Point p1, p2;
        Color color;

        bool slope(double& m) const;
        bool intercept(double& b) const;

    public:

        Line();
        Line(Point, Point);

        void setP1(const Point& p);
        void setP2(const Point& p);
        void setColor(const Color& c);

        Point getP1() const;
        Point getP2() const;
        Color getColor() const;

        void draw(ostream&) const;
        void draw(SDL_Plotter&) const;
};

#endif // LINE_H_INCLUDED
