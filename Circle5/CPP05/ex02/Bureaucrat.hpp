#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat operator=(const Bureaucrat& obj);
	Bureaucrat(std::string str, int num);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	void signForm(AForm& obj);
	void executeForm(AForm const & form);
	class GradeTooHighException : public std::exception
	{
		public:
			const char * what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char * what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj);

#endif