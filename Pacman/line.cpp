#include "line.h"

Line::Line(Point p1, Point p2){
    point1 = p1;
    point2 = p2;
}
Line::Line(Point p1, Point p2, Color c){
    point1 = p1;
    point2 = p2;
    color = c;
}
void Line::setP1(const Point& p){
    point1 = p;
}

void Line::setP2(const Point& p){
    point2 = p;
}

void Line::setColor(const Color& c){
    color = c;
}

Color Line::getColor() const{
    return color;
}


bool Line::slope(double& m) const{
    bool hasSlope;

    hasSlope = (point1.x != point2.x);

    if(hasSlope){
        m = (point1.y - point2.y) / (point1.x - point2.x);
    }
    return hasSlope;
}
bool Line::intercept(double& b) const{
    bool hasIntercept;
    double m;

    hasIntercept = slope(m);

    if(hasIntercept){
        b = point1.y - (m * point1.x);
    }

    return hasIntercept;
}


void Line::draw(SDL_Plotter& g) const{
    double m, b;
    double delta = 0.001;
    int y;

    if(slope(m)){
        intercept(b);
        if(point1.x < point2.x){

            for(double x = point1.x; x <= point2.x; x += delta){
                y = m * x + b + 0.5;
                g.plotPixel(x, y, color.R, color.G, color.B);
            }
        }
        else{

            for(double x = point1.x; x >= point2.x; x -= delta){
                y = m * x + b + 0.5;
                g.plotPixel(x, y, color.R, color.G, color.B);
            }
        }
    }
}
