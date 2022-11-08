#ifndef     BUREAUCRAT_HPP
# define    BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{

    Bureaucrat( void );
    Bureaucrat( const std::string& );

    short               _grade;
    const std::string   _name;

public:

    ~Bureaucrat();
    Bureaucrat( const Bureaucrat& );
    Bureaucrat( short, const std::string& );
    Bureaucrat& operator=( const Bureaucrat& );

    short               getGrade()  const;
    const std::string&  getName()   const;

    void                upGrade();
    void                downGrade();

    struct GradeTooLowException     : std::exception { const char* what() const throw(); };
    struct GradeTooHighException    : std::exception { const char* what() const throw(); };
    
};

std::ostream&   operator<<( std::ostream&, const Bureaucrat& );

#endif