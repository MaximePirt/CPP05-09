#ifndef RPN_HPP
	#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

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

template <typename T>
struct t_calc
{
	T a;
	T b;
	char op;

	t_calc(T a, T b, char op) : a(a), b(b), op(op) {
		if (op != '+' && op != '-' && op != '*' && op != '/')
			throw std::runtime_error("Error: Invalid operator");
	}

	T c()
	{
		switch(op)
		{
			case '+':
				return a + b;
			case '-':
				return a - b;
			case '*':
				return a * b;
			case '/':
				return b != 0 ? a / b : 0;
			default:
				throw std::runtime_error("Error: Invalid operator");
		}
	}
};

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN &obj);
		RPN &operator=(const RPN &old);
		~RPN();
		void Calculate(std::string input);

};


#endif