#include "pacman.h"

void Pacman::setRadius(const double r)
{
    radius = r;
}
void Pacman::setCenter(const Point p)
{
    center = p;
}
void Pacman::setColor(const Color c)
{
    color = c;
}

double Pacman::getRadius() const
{
    return radius;
}
Point Pacman::getCenter() const
{
    return center;
}
Color Pacman::getColor() const
{
    return color;
}

void Pacman::draw(SDL_Plotter& g) const
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
void Pacman::erase(SDL_Plotter& g) const
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
