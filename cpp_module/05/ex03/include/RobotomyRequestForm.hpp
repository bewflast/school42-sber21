#ifndef     ROBOTOMYREQUESTFORM_HPP
# define    ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
    RobotomyRequestForm( void );
    RobotomyRequestForm( const RobotomyRequestForm& );
    
    const std::string   _target;

public:
    ~RobotomyRequestForm();
    RobotomyRequestForm( const std::string& );
    RobotomyRequestForm& operator=( const RobotomyRequestForm& );

    void    execute( const Bureaucrat& );
};

#endif