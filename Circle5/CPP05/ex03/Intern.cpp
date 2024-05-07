#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm *Intern::makeForm(std::string str1, std::string str2)
{
	std::string arr[3] = {"shrubberry creation", "robotomy request", "presidential pardon"};
	f_ptr ptr[3] = {&Intern::ShrubberyCreate, &Intern::RobotomyRequest, &Intern::PresidentialPardon};
	
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (arr[i] == str1)
				return (this->*(ptr[i]))(str2);
		}
		throw InternException();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 0;
	}
	return (0);
}

AForm *Intern::ShrubberyCreate(std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::RobotomyRequest(std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::PresidentialPardon(std::string &target)
{
	return (new PresidentialPardonForm(target));
}
const char* Intern::InternException::what(void) const throw()
{
	return ("Not correct Form");
}