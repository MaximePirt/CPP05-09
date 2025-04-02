#include "RPN.hpp"

// Constructor and Destructor
// ------------------------------------------------
RPN::RPN()
{
}
RPN::RPN(const RPN &obj)
{
	*this = obj;
}
RPN &RPN::operator=(const RPN &old)
{
	if (this != &old)
	{
		this->_stack = old._stack;
	}
	return (*this);
}
RPN::~RPN()
{
}

// ------------------------------------------------
// Member functions

std::stack<int> parse(std::string input)
{
	std::stack<int> stack;
	std::stringstream ss(input);
	std::string token;
	while (ss >> token)
	{
		if (isdigit(token[0]))
		{
			size_t len = token.length();
			for (size_t i = 0; i < len; ++i)
			{
				if (token[i] == '0')
				{
					token.erase(i, 1);
					--i;
				}
			}
			if (token.length() == 0 || token.length() > 1)
				throw std::runtime_error("Error: Invalid number");
			double value = stringToValue<double>(token);
			if (value < 0)
				throw std::runtime_error("Error: Negative number");
			if (value > 9)
				throw std::runtime_error("Error: Number too large");
			stack.push(value);
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: Not enough operands");
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			t_calc<int> calc(a, b, token[0]);
			int result = calc.c();
			stack.push(result);
		}
		else
			throw std::runtime_error("Error: Invalid token");
	}
	return (stack);
}

void RPN::Calculate(std::string input)
{
	this->_stack = parse(input);
	if (this->_stack.size() != 1)
		throw std::runtime_error("Error: Invalid expression, stack size not 1");
	std::cout << this->_stack.top() << std::endl;
	this->_stack.pop();
	if (!this->_stack.empty())
		throw std::runtime_error("Error: Invalid expression, stack not empty");
	return ;
}