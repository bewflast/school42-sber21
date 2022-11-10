#include "span.hpp"
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iostream>

Span::Span(unsigned int N): N(N), counter(0)
{
	this->arr.reserve(N);
}

Span::Span(const Span& ref)
{
	this->N = ref.N;
	this->arr = std::vector<int>(ref.arr);
	this->counter = ref.counter;
}

Span& Span::operator = (const Span& ref)
{
	this->N = ref.N;
	this->arr =  std::vector<int>(ref.arr);
	this->counter = ref.counter;
	return (*this);
}

Span::~Span(){}

void Span::addNumber(int n)
{
	if (static_cast<unsigned int>(this->counter) >= this->N)
		throw std::exception();
	this->arr.push_back(n);
	this->counter++;
}

int Span::shortestSpan()
{
	if (this->counter < 2)
		throw std::exception();
	std::vector<int> qq(this->arr);
	std::sort(qq.begin(), qq.end());
	std::adjacent_difference(qq.begin(), qq.end(), qq.begin());
	return (std::abs(*std::min_element(qq.begin(), qq.end())));
}

int Span::longestSpan()
{
	if (this->counter < 2)
		throw std::exception();
	std::vector<int> qq(this->arr);
	std::sort(qq.begin(), qq.end());
	return (*std::max_element(qq.begin(), qq.end()) - (*std::min_element(qq.begin(), qq.end())));
}

void Span::BETTERaddNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	int a = std::distance(start, end);
	if (arr.size() + a > this->N)
		throw std::exception();
	this->counter += a;
	arr.insert(arr.begin() + arr.size(), start, end);
}

static void out(int a)
{
	std::cout << "\033[1;34m" << a << "\033[0m" << " ";
}

void Span::printSpan()
{
	std:: cout << "THIS SPAN: ";
	std::for_each(arr.begin(), arr.end(), out);
	std::cout << std::endl;
}