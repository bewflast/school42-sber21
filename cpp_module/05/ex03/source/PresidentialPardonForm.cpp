#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm()   {};
PresidentialPardonForm::PresidentialPardonForm() 
: 
    Form(5, 25, "presidential pardon"), 
    _target("undef") 
{};
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other)    
:
    Form(5, 25, "presidential pardon"),
    _target(other._target)
{};
PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
:
    Form(5, 25, "presidential pardon"),
    _target(target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
    dynamic_cast<Form&>(*this)              = other;
    const_cast<std::string&>(this->_target) = other._target;

    return (*this);
}

void PresidentialPardonForm::execute( const Bureaucrat& bureaucrat )
{
    int doThrow = this->canExecute(bureaucrat);
    
    if (doThrow == 1)
        throw (Form::GradeTooLowException());
    if (doThrow == 2)
        throw (Form::FormNotSignedException());

    std::cout   <<  this->_target
                <<  " has been pardoned by Zaphod Beeblebox"
                <<  std::endl;
}