#include "pacman.h"

Pacman::Pacman(){
    radius = 25;
    center = Point(500, 565);
    color = yellow;
    speed = 3;
    dir = STOP;
}
Pacman::Pacman(Circle c){
    radius = c.getRadius();
    center = c.getCenter();
    color = c.getColor();
    speed = 3;
    dir = STOP;
}

void Pacman::setRadius(const double r){
    radius = r;
}
void Pacman::setCenter(const Point p){
    center = p;
}
void Pacman::setColor(const Color c){
    color = c;
}
void Pacman::setSpeed(const int s){
    speed = s;
}
void Pacman::setDirection(DIRECTION d){
    dir = d;
}

double Pacman::getRadius() const{
    return radius;
}
Point Pacman::getCenter() const{
    return center;
}
Color Pacman::getColor() const{
    return color;
}
int Pacman::getSpeed() const{
 return speed;
}
DIRECTION Pacman::getDirection() const{
    return dir;
}

void Pacman::draw(SDL_Plotter& g) const{
    Circle(radius, center, color).draw(g);
}
void Pacman::move(SDL_Plotter& g){
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
void Pacman::erase(SDL_Plotter& g) const{
    Circle(radius, center, color).erase(g);
}

bool Pacman::collision(Circle c) const{
    bool flag = false;

    if (sqrt(pow((c.getCenter().x - center.x), 2) + pow((c.getCenter().y - center.y), 2)) < (radius + (c.getRadius() / 2)))
    {
        flag = true;
    }

    return flag;
}
bool Pacman::collision(Ghost g) const{
    bool flag = false;

    if (sqrt(pow((g.getCenter().x - center.x), 2) + pow((g.getCenter().y - center.y), 2)) < (radius + g.getRadius()))
    {
        flag = true;
    }

    return flag;
}
