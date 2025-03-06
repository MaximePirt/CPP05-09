#ifndef AForm_HPP
	#define AForm_HPP

#include <cstring>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class GradeTooHighExceptionAForm : public std::exception
{
	private:
	public:
		const char *what() const throw();
};

class GradeTooLowExceptionAForm : public std::exception
{
	private:
	public:
		const char *what() const throw();
};

class EmptyAForm : public std::exception
{
	private:
	public:
		const char *what() const throw();
};

class AlreadySigned : public std::exception
{
	private:
	public:
		const char *what() const throw();
};

class NotSignedForm : public std::exception
{
	private:
	public:
		const char *what() const throw();
};

//////

class AForm
{
	protected:
		const std::string 	_name;
		bool 				_is_signed;
		const int			_sign_required;
		const int			_exec_required;
	public:
	// Constructor and destructor
		AForm();
		AForm(std::string name, int sign_required, int exec_required);
		AForm(const AForm &obj);
		AForm &operator=(const AForm &old);
		virtual ~AForm();
	// Getter
		int			getSignRequired() const;
		int			getExecRequired() const;
		bool		getIsSigned() const;
		std::string	getName() const;
	// Functions
		virtual void 	beSigned(const Bureaucrat &worker);
		virtual void 	execute(Bureaucrat const & executor) const = 0;


};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif