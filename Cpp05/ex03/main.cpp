#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "___Subject test___" << std::endl;
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;

	std::cout << "___Mytest___" << std::endl;
	std::cout << "\n___Success Creation___" << std::endl;

	Intern slave;
	AForm *form;
	Bureaucrat boss("boss", 2);
	form = slave.makeForm("presidential request", "nobody");
	if (!form)
	{
		std::cerr << "Error during form creation" << std::endl;
		return (1);
	}
	boss.signForm(*form);
	std::cout << *form << std::endl;
	try
	{
		form->execute(boss);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete form;


	std::cout << "___Failed creation___" << std::endl;

	AForm *formtwo;
	formtwo= slave.makeForm("blablafail", "nobody");
	if (!formtwo)
	{
		std::cerr << "Error during formtwo creation" << std::endl;
		return (1);
	}
	boss.signForm(*formtwo);
	std::cout << *formtwo << std::endl;
	try
	{
		formtwo->execute(boss);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete formtwo;

	std::cout << "___End___" << std::endl;
	
}