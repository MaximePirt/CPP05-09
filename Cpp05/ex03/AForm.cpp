#include "AForm.hpp"

//=============Exceptions======================

const char *GradeTooHighExceptionAForm::what() const throw()
{
	return("Grade too high");
}

const char *GradeTooLowExceptionAForm::what() const throw()
{
	return("Grade too low");
}

const char *AlreadySigned::what() const throw()
{
	return("Form is already signed, no need to sign it twice");
}

const char *EmptyAForm::what() const throw()
{
	return("Form is empty, cannot initialized it");
}

const char *NotSignedForm::what() const throw()
{
	return("Form hasn't been signed before use");	
}
//=============Constructors && Destructor ======================


AForm::AForm(): _name("default"), _is_signed(false), _sign_required(150), _exec_required(150)
{
	throw(EmptyAForm());
}

AForm::AForm(std::string name, int sign_required, int exec_required) : 
	_name(name),  _is_signed(false), _sign_required(sign_required), _exec_required(exec_required)
{
	if (sign_required < 1 || exec_required < 1)
		throw(GradeTooHighExceptionAForm());
	if (sign_required > 150 || exec_required > 150)
		throw(GradeTooLowExceptionAForm());
	std::cout << "AForm " << this->_name << " has been created" << std::endl;
}

AForm::AForm(const AForm &obj):
_name(obj._name), _is_signed(obj._is_signed), _sign_required(obj._sign_required), _exec_required(obj._exec_required)

{
	std::cout << "Copy from " << this->_name << " has been created" << std::endl;
}


AForm &AForm::operator=(const AForm &old)
{
	if (this != &old)
	{
		this->_is_signed = old._is_signed;
	}
	std::cout << "Operator constructor for AForm has been called" << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm " << this->_name << " has been destroyed" << std::endl;
}

//=============Getters======================

int AForm::getSignRequired() const
{
	return (this->_sign_required);
}

int AForm::getExecRequired() const
{
	return (this->_exec_required);
}

bool AForm::getIsSigned() const
{
	return (this->_is_signed);
}

std::string AForm::getName() const
{
	return (this->_name);
}

//=============Overload======================

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
	out << obj.getName() << ": grade required to sign it : " << obj.getSignRequired() \
	<< "\n grade recquired to execute it : " << obj.getExecRequired() \
	<< "\n is signed : " << obj.getIsSigned();
	return (out);
}

//=============Functions to modify grade ======================
 
void AForm::beSigned(const Bureaucrat &worker)
{
	if (this->_is_signed)
		throw(AlreadySigned());
	if (this->_sign_required < worker.getGrade())
		throw(GradeTooLowExceptionAForm());
	this->_is_signed = true;
}

