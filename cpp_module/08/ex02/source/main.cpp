#include "mutantstack.hpp"
#include <iostream>
#define XGREEN "\033[1;32m"
#define XWHITE "\033[0m"

void out(int a)
{
	std::cout << XGREEN << a << " " << XWHITE;
}

void stringOut(std::string a)
{
	std::cout << XGREEN << a << " " << XWHITE;
}

void charOut(char a)
{
	std::cout << XGREEN << a << " " << XWHITE;
}

int main()
{
	MutantStack<int> intStack;
	intStack.push(5);
	intStack.push(17);
	std::cout << "============================" << std::endl;
	std::cout << "Stack: ";
	std::for_each(intStack.begin(), intStack.end(), out);
	std::cout << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "Top: " << XGREEN << intStack.top() << XWHITE << std::endl;
	std::cout << "============================" << std::endl;
	intStack.pop();
	std::cout << "Size: " << XGREEN << intStack.size() << XWHITE << std::endl;
	std::cout << "Top: " << XGREEN << intStack.top() << XWHITE << std::endl;
	std::cout << "============================" << std::endl;
	intStack.push(3);
	intStack.push(5);
	intStack.push(737);
	intStack.push(0);
	MutantStack<int>::iterator itbegin = intStack.begin();
	MutantStack<int>::iterator itend = intStack.end();
	++itbegin;
	--itbegin;
	while (itbegin != itend)
	{
		std::cout << XGREEN << *itbegin << XWHITE <<std::endl;
		++itbegin;
	}
	std::cout << "============================" << std::endl;
	std::cout << "Stack: ";
	std::for_each(intStack.begin(), intStack.end(), out);
	std::cout << std::endl;
	std::cout << "===========REVERSE==========" << std::endl;
	std::cout << "Stack: ";
	std::for_each(intStack.rbegin(), intStack.rend(), out);
	std::cout << std::endl;
	std::cout << "============================" << std::endl;

	MutantStack<std::string> stringStack;
	stringStack.push("a");
	stringStack.push("bb");
	stringStack.push("ccc");
	stringStack.push("dddd");
	stringStack.push("eeeee");
	stringStack.push("LOL");
	
	std::cout << "Stack: ";
	std::for_each(stringStack.begin(), stringStack.end(), stringOut);
	std::cout << std::endl;

	std::cout << "===========REVERSE==========" << std::endl;
	std::cout << "Stack: ";
	std::for_each(stringStack.rbegin(), stringStack.rend(), stringOut);
	std::cout << std::endl;

	MutantStack<char> charStack;
	charStack.push('a');
	charStack.push('b');
	charStack.push('c');
	charStack.push('d');
	charStack.push('e');
	charStack.push('L');
	std::cout << "============================" << std::endl;
	
	std::cout << "Stack: ";
	std::for_each(charStack.begin(), charStack.end(), charOut);
	std::cout << std::endl;

	std::cout << "===========REVERSE==========" << std::endl;
	std::cout << "Stack: ";
	std::for_each(charStack.rbegin(), charStack.rend(), charOut);
	std::cout << std::endl;
	return 0;
}