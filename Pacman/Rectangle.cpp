#include "rectangle.h"

Rectangle::Rectangle(Point uL, Point lR){
    upperLeft = uL;
    lowerRight = lR;
}
Rectangle::Rectangle(Point uL, Point lR, Color c){
    upperLeft = uL;
    lowerRight = lR;
    color = c;
}

void Rectangle::setupperLeft(const Point p){
    upperLeft = p;
}
void Rectangle::setlowerRight(const Point p){
    lowerRight = p;
}
void Rectangle::setColor(const Color& c){
    color = c;
}

Point Rectangle::getupperLeft() const{
    return upperLeft;
}
Point Rectangle::getlowerRight() const{
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
