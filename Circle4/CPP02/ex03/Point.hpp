#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point(void);
        ~Point(void);
        Point(float const x, float const y);
        Point(const Point &Point);
        Point   operator=(const Point &Point);
        Fixed GetX(void) const;
        Fixed GetY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif