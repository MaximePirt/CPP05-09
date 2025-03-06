#ifndef BUREAUCRAT_HPP
	#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cstring>

class AForm;

class GradeTooHighException : public std::exception
{
	public:
		const char *what() const throw();
	private:
};

class GradeTooLowException : public std::exception
{
	public:
		const char *what() const throw();
	private:
};

class NoNameException : public std::exception
{
	public:
		const char *what() const throw();
	private:
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
		void signForm(AForm &contract);
		void executeForm(AForm const & form);
	protected:

	private:
		const std::string name;
		int	grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif