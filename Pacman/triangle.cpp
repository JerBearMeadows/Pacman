#include "triangle.h"

Triangle::Triangle(){
}
Triangle::Triangle(Point p1, Point p2, Point p3){
    point1 = p1;
    point2 = p2;
    point3 = p3;
}
Triangle::Triangle(Point p1, Point p2, Point p3, Color c){
    point1 = p1;
    point2 = p2;
    point3 = p3;
    color = c;
}

void Triangle::setPoint1(const Point p){
    point1 = p;
}
void Triangle::setPoint2(const Point p){
    point2 = p;
}
void Triangle::setPoint3(const Point p){
    point3 = p;
}
void Triangle::setColor(const Color& c){
    color = c;
}

Point Triangle::getPoint1() const{
    return point1;
}
Point Triangle::getPoint2() const{
    return point2;
}
Point Triangle::getPoint3() const{
    return point3;
}
Color Triangle::getColor() const{
    return color;
}

void Triangle::draw(SDL_Plotter& g) const{
    for(int x =  min(min(point1.x, point2.x), point3.x); x <= max(max(point1.x, point2.x), point3.x); x++)
    {
        for(int y = min(min(point1.y, point2.y), point3.y); y <= max(max(point1.y, point2.y), point3.y); y++)
        {
            if((point1.x - point2.x) * (y - point1.y) - (point1.y - point2.y) * (x - point1.x) >= 0 &&
               (point2.x - point3.x) * (y - point2.y) - (point2.y - point3.y) * (x - point2.x) >= 0 &&
               (point3.x - point1.x) * (y - point3.y) - (point3.y - point1.y) * (x - point3.x) >= 0)
            {
                g.plotPixel(x, y, 0, 0, 0);
            }
        }
    }
}
void Triangle::erase(SDL_Plotter& g) const{
    for(int x =  min(min(point1.x, point2.x), point3.x); x <= max(max(point1.x, point2.x), point3.x); x++)
    {
        for(int y = min(min(point1.y, point2.y), point3.y); y <= max(max(point1.y, point2.y), point3.y); y++)
        {
            if((point1.x - point2.x) * (y - point1.y) - (point1.y - point2.y) * (x - point1.x) >= 0 &&
               (point2.x - point3.x) * (y - point2.y) - (point2.y - point3.y) * (x - point2.x) >= 0 &&
               (point3.x - point1.x) * (y - point3.y) - (point3.y - point1.y) * (x - point3.x) >= 0)
            {
                g.plotPixel(x, y, 0, 0, 0);
            }
        }
    }
}
