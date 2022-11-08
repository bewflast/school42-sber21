#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

int main()
{

	Bureaucrat stive(1, "Stive");
	Bureaucrat john(150, "John");
	std::cout << stive << std::endl;
	std::cout << john << std::endl;
	std::cout << "============================" << std::endl;

	ShrubberyCreationForm form("file");
	try
	{
		stive.signForm(form);
		john.signForm(form);
		form.execute(stive);
		form.execute(john);
	}
	catch (std::exception& ex)
	{
		std:: cout << ex.what() << std::endl;
	}
	std::cout << "============================" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "============================" << std::endl;

	RobotomyRequestForm form2("AAAA");
	try
	{
		stive.signForm(form2);
		john.signForm(form2);
		form2.execute(stive);
		form2.execute(john);
	}
	catch (std::exception& ex)
	{
		std:: cout << ex.what() << std::endl;
	}
	std::cout << "============================" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "============================" << std::endl;

	PresidentialPardonForm form3("Bob");
	try
	{
		stive.signForm(form3);
		john.signForm(form3);
		form3.execute(stive);
		form3.execute(john);
	}
	catch (std::exception& ex)
	{
		std:: cout << ex.what() << std::endl;
	}
	std::cout << "============================" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "============================" << std::endl;
	stive.executeForm(form2);
	std::cout << "============================" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "============================" << std::endl;
	john.executeForm(form2);

	return (0);
}