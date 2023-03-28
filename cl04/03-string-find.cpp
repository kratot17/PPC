#include <iostream>

int main()
{
    std::string a = "Ahoj lidi, jak se dnes mate mezi lidmi";
    std::string b = "lid";

    std::size_t found = a.find(b);
    if (found != std::string::npos)
        std::cout << "prvni 'lid' nalezen na: " << found << '\n';

    found = a.find(b, found + 1);
    if (found != std::string::npos)
        std::cout << "dalsi 'lid' nalezen na: " << found << '\n';

    return 0;
}