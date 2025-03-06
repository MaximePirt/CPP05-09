#include "Bureaucrat.hpp"

//=============Exceptions======================

GradeTooHighException::GradeTooHighException()
{
	this->error = "Grade too high for a Bureaucrat";
}

const std::string &GradeTooHighException::what() const
{
	return (this->error);
}

GradeTooLowException::GradeTooLowException()
{
	this->error = "Grade too low for a Bureaucrat";
}

const std::string &GradeTooLowException::what() const
{
	return (this->error);
}

NoNameException::NoNameException()
{
	this->error = "You forgot to put a name to this poor Bureaucrat";
}

const std::string &NoNameException::what() const
{
	return (this->error);
}


//=============Constructors && Destructor ======================


Bureaucrat::Bureaucrat(){
	throw(NoNameException());
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if(name.empty())
		throw(NoNameException());
	if (grade < 1)
		throw(GradeTooHighException());
	if (grade > 150)
		throw(GradeTooLowException());
	const_cast<std::string&>(this->name) = name;
	this->grade = grade;
	std::cout << this->name << " has been created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name), grade(obj.grade)
{
	std::cout << "Copy constructor for " << this->name << " has been called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &old)
{
	if (this != &old)
	{
		this->grade = old.grade;
		const_cast<std::string&>(this->name) = old.name;
	}
	std::cout << "Operator= constructor for " << this->name << " has been called." << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A bureaucrat named " << this->name << " is destroyed" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (out);
}

//=============Getters======================

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

//=============Functions to modify grade ======================

void Bureaucrat::DecrementGrade()
{
	if (this->grade + 1 > 150)
		throw(GradeTooLowException());
	this->grade++;
	std::cout << this->name << " has been unpromoted to grade " << this->grade << std::endl;
}

void Bureaucrat::IncrementGrade()
{
	if (this->grade - 1 < 1)
		throw(GradeTooHighException());
	this->grade--;
	std::cout << this->name << " has been promoted to grade " << this->grade << std::endl;

}