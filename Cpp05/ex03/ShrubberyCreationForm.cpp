#include "ShrubberyCreationForm.hpp"

//=============Constructors && Destructor ======================


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137)
{
	this->_target = "default_target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) : AForm("Shrubbery", 145, 137)
{
	if (target.empty())
		throw(EmptyAForm());
	this->_target = target;
	std::cout << "ShrubbForm " << this->_name << " has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm(obj._name, obj._sign_required, obj._exec_required)
{
	this->_target = obj._target;
	std::cout << "Copy from " << this->_name << " has been created" << std::endl;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &old)
{
	if (this != &old)
	{
		this->_target = old._target;
		this->_is_signed = old._is_signed;
	}
	std::cout << "Operator constructor for ShrubbForm has been called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubbForm " << this->_name << " has been destroyed" << std::endl;
}

//=============Overload======================

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj)
{
	out << obj.getName() << ": grade required to sign it : " << obj.getSignRequired() \
	<< "\n grade recquired to execute it : " << obj.getExecRequired() \
	<< "\n is signed : " << obj.getIsSigned();
	return (out);
}

//=============Function ======================
 

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	
	if (this->_is_signed == true && executor.getGrade() <= this->_exec_required)
	{
		std::ofstream file((this->_target + "_shrubbery").c_str());
		if (!file)
			std::cerr << "Unable to open" << this->_target + "_shrubbery" << std::endl;
		else
		{
			file << "         &&&&&     " << std::endl;
			file << "      &&& && & &&" << std::endl;
			file << "   && &\\/&\\|& ()|/ @, &&"  << std::endl;
			file << "   &\\/(/&/&||/& /_/)_&" << std::endl ;
			file << " &() &\\/&|()|/&\\/ '%\" &" << std::endl;
			file << "&_\\/&|&||/&//|&_&'_&" << std::endl ;
			file << "&&   && & &| &| /& &" << std::endl;
			file << "       |||" << std::endl ;
			file << "       |||" << std::endl ;
			file << "       |||" << std::endl ;
			file << ", -=-~  .-^- _" << std::endl ;
			file.close();
		}
	}
	else
		if (this->_is_signed == false)
			throw(NotSignedForm());
		else
			throw(GradeTooLowExceptionAForm());
}
/*
       &&& &&  & &&
    && &\/&\|& ()|/ @, &&
    &\/(/&/&||/& /_/)_&
 &() &\/&|()|/&\/ '%" &
&_\/&|&||/&//|&_&'_&
&&   && & &| &| /& &
        |||
        |||
        |||
        |||
   , -=-~  .-^- _
*/