#include "Bureaucrat.hpp"
#include "AForm.hpp"

//=============Exceptions======================

const char *GradeTooHighException::what() const throw()
{
	return("Grade too high for a Bureaucrat");	
}

const char *GradeTooLowException::what() const throw()
{
	return("Grade too low for a Bureaucrat");
}

const char *NoNameException::what() const throw()
{
	return ( "You forgot to put a name to this poor Bureaucrat");
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

//New function
void Bureaucrat::signForm(AForm &contract)
{
	if (this->grade <= contract.getSignRequired())
	{
		contract.beSigned(*this);
		std::cout << this->name << " signed " << contract.getName() << std::endl;
	}
	else
		std::cout << this->name << " couldn't sign " << contract.getName() << " because its grade is too low" << std::endl;
	
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << this->name << " failed to execute " << form.getName() << " because of " << e.what() << std::endl;
	}
}