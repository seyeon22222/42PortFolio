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
	if (arr.capacity() == arr.size())
		throw std::exception();
	else
		arr.push_back(num);
}

size_t Span::shortestSpan()
{
	if (arr.size() == 0 || arr.size() == 1)
		throw std::exception();
	std::sort(arr.begin(), arr.end());
	int min_arr = INFINITY;
	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		min_arr = std::min((*(arr.begin() + i + 1)) - (*(arr.begin() + i)), min_arr);
	}
	return (min_arr);

}

size_t Span::longestSpan()
{
	if (arr.size() == 0 || arr.size() == 1)
		throw std::exception();
	std::sort(arr.begin(), arr.end());
	return (*(arr.end() - 1) - *(arr.begin()));
}