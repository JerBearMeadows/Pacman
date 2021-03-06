#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <cmath>

using namespace std;

struct Point
{
    double x, y;

    Point(){
        x = y = 0;
    }
    Point(double a, double b){
        x = a;
        y = b;
    }
    double distance(Point p){
        return sqrt(pow(x - p.x, 2.0) + pow(y - p.y, 2.0));
    }
};

#endif // POINT_H_INCLUDED
