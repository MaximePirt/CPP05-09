#include "RobotomyRequestForm.hpp"

const char *RobotomyFailed::what() const throw()
{
	return("No chance, next time will work!");
}

//=============Constructors && Destructor ======================


RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45)
{
	this->_target = "default_target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) : AForm("Robotomy", 72, 45)
{
	if (target.empty())
		throw(EmptyAForm());
	this->_target = target;
	std::cout << "RobotomyRequestForm " << this->_name << " has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj): AForm(obj._name, obj._sign_required, obj._exec_required)
{
	this->_target = obj._target;
	std::cout << "Copy from " << this->_name << " has been created" << std::endl;
}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &old)
{
	if (this != &old)
	{
		this->_target = old._target;
		this->_is_signed = old._is_signed;
	}
	std::cout << "Operator constructor for RobotomyRequestForm has been called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << this->_name << " has been destroyed" << std::endl;
}

//=============Overload======================

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &obj)
{
	out << obj.getName() << ": grade required to sign it : " << obj.getSignRequired() \
	<< "\n grade recquired to execute it : " << obj.getExecRequired() \
	<< "\n is signed : " << obj.getIsSigned();
	return (out);
}

//=============Function ======================
 

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static int i = 0;
	if (this->_is_signed == false && executor.getGrade() > this->_exec_required)
		throw(GradeTooLowExceptionAForm());
	i++;
	if (i % 2)
		std::cout << "zdriiiii zdriiii *drilling noise* " << this->_target << " has been robotomized." << std::endl;
	else
	{
		std::cout << "oh shout, robotomy of " << this->_target << " has failed." << std::endl;
		throw(RobotomyFailed());
	}
}