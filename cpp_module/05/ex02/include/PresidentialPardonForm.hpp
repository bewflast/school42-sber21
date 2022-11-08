#ifndef     PRESIDENTIALPARDONFORM_HPP
# define    PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
    PresidentialPardonForm( void );
    PresidentialPardonForm( const PresidentialPardonForm& );
    
    const std::string   _target;

public:
    ~PresidentialPardonForm();
    PresidentialPardonForm( const std::string& );
    PresidentialPardonForm& operator=( const PresidentialPardonForm& );

    void    execute( const Bureaucrat& );
};

#endif