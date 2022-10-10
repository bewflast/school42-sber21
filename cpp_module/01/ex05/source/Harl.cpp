#include "Harl.hpp"

void    Harl::debug()
{
    std::cout   <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"  <<  std::endl;
}

void    Harl::info()
{
    std::cout   <<  "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" <<  std::endl;
}

void    Harl::warning()
{
    std::cout   <<  "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."    <<  std::endl;
}

void    Harl::error()
{
    std::cout   <<   "This is unacceptable! I want to speak to the manager now."    <<  std::endl;
}


void    Harl::complain(std::string lvl)
{
    std::size_t func_index;

    std::string levels[4] = 
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    void    (Harl::*member_funcs[4])( void ) =
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (func_index = 0; 
        (lvl.compare(levels[func_index])) && (func_index < 4); 
        func_index++);
    
    switch (func_index)
    {
        case (0):
        case (1):
        case (2):
        case (3):
            (this->*member_funcs[func_index])();
            break;
        
        default:
            std::cout << "Wrong level passed" << std::endl;
            break;
    }
}