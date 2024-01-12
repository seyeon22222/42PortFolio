#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <utility>
# include <iostream>

class PmergeMe
{
private:
	std::vector<int> cont1;
	std::deque<int> cont2;
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(char *str);
	PmergeMe(const PmergeMe& obj);
	PmergeMe &operator=(const PmergeMe& obj);
	// 병합정렬
	void vectorMerge();
	// 삽입 정렬
	void insertsort();
	// 이진 탐색
	void binarySearch();
	// 정렬결과 출력파트
	void vectorSort();
	void dequeSort();
	void push(char *str);
	void display();
	class Error : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
};


#endif