#ifndef     FORM_HPP
# define    FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{

    Form( void );
    Form( const std::string& );

protected:
    bool                _isSigned;
    const short         _gToExec;
    const short         _gToSign;
    const std::string   _name;

public:

    ~Form();
    Form( const Form& );
    Form( const short, const short, const std::string& );
    Form& operator=( const Form& );

    const std::string&  getName()           const;
    bool                isSigned()          const;
    short               getGradeToSign()    const;
    short               getGradeToExecute() const;

    void    beSigned( const Bureaucrat& );

    virtual void    execute( const Bureaucrat&  )   =   0;
    int             canExecute( const Bureaucrat& );


    struct GradeTooLowException     : std::exception { const char* what() const throw(); };
    struct GradeTooHighException    : std::exception { const char* what() const throw(); };
    struct FormNotSignedException   : std::exception { const char* what() const throw(); };

};

std::ostream& operator<<(std::ostream&, const Form& );

#endif