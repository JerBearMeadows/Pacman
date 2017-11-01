#include "triangle.h"

void Triangle::setVertex(const Point v){
    vertex = v;
}
void Triangle::setPoint1(const Point p){
    point1 = p;
}
void Triangle::setPoint2(const Point p){
    point2 = p;
}
void Triangle::setColor(const Color& c){
    color = c;
}

Point Triangle::getVertex() const{
    return vertex;
}
Point Triangle::getPoint1() const{
    return point1;
}
Point Triangle::getPoint2() const{
    return point2;
}
Color Triangle::getColor() const{
    return color;
}

void Triangle::draw(SDL_Plotter& g) const{
    g.plotPixel(vertex.x, vertex.y, color.R, color.G, color.B);
    g.plotPixel(point1.x, point1.y, color.R, color.G, color.B);
    g.plotPixel(point2.x, point2.y, color.R, color.G, color.B);
}
void Triangle::erase(SDL_Plotter& g) const{
    g.plotPixel(vertex.x, vertex.y, 0, 0, 0);
    g.plotPixel(point1.x, point1.y, 0, 0, 0);
    g.plotPixel(point2.x, point2.y, 0, 0, 0);
}
