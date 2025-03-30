#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::cout << "=== Testing with std::vector<int> ===" << std::endl;
    int arr1[] = {1, 8, 2, 4, 11, 2};
    std::vector<int> vec(arr1, arr1 + sizeof(arr1) / sizeof(int));

    try {
        std::cout << "First occurrence of 2: " << easyfind(vec, 2) << std::endl;
        std::cout << "First occurrence of 11: " << easyfind(vec, 11) << std::endl;
        std::cout << "Try finding 12: " << easyfind(vec, 12) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing with std::list<int> ===" << std::endl;
    int arr2[] = {5, 10, 15, 20, 25};
    std::list<int> lst(arr2, arr2 + sizeof(arr2) / sizeof(int));

    try {
        std::cout << "First occurrence of 10: " << easyfind(lst, 10) << std::endl;
        std::cout << "Try finding 30: " << easyfind(lst, 30) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing with std::deque<int> ===" << std::endl;
    int arr3[] = {42, 55, 67, 89, 100};
    std::deque<int> deq(arr3, arr3 + sizeof(arr3) / sizeof(int));

    try {
        std::cout << "First occurrence of 67: " << easyfind(deq, 67) << std::endl;
        std::cout << "Try finding 200: " << easyfind(deq, 200) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing with an empty std::vector<int> ===" << std::endl;
    std::vector<int> emptyVec;

    try {
        std::cout << "Try finding 1 in an empty container: " << easyfind(emptyVec, 1) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
