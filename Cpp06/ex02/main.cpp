#include <iostream>
#include <random>
#include <cstdint>
/////////
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

//Functions
/**
 * @brief: Create a random base class
 * @return A if rand %3 = 0
 * 			B if 1
 * 			C if 2
 */
Base* generate(void)
{
	srand(time(0));
	int res = rand() %3;
	if (res == 0)
		return (new A);
	else if (res == 1)
		return (new B);
	else
		return(new C);
}


void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Base type is A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Base type is B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Base type is C" << std::endl;
	else
		std::cerr << "Error, base type not found" << std::endl;
	return ;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Base type is A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "Base type is B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "Base type is C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error, base type not found" << std::endl;
			}
		}
	}
	return ;

	
}


/**
 * @brief main program
 * 	Relaunch program multiples times to better 
 */
int main()
{
	std::cout << "Base Generation" << std::endl;
	Base *basePtr = generate();



    std::cout << "basePtr = " << basePtr << std::endl;
    identify(basePtr);
    identify(*basePtr);
	//To see error catching when putting wrong type, unset flags in compilations
	// identify(false);

    delete basePtr;
	std::cout << "END TESTS" << std::endl;

    return 0;
}
