#include <iostream>
#include "Array.hpp"




int main()
{
    try
    {
        std::cout << "Create an Int array " << std::endl;
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
        std::cout << "Create String array " << std::endl;

        Array<std::string> objStr(5);
        for (int i = 0; i < 5; i++)
        {
            objStr[i] = "Vive les pâtes";
            std::cout << "obj[" << i << "] = " << objStr[i] << "\n";
        }
        std::cout << "obj[" << 12 << "] = " << objStr[12] << "\n";

    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }    
    try
    {
        std::cout << "Create Floats array " << std::endl;

        Array<float> objFloat(5);
        float i = 1.23;
        for (double j = 0; j < 5; j++)
        {
            objFloat[j] = i;
            std::cout << "obj[" << j << "] = " << objFloat[j] << "\n";
            i += 0.2;
        }
        std::cout << "Modifying array" << std::endl;

        Array<float> objfloat2(5);
        objfloat2 = objFloat;
        objfloat2[2] = 8;
        for (double j = 0; j < 5; j++)
        {
            std::cout << "obj1[" << j << "] = " << objFloat[j] << "\n";
            std::cout << "obj2[" << j << "] = " << objfloat2[j] << "\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

	return 0;
}

