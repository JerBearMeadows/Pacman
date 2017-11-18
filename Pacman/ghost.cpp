#include "ghost.h"


Ghost::Ghost(){
    radius = 10;
    center = Point(500, 465);
    color = red;
    speed = 2;
    dir = STOP;
}
Ghost::Ghost(Circle c){
    radius = c.getRadius();
    center = c.getCenter();
    color = c.getColor();
    speed = 2;
    dir = STOP;
}

void Ghost::setRadius(const double r){
    radius = r;
}
void Ghost::setCenter(const Point p){
    center = p;
}
void Ghost::setColor(const Color c){
    color = c;
}
void Ghost::setSpeed(const int s){
    speed = s;
}
void Ghost::setDirection(DIRECTION d){
    dir = d;
}

double Ghost::getRadius() const{
    return radius;
}
Point Ghost::getCenter() const{
    return center;
}
Color Ghost::getColor() const{
    return color;
}
int Ghost::getSpeed() const{
 return speed;
}
DIRECTION Ghost::getDirection() const{
    return dir;
}

void Ghost::draw(SDL_Plotter& g) const{
    Circle(radius, center, color).draw(g);
}
void Ghost::move(SDL_Plotter& g){
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
void Ghost::erase(SDL_Plotter& g) const{
    Circle(radius, center, color).erase(g);
}
