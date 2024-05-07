#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern Kardet;
	AForm *a;
	AForm *b;
	AForm *c;
	Bureaucrat Bocal("Bocal", 1);
	Bureaucrat Tutor("Tutor", 44);
	Bureaucrat Member("Member", 136);
	

	a = Kardet.makeForm("shrubberry creation", "hello");
	b = Kardet.makeForm("robotomy request", "hello");
	c = Kardet.makeForm("presidential pardon", "hello");
	Bocal.executeForm(*a);
	Bocal.executeForm(*b);
	Bocal.executeForm(*c);
	std::cout << "-----------------------------------" << std::endl;
	Tutor.executeForm(*a);
	Tutor.executeForm(*b);
	Tutor.executeForm(*c);
	std::cout << "-----------------------------------" << std::endl;
	Member.executeForm(*a);
	Member.executeForm(*b);
	Member.executeForm(*c);
	
	// Error Form
	AForm *d;
	d = Kardet.makeForm("new Form", "hello");
}