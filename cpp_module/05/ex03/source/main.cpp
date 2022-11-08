#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{

	Bureaucrat stive(1, "Stive");
	Bureaucrat john(150, "John");
	std::cout << stive << std::endl;
	std::cout << john << std::endl;
	Intern intern;

	Form* form;
	try 
	{
		form = intern.makeForm("presidential pardon", "Bender");
		std::cout << *form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try 
	{
		stive.signForm(*form);
		form->execute(stive);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "==============================" << std::endl;
	try 
	{
		form = intern.makeForm("bibaboba", "Bender");
		std::cout << *form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}