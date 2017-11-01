#include "Rectangle.h"
#include "point.h"


    void Rectangle::setupperLeft(const Point p1){
        upperLeft = p1;
    }
    void Rectangle::setlowerRight(const Point p2){
        lowerRight = p2;
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
            g.update();
        }

    }

