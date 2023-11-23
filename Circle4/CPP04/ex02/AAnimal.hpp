#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
protected:
    std::string type;
public:
    AAnimal(void);
    virtual ~AAnimal(void);
    AAnimal(std::string type);
    AAnimal(const AAnimal &obj);
    AAnimal &operator=(const AAnimal &obj);
    std::string getType(void) const;
    void        setType(std::string type);
    virtual void    makeSound(void) const = 0;
};

#endif