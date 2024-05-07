#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("default" ,72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string str)
: AForm(str, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
: AForm(obj.getName(), obj.getSignGrade(), obj.getRequire_grade())
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this == &obj)
		return (*this);
	return (*dynamic_cast<RobotomyRequestForm*>(&(AForm::operator=(obj))));
}


void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > getSignGrade())
			throw Bureaucrat::GradeTooLowException();
		if (executor.getGrade() > getRequire_grade())
			throw Bureaucrat::GradeTooLowException();
		std::cout << "Drilling Nose ";
		srand(time(NULL));
		int num = rand() % 2;
		if (num % 2 == 0)
			std::cout << "has been robotomized successfully" << std::endl;
		else
			std::cout << "has been robotomized failed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Robotomy Exception : " << e.what() << '\n';
	}
	
}