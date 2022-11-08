#ifndef     SHRUBBERYCREATIONFORM_HPP
# define    SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
    ShrubberyCreationForm( void );
    ShrubberyCreationForm( const ShrubberyCreationForm& );
    
    const std::string   _target;

public:
    ~ShrubberyCreationForm();
    ShrubberyCreationForm( const std::string& );
    ShrubberyCreationForm& operator=( const ShrubberyCreationForm& );

    void    execute( const Bureaucrat& );
};

#endif