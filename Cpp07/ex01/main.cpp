#include <iostream>
#include "iter.hpp"


void ft_is_number(char &c)
{
	if (c >= '0' && c <= '9')
	{
		std::cout << "NUMBER" << std::endl;
	}
	else
		std::cout << "Not number" << std::endl;
}
	
void increment(int &n)
{
    n++;
}

void double_value(float &f)
{
    f *= 2;
}

void print_char(char &c)
{
    std::cout << c << " ";
}



int main()
{
    std::cout << "Test 1 : is number" << std::endl;
    char str[] = "Th1s 1s n0t numb3r";
    size_t len_str = strlen(str);
    ::iter(str, len_str, ft_is_number);
    std::cout << std::endl;

    std::cout << "Test 2 : Incrementation" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    size_t len_numbers = sizeof(numbers) / sizeof(numbers[0]);
    ::iter(numbers, len_numbers, increment);
    ::iter(numbers, len_numbers, print_number<int>);
    std::cout << std::endl << std::endl;

    std::cout << "Test 3 : multiply floats" << std::endl;
    float floats[] = {1.5, 2.0, 3.25, 4.75};
    size_t len_floats = sizeof(floats) / sizeof(floats[0]);
    ::iter(floats, len_floats, double_value);
    ::iter(floats, len_floats, print_number<float>);
    std::cout << std::endl << std::endl;

    std::cout << "Test 4 : print characters" << std::endl;
    char sentence[] = "Hello, world!";
    size_t len_sentence = strlen(sentence);
    ::iter(sentence, len_sentence, print_char);
    std::cout << std::endl << std::endl;

    std::cout << "Test 5 : printing doubles " << std::endl;
    double doubles[] = {3.1415, 2.718, 1.414, 0.577};
    size_t len_doubles = sizeof(doubles) / sizeof(doubles[0]);
    ::iter(doubles, len_doubles, print_number<double>);
    std::cout << std::endl;

    return 0;
}