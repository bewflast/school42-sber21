#include "Bureaucrat.hpp"

int main()
{

	Bureaucrat stive(1, "Stive");

	std::cout << stive << std::endl;
	stive.downGrade();
	std::cout << stive << std::endl;
	stive.downGrade();
	std::cout << stive << std::endl;

	try 
	{
		stive.upGrade();
		stive.upGrade();
		stive.upGrade();
	} 
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	std::cout << stive << std::endl;
	std::cout << "===================================" << std::endl;
	Bureaucrat john(150, "John");
	std::cout << john << std::endl;
	john.upGrade();
	john.upGrade();
	john.upGrade();
	john.upGrade();
	std::cout << john << std::endl;
	john.downGrade();
	john.downGrade();
	john.downGrade();
	try
	{
		john.downGrade();
		std::cout << john << std::endl;
		john.downGrade();
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	std::cout << john << std::endl;
	std::cout << "===================================" << std::endl;
	try
	{
		Bureaucrat wrong(200, "Wrong");
		std::cout << wrong << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	try
	{
		Bureaucrat wrong(0, "Wrong");
		std::cout << wrong << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	return (0);
}