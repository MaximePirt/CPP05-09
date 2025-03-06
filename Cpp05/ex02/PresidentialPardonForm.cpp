#include "PresidentialPardonForm.hpp"

//=============Constructors && Destructor ======================


PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5)
{
	this->_target = "default_target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string &target) : AForm("Presidential", 25, 5)
{
	if (target.empty())
		throw(EmptyAForm());
	this->_target = target;
	std::cout << "PresidentialForm " << this->_name << " has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): AForm(obj._name, obj._sign_required, obj._exec_required)
{
	this->_target = obj._target;
	std::cout << "Copy from " << this->_name << " has been created" << std::endl;
}


PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &old)
{
	if (this != &old)
	{
		this->_target = old._target;
		this->_is_signed = old._is_signed;
	}
	std::cout << "Operator constructor for PresidentialForm has been called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialForm " << this->_name << " has been destroyed" << std::endl;
}

//=============Overload======================

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &obj)
{
	out << obj.getName() << ": grade required to sign it : " << obj.getSignRequired() \
	<< "\n grade recquired to execute it : " << obj.getExecRequired() \
	<< "\n is signed : " << obj.getIsSigned();
	return (out);
}

//=============Function ======================
 

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->_is_signed == true && executor.getGrade() <= this->_exec_required)
	{
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw(GradeTooLowExceptionAForm());
}
//Informs that <target> has been pardoned by Zaphod Beeblebrox.