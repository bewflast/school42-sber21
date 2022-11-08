#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()    {};
Intern::~Intern()   {};



Form*   Intern::makeForm( const std::string& formName, const std::string& targetName)
{
    size_t  ix = 0;
    const   std::string formsNames[3] = 
    {
        "robotomy request",
        "shrubbery creation",
        "presidential pardon"
    };

    for (ix = 0; (ix < 3) && (formName != formsNames[ix]); ix++);

    if (ix >= 3)
    {
        throw(Intern::WrongFormNameException());
        return (0);
    }
    
    switch (ix)
    {
        case 0:
            return (new RobotomyRequestForm(targetName));
        case 1:
            return (new ShrubberyCreationForm(targetName));
        default:
            return (new PresidentialPardonForm(targetName));
    }

}

const char* Intern::WrongFormNameException::what() const throw()
{
    return ("wrong form\'s name");
}