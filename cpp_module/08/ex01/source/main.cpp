#include "span.hpp"
#include <iostream>
#include <algorithm>

int main()
{
	Span sp = Span(3);
	try
	{
		//sp.shortestSpan();
	}
	catch (std::exception& ex)
	{
		std::cout << "\033[31mERROR shortestSpan\033[0m" << std::endl;
	}
	try
	{
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(1);
		sp.printSpan();
		//sp.addNumber(9);
		//sp.addNumber(11);
		//sp.addNumber(10);
	}
	catch (std::exception& ex)
	{
		std::cout << "\033[31mMORE\033[0m" << std::endl;
	}
	std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan = " << sp.longestSpan() << std::endl;	

	Span span = Span(10);
	std::vector<int> vec(8, 9);
	try
	{
		span.BETTERaddNumber(vec.begin(), vec.end());
		std::vector<int> vec2(1, 99);
		span.BETTERaddNumber(vec2.begin(), vec2.end());
	}
	catch (std::exception& ex)
	{
		std::cout << "\033[1;31mBETTERaddNumber NOT WORK\033[0m" << std::endl;
	}
	span.printSpan();
	std::cout << "shortestSpan = " << span.shortestSpan() << std::endl;
	std::cout << "longestSpan = " << span.longestSpan() << std::endl;	
}