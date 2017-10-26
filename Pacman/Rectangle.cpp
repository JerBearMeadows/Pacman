#include "Rectangle.h"
#include "point.h"

    Rectangle::Rectangle(){
        upperLeft.x = 0;
        upperLeft.y = 0;
        lowerRight.x = 1;
        lowerRight.y = 1;
    }
    Rectangle::Rectangle(Point point1, Point point2){
        upperLeft = point1;
        lowerRight = point2;
    }

    void Rectangle::setupperLeft(const Point& p){
        upperLeft = p;
    }
    void Rectangle::setlowerRight(const Point& p){
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

    void Rectangle::draw(ostream&) const{

    }
    void Rectangle::draw(SDL_Plotter&) const{

    }
