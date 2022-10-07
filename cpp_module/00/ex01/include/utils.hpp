#ifndef UTILS_HPP
# define UTILS_HPP


# include "PhoneBook.hpp"

# include <iostream>
# include <iomanip>
# include <string>

namespace utils
{
    
    namespace contact_fields_ixs
    {
        const int secret        = 0;
        const int nickname      = 1;
        const int lastname      = 2;
        const int firstname     = 3;
        const int phonenumber   = 4;
    } 
    
    namespace cmd
    {
        void    add(PhoneBook& phone_book);
        void    search(PhoneBook& phone_book);
        void    exit();
    }
    bool    parse_cmd(std::string& cmd, PhoneBook& phone_book);

    namespace io
    {
        void        show_field(std::string field);
        std::string get_field(std::string field_name);
    }

    void surf_phonebook(PhoneBook& phone_book);
}

#endif