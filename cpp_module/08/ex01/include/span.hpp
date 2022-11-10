#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>

class Span
{
	private:
		unsigned int N;
		std::vector<int> arr;
		int counter;
		Span();
	public:
		~Span();
		Span(unsigned int N);
		Span(const Span& ref);
		Span& operator = (const Span& ref);

		void addNumber(int n);
		void BETTERaddNumber(std::vector<int>::iterator qq, std::vector<int>::iterator qQa);
		int shortestSpan();
		int longestSpan();
		void printSpan();
};
#endif