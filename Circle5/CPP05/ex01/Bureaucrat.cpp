#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("defalut")
{
	grade = 150;
}

Bureaucrat::Bureaucrat(std::string str, int num) : name(str)
{
	try
	{
		grade = num;
		if (grade <= 0)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}	
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.getName()), grade(obj.getGrade())
{
	// std::cout << "copy constructor called" << std::endl;
}

Bureaucrat Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this == &obj)
		return (*this);
	*const_cast<std::string*>(&name) = obj.getName();
	grade = obj.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::increment()
{
	int temp = getGrade();
	try
	{
		temp--;
		if (temp <= 0)
			throw Bureaucrat::GradeTooHighException();
		if (temp > 150)
			throw Bureaucrat::GradeTooLowException();
		grade = temp;
	}
	catch(const std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}

void Bureaucrat::decrement()
{
	int temp = getGrade();
	try
	{
		temp++;
		if (temp <= 0)
			throw Bureaucrat::GradeTooHighException();
		if (temp > 150)
			throw Bureaucrat::GradeTooLowException();
		grade = temp;
	}
	catch(const std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(Form& obj)
{
	try
	{
		if (obj.getSignGrade() < getGrade())
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't sign " << obj.getName() << " because " << e.what() << "." << std::endl;
		return ;
	}
	obj.beSigned(*this);
	std::cout << getName() << " signed " << obj.getName() << "." << std::endl;
}


std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", " << "bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return (out);
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Too High Grade");
}
const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Too Low Grade");
}