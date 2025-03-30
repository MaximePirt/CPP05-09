#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    

void testBasic()
{
    std::cout << "\n===== Subject test =====" << std::endl;
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Will be 2 (11 - 9)
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // Will be 14 (17 - 3)
}

void testExceptionStorageFull()
{
    std::cout << "\n===== Test Storage Full Capacity =====" << std::endl;
    Span sp(3);

    try {
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4); // Throw an exception
    }
    catch (const std::exception &e) {
        std::cerr << "Exception  : " << e.what() << std::endl;
    }
}

void testExceptionNotEnoughNumbers()
{
    std::cout << "\n===== Test impossible Span =====" << std::endl;
    Span sp(5);

    try {
        sp.shortestSpan();
    }
    catch (const std::exception &e) {
        std::cerr << "Exception catch (void) : " << e.what() << std::endl;
    }

    sp.addNumber(42);
    try {
        sp.shortestSpan();
    }
    catch (const std::exception &e) {
        std::cerr << "Exception catch (1 element) : " << e.what() << std::endl;
    }
}

void testAddRange()
{
    std::cout << "\n===== Test Ajout par Plage =====" << std::endl;
    Span sp(10);
    std::vector<int> numbers;

    numbers.push_back(5);
    numbers.push_back(10);
    numbers.push_back(15);
    numbers.push_back(20);
    numbers.push_back(25);

    sp.addNumber(numbers.begin(), numbers.end()); 
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Must be 5
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // Must be 20
}

void testAddLargeRange()
{
    std::cout << "\n===== Test Ajout Massif =====" << std::endl;
    Span sp(10000);
    std::vector<int> largeNumbers;

    for (int i = 0; i < 10000; i++)
        largeNumbers.push_back(rand() % 100000);

    sp.addNumber(largeNumbers.begin(), largeNumbers.end());

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

int main()
{
    srand(time(0));

    testBasic();
    testExceptionStorageFull();
    testExceptionNotEnoughNumbers();
    testAddRange();
    testAddLargeRange();

    return (0);
}
