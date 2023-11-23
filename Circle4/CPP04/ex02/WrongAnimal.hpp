#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal(void);
    ~WrongAnimal(void);
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal &obj);
    WrongAnimal &operator=(const WrongAnimal &obj);
    void    setType(std::string type);
    std::string getType(void) const;
    void makeSound(void) const;
};


#endif