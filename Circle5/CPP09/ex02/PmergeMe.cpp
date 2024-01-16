#include "PmergeMe.hpp"
#include <cstring>
#include <iomanip>

std::vector<int> mainchain_vec;
std::deque<int> mainchain_deq;


PmergeMe::PmergeMe()
: cont1(), cont2()
{
	jacobsthal[0] = 0;
	jacobsthal[1] = 1;
	for (int i = 2; i < 20; i++)
		jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj) {*this = obj;}

PmergeMe &PmergeMe::operator=(const PmergeMe& obj)
{
	if (this == &obj)
		return (*this);
	cont1 = obj.cont1;
	cont2 = obj.cont2;
	jacobsthal[0] = 0;
	jacobsthal[1] = 1;
	for (int i = 2; i < 20; i++)
		jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
	return (*this);
}

void PmergeMe::push(char *str)
{
	try
	{
		if (!str)
			throw PmergeMe::Error();
		for (size_t i = 0; i < strlen(str); i++)
		{
			if (std::isdigit(str[i]) != 1)
				throw PmergeMe::Error();
		}
		long long num = atoi(str);
		if (num < 0 || num > INT_MAX || std::isdigit(*str) != 1 || (num < INT_MAX && strlen(str) >= 11))
		{
			throw PmergeMe::Error();
		}
		vector_stack *vs = new vector_stack;
		vs->data = num;
		cont1.push_back(vs);
		deque_stack *ds = new deque_stack;
		ds->data = num;
		cont2.push_back(ds);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
		exit(1);
	}
}

void PmergeMe::vectorMerge(std::vector<vector_stack*> &vs, int depth, vector_stack *ptr)
{
	std::vector<vector_stack*> temp_vs;
	for (size_t i = 0; i < vs.size(); ++i)
	{
		if (vs[i]->stack.size() == 0)
			continue ;
		if (vs[i]->stack[vs[i]->stack.size() - 1]->stack_depth == depth)
		{
			temp_vs.push_back(vs[i]->stack[vs[i]->stack.size() - 1]);
			vs[i]->stack.pop_back();
		}
	}
	if (ptr)
		temp_vs.push_back(ptr);
	int idx = 1;
	int min_idx = 0;
	while (1)
	{
		for (int i = jacobsthal[idx]; i > jacobsthal[idx - 1]; i--)
		{
			if (static_cast<size_t>(i) > temp_vs.size())
            	continue;
			vector_stack *temp = temp_vs[i - 1];
			int first = 0;
			int last = std::min(min_idx, static_cast<int>(vs.size() - 1));
			int p_idx = last;
			while (first <= last)
			{
				int mid = (first + last) / 2;
				if (vs[mid]->data == temp->data)
				{
					p_idx = mid;
					break;
				}
				else if (vs[mid]->data > temp->data)
				{
					p_idx = mid;
					last = mid - 1;
				}
				else
				{
					first = mid + 1;
					p_idx = first;
				}
			}
			vs.insert(vs.begin() + p_idx, temp);
		}
		if (static_cast<size_t>(jacobsthal[idx]) > temp_vs.size())
        	break;
		++idx;
		min_idx += jacobsthal[idx] - 1;
	}
}


void PmergeMe::divideVector(std::vector<vector_stack*> &vs)
{
	clock_t	start = clock();
	vectorSort(vs, 0);
	clock_t end = clock();
	std::cout << "After  : ";
	for (size_t i = 0; i < cont1.size(); i++)
		std::cout << cont1[i]->data << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << std::setw(4) << cont1.size() << " elements with std::vector : " << end - start << " ms" << std::endl;
}

void PmergeMe::vectorSort(std::vector<vector_stack*> &vs, int depth)
{
	size_t size = vs.size();
	if (size < 2)
		return ;
	vector_stack *ptr = 0;
	size_t mid = size / 2;
	if (size % 2 != 0)
	{
		ptr = vs[size - 1];
		--size;
		vs.pop_back();
	}
	for (size_t i = size - 1; i >= size - mid; --i)
	{
		if (vs[i]->data > vs[i - mid]->data)
		{
			vector_stack *temp = vs[i];
			vs[i] = vs[i - mid];
			vs[i - mid] = temp;
		}
		vs[i]->stack_depth = depth;
		vs[i - mid]->stack.push_back(vs[i]);
		vs.pop_back();
	}
	vectorSort(vs, depth + 1);
	vectorMerge(vs, depth, ptr);
}

void PmergeMe::divideDeque(std::deque<deque_stack*> &ds)
{
	clock_t	start = clock();
	dequeSort(ds, 0);
	clock_t end = clock();
	std::cout << "Time to process a range of " << std::setw(4) << cont2.size() << " elements with std::deque  : " << end - start << " ms" << std::endl;
}

void PmergeMe::dequeSort(std::deque<deque_stack*> &ds, int depth)
{
	size_t size = ds.size();
	if (size < 2)
		return ;
	deque_stack *ptr = 0;
	size_t mid = size / 2;
	if (size % 2 != 0)
	{
		ptr = ds[size - 1];
		--size;
		ds.pop_back();
	}
	for (size_t i = size - 1; i >= size - mid; --i)
	{
		if (ds[i]->data > ds[i - mid]->data)
		{
			deque_stack *temp = ds[i];
			ds[i] = ds[i - mid];
			ds[i - mid] = temp;
		}
		ds[i]->stack_depth = depth;
		ds[i - mid]->stack.push_back(ds[i]);
		ds.pop_back();
	}
	dequeSort(ds, depth + 1);
	dequeMerge(ds, depth, ptr);
}

void PmergeMe::dequeMerge(std::deque<deque_stack*> &ds, int depth, deque_stack *ptr)
{
	std::deque<deque_stack*> temp_ds;
	for (size_t i = 0; i < ds.size(); ++i)
	{
		if (ds[i]->stack.size() == 0)
			continue ;
		if (ds[i]->stack[ds[i]->stack.size() - 1]->stack_depth == depth)
		{
			temp_ds.push_back(ds[i]->stack[ds[i]->stack.size() - 1]);
			ds[i]->stack.pop_back();
		}
	}
	if (ptr)
		temp_ds.push_back(ptr);
	int idx = 1;
	int min_idx = 0;
	while (1)
	{
		for (size_t i = static_cast<size_t>(jacobsthal[idx]); i > static_cast<size_t>(jacobsthal[idx - 1]); i--)
		{
			if (i > temp_ds.size())
            	continue;
			deque_stack *temp = temp_ds[i - 1];
			int first = 0;
			int last = std::min(min_idx, static_cast<int>(ds.size() - 1));
			int p_idx = last;
			while (first <= last)
			{
				int mid = (first + last) / 2;
				if (ds[mid]->data == temp->data)
				{
					p_idx = mid;
					break;
				}
				else if (ds[mid]->data > temp->data)
				{
					p_idx = mid;
					last = mid - 1;
				}
				else
				{
					first = mid + 1;
					p_idx = first;
				}
			}
			ds.insert(ds.begin() + p_idx, temp);
		}
		if (static_cast<size_t>(jacobsthal[idx]) > temp_ds.size())
        	break;
		++idx;
		min_idx = jacobsthal[idx];
	}
}



const char* PmergeMe::Error::what(void) const throw()
{
	return ("Error\n");
}

void PmergeMe::display()
{
	std::cout << "Before : ";
	for (size_t i = 0; i < cont1.size(); i++)
		std::cout << cont1[i]->data << " ";
	std::cout << std::endl;
	divideVector(cont1);
	divideDeque(cont2);
	for (size_t i = 0; i < cont1.size(); i++)
		delete cont1[i];
	for (size_t i = 0; i < cont2.size(); i++)
		delete cont2[i];

}