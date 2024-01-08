#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template<class T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator	iterator;
public:
	MutantStack() {}

	~MutantStack() {}

	MutantStack(const MutantStack& obj)
	{
		*this = obj;
	}

	MutantStack &operator=(const MutantStack& obj)
	{
		this->c = obj.c;
		return (*this);
	}

	iterator begin() {return (this->c.begin());}
	iterator end() {return (this->c.end());}
	T& top() {return (this->c.front());}
	std::size_t	size() {return (this->c.size());} 
	void push(const T& val) {return (this->c.push_back(val));}
	void pop() {return (this->c.pop_back());}
};



#endif