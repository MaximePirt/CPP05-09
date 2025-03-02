#include "Bureaucrat.hpp"


int main()
{
	std::cout << "Bureaucrat creation" << std::endl;
	try{
		Bureaucrat first =  Bureaucrat("first", 149);
		Bureaucrat second =  Bureaucrat("second", 2);

		second.IncrementGrade();
		first.DecrementGrade();

		std::cout << "\n\nHere is first bureaucrat overload" << std::endl;
		std::cout << first << std::endl;
		std::cout << "\n\nHere is second bureaucrat overload" << std::endl;
		std::cout << second << std::endl;
		//This will fail, grade too high and too low
		// second->IncrementGrade();
		// first->DecrementGrade();

		// Theses will fail : constructor failure because of grade or name
		// Bureaucrat third = Bureaucrat("third_fail", 0);
		// Bureaucrat fourth = Bureaucrat("fourth_fail", 156);
		// Bureaucrat();
	}
	catch(const GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const NoNameException& e)
	{
		std::cerr << e.what() << std::endl;

	}

}