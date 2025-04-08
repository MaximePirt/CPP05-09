#include "PmergeMe.hpp"


/**
 * @brief Launch the program
 * @param argc number of arguments
 * @param argv
 * @return 0 if success, 1 if fail
 */
int main(int argc, char *argv[])
{

	if (argc < 2)
	{
		std::cerr << "Inputs error, \"./PmergeMe \"x x x y z\"\" is expected." << std::endl;
		return (1);
	}
	PmergeMe merge;
	std::vector<int> vec;
	std::deque<int> deq;
	try
	{
		check_input(argv, vec);
		check_input(argv, deq);
		std::cout << "Before : ";
		for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
		///////
		clock_t start_vec = clock();
		sort_for_veq(vec);
		clock_t end_vec = clock();
		///////
		clock_t start_deq = clock();
		sort_for_deq(deq);
		clock_t end_deq = clock();
		///////
		double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;
		double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << time_deq << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	


	return (0);
}
