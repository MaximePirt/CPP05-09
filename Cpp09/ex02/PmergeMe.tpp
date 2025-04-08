#pragma once

/**
 * @brief Convert string to value
 * @param str string to convert
 * @return value (int, double, float, etc)
 * @note This function is used to convert a string to a value
 */
template <typename T>
T stringToValue(const std::string& str) {
	std::stringstream ss(str);
	T result;
	ss >> result;
	if (ss.fail() || !ss.eof()) {
		return T();
	}
	return (result);
}

/**
 * @brief Check the input
 * @param str string to check
 * @param cont container to fill
 * @return 
 * @throw std::runtime_error if the input is invalid
 * @note This function is used to check the input and fill the container
 */
template <typename T>
T check_input(char **str, T &cont)
{
	char *input = *str;
	for (int i = 1; input != '\0'; ++i)
	{
		if (!str[i])
			break;
		input = str[i];
		std::stringstream ss(input);
		std::string token;
		while (ss >> token)
		{
			if (std::all_of(token.begin(), token.end(), ::isdigit))
			{
				size_t len = token.length();
				for (size_t i = 0; i < len; ++i)
				{
					if (token[i] == '0' && i == 0 && len > 1)
					{
						token.erase(i, 1);
						--i;
					}
					else
						break;
				}
				if (token.length() == 0 || token.length() > 10)
					throw std::runtime_error("Error: Invalid number");
				double value = stringToValue<double>(token);
				if (value < 0)
					throw std::runtime_error("Error: Negative number");
				else if (value > 2147483647)
					throw std::runtime_error("Error: Number need to be an int");
				cont.push_back(value);
			}
			else
				throw std::runtime_error("Error: Invalid token");
			}
	}
	return (cont);
}

/**
 * @brief
 * @param T container use in functions (vector, deque,..)
 * @return 
 */
template <typename T, typename U>
void creation_stack(T &cont, U &pair)
{	
	for (size_t i = 0; i < cont.size(); i+=2)
	{
		if (i + 1 < cont.size())
			pair.push_back(std::make_pair(cont[i], cont[i+1]));
		else
			pair.push_back(std::make_pair(cont[i], -1));
	}
}

/**
 * @brief Swap values
 * @param a first value
 * @param b second value
 * @return
 * @note This function is used to swap two values
 */
template <typename T>
void swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}


/**
 * @brief Sort the pairs, first sort the inside of the pair, then sort the pairs
 * 
 * @param T pair container use in functions (vector, deque,..)
 * @return 
 */
template <typename T>
void ford_pair(T &pair)
{
	for (size_t i = 0; i < pair.size(); ++i)
	{
		if (pair[i].second != -1 && pair[i].first > pair[i].second)
			swap(pair[i].first, pair[i].second);
	}
	for (size_t i = 0; i < pair.size(); ++i)
	{
		for (size_t j = i + 1; j < pair.size(); ++j)
		{
			if (pair[i].first > pair[j].first)
				swap(pair[i], pair[j]);
		}
	}
}
/**
 * @brief Fill the main chain with the first value of the pair
 * 		  from the pair container
 * @param T pair container use in functions (vector, deque,..)
 * @param U container to fill
 * @return
 * @note This function is used to fill the main chain with the first value of the pair
 */
template <typename T, typename U>
void main_chain_fill(const T &pair, U &main_chain)
{
	for (size_t i = 0; i < pair.size(); ++i)
		main_chain.push_back(pair[i].first);
}

/**
 * @brief Fill the pend chain with the second value of the pair
 * @param T pair container use in functions (vector, deque,..)
 * @param U container to fill
 * @return
 * @note This function is used to fill the pend chain with the second value of the pair
 */
template <typename T, typename U>
void pend_fill(const T &pair, U &pend)
{
	for (size_t i = 0; i < pair.size(); ++i)
	{
		if (pair[i].second != -1)
			pend.push_back(pair[i].second);
	}
}

/**
 * @brief Generate the jacob indices
 * @param  size_t size of the container
 * @return T pair container use in functions (vector, deque,..)
 */
template <typename T>
T generate_jacob_indices(size_t size)
{
	T indices;
	size_t n = 0;
	while (jacobsthal(n) < size)
	{
		indices.push_back(jacobsthal(n));
		++n;
	}
	for (size_t i = 0; i < size; ++i)
	{
		if (std::find(indices.begin(), indices.end(), i) == indices.end())
			indices.push_back(i);
	}
	return (indices);
}

/**
 * @brief Insert the element in the pair using jacobsthal method
 * @param T pair container use in functions (vector, deque,..)
 * @param U container to fill
 * @note typedef are use for the iterator and value_type
 * @return 
 */
template <typename T>
void insert_element(T &main_chain, const T &pend)
{
	typedef typename T::value_type value_type;
	typedef typename T::iterator iterator;

	T indices = generate_jacob_indices<T>(pend.size());

	for (size_t i = 0; i < indices.size(); ++i)
	{
		if ((size_t)indices[i] >= pend.size())
			continue;

		value_type value = pend[indices[i]];

		iterator pos = main_chain.begin();
		while (pos != main_chain.end() && *pos < value)
			++pos;

		main_chain.insert(pos, value);
	}
}

/**
 * @brief Fill containers with the second value of the pair
 * @param T pair container use in functions (vector, deque,..)
 * @param U container to fill
 * @return 
 */
template <typename T>
void jacobfill(T &pair, T &w)
{
	size_t index;
	for (size_t i = 0; i < pair.size(); i++)
	{
		index = jacobsthal(i);
        
        index = std::min(index, pair.size() - 1);
		if (pair[i].second)
			w.push_back(std::make_pair(pair[i].second, index));
	}
	for (size_t i = 0; i < pair.size() - 1; i++)
	{
		if (pair[i].second > pair[i + 1].second)
			swap(pair[i], pair[i + 1]);
	}

}

/**
 * @brief Print the pairs
 * @param T pair container use in functions (vector, deque,..)
 * @return 
 */
template<typename T>
void print_pair(T &pair)
{
	for (size_t i = 0; i < pair.size(); ++i) {
        std::cout << "(" << pair[i].first << ", " << pair[i].second << ") ";
    }
	std::cout << std::endl;
}
