#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type;
public:
	AMateria(void);
	AMateria(std::string const &type);
	virtual ~AMateria(void);
	AMateria(const AMateria &obj);
	AMateria &operator=(const AMateria &obj);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif