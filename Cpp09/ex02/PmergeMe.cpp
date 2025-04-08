#include "PmergeMe.hpp"

// Constructor and Destructor

PmergeMe::PmergeMe(){}


PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &old)
{
	(void)old;
	return (*this);
}

PmergeMe::~PmergeMe(){}


// Useful functions : one for each container
void sort_for_veq(std::vector<int> &vec)
{
	std::vector<std::pair<int, int> > pair;
	creation_stack(vec, pair);
	ford_pair(pair);

	std::vector<int> main_chain;
	std::vector<int> pend;
	main_chain_fill(pair, main_chain);
	pend_fill(pair, pend);
	insert_element(main_chain, pend);
	std::cout << "After: ";
	for (size_t i = 0; i < main_chain.size(); ++i)
		std::cout << main_chain[i] << " ";
	std::cout << std::endl;
}
void sort_for_deq(std::deque<int> &deq)
{
	std::deque<std::pair<int, int> > pair;
	creation_stack(deq, pair);

	ford_pair(pair);
	std::deque<int> main_chain;
	std::deque<int> pend;
	main_chain_fill(pair, main_chain);
	pend_fill(pair, pend);
	insert_element(main_chain, pend);

}


// Jacobsthal function
size_t jacobsthal(size_t n)
{
	if (n == 0 || n == 1)
		return (n + 1);
	size_t prev1 = 1;
	size_t prev2 = 2;
	size_t result = 0;
	for (size_t i = 2; i <= n; ++i)
	{
		result = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = result;
	}
	return (result);
}

