#include "Harl.hpp"

int main( int argc, char* argv[] )
{
    switch(argc)
    {
        case (2):
            Harl    harl;
            harl.complain(argv[1]);
            break;
        default:
            return (1);
    }

    return (0);
}