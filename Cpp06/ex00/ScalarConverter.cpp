#include "ScalarConverter.hpp"


// Constructor and destructor

ScalarConverter::ScalarConverter(){

}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &old)
{
	(void)old;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

// enum

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	ZERO,
	ERROR
};

// functions

/**
 * @brief check presence of charset in str
 * @return 0 if only charset, 1 if not
 */
int	ft_str_is_charset(std::string str, const std::string charset)
{
	int	i;
	int	j;
	int	valide;

	i = 0;
	while (str[i])
	{
		j = 0;
		valide = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				valide = 1;
			j++;
		}
		if (!valide)
			return (1);
		i++;
	}
	return (0);
}

int	supertoi(char *str)
{
	long	i;
	long	j;
	long	z;

	i = 0;
	j = 1;
	z = 0;
	if (strlen(str) > 11)
		return (DOUBLE);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		j *= -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		z = z * 10 + (str[i] - '0');
		i++;
	}
	z *= j;
	if (z > 2147483647 || z < -2147483648)
		return (DOUBLE);
	return (INT);
}

int find_type(std::string arg)
{
	if (arg.size() > 20)
		return (ERROR);
	if (arg == "-inff" || arg == "+inff")
		return (FLOAT);
	if (arg == "-inf" || arg == "+inf" || arg == "nan")
		return (DOUBLE);
	if (ft_str_is_charset(arg, "0123456789f.-+"))
	{
		if (arg.size() > 1)
			return (ERROR);
		return (CHAR);
	}
	if (!ft_str_is_charset(arg, "0123456789-+"))
	{
		int i;
		for (i = 0; arg[i] == '0'; i++)
			;
		if (!arg[i])
			return (ZERO);
		char tmp[100];
		for(int j = 0; arg[i]; j++)
		{
			tmp[i] = arg[j];
			i++;
		}
		if (supertoi(tmp) == INT)
			return(INT);
		return(DOUBLE);
	}
	if (!ft_str_is_charset(arg, "0123456789f.-+f") && arg.size() > 1)
		return (FLOAT);
	return (CHAR);
}

void ScalarConverter::convert(std::string literal){

	
	int type = find_type(literal);
	switch (type){
		case CHAR:
		{
				std::cout << "char : " << literal[0] << std::endl;
				std::cout << "int : " << static_cast<int>(literal[0]) << std::endl;
				std::cout << "float : " << static_cast<float>(literal[0]) << std::endl;
				std::cout << "double : " << static_cast<double>(literal[0]) << std::endl;
			break ;
		}
		case INT:
		{
			int nb = strtod(literal.c_str(), NULL);
			if (nb > 32 && nb < 128)
				std::cout << "char : " << static_cast<char>(nb) << std::endl;
			else
			std::cout << "char = Non displayable"<< std::endl;
			std::cout << "int : " << static_cast<int>(nb) << std::endl;
			std::cout << "float : " << static_cast<float>(nb) << ".0f" << std::endl;
			std::cout << "double : " << static_cast<double>(nb) << std::endl;
			break ;
		}
		case FLOAT:
		{
			if (literal == "-inff")
			{
				double nb = -HUGE_VAL;
				std::cout << "char : impossible"<< std::endl;
				std::cout << "int : impossible"<< std::endl;
				std::cout << "float : " << static_cast<float>(nb) << std::endl;
				std::cout << "double : " << static_cast<double>(nb) << std::endl;
				break ;
			}
			else if (literal == "+inff")
			{
				double nb = HUGE_VAL;
				std::cout << "char : impossible"<< std::endl;
				std::cout << "int : impossible"<< std::endl;
				std::cout << "float : " << static_cast<float>(nb) << std::endl;
				std::cout << "double : " << static_cast<double>(nb) << std::endl;
				break ;

			}
			float nb = strtod(literal.c_str(), NULL);
			if (nb > 32 && nb < 128)
				std::cout << "char : " << static_cast<char>(nb) << std::endl;
			else
			std::cout << "char = Non displayable"<< std::endl;
			std::cout << "int : " << static_cast<int>(nb) << std::endl;
			std::cout << "float : " << static_cast<float>(nb) << "f" << std::endl;
			std::cout << "double : " << static_cast<double>(nb) << std::endl;
			break ;
		}
		case DOUBLE:
		{
			if (literal == "-inf")
			{
				double nb = -HUGE_VALL;
				std::cout << "char : impossible"<< std::endl;
				std::cout << "int : impossible"<< std::endl;
				std::cout << "float : " << static_cast<float>(nb) << std::endl;
				std::cout << "double : " << static_cast<double>(nb) << std::endl;
				break ;
			}
			else if (literal == "+inf")
			{
				double nb = HUGE_VALL;
				std::cout << "char : impossible"<< std::endl;
				std::cout << "int : impossible"<< std::endl;
				std::cout << "float : " << static_cast<float>(nb) << std::endl;
				std::cout << "double : " << static_cast<double>(nb) << std::endl;
				break ;

			}
			else if (literal == "nan")
			{
				std::cout << "char : impossible"<< std::endl;
				std::cout << "int : impossible"<< std::endl;
				std::cout << "float : nanf"<< std::endl;
				std::cout << "double : nan"<< std::endl;
				break ;
			}
			double nb = strtod(literal.c_str(), NULL);
			if (nb > 32 && nb < 128)
				std::cout << "char : " << static_cast<char>(nb) << std::endl;
			else
			std::cout << "char = Non displayable"<< std::endl;
			std::cout << "int : " << static_cast<int>(nb) << std::endl;
			std::cout << "float : " << static_cast<float>(nb) << "f" << std::endl;
			std::cout << "double : " << static_cast<double>(nb) << std::endl;
			break ;
		}
		case ZERO:
		{
			std::cout << "char : Non displayable" << std::endl;
			std::cout << "int : " << static_cast<int>(0) << std::endl;
			std::cout << "float : " << static_cast<float>(0) << "f" << std::endl;
			std::cout << "double : " << static_cast<double>(0) << std::endl;
			break ;
		}
		case ERROR:
		{

			std::cout << "result ERROR" << std::endl;
		}
	}
}

