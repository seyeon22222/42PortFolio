#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>

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
	int shortestSpan();
	int longestSpan();
	template<class T>
	void addNumbers(typename T::iterator s, typename T::iterator e)
	{
		if (e <= s)
			throw std::exception();
		size_t sub = e - s;
		for (size_t i = 0; i < sub; i++)
			this->addNumber(*(s + i));
	}
};



#endif