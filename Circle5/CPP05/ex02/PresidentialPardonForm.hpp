#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string);
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	PresidentialPardonForm &operator=(const PresidentialPardonForm& obj);
	virtual ~PresidentialPardonForm() {};
	virtual void	execute(Bureaucrat const &executor) const;
};


#endif