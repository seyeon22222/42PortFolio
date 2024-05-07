#ifndef SHRUBBERYCREADTIONFORM_HPP
# define SHRUBBERYCREADTIONFORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm& obj);
	virtual ~ShrubberyCreationForm() {}
	virtual void	execute(Bureaucrat const &executor) const;
};

#endif