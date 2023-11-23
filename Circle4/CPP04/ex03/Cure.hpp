#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	virtual ~Cure(void);
	Cure(const Cure &obj);
	Cure &operator=(const Cure &obj);
	virtual void use(ICharacter& target);
	virtual AMateria* clone() const;
};

#endif