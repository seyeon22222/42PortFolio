#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm a("shru");
	RobotomyRequestForm b("robot");
	PresidentialPardonForm c("pres");
	Bureaucrat d("A", 1);
	Bureaucrat e("B", 6);
	Bureaucrat f("C", 46);
	Bureaucrat g("D", 144);


	d.executeForm(a);
	d.executeForm(b);
	d.executeForm(c);
	std::cout << "---------------------\n";
	e.executeForm(a);
	e.executeForm(b);
	e.executeForm(c);
	std::cout << "---------------------\n";
	f.executeForm(a);
	f.executeForm(b);
	f.executeForm(c);
	std::cout << "---------------------\n";
	g.executeForm(a);
	g.executeForm(b);
	g.executeForm(c);
}