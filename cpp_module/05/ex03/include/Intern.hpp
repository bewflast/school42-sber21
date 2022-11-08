#ifndef     INTERN_HPP
# define    INTERN_HPP

# include <string>
class Form;

class Intern
{
public:
    Intern();
    ~Intern();
    //Intern( const Intern& )           = delete;
    //Intern& operator=( const Intern& )  = delete;

    Form*   makeForm( const std::string&, const std::string& );

    struct WrongFormNameException     : std::exception { const char* what() const throw(); };
};

#endif
