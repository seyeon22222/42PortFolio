#include "FragTrap.hpp"

int main(void)
{
	FragTrap	Player1("A");
	FragTrap	Player2("B");

	std::cout << "------------------------------------" << std::endl;
	Player1.attack("B");
	Player2.takeDamage(30);
	Player2.beRepaired(50);
	std::cout << "------------------------------------" << std::endl;
	Player2.attack("A");
	Player1.takeDamage(30);
	Player1.beRepaired(10);
	std::cout << "------------------------------------" << std::endl;
	Player1.highFivesGuys();
	Player2.highFivesGuys();
	std::cout << "------------------------------------" << std::endl;
}