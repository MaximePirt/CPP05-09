#ifndef ROBOTOMYREQUESTFORM_HPP
	#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyFailed : public std::exception 
{
	private:
	public :
		const char *what() const throw();
};

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &old);
		~RobotomyRequestForm();
		void 	execute(Bureaucrat const & executor) const;
};

#endif
