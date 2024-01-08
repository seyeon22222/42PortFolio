#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
class Span
{
private:
	std::vector<int> arr;
public:
	Span();
	Span(unsigned int);
	Span(const Span& obj);
	Span &operator=(const Span& obj);
	~Span();
	void addNumber(int);
	size_t shortestSpan();
	size_t longestSpan();
};

#endif