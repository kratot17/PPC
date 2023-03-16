#include <iostream>
#include <fstream> // streamove cteni/zapis souboru

int main()
{
    std::ifstream in ("01-io.cpp");
    std::ofstream out ("COPY-OF-01-io.cpp");

    if (in.good())
    {
        std::cout << "soubor byl otevren pro cteni" << std::endl;

        std::string s;

        while (getline(in, s)) // dokud jsme schopni prepsat radek ze souboru do stringu
        {
            std::cout << s << std::endl; // nacteny radek posleme do terminalu
            out << s << std::endl; // nacteny radek posleme do vystupniho fstreamu
        }
    }
    return 0;
}