#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{

	Form t(10, 15, "kega");
	Bureaucrat b(50,"Buddy");

	std::cout	<<	t << std::endl;

	b.signForm(t);

	return (0);
}