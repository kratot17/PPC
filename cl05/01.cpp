#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

namespace table
{
    std::string line()
    {
        std::stringstream ss;
        ss << "+" << std::string(10, '-')
    }
}

struct  Auto
{
    int motor;
    int dvere;
    std::string znacka;

    Auto (const char * n, int a, int b): dvere(b){};
};


// slo by pouzit na hw01
void operator<< (std::ostream & proud, Auto * data)
{
    proud << "|" << std::setw(10) << data->znacka << "|" << std::setw(10) << data->motor << "|" << std::setw(10) << data->dvere << "| /n";
}

int main()
{
    std::vector<Auto *> bazar;

    Auto a = Auto("Peugeot", 1000, 1);

    bazar.push_back(new Auto("Skoda", 1600, 5));
    bazar.push_back(new Auto("Skoda", 1600, 5));
    bazar.push_back(new Auto("Skoda", 1600, 5));
    bazar.push_back(new Auto("Tatra", 2500, 2));

    for (auto i : bazar)
    {
        // std::cout << i->znacka << " " << i->motor << "\n";
        std::cout <<i;
    }

    return 0;
}