#ifndef EASYFIND_HPP
	#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <cstdlib>



template <typename T>
int easyfind(T &array, int search)
{
	typename T::iterator res = std::find(array.begin(), array.end(), search);
	if (res != array.end())
		return *res;
	else
		throw std::runtime_error("Shoot, no occurence found in array");
	
	return (-1);
}

#endif