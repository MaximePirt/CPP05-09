#include "Span.hpp"

Span::Span()
{
	this->max_size = 0;
}
Span::Span(unsigned int N) : max_size(N)
{

}
Span::Span(const Span &obj) : storage(obj.storage),  max_size(obj.max_size)
{

}
Span::~Span()
{

}
Span &Span::operator=(const Span &old)
{
	if (this != &old)
	{
		this->storage = old.storage;
		this->max_size = old.max_size;
	}
	return (*this);
}

/**
 * @brief add a single number into container
 */
void Span::addNumber(int number)
{
	if (this->storage.size() >= this->max_size)
		throw std::runtime_error("Storage full, cannot add more numbers.");
	this->storage.push_back(number);
	return ;
}
/**
 * @brief add a range of number into container
 */
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->storage.size() + std::distance(begin, end) > this->max_size)
		throw std::runtime_error("Not enough stockage in storage to add this much iterators.");
	this->storage.insert(this->storage.end(), begin, end);
	return ;
}
int Span::shortestSpan()
{
	if (this->storage.size() < 2)
		throw std::runtime_error("Storage too small, can't find the shortest span if there's only one or none.");
	
	std::vector<int> sorted = this->storage;
	std::sort(sorted.begin(), sorted.end());
	int actual_mins = sorted[1] - sorted[0];
	unsigned int len = sorted.size();
	for(unsigned int i = 1; i < len - 1; i++)
	{
		int try_mins = sorted[i + 1] - sorted[i];
		if (try_mins < actual_mins)
			actual_mins = try_mins;
	}
	return (actual_mins);
}
int Span::longestSpan()
{
	if (this->storage.size() < 2)
		throw std::runtime_error("Storage too small, can't find the longest span if there's only one or none.");
	int min = *std::min_element(this->storage.begin(), this->storage.end());
	int max = *std::max_element(this->storage.begin(), this->storage.end());
	return (max-min);
}