#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &obj)
{
	*this = obj;
}

Intern &Intern::operator=(const Intern &old)
{
	if (this != &old)
		*this = old;
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::shrubForm(std::string name)
{
	return (new ShrubberyCreationForm(name));
}	

AForm *Intern::robotForm(std::string name)
{
	return (new RobotomyRequestForm(name));
}	

AForm *Intern::presiForm(std::string name)
{
	return(new PresidentialPardonForm(name));
}	

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string	compare[3] = {"shrubbery request", "presidential request", "robotomy request"};
	AForm* (Intern::*res[3])(std::string);
	res[0] = &Intern::shrubForm;
	res[1] = &Intern::presiForm;
	res[2] = &Intern::robotForm;

	for(int i = 0; i < 3; i++)
	{
		if (name == compare[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*res[i])(target);
		}
	}
	std::cerr << "Intern wasn't able to create " << name << std::endl;
	return (NULL);
}	