#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("a", 150);
	Bureaucrat b("b", 1);

	Form form("Cursus", 150, 100);
	Form form2("Cursus2", 1, 100);
	Form form3("Cursus3", 2, 100);

	a.signForm(form);
	a.signForm(form2);
	a.signForm(form3);
	std::cout << form << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;
	std::cout << "-------------" << std::endl;
	b.signForm(form);
	b.signForm(form2);
	b.signForm(form3);
	std::cout << "-------------" << std::endl;
	std::cout << form << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;
}