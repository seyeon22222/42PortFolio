#include "FragTrap.hpp"

int main(void)
{
	ClapTrap *Player1 = new FragTrap("A");
	ClapTrap *Player2 = new FragTrap("B");

	std::cout << "------------------------------------" << std::endl;
	Player1->attack(Player2->getName());
	Player2->takeDamage(Player1->getAttack());
	Player2->beRepaired(50);
	std::cout << "------------------------------------" << std::endl;
	Player2->attack(Player1->getName());
	Player1->takeDamage(Player2->getAttack());
	Player1->beRepaired(10);
	std::cout << "------------------------------------" << std::endl;
	FragTrap *a = (FragTrap*)Player1;
	FragTrap *b = (FragTrap*)Player2;
	a->highFivesGuys();
	b->highFivesGuys();
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Player1 Energy : " << Player1->getEnergy() << std::endl;
	std::cout << "Player2 Energy : " << Player2->getEnergy() << std::endl;

	delete Player1;
	delete Player2;
	return 0;
}