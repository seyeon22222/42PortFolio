#include <iostream>
#include "Point.hpp"

int main( void )
{
  Point a(1, 3), b(5,7), c(4,1), p(2,3), p2(5,7);

  std::cout << "a의 x좌표 :" << a.GetX() << " a의 y좌표 :" << a.GetY() << std::endl;
  std::cout << "b의 x좌표 :" << b.GetX() << " b의 y좌표 :" << b.GetY() << std::endl;
  std::cout << "c의 x좌표 :" << c.GetX() << " c의 y좌표 :" << c.GetY() << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "p의 x좌표 :" << p.GetX() << " p의 y좌표 :" << p.GetY() << std::endl;
  std::cout << "p2의 x좌표 :" << p2.GetX() << " p2의 y좌표 :" << p2.GetY() << std::endl;
  std::cout << "-------------------------------" << std::endl;

  if (bsp(a, b, c, p))
    std::cout << "p는 a,b,c로 이루어진 삼각형 안에 있습니다." << std::endl;
  else
    std::cout << "p는 a,b,c로 이루어진 삼각형 안에 없습니다." << std::endl;
  std::cout << "-------------------------------" << std::endl;
  if (bsp(a, b, c, p2))
    std::cout << "p2는 a,b,c로 이루어진 삼각형 안에 있습니다." << std::endl;
  else
    std::cout << "p2는 a,b,c로 이루어진 삼각형 안에 없습니다." << std::endl;
  return (0);
}