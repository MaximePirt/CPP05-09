#ifndef MUTANTSTACK_HPP
	#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>
#include <stack>


template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	private :
	public :
	// Constructor and Destructor
		MutantStack(){};
		MutantStack(const MutantStack &obj)
		{
			*this = obj;
		}
		MutantStack<T> &operator=(const MutantStack &old)
		{
			if (this != &old)
				std::stack<T, Container>::operator=(old);
			return (*this);
		}
		~MutantStack(){};

		typedef typename Container::iterator iterator;
		typedef typename Container::iterator const_it;

	// Basic stacks functions
		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
		const_it begin() const
		{
			return (this->c.begin());
		}
		const_it end() const
		{
			return (this->c.end());
		}


};

#endif
