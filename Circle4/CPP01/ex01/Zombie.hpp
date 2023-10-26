#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string name);
    Zombie(void);
    ~Zombie(void);
    void    announce(void) ;
    void    set(std::string name);
};

#include <string>

Zombie* zombieHorde( int N, std::string name );

#endif