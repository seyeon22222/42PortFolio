#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("defalut"), sign(false), sign_grade(0), require_grade(0)
{
}

AForm::AForm(const AForm& obj)
: name(obj.getName()), sign(obj.getSign()), sign_grade(obj.getSignGrade()), require_grade(obj.getRequire_grade())
{
}

AForm::AForm(std::string str, int s_grade, int r_grade) : name(str), sign(false), sign_grade(s_grade), require_grade(r_grade)
{
	try
	{
		if (s_grade < 1 || r_grade < 1)
			throw AForm::GradeTooHighException();
		else if (s_grade > 150 || r_grade > 150)
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	
}

AForm &AForm::operator=(const AForm& obj)
{
	if (this == &obj)
		return (*this);
	const_cast<std::string&>(name) = obj.getName();
	sign = obj.getSign();
	const_cast<int&>(sign_grade) = obj.getSignGrade();
	const_cast<int&>(require_grade) = obj.getRequire_grade();
	return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return (this->name);
}

int AForm::getSignGrade() const
{
	return (this->sign_grade);
}

int AForm::getRequire_grade() const
{
	return (this->require_grade);
}

bool AForm::getSign() const
{
	return (this->sign);
}

void	AForm::beSigned(Bureaucrat obj)
{
	try
	{
		if (this->sign_grade < obj.getGrade())
			throw AForm::GradeTooLowException();
		// else if (this->sign_grade > obj.getGrade())
		// 	throw AForm::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
		return ;
	}
	this->sign = true;
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm Grade is Too High");
}
const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm Grade is Too Low");
}

std::ostream& operator<<(std::ostream &out, const AForm &obj)
{
	if (obj.getSign())
		out << obj.getName() << " signed, sign_grade " << obj.getSignGrade() << ", execute_grade " << obj.getRequire_grade() << std::endl;
	else
		out << obj.getName() << " not signed, sign_grade " << obj.getSignGrade() << ", execute_grade " << obj.getRequire_grade() << std::endl;
	return (out);
}