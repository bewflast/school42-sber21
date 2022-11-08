#include "Bureaucrat.hpp"
#include "Form.hpp"
Bureaucrat::~Bureaucrat()                                                                                           {};
Bureaucrat::Bureaucrat( void )                                  : _grade(150),              _name("undef")          {};
Bureaucrat::Bureaucrat( const Bureaucrat& other )               : _grade(other.getGrade()), _name(other.getName())  {};
Bureaucrat::Bureaucrat( const std::string& name )               : _grade(150),              _name(name)             {};

Bureaucrat::Bureaucrat( short grade, const std::string& name)   
: 
    _grade(50), 
    _name(name)             
{
    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    
    this->_grade = grade;
};

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
    this->_grade                                = other.getGrade();
    const_cast<std::string&>(this->_name)       = static_cast<const std::string>(other.getName());

    return (*this);
}

short                Bureaucrat::getGrade() const
{
    return (this->_grade);
}

const std::string&   Bureaucrat::getName()  const
{
    return (this->_name);
}

const char* Bureaucrat::GradeTooLowException::what()    const throw()
{
    return ("Grade is too low");
}

const char* Bureaucrat::GradeTooHighException::what()   const throw()
{
    return ("Grade is too high");
}

void    Bureaucrat::upGrade()
{
    if (this->_grade <= 1)
        throw(Bureaucrat::GradeTooHighException());
    
    this->_grade--;
}

void    Bureaucrat::downGrade()
{
    if (150 <= this->_grade)
        throw(Bureaucrat::GradeTooLowException());
    
    this->_grade++;
}

void    Bureaucrat::signForm( Form& form ) 
    try 
{
    form.beSigned(*this);

    std::cout   <<  this->getName() 
                <<  " signed "
                <<  form.getName()
                <<  std::endl;
} 
    catch(Form::GradeTooLowException& e)
{
    std::cout   <<  this->getName()
                <<  " could not sign "
                <<  form.getName()
                <<  " because "
                <<  e.what()
                <<  std::endl;
}

void    Bureaucrat::executeForm( Form& form ) 
    try 
{
    form.execute(*this);

    std::cout   <<  this->getName() 
                <<  " executed "
                <<  form.getName()
                <<  std::endl;
} 
    catch(Form::GradeTooLowException& e)
{
    std::cout   <<  this->getName()
                <<  " could not execute "
                <<  form.getName()
                <<  " because "
                <<  e.what()
                <<  std::endl;
}

std::ostream&   operator<<( std::ostream& out, const Bureaucrat& bur)
{
    out <<  bur.getName()    
        << ", bureaucrat grade "   
        <<  bur.getGrade();

    return (out);
}
