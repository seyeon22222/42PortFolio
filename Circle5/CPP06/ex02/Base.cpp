#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	srand(time(NULL));
	int num = rand() % 3;
	switch (num)
	{
	case (0):
		std::cout << "Create A Class" << std::endl;
		return (new A());
	case (1):
		std::cout << "Create B Class" << std::endl;
		return (new B());
	case (2):
		std::cout << "Create C Class" << std::endl;
		return (new C());
	}
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class Type A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "Class Type B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "Class Type C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Reference A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "Reference B" << std::endl;
		(void)b;
	}
	catch(const std::exception& e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "Reference C" << std::endl;
		(void)c;
	}
	catch(const std::exception& e) {}
}