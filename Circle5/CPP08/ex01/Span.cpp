#include "Span.hpp"

Span::Span()
: arr(0)
{
}

Span::Span(unsigned int n)
{
	arr.reserve(n);
}

Span::Span(const Span& obj)
{
	*this = obj;
}

Span &Span::operator=(const Span& obj)
{
	arr = obj.arr;
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
	try
	{
		if (arr.capacity() == arr.size())
			throw std::exception();	
		arr.push_back(num);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(1);
	}
}

int Span::shortestSpan()
{
	try
	{
		if (arr.size() == 0 || arr.size() == 1)
			throw std::exception();
		std::sort(arr.begin(), arr.end());
		int min_arr = 2147483647;
		for (size_t i = 0; i < arr.size() - 1; i++)
		{
			min_arr = std::min((*(arr.begin() + i + 1)) - (*(arr.begin() + i)), min_arr);
		}
		return (min_arr);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(1);
	}
}

int Span::longestSpan()
{
	try
	{
		if (arr.size() == 0 || arr.size() == 1)
			throw std::exception();
		std::sort(arr.begin(), arr.end());	
		return (*(arr.end() - 1) - *(arr.begin()));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(1);
	}
}