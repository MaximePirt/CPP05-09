#include "Form.hpp"


int main()
{
	std::cout << "___Bureaucrat creations___" << std::endl;
	Bureaucrat boss =  Bureaucrat("boss", 10);
	Bureaucrat nottheboss =  Bureaucrat("looser", 100);
	try{
		std::cout << "___Form creation___" << std::endl;
		Form highlevelform = Form("classic", 12, 12);
		std::cout << "====Now it ll be signed====" << std::endl;
		boss.signForm(highlevelform);
		std::cout << highlevelform << std::endl;

		// Theses tests will throw an error

		// Signing twice
		// boss.signForm(highlevelform);

		// Signing from a not allowed bureaucrat
		// highlevelform.beSigned(nottheboss);

		// Empty form
		// Form impossibleform = Form();
		
		// Form toohighlevelform = Form("impossible", 0, 0);
		// Form toolowlevelform = Form("nonono", 151, 200);

	}
	catch(const GradeTooHighExceptionForm& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const GradeTooLowExceptionForm& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const EmptyForm& e)
	{
		std::cerr << e.what() << std::endl;

	}
	catch(const AlreadySigned& e)
	{
		std::cerr << e.what() << std::endl;
	}

}