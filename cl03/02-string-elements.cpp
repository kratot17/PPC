#include <iostream>

int main()
{
    std::string s1 = "Ahoj PRP";

    for (auto &x : s1)
    {
        std::cout << x << " ";
        x = 'x';
    }
    std::cout << std::endl;
    std::cout << s1 << std::endl;

    for (int i = 0; i < 20; i++)
    {
        std::cout << s1[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 20; i++)
    {
        try {
            std::cout << s1.at(i) << " ";
        }
        catch (std::out_of_range) {
            std::cout << "\nout of range (i = " << i << ")";
            break;
        }
    }
    std::cout << std::endl;

    return 0;
}