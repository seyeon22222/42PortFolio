#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("default", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string str)
: AForm(str, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
: AForm(obj.getName(), obj.getSignGrade(), obj.getRequire_grade())
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (this == &obj)
		return (*this);
	return (*dynamic_cast<PresidentialPardonForm*>(&(AForm::operator=(obj))));
}


void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > getSignGrade())
			throw Bureaucrat::GradeTooLowException();
		if (executor.getGrade() > getRequire_grade())
			throw Bureaucrat::GradeTooLowException();
		std::cout << "has been pardoned by Zaphod Beeblebrox." << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cout << "PresidentialPardonForm Exception : " << e.what() << std::endl;
	}
}