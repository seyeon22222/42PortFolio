#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(float const x, float const y) : x(x), y (y)
{
}

Point::~Point(void)
{
}

Point::Point(const Point &Point) : x(Point.GetX()), y(Point.GetY())
{
}

Point Point::operator=(const Point &Point)
{
    if (this != &Point)
    {
        const_cast<Fixed&>(this->x) = Point.GetX();
        const_cast<Fixed&>(this->y) = Point.GetY();
    }
    return (*this);
}

Fixed Point::GetX(void) const
{
    return (x);
}

Fixed Point::GetY(void) const
{
    return (y);
}