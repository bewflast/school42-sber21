#include "Harl.hpp"

int main( void )
{
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    harl.complain("SUCCESS");
    harl.complain("WTF");
    harl.complain("");

    return (0);
}