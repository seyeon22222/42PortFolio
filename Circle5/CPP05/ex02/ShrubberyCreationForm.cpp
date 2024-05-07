#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <ostream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string str)
: AForm(str, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
: AForm(obj.getName(), obj.getSignGrade(), obj.getRequire_grade())
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this == &obj)
		return (*this);
	return (*dynamic_cast<ShrubberyCreationForm*>(&(AForm::operator=(obj))));
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > getSignGrade())
			throw Bureaucrat::GradeTooLowException();
		if (executor.getGrade() > getRequire_grade())
			throw Bureaucrat::GradeTooLowException();
		std::string     output_name = std::string(executor.getName()) + "_shrubbery";
		std::ofstream   file(output_name);
		file << "      _-_" << std::endl;
		file << "    /~~   ~~\\" << std::endl;
		file << " /~~         ~~\\" << std::endl;
		file << "{               }" << std::endl;
		file << " \\  _-     -_  /" << std::endl;
		file << "   ~  \\\\ //  ~" << std::endl;
		file << "_- -   | | _- _" << std::endl;
		file << "  _ -  | |   -_" << std::endl;
		file << "      // \\" << std::endl;
		std::cout << "Shrubbery" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Shrubbery Exception : " << e.what() << '\n';
	}
	
}