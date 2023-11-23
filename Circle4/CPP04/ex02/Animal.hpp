#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;
public:
    Animal(void);
    virtual ~Animal(void);
    Animal(std::string type);
    Animal(const Animal &obj);
    Animal &operator=(const Animal &obj);
    std::string getType(void) const;
    void        setType(std::string type);
    virtual void    makeSound(void) const;
};

#endif