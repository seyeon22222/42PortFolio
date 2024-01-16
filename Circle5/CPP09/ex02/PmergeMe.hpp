#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <utility>
# include <iostream>

struct vector_stack
{
	std::vector<vector_stack*>	stack;
	int							data;
	int							stack_depth;
};

struct deque_stack
{
	std::deque<deque_stack*>	stack;
	int							data;
	int							stack_depth;
};

class PmergeMe
{
private:
	std::vector<vector_stack*> cont1;
	std::deque<deque_stack*> cont2;
	// 스택의 역할을 벡터로 구현
	// 야콥 스타일 수를 따라감
	int jacobsthal[20];
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& obj);
	PmergeMe &operator=(const PmergeMe& obj);
	void vectorSort(std::vector<vector_stack*> &vs, int depth);
	void vectorMerge(std::vector<vector_stack*> &vs, int depth, vector_stack *);
	void divideVector(std::vector<vector_stack*> &ds);
	void dequeSort(std::deque<deque_stack*> &ds, int depth);
	void dequeMerge(std::deque<deque_stack*> &ds, int depth, deque_stack *);
	void divideDeque(std::deque<deque_stack*> &ds);
	void push(char *str);
	void display();
	class Error : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
};

#endif