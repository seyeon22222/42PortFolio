#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain(void);
    ~Brain(void);
    Brain(const Brain &obj);
    Brain &operator=(const Brain &obj);
	void	fillBrain(std::string type);
	void	printIdea(int num);
	void	setIdea(std::string str, int num);
};


#endif