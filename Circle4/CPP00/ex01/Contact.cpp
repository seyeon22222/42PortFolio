#include "Contact.hpp"

void	Contact::addcontact(void)
{
	std::cout << "First_name : ";
	std::cin >> this->first_name;
	std::cout << "Last_name : ";
	std::cin >> this->last_name;
	std::cout << "Nickname : ";
	std::cin >> this->nickname;
	std::cout << "Phone number : ";
	std::cin >> this->phone_number;
	std::cout << "Darkset secret : ";
	std::cin >> this->darkset_secret;
}

std::string	Contact::parser(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0,9) + ".");
	else
		return (std::string(10 - (str.size()), ' ') + str);
}

void Contact::contact_search(void)
{
	std::cout << "|" << parser(this->first_name) \
	<< "|" << parser(this->last_name) \
	<< "|" << parser(this->nickname)  \
	<< "|" << std::endl;
	return ;
}

void	Contact::print_selcet()
{
	std::cout << "First name : " << this->first_name << std::endl;
	std::cout << "Last name : " << this->last_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone number : " << this->phone_number << std::endl;
	std::cout << "Darkest secret : " << this->darkset_secret << std::endl;
}