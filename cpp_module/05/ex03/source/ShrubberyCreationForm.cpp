#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::~ShrubberyCreationForm()   {};
ShrubberyCreationForm::ShrubberyCreationForm() 
: 
    Form(137, 145, "shrubbery creation"), 
    _target("undef") 
{};
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other)    
:
    Form(137, 145, "shrubbery creation"),
    _target(other._target)
{};
ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target )
:
    Form(137, 145, "shrubbery creation"),
    _target(target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
    dynamic_cast<Form&>(*this)              = other;
    const_cast<std::string&>(this->_target) = other._target;

    return (*this);
}

void ShrubberyCreationForm::execute( const Bureaucrat& bureaucrat )
{
    int doThrow = this->canExecute(bureaucrat);
    
    if (doThrow == 1)
        throw (Form::GradeTooLowException());
    if (doThrow == 2)
        throw (Form::FormNotSignedException());

    std::ofstream   write_to(this->_target + "_shrubbery", std::ofstream::out);
    
    if(!write_to.is_open())
        return ;
    
    write_to    <<  "*ASCII trees inside*"  <<  std::endl;
    write_to.close();
}