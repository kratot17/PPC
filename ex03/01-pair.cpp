#include <iostream>

void vypis_par(std::pair<std::string, int> x)
{
    std::cout << "x.first: " << x.first << " \tx.second: " <<  x.second << std:: endl;
}

void vypis_par_ref(const std::pair<std::string, int> & x)
{
    std::cout << "x.first: " << x.first << " \tx.second: " <<  x.second << std:: endl;
}

int main()
{
    std::pair<std::string, int> p1("David", 1);
    std::pair<std::string, int> p2 = std::make_pair("Divis", 2);
    std::pair<std::string, double> p3 = {"Ludolf", 3.14};
    auto p4 = std::pair<std::string, int>();
    p4.first = "Fiala";
    p4.second = 3;

    std::cout << "p1.first: " << p1.first << " \tp1.second: " <<  p1.second << std:: endl;
    std::cout << "p2.first: " << p2.first << " \tp2.second: " <<  p2.second << std:: endl;
    std::cout << "p3.first: " << p3.first << " \tp3.second: " <<  p3.second << std:: endl;
    std::cout << "p4.first: " << p4.first << " \tp4.second: " <<  p4.second << std:: endl;

    vypis_par(std::make_pair("ABC",123));
    vypis_par_ref(std::make_pair("XYZ",987));

    return 0;
}
