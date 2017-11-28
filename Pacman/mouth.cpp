#include "mouth.h"

Mouth::Mouth(){
}
Mouth::Mouth(Point p1, Point p2, Point p3){
    point1 = p1;
    point2 = p2;
    point3 = p3;
}
Mouth::Mouth(Point p1, Point p2, Point p3, Color c){
    point1 = p1;
    point2 = p2;
    point3 = p3;
    color = c;
}

void Mouth::setPoint1(const Point p){
    point1 = p;
}
void Mouth::setPoint2(const Point p){
    point2 = p;
}
void Mouth::setPoint3(const Point p){
    point3 = p;
}
void Mouth::setColor(const Color& c){
    color = c;
}

Point Mouth::getPoint1() const{
    return point1;
}
Point Mouth::getPoint2() const{
    return point2;
}
Point Mouth::getPoint3() const{
    return point3;
}
Color Mouth::getColor() const{
    return color;
}

void Mouth::draw(SDL_Plotter& g) const{
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
void Mouth::follow(Pacman p, SDL_Plotter& g){
    switch (p.getDirection())
    {
    case STOP:  erase(g, p);
    case RIGHT: erase(g, p);
                setPoint1(p.getCenter());
                setPoint2(Point(p.getCenter().x + 25, p.getCenter().y - 15));
                setPoint3(Point(p.getCenter().x + 25, p.getCenter().y + 15));
                draw(g);
                break;
    case LEFT:  erase(g, p);
                setPoint1(p.getCenter());
                setPoint2(Point(p.getCenter().x - 25, p.getCenter().y - 15));
                setPoint3(Point(p.getCenter().x - 25, p.getCenter().y + 15));
                draw(g);
                break;
    case UP:    erase(g, p);
                setPoint1(p.getCenter());
                setPoint2(Point(p.getCenter().x - 15, p.getCenter().y - 25));
                setPoint3(Point(p.getCenter().x + 15, p.getCenter().y - 25));
                draw(g);
                break;
    case DOWN:  erase(g, p);
                setPoint1(p.getCenter());
                setPoint2(Point(p.getCenter().x - 15, p.getCenter().y + 25));
                setPoint3(Point(p.getCenter().x + 15, p.getCenter().y + 25));
                draw(g);
                break;
    }
}
void Mouth::erase(SDL_Plotter& g, Pacman& p) const{
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
    p.draw(g);
}
