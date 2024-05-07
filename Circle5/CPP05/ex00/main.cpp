#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("a", 150);
	Bureaucrat b("b", 1);
	Bureaucrat c("c", 200);
	Bureaucrat d("d", 0);

	a.decrement();
	std::cout << a;
	b.decrement();
	std::cout << b;
	b.increment();
	std::cout << b;
}