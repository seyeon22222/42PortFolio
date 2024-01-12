#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
: cont1(), cont2()
{}

PmergeMe::PmergeMe(char *str) : cont1(), cont2() 
{
	try
	{
		int num = atoi(str);
		if (num < 0 || std::isdigit(*str) != 1)
			throw PmergeMe::Error();
		cont1.push_back(num);
		cont2.push_back(num);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj) : cont1(obj.cont1), cont2(obj.cont2) {}

PmergeMe &PmergeMe::operator=(const PmergeMe& obj)
{
	cont1 = obj.cont1;
	cont2 = obj.cont2;
	return (*this);
}

void PmergeMe::push(char *str)
{
	if (!str)
		return ;
	try
	{
		int num = atoi(str);
		if (num < 0 || std::isdigit(*str) != 1)
			throw PmergeMe::Error();
		cont1.push_back(num);
		cont2.push_back(num);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
		exit(1);
	}
}

// 병합정렬
void PmergeMe::vectorMerge()
{

}
// 삽입 정렬
void PmergeMe::insertsort()
{

}
// 이진 탐색
void PmergeMe::binarySearch()
{

}
// 정렬결과 출력파트
void PmergeMe::vectorSort()
{

}

void PmergeMe::dequeSort()
{

}

const char* PmergeMe::Error::what(void) const throw()
{
	return ("Error\n");
}

void PmergeMe::display()
{
	for (size_t i = 0; i < cont1.size(); i++)
		std::cout << cont1[i] << " ";
	std::cout << "\n-------------------\n";
	for (size_t i = 0; i < cont2.size(); i++)
		std::cout << cont2[i] << " ";
	std::cout << std::endl;
}