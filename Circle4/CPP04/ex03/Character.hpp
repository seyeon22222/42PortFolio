#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	AMateria *inventory[4];
	AMateria *trash[4];
public:
	Character(void);
	virtual ~Character(void);
	Character(std::string name);
	Character(const Character &obj);
	Character &operator=(const Character &obj);
	virtual void use(int idx, ICharacter& target);
	virtual std::string const &getName(void) const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	void	printInventory(void);
};

#endif