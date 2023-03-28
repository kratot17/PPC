#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>

namespace table
{
    std::string line ()
    {
        std::stringstream ss;
        ss << "+" << std::string (10, '-') << "+" << std::string(10, '-') << "+" << std::string(10, '-') << "+\n";
        return ss.str();
    }
}

struct Auto
{
    int motor;
    int dvere;
    std::string znacka;

    Auto (const char * a, int b, int c) : znacka (a), motor(b), dvere(c) {}
};

std::ostream & operator<< (std::ostream & p, Auto * a)
{
    p << "|" << std::setw(10) << a->znacka << "|" << std::setw(10) << a->motor << "|" << std::setw(10) << a->dvere << "|\n";
    return p;
} 

int main()
{
    std::vector<Auto *> bazar;

    bazar.push_back (new Auto ("Skoda", 1600, 5));
    bazar.push_back (new Auto ("Skoda", 1600, 5));
    bazar.push_back (new Auto ("Skoda", 1600, 5));
    bazar.push_back (new Auto ("Tatra", 2500, 4));
    bazar.push_back (new Auto ("Skoda", 2000, 5));
    bazar.push_back (new Auto ("Tatra", 2500, 4));
    
    std::string cmd;
    std::cout << "jak se bude radit? (asc|desc)\n> ";
    std::cin >> cmd;

    std::map<std::string, std::function<bool(Auto *, Auto *)>> prikaz;

    prikaz["asc"] = [](Auto * a, Auto * b){return a->znacka < b->znacka;};
    prikaz["desc"] = [](Auto * a, Auto * b){return a->znacka > b->znacka;};

    std::sort (bazar.begin(), bazar.end(), prikaz[cmd]);

    std::cout << table::line();
    for (auto i : bazar)
    {
        std::cout << i << table::line();
    }

    auto it = std::find_if (bazar.begin(), bazar.end(), [toFind = "Tatra"](Auto * a){return a->znacka == toFind;});

    std::cout << std::endl << table::line() << *(it+1) << table::line() << std::endl;

    return 0;
}