#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    if (argc != 4)
        return (1);
    if (argv[2][0] == '\0')
        return (1);

    std::size_t     target_len;
    std::size_t     replace_len;

    std::string     buff;
    std::string     find_to;
    std::string     replace_to;

    std::ifstream   read_from(argv[1], std::ifstream::in);
    if (!read_from.is_open())
        return (1);
    std::ofstream   write_to(std::string(argv[1])+".replace", std::ofstream::out);


    find_to     = argv[2];
    replace_to  = argv[3];

    target_len  = find_to.length();
    replace_len = replace_to.length();

    while(std::getline(read_from, buff))
    {
        for (std::size_t f_pos = buff.find(find_to); f_pos != std::string::npos; f_pos = buff.find(find_to, f_pos))
        {
            buff.erase(f_pos, target_len);
            buff.insert(f_pos, replace_to);
            f_pos += replace_len;
        }

        write_to << buff << std::endl;
    }

    read_from.close();
    write_to.close();

    return (0);
}