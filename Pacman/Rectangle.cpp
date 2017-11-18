#include "rectangle.h"

Rectangle::Rectangle(){
    color = blue;
}
Rectangle::Rectangle(Point uL, Point lR){
    upperLeft = uL;
    lowerRight = lR;
}
Rectangle::Rectangle(Point uL, Point lR, Color c){
    upperLeft = uL;
    lowerRight = lR;
    color = c;
}

void Rectangle::setUpperLeft(const Point p){
    upperLeft = p;
}
void Rectangle::setLowerRight(const Point p){
    lowerRight = p;
}
void Rectangle::setColor(const Color& c){
    color = c;
}

Point Rectangle::getUpperLeft() const{
    return upperLeft;
}
Point Rectangle::getLowerRight() const{
    return lowerRight;
}
Color Rectangle::getColor() const{
    return color;
}

void Rectangle::draw(SDL_Plotter& g) const{
    for(int x = upperLeft.x; x <= lowerRight.x; x++){
        for(int y = upperLeft.y; y <= lowerRight.y; y++){
            g.plotPixel(x, y, color.R, color.G, color.B);
        }
    }
}
void Rectangle::erase(SDL_Plotter& g){
    Color tmp = getColor();
    setColor(black);
    draw(g);
    setColor(tmp);
}

bool Rectangle::collision(Pacman p) const{
    bool flag = false;

    for(int x = upperLeft.x; x <= lowerRight.x && !flag; x++){
        if(Point(x, upperLeft.y).distance(p.getCenter()) <= p.getRadius() ||
           Point(x, lowerRight.y).distance(p.getCenter()) <= p.getRadius()){
           flag = true;
        }
    }
    for(int y = upperLeft.y; y <= lowerRight.y && !flag; y++){
        if(Point(upperLeft.x, y).distance(p.getCenter()) <= p.getRadius() ||
           Point(lowerRight.x, y).distance(p.getCenter()) <= p.getRadius()){
           flag = true;
        }
    }

    return flag;
}
bool Rectangle::collision(Ghost g) const{
    bool flag = false;

    for(int x = upperLeft.x; x <= lowerRight.x && !flag; x++){
        if(Point(x, upperLeft.y).distance(g.getCenter()) <= g.getRadius() ||
           Point(x, lowerRight.y).distance(g.getCenter()) <= g.getRadius()){
           flag = true;
        }
    }
    for(int y = upperLeft.y; y <= lowerRight.y && !flag; y++){
        if(Point(upperLeft.x, y).distance(g.getCenter()) <= g.getRadius() ||
           Point(lowerRight.x, y).distance(g.getCenter()) <= g.getRadius()){
           flag = true;
        }
    }

    return flag;
}
