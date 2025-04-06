#ifndef ITER_HPP
	#define ITER_HPP

#include <iostream>
#include <cstring>

template <typename T>
void iter(T *array, size_t len, void (*func)(T &))
{
	for(size_t i = 0; i < len; i++)
		func(array[i]);
	return ;
}

template <typename T>
void print_number(T &n)
{
    std::cout << n << " ";
}

#endif