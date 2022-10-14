#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main ( void )
{
    Point   a(1, 1);
    Point   b(2, 5);
    Point   c(3, 2);

    Point   t(2.6, 1);

    std::cout << bsp(a, b, c, t) << std::endl;

    return (0);
}