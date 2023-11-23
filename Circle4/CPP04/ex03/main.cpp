#include "Character.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->unequip(0);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	std::cout << "------Character Deep Copy------" << std::endl;
	Character Player1("A");
	tmp = src->createMateria("ice");
	Player1.equip(tmp);
	Character Player2;
	Player2 = Player1;
	tmp = src->createMateria("cure");
	Player2.equip(tmp);
	Player1.use(0, *bob);
	Player2.use(0, *bob);
	Player2.unequip(0);
	Player1.use(0, *bob);
	Player2.use(0, *bob);
	delete bob;
	delete me;
	delete src;
	// system("leaks Materia");
	return 0;
}
