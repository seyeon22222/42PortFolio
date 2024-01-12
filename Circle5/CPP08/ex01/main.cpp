#include "Span.hpp"
#include <iostream>
#include <vector>
int main()
{
	std::vector<int> a;
	for (int i = 0; i < 10000; i++)
		a.push_back(i);
	Span sp = Span(10000);
	sp.addNumbers<std::vector<int> >(a.begin(), a.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}