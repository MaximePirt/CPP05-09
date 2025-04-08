#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <utility>
#include <ctime>
#include <vector>
#include <deque>
#include <sstream>
#include "algorithm"

class PmergeMe
{
	private:
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &old);
		~PmergeMe();

};

void check_input(char *str, std::vector<int> &vec, std::deque<int> &deq);
void sort_for_veq(std::vector<int> &vec);
void sort_for_deq(std::deque<int> &deq);
size_t jacobsthal(size_t n);


#include "PmergeMe.tpp"

#endif