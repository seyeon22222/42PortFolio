#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				sign;
	const int			sign_grade;
	const int			require_grade;
public:
	Form();
	Form(const Form& obj);
	Form operator=(const Form& obj);
	Form(std::string str, int s_grade, int r_grade);
	~Form();
	std::string getName() const;
	bool getSign() const;
	int getSignGrade() const;
	int getRequire_grade() const;
	void	beSigned(Bureaucrat obj);
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

std::ostream& operator<<(std::ostream &out, const Form &obj);

#endif