#include <stdio.h>
#include <iostream>

class Config
{
    int min, max, width, align;
};

int main ()
{
    int input;
    while (1)
    {
        std::cin >> input;
        if (std::cin.good())
        {
            std::cout << "Your input is: " << input << std::endl;
        }
        else
            std::cout << "Wrong input try again." << std::endl;
    }
    return 0;
}
