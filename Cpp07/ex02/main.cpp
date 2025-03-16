#include <iostream>
#include "Array.hpp"




int main()
{
    try
    {
        Array<int> objInt(5);
        for (int i = 0; i < 5; i++)
        {
            objInt[i] = int(i);
            std::cout << "obj[" << i << "] = " << objInt[i] << "\n";
        }
        std::cout << "obj[" << 12 << "] = " << objInt[12] << "\n";

    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        Array<std::string> objInt(5);
        for (int i = 0; i < 5; i++)
        {
            objInt[i] = "Vive les pâtes";
            std::cout << "obj[" << i << "] = " << objInt[i] << "\n";
        }
        std::cout << "obj[" << 12 << "] = " << objInt[12] << "\n";

    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }    
    try
    {
        Array<float> objInt(5);
        float i = 1.23;
        for (double j = 0; j < 5; j++)
        {
            objInt[j] = i;
            std::cout << "obj[" << j << "] = " << objInt[j] << "\n";
            i += 0.2;
        }
        std::cout << "obj[" << 12 << "] = " << objInt[12] << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

	return 0;
}

