#include "MutantStack.hpp"
#include <iterator>
#include <iostream>

int main()
{
	std::cout << "Subject test" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);


	std::cout << "My tests " << std::endl;

    MutantStack<int> ms;

    ms.push(10);
    ms.push(20);
    ms.push(30);
    ms.push(40);
    std::cout << "After add 4 elements : " << std::endl;
    std::cout << "Top : " << ms.top() << std::endl; // Must print 40
    std::cout << "Stack size: " << ms.size() << std::endl; // Must print 4

    std::cout << "Iteration tests : ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
        std::cout << *it << " ";  // Must print 10 20 30 40
    }
    std::cout << std::endl;

    std::cout << "Itération test 2 ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
        std::cout << *it << " ";  // Must print 10 20 30 40
    }
    std::cout << std::endl;

    ms.pop();
    std::cout << "After pop : " << std::endl;
    std::cout << "Top : " << ms.top() << std::endl; // Must print 30
    std::cout << "Stack size : " << ms.size() << std::endl; // Must print 3

    std::cout << "Is stack empty ? " << (ms.empty() ? "Yes" : "No") << std::endl; // Must print "No"

    ms.pop();
    ms.pop();
    ms.pop();
    std::cout << "After drain the stack " << std::endl;
    std::cout << "Is stack empty ? " << (ms.empty() ? "Yes" : "No") << std::endl; // Must print "Yes"


    ms.push(50);
    ms.push(60);
    std::cout << "Readding elements : " << std::endl;
    std::cout << "Top : " << ms.top() << std::endl; // Must print 60
    std::cout << "Stack size : " << ms.size() << std::endl; // Must print 2

return 0;
}