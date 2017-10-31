#include "circle.h"

void Circle::setRadius(const double r)
{
    radius = r;
}
void Circle::setCenter(const Point p)
{
    center = p;
}
void Circle::setColor(const Color c)
{
    color = c;
}

double Circle::getRadius() const
{
    return radius;
}
Point Circle::getCenter() const
{
    return center;
}
Color Circle::getColor() const
{
    return color;
}

void Circle::draw(SDL_Plotter& g) const
{
    int y;
    for (int x = -radius; x <= radius; x++)
    {
        for (int y = -radius; y <= radius; y++)
        {
            if (sqrt((x * x) + (y * y)) <= radius)
            {
            g.plotPixel(x + center.x, y + center.y, color.R, color.G, color.B);
            g.plotPixel(x + center.x, -y + center.y, color.R, color.G, color.B);
            }
        }
    }
}
void Circle::erase(SDL_Plotter& g) const
{
    int y;
    for (int x = -radius; x <= radius; x++)
    {
        for (int y = -radius; y <= radius; y++)
        {
            if (sqrt((x * x) + (y * y)) <= radius)
            {
            g.plotPixel(x + center.x, y + center.y, 255, 255, 255);
            g.plotPixel(x + center.x, -y + center.y, 255, 255, 255);
            }
        }
    }
}
