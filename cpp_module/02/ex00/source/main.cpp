#include "Fixed.hpp"

int main ( void )
{
    Fixed a;
   // a.setRawBits(100);
    Fixed b( a );
    //b.setRawBits(30);
    Fixed c;
    c = b;
   // c.setRawBits(10);
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}