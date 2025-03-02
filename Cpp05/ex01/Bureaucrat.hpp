#ifndef BUREAUCRAT_HPP
	#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cstring>

class Form;

class GradeTooHighException 	
{
	public:
		GradeTooHighException();
		const std::string& what() const;
	private:
		std::string error;
};

class GradeTooLowException 
{
	public:
		GradeTooLowException();
		const std::string& what() const;
	private:
		std::string error;
};

class NoNameException
{
	public:
		NoNameException();
		const std::string& what() const;
	private:
		std::string error;
};

class Bureaucrat
{
	public:
	//Constructor
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &old);
		~Bureaucrat();
	//Getter
		std::string getName() const;
		int getGrade() const;
	//Functions
		void IncrementGrade();
		void DecrementGrade();
	//New function
		void signForm(Form &contract);
	protected:

	private:
		std::string name;
		int	grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif