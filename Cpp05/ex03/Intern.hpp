#ifndef INTERN_HPP
	#define INTERN_HPP


#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

class Intern
{
	private:
	public:
	//Constructor
		Intern();
		Intern(const Intern &obj);
		Intern &operator=(const Intern &old);
		~Intern();
	//Intern mission
		AForm *shrubForm(std::string name);
		AForm *presiForm(std::string name);
		AForm *robotForm(std::string name);
		AForm *makeForm(std::string name, std::string target);
};

#endif