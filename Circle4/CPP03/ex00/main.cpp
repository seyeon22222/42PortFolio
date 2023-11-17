#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	Player1;
	ClapTrap	Player2("Kardet");

	std::cout << "------------" << std::endl;
	Player1.attack(Player2.getName());
	Player2.takeDamage(Player1.getAttack());
	Player1.beRepaired(5);
	std::cout << "------------" << std::endl;
	Player2.attack(Player1.getName());
	Player1.takeDamage(Player2.getAttack());
	Player2.beRepaired(1);
	std::cout << "------------" << std::endl;
	std::cout << "Player1 Energy : " << Player1.getEnergy() << std::endl;
	std::cout << "Player2 Energy : " << Player2.getEnergy() << std::endl;
	return 0;
}