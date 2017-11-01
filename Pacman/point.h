#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

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
};

#endif // POINT_H_INCLUDED
