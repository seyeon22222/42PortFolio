#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	RobotomyRequestForm &operator=(const RobotomyRequestForm& obj);
	virtual~RobotomyRequestForm() {}
	virtual void	execute(Bureaucrat const &executor) const;
};

#endif