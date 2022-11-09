#include "Converter.hpp"

Converter::Converter(){};
Converter::~Converter(){};
Converter::Converter(const Converter& ref)
{
	this->input = ref.input;
	//this->number = ref.number;
	//this->fNumber = ref.fNumber;
	//this->dNumber = ref.dNumber;
	//this->cNumber = ref.cNumber;
}
Converter& Converter::operator=(const Converter &ref)
{
	this->input = ref.input;
	//this->number = ref.number;
	//this->fNumber = ref.fNumber;
	//this->dNumber = ref.dNumber;
	//this->cNumber = ref.cNumber;
	return (*this);
}

Converter::Converter(char *name): input(name)
{
	this->s = this->input;
	if (s == "inf" || s == "inff" || s == "+inf" || s == "+inff")
		this->infP = true;
	else if (s == "-inf" || s == "-inff")
		this->infM = true;
	else if (s == "nan")
		this->nan = true;
	this->num = static_cast<double>(atof(name));
}

void Converter::ConvertChar()
{
	if (this->infP || this->infM || this->nan || this->num < 0 || this->num > 127)
		std::cout << "Char: impossible" << std::endl;
	else if (this->num >= 0 && this->num <= 32)
		std::cout << "Char: Non displayable" << std::endl;
	else
	{
		char c = static_cast<char>(this->num);
		std::cout << "Char: " << c << std::endl;
	}
}

void Converter::ConvertInt()
{
	if (this->nan || this->num > INT_MAX || this->num < INT_MIN)
		std::cout << "Int: impossible" << std::endl;
	else if (this->infP)
		std::cout << "Int: +inf" << std::endl;
	else if (this->infM)
		std::cout << "Int: -inf" << std::endl;
	else
	{
		int i = static_cast<int>(this->num);
		std::cout << "Int: " << i << std::endl;

	}
}

void Converter::ConvertFloat()
{
	if (this->nan)
		std::cout << "Float: nan";
	else if (this->infP)
		std::cout << "Float: +inf";
	else if (this->infM)
		std::cout << "Float: -inf";
	else
	{
		float f = static_cast<float>(this->num);
		std::cout << "Float: " << std::fixed << std::setprecision(1) << f;
	}
	std::cout << "f" << std::endl;
}

void Converter::ConvertDouble()
{
	if (this->nan)
		std::cout << "Double: nan";
	else if (this->infP)
		std::cout << "Double: +inf";
	else if (this->infM)
		std::cout << "Double: -inf";
	else
	{
		double d = static_cast<double>(this->num);
		std::cout << "Double: " << std::fixed << std::setprecision(1) << d;
	}
	std::cout << std::endl;
}

void Converter::Convert()
{
	this->ConvertChar();
	this->ConvertInt();
	this->ConvertFloat();
	this->ConvertDouble();
}