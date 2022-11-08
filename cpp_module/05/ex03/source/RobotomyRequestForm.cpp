#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm()   {};
RobotomyRequestForm::RobotomyRequestForm() 
: 
    Form(45, 72, "robotomy request"), 
    _target("undef") 
{};
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other)    
:
    Form(45, 72, "robotomy request"),
    _target(other._target)
{};
RobotomyRequestForm::RobotomyRequestForm( const std::string& target )
:
    Form(45, 72, "robotomy request"),
    _target(target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
    dynamic_cast<Form&>(*this)              = other;
    const_cast<std::string&>(this->_target) = other._target;

    return (*this);
}

void RobotomyRequestForm::execute( const Bureaucrat& bureaucrat )
{
    int doThrow = this->canExecute(bureaucrat);
    
    if (doThrow)
        std::cout   <<  "Robotomy failed"   <<  std::endl;
    if (doThrow == 1)
        throw (Form::GradeTooLowException());
    if (doThrow == 2)
        throw (Form::FormNotSignedException());


    std::cout   <<  "BZBZBZBBZDBBBDDRZBDZRDBZRDBZRDBZD" <<  std::endl;

    std::cout   <<  this->_target
                <<  " has been robotomized successfully 50%% of the time"
                <<  std::endl;
}