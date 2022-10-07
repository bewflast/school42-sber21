#include <iostream>
#include <sstream>

std::string upper_string(char* src)
{
    std::string uppered("");

    for ( int i = 0; src[i]; uppered += std::toupper(src[i++]) );

    return (uppered);
}

int main(int argc, char *argv[])
{
    std::string result("* LOUD AND UNBEARABLE FEEDBACK NOISE *");

    if (argc != 1)
    {
        result = "";
        for ( int i = 1; i < argc - 1; result += (upper_string(argv[i++]) + ' ') );
        result += upper_string(argv[argc - 1]);
    }

    std::cout << result << std::endl;
    return (0);
}