#include "line.h"

    Line::Line(){
        p1.x = 0;
        p1.y = 0;
        p2.x = 1;
        p2.y = 1;
    }
    Line::Line(Point point1, Point point2){
        p1 = point1;
        p2 = point2;
    }
    void Line::setP1(const Point& p){
        p1 = p;
    }

    void Line::setP2(const Point& p){
        p2 = p;
    }

    void Line::setColor(const Color& c){
        color = c;
    }

    Color Line::getColor() const{
        return color;
    }


    bool Line::slope(double& m) const{
        bool hasSlope;

        hasSlope = (p1.x != p2.x);

        if(hasSlope){
            m = (p1.y - p2.y) / (p1.x - p2.x);
        }
        return hasSlope;
    }
    bool Line::intercept(double& b) const{
        bool hasIntercept;
        double m;

        hasIntercept = slope(m);

        if(hasIntercept){
            b = p1.y - (m * p1.x);
        }

        return hasIntercept;
    }

    void Line::draw(ostream& output) const{
        double m, b;

        if(slope(m)){
            intercept(b);
            output << " y = " << m << "x + " << b;
        }
        else{
            output << "x = " << p1.x;
        }
    }
    void Line::draw(SDL_Plotter& g) const{
        double m, b;
        double delta = 0.001;
        int y;

        if(slope(m)){
            intercept(b);
            if(p1.x < p2.x){

                for(double x = p1.x; x <= p2.x; x += delta){
                    y = m * x + b + 0.5;
                    g.plotPixel(x,y, color.R, color.G, color.B);
                }
            }
            else{

                for(double x = p1.x; x >= p2.x; x -= delta){
                    y = m * x + b + 0.5;
                    g.plotPixel(x,y, color.R, color.G, color.B);
                }
            }
        }
    }
