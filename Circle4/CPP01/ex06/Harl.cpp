#include "Harl.hpp"

void Harl::debug( void )
{   
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. \n" 
    << "I just love it!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money. \n"
    << "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. \n"
    << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
    std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        if (level == arr[i])
            break;
    }

    switch (i)
    {
    case 0:
        this->debug();
		std::cout << std::endl;
    case 1:
        this->info();
		std::cout << std::endl;
    case 2:
        this->warning();
		std::cout << std::endl;
    case 3:
        this->error();
		std::cout << std::endl;
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

