#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <functional>

namespace table
{
    std::string line(int elCnt, int elWidth)
    {
        std::stringstream ss;
        ss << "+" << std::string(10, '-') << "+" << std::string(10, '-') << "+" << std::string(10, '-') << "+\n";
        return ss.str();
    }
}

struct Auto
{
    int motor;
    int dvere;
    std::string znacka;

    Auto(const char *n, int a, int b) : znacka(n), motor(a), dvere(b){};
};

std::ostream &operator<<(std::ostream &proud, Auto *data)
{
    proud << "|" << std::setw(10) << data->znacka << "|" << std::setw(10) << data->motor << "|" << std::setw(10) << data->dvere << "|\n";
    return proud;
}

int main()
{
    std::vector<Auto *> bazar;

    Auto a = Auto("Peugeot", 1000, 1);

    bazar.push_back(new Auto("Tatra", 2500, 2));
    bazar.push_back(new Auto("Skoda", 1600, 3));
    bazar.push_back(new Auto("Skoda", 1600, 8));
    bazar.push_back(new Auto("Skoda", 1600, 5));

    // std::string cmd;
    // std::cout << "Jakym smerem chces tridit (asc|desc)\n";
    // std::cin >> cmd;

    std::map<std::string, std::function<bool(Auto *, Auto *)>> prikaz;

    // prikaz["asc"] = [](Auto *a, Auto *b)
    // { return a->znacka < b->znacka; };
    // prikaz["desc"] = [](Auto *a, Auto *b)
    // { return a->znacka < b->znacka; };

    // std::sort(bazar.begin(), bazar.end(), prikaz[cmd]);

    std::cout << table::line();

    for (auto i : bazar)
    {
        // std::cout << i->znacka << " " << i->motor << "\n";
        std::cout << i << table::line();
    }

    return 0;
}
