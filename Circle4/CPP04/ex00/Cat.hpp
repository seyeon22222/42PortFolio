#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{    
public:
    Cat(void);
    ~Cat(void);
    Cat(const Cat &obj);
    Cat &operator=(const Cat &obj);
    Cat(std::string type);
    void makeSound(void) const;
};


#endif