#include "Point.hpp"

static Fixed Abs(Fixed value)
{
    if (value < 0)
        value = value * -1;
    return (value);
}

static Fixed check(Point const a, Point const b, Point const c)
{
    Fixed area = 0;

    area = ((a.GetX() * b.GetY()) + (b.GetX() * c.GetY()) + (c.GetX() * a.GetY())
    - (b.GetX() * a.GetY()) - (c.GetX() * b.GetY()) - (a.GetX() * c.GetY())) / 2;
    return (Abs(area));
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed   check_a, check_b, check_c, area, sum;

    check_a = check(point, a, b);
    check_b = check(point, b, c);
    check_c = check(point, c, a);
    sum = check_a + check_b + check_c;
    area = check(a,b,c);

    std::cout << "A :" << check_a << " B : " << check_b << " C : " << check_c << " sum : " << sum << " area : " << area << std::endl;

    if (sum == area)
    {
        if (check_a == 0 || check_b == 0 || check_c == 0 )
            return (false);
        else
            return (true);
    }
    return (false);
}
