#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::~Form()   {};

Form::Form()    
:   
    _isSigned(false), 
    _gToExec(0), 
    _gToSign(0), 
    _name("undef")   
{};
Form::Form( const std::string& name)    
:   
    _isSigned(false), 
    _gToExec(0), 
    _gToSign(0), 
    _name(name)
{};
Form::Form( const Form& other )
:
    _isSigned(false), 
    _gToExec(other._gToExec), 
    _gToSign(other._gToSign), 
    _name(other._name)
{};

Form::Form( const short toExec, const short toSign, const std::string& name)
:
    _isSigned(false), 
    _gToExec(toExec), 
    _gToSign(toSign), 
    _name(name)
{

    if ( (150 < this->_gToSign)  || (150 < this->_gToExec) )
		throw Form::GradeTooLowException();

	if ( (this->_gToSign < 1) || (this->_gToExec < 1) )
		throw Form::GradeTooHighException();

};

Form& Form::operator=( const Form& other )
{
    this->_isSigned = other._isSigned;
    const_cast<short&>(this->_gToExec)      = other._gToExec;
    const_cast<short&>(this->_gToSign)      = other._gToSign;
    const_cast<std::string&>(this->_name)   = other._name;

    return (*this);
}

const std::string&  Form::getName()             const
{
    return(this->_name);
}
bool                Form::isSigned()            const
{
    return(this->_isSigned);
}
short               Form::getGradeToExecute()   const
{
    return(this->_gToExec);
}
short               Form::getGradeToSign()      const
{
    return(this->_gToSign);
}

void    Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (this->_gToSign < bureaucrat.getGrade())
        throw(Form::GradeTooLowException());
    
    this->_isSigned = true;


}

const char* Form::GradeTooLowException::what()    const throw()
{
    return ("grade is too low");
}
const char* Form::GradeTooHighException::what()   const throw()
{
    return ("grade is too high");
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out <<  "Form\t"                <<  form.getName()
        <<  std::endl
        <<  "Is signed: "           <<  (form.isSigned() ? "yes" : "no")
        <<  std::endl
        <<  "Grade to execute: "    <<  form.getGradeToExecute()
        <<  std::endl
        <<  "Grade to sign: "       <<  form.getGradeToSign();

    return (out);
}