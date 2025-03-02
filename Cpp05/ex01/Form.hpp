#ifndef FORM_HPP
	#define FORM_HPP

#include <cstring>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class GradeTooHighExceptionForm 
{
	private:
		std::string _error;
	public:
		GradeTooHighExceptionForm();
		const std::string& what() const;
};

class GradeTooLowExceptionForm
{
	private:
		std::string _error;
	public:
		GradeTooLowExceptionForm();
		const std::string& what() const;
};

class EmptyForm
{
	private:
		std::string _error;
	public:
		EmptyForm();
		const std::string& what() const;
};

class AlreadySigned
{
	private:
		std::string _error;
	public:
		AlreadySigned();
		const std::string &what() const;
};

//////

class Form
{
	private:
	const std::string 	_name;
	bool 				_is_signed;
	const int			_sign_required;
	const int			_exec_required;
	public:
	// Constructor and destructor
		Form();
		Form(std::string name, int sign_required, int exec_required);
		Form(const Form &obj);
		Form &operator=(const Form &old);
		~Form();
	// Getter
		int			getSignRequired() const;
		int			getExecRequired() const;
		bool		getIsSigned() const;
		std::string	getName() const;
	// Functions
		void beSigned(const Bureaucrat &worker);


};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif