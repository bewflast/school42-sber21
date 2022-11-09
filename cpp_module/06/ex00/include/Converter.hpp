#ifndef CONVERTER_HPP
#define CONVERTER_HPP
#include <iostream>
#include <iomanip>

class Converter
{
	private:
		char *input;
		std::string s;
		double num;
		bool infP;
		bool infM;
		bool nan;
	public:
		Converter();
		~Converter();
		Converter(char* name);
		Converter(const Converter& ref);
		Converter& operator = (const Converter& ref);

		void ConvertChar();
		void ConvertInt();
		void ConvertFloat();
		void ConvertDouble();
		void Convert();
};
#endif