#include "circle.h"

Circle::Circle(){
    speed = 5;
}
Circle::Circle(double r, Point cent){
    radius = r;
    center = cent;
}
Circle::Circle(double r, Point cent, Color col){
    radius = r;
    center = cent;
    color = col;
}

void Circle::setRadius(const double r){
    radius = r;
}
void Circle::setCenter(const Point p){
    center = p;
}
void Circle::setColor(const Color c){
    color = c;
}
void Circle::setSpeed(const int s){
    speed = s;
}
void Circle::setDirection(DIRECTION d){
    dir = d;
}

double Circle::getRadius() const{
    return radius;
}
Point Circle::getCenter() const{
    return center;
}
Color Circle::getColor() const{
    return color;
}

int Circle::getSpeed() const{
 return speed;
}
DIRECTION Circle::getDirection() const{
    return dir;
}

void Circle::draw(SDL_Plotter& g) const{
    int y;
    for (int x = -radius; x <= radius; x++){
        for (int y = -radius; y <= radius; y++){
            if (sqrt((x * x) + (y * y)) <= radius){
            g.plotPixel(x + center.x, y + center.y, color.R, color.G, color.B);
            g.plotPixel(x + center.x, -y + center.y, color.R, color.G, color.B);
            }
        }
    }
}
void Circle::move(SDL_Plotter& g){
    erase(g);

    switch(dir)
    {
        case RIGHT: center.x+=speed;
                    break;
        case LEFT:  center.x-=speed;
                    break;
        case UP:    center.y-=speed;
                    break;
        case DOWN:  center.y+=speed;
                    break;
    }
    draw(g);
}
void Circle::erase(SDL_Plotter& g) const{
    int y;
    for (int x = -radius; x <= radius; x++){
        for (int y = -radius; y <= radius; y++){
            if (sqrt((x * x) + (y * y)) <= radius){
            g.plotPixel(x + center.x, y + center.y, 0, 0, 0);
            g.plotPixel(x + center.x, -y + center.y, 0, 0, 0);
            }
        }
    }
}
/*
bool Circle::collision(Circle c) const{
    bool flag = false;

    for (int x = -radius; x <= radius && !flag; x++){
        if(Point(x, upperLeft.y).distance(c.getCenter()) <= c.getRadius() ||
           Point(x, lowerRight.y).distance(c.getCenter()) <= c.getRadius()){
            flag = true;
        }
    }
    for (int y = -radius; y <= radius && !flag; y++){
        if(Point(upperLeft.x, y).distance(c.getCenter()) <= c.getRadius() ||
           Point(lowerRight.x, y).distance(c.getCenter()) <= c.getRadius()){
            flag = true;
        }
    }

    return flag;
}*/
