#ifndef SPAN_HPP
	#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>



class Span{
	private:
		std::vector<int>	storage;
		unsigned int		max_size;
	public:
	// constructor & destructor
		Span();
		Span(unsigned int N);
		Span(const Span &obj);
		~Span();
		Span &operator=(const Span &old);
	// functions
		void addNumber(int number);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();


};

#endif