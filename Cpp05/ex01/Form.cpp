#include "Form.hpp"

//=============Exceptions======================


GradeTooHighExceptionForm::GradeTooHighExceptionForm()
{
	this->_error = "Grade too high";
}

const std::string &GradeTooHighExceptionForm::what() const
{
	return (this->_error);
}

GradeTooLowExceptionForm::GradeTooLowExceptionForm()
{
	this->_error = "Grade too low";
}

const std::string &GradeTooLowExceptionForm::what() const
{
	return (this->_error);
}

AlreadySigned::AlreadySigned()
{
	this->_error = "Form is already signed, no need to sign it twice";
}

const std::string &AlreadySigned::what() const
{
	return (this->_error);
}

EmptyForm::EmptyForm()
{
	this->_error = "Form is empty, cannot initialized it";
}

const std::string &EmptyForm::what() const
{
	return (this->_error);
}

//=============Constructors && Destructor ======================


Form::Form(): _name("default"), _is_signed(false), _sign_required(0), _exec_required(0)
{
	throw(EmptyForm());
}

Form::Form(std::string name, int sign_required, int exec_required) : 
	_name(name),  _is_signed(false), _sign_required(sign_required), _exec_required(exec_required)
{
	if (sign_required < 1 || exec_required < 1)
		throw(GradeTooHighExceptionForm());
	if (sign_required > 150 || exec_required > 150)
		throw(GradeTooLowExceptionForm());
	std::cout << "Form " << this->_name << " has been created" << std::endl;
}

Form::Form(const Form &obj):
_name(obj._name), _is_signed(obj._is_signed), _sign_required(obj._sign_required), _exec_required(obj._exec_required)

{
	std::cout << "Copy from " << this->_name << " has been created" << std::endl;
}


Form &Form::operator=(const Form &old)
{
	if (this != &old)
	{
		this->_is_signed = old._is_signed;
	}
	std::cout << "Operator constructor for Form has been called" << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " has been destroyed" << std::endl;
}

//=============Getters======================

int Form::getSignRequired() const
{
	return (this->_sign_required);
}

int Form::getExecRequired() const
{
	return (this->_exec_required);
}

bool Form::getIsSigned() const
{
	return (this->_is_signed);
}

std::string Form::getName() const
{
	return (this->_name);
}

//=============Overload======================

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
	out << obj.getName() << ": grade required to sign it : " << obj.getSignRequired() \
	<< "\n grade recquired to execute it : " << obj.getExecRequired() \
	<< "\n is signed : " << obj.getIsSigned();
	return (out);
}

//=============Functions to modify grade ======================
 
void Form::beSigned(const Bureaucrat &worker)
{
	if (this->_is_signed)
		throw(AlreadySigned());
	if (this->_sign_required < worker.getGrade())
		throw(GradeTooLowExceptionForm());
	this->_is_signed = true;
}
