#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

class AForm;

class Intern
{
public:
	Intern() {}
	~Intern() {}
	AForm *makeForm(std::string str1, std::string str2);
	AForm *ShrubberyCreate(std::string &target);
	AForm *RobotomyRequest(std::string &target);
	AForm *PresidentialPardon(std::string &target);
	typedef AForm* (Intern::*f_ptr)(std::string&);
	class InternException : public std::exception
	{
		public:
			const char * what(void) const throw();
	};
};

#endif