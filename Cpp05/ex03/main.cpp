#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "___Bureaucrat creations___" << std::endl;
	Bureaucrat boss =  Bureaucrat("boss", 1);
	Bureaucrat nottheboss =  Bureaucrat("looser", 150);
	std::cout << "\n" << std::endl;

	std::cout << "___Forms cretions___" << std::endl;
	ShrubberyCreationForm shrub;
	RobotomyRequestForm robot;
	PresidentialPardonForm pres;
	ShrubberyCreationForm shrubtwo;
	RobotomyRequestForm robottwo;
	PresidentialPardonForm prestwo;
	std::cout << "\n" << std::endl;



	std::cout << "___Form print___" << std::endl;
	// Show form properties
	std::cout << shrub << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << robot << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << pres << std::endl;
	std::cout << "\n" << std::endl;

	std::cout << "___Signing with qualified bureaucrat___" << std::endl;
	// Comment line below to get a failed execution because of not signed form
	boss.signForm(shrub);
	std::cout << "\n" << std::endl;
	boss.signForm(pres);
	std::cout << "\n" << std::endl;
	boss.signForm(robot);
	std::cout << "\n" << std::endl;

	std::cout << "___Form print___" << std::endl;
	// Show form properties
	std::cout << shrub << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << robot << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << pres << std::endl;
	std::cout << "\n" << std::endl;

	std::cout << "___Using with qualified bureaucrat___" << std::endl;

	boss.executeForm(shrub);
	std::cout << "\n" << std::endl;
	boss.executeForm(pres);
	std::cout << "\n" << std::endl;
	std::cout << "First use of robot " << std::endl; 
	boss.executeForm(robot);
	std::cout << "\n" << std::endl;
	std::cout << "Second use of robot " << std::endl; 
	boss.executeForm(robot);
	std::cout << "\n" << std::endl;
	std::cout << "Third use of robot " << std::endl; 
	boss.executeForm(robot);
	std::cout << "\n" << std::endl;

	std::cout << "___Try signing with unqualified bureaucrat___" << std::endl;
	nottheboss.signForm(shrubtwo);
	std::cout << "\n" << std::endl;
	nottheboss.signForm(prestwo);
	std::cout << "\n" << std::endl;
	nottheboss.signForm(robottwo);
	std::cout << "\n" << std::endl;

	std::cout << "___Form print___" << std::endl;
	// Show form properties
	std::cout << shrubtwo << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << robottwo << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << prestwo << std::endl;
	std::cout << "\n" << std::endl;


	std::cout << "___Try using with unqualified bureaucrat___" << std::endl;
	nottheboss.executeForm(shrubtwo);
	std::cout << "\n" << std::endl;
	nottheboss.executeForm(prestwo);
	std::cout << "\n" << std::endl;
	nottheboss.executeForm(robottwo);
	std::cout << "\n" << std::endl;

	std::cout << "___End___" << std::endl;


	
}