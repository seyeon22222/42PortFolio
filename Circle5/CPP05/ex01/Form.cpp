#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("defalut"), sign(false), sign_grade(0), require_grade(0)
{
}

Form::Form(const Form& obj)
: name(obj.getName()), sign(obj.getSign()), sign_grade(obj.getSignGrade()), require_grade(obj.getRequire_grade())
{
}

Form Form::operator=(const Form& obj)
{
	if (this == &obj)
		return (*this);
	const_cast<std::string&>(this->name) = obj.getName();
	this->sign = obj.getSign();
	const_cast<int&>(this->sign_grade) = obj.getSignGrade();
	const_cast<int&>(this->require_grade) = obj.getRequire_grade();
	return (*this);
}

Form::Form(std::string str, int s_grade, int r_grade) : name(str), sign(false), sign_grade(s_grade), require_grade(r_grade)
{
	try
	{
		if (s_grade < 1 || r_grade < 1)
			throw Form::GradeTooHighException();
		else if (s_grade > 150 || r_grade > 150)
			throw Form::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (this->name);
}

int Form::getSignGrade() const
{
	return (this->sign_grade);
}

int Form::getRequire_grade() const
{
	return (this->require_grade);
}

bool Form::getSign() const
{
	return (this->sign);
}

void	Form::beSigned(Bureaucrat obj)
{
	try
	{
		if (this->sign_grade < obj.getGrade())
			throw Form::GradeTooLowException();
		// else if (this->sign_grade > obj.getGrade())
		// 	throw Form::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
		return ;
	}
	this->sign = true;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Form Grade is Too High");
}
const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Form Grade is Too Low");
}

std::ostream& operator<<(std::ostream &out, const Form &obj)
{
	if (obj.getSign())
		out << obj.getName() << " signed, sign_grade " << obj.getSignGrade() << ", execute_grade " << obj.getRequire_grade() << std::endl;
	else
		out << obj.getName() << " not signed, sign_grade " << obj.getSignGrade() << ", execute_grade " << obj.getRequire_grade() << std::endl;
	return (out);
}