#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				sign;
	const int			sign_grade;
	const int			require_grade;
public:
	AForm();
	AForm(const AForm& obj);
	AForm(std::string str, int s_grade, int r_grade);
	AForm &operator=(const AForm& obj);
	virtual ~AForm();
	std::string getName() const;
	bool getSign() const;
	int getSignGrade() const;
	int getRequire_grade() const;
	void	beSigned(Bureaucrat obj);
	virtual void	execute(Bureaucrat const &executor) const = 0;
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

std::ostream& operator<<(std::ostream &out, const AForm &obj);

#endif